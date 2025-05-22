#pragma once
#include"Math.h"

namespace Math
{
    //                       [L00:  DC]
    //            [L1-1:  y] [L10:   z] [L11:   x]
    // [L2-2: xy] [L2-1: yz] [L20:  zz] [L21:  xz]  [L22:  xx - yy]
    template<typename T, size_t Order>
    struct SH
    {
        static constexpr size_t BaseCount = Order * Order;

        /** The integral of the constant SH basis. */
        static constexpr float ConstantBasisIntegral = 3.5449077018110320545963349666823f; // 2 * Sqrt(PI)

        /** SH Base **/
        static constexpr float L0Basis      = 0.28209479177387814347403972578039f; // 1 / (2*sqrt(kPI))
        static constexpr float L1Basis      = 0.48860251190291992158638462283835f; // sqrt(3) / (2*sqrt(kPI))
        static constexpr float L2xBasis     = 1.0925484305920790705433857058027f;  // sqrt(15) / (2*sqrt(kPI))
        static constexpr float L20Basis     = 0.315391565252520050f;               // sqrt(5) / (4*sqrt(kPI))
        static constexpr float L20BasisMul3 = 0.94617469575756001809268107088713f; // 3 * L20Basis
        static constexpr float L22Basis     = 0.54627421529603953527169285290135f; // sqrt(15) / (4*sqrt(kPI))

        /** Radiance to Irradiance factor **/
        static constexpr float L0IrradianceFactor = FPi;
        static constexpr float L1IrradianceFactor = 2.0f * FPi / 3.0f;
        static constexpr float L2IrradianceFactor = FPi / 4.0f;
        static constexpr float L1DiffuseRadianceFactor = 2.0f / 3.0f; // L1IrradianceFactor / Pi
        static constexpr float L2DiffuseRadianceFactor = 1.0f / 4.0f; // L2IrradianceFactor / Pi

        /** Compression scale constants **/
        /* 
        * Ref: Precomputed Lighting Advances in Call of Duty: Modern Warfare
        *  For band L, assume largest coeff is sqrt(2L + 1). 1 - sqrt(3) - sqrt(5)
        */
        static constexpr float L1RawCompressScale = 0.5773502691896258f; // L0Base / L1Base = 1 / Sqrt(3)
        static constexpr float L2RawCompressScale = 0.4472135954999579f; // L0Base / (L20Basis * 2) = 1 / Sqrt(5)
        static constexpr float L1RawIrradianceCompressScale = 0.8660254037844386f; // L1RawCompressScale / L1DiffuseRadianceFactor = 3 / (2 * Sqrt(3))
        static constexpr float L2RawIrradianceCompressScale = 1.788854381999832f; // L2RawCompressScale / L2DiffuseRadianceFactor = 4 / Sqrt(5)

        static constexpr float L1PreMulCompressScale = 1.0f / 3.0f;  // L1RawCompressScale * (L0Base / L1Base) = 1 / 3
        static constexpr float L2PreMulCompressScale = 4.0f / 15.0f; // For premuled L2, largest coff comes to L2-2/L2-1/L21 - 15/4, so scale is 4 / 15
        static constexpr float L1PreMulIrradianceCompressScale = 0.5f;           // L1PreMulCompressScale / L1DiffuseRadianceFactor = 1 / 2
        static constexpr float L2PreMulIrradianceCompressScale = 16.0f / 15.0f;  // L2RawCompressScale / L2DiffuseRadianceFactor = 16 / 15

        T V[BaseCount];
        
        SH operator *(T f);
        SH operator /(T f);

        SH& operator *=(T f);
        SH& operator /=(T f);
        
        SH operator +(const SH& sh);
        SH operator -(const SH& sh);
        
        SH& operator +=(const SH& sh);
        SH& operator -=(const SH& sh);

        T Dot(const SH& sh);       

        /** Integral of the function over the surface of the sphere. */
        T Integral() const { return V[0] * ConstantBasisIntegral; }
        /** Scales the function uniformly so its integral equals one. */
        void Normalize()
        {
            const T Integral = Integral();
            if (Integral > 0.00001f)
            {
                *this /= Integral;
            }
        }

        inline T Evaluate(const MathVector<T, 3>& vector) const noexcept { return Dot(Base(vector)); }

        inline void Accumulate(const MathVector<T, 3>& vector, T weight) { *this += Base(vector) * weight; }

        // Cos project of Radiance SH
        inline SH RadianceToIrradiance() const noexcept;
        // Pre divide Pi for Irradiance - Diffuse Reflection
        inline SH RadianceToDiffuseRadiance() const noexcept;

        // Pre Mul Basis to coeff, used by generate shader constants
        inline SH PreMultCoeffs() const noexcept;

        // Compress SH Coeffs, DC unchange, Other band to [-1, 1]
        inline SH CompressRaw() const noexcept; // Compress Raw SH
        inline SH CompressRawIrradiance() const noexcept; // Compress Irradiance or DiffuseRadiance
        inline SH CompressPreMul() const noexcept; // Compress PreMuled SH
        inline SH CompressPreMulIrradiance() const noexcept; // Compress PreMuled Irradiance or DiffuseRadiance

        
        static SH GetDiffuseTransfer(float3 normal);      

        inline static SH Base(const MathVector<T, 3>& vector) noexcept;
    };

    template<typename T, size_t Order>
    struct SHRGB
    {
        SH<T, Order> R, G, B;

        inline MathVector<T, 3> Evaluate(const MathVector<T, 3>& vector) const noexcept { return MathVector<T, 3>(R.Evaluate(vector), G.Evaluate(vector), B.Evaluate(vector)); }
    };

    using SH1 = SH<float, 2>;
    using SH2 = SH<float, 3>;
    using SH1Color = SHRGB<float, 2>;
    using SH2Color = SHRGB<float, 3>;

    struct SH1ShaderConstants
    {
        float4 A; // [x, y, z, DC]

        // norm.w shoud be one
        inline float1 Evaluate(float4 norm) const noexcept { return dot(norm, A); };
        inline float1 Evaluate(float3 norm) const noexcept { return dot(float4(norm, 1), A); };
        inline float Evaluate(Float3 norm) const noexcept { return (float)dot(float4(norm, 1), A); };

        void CovertFromSH(const SH1& sh) noexcept;
        void CovertFromPreMulSH(const SH1& sh) noexcept;
    };

    struct SH2ShaderConstants
    {
        float4 A, B;
        float1 C;

        inline float1 Evaluate(float4 norm) const noexcept;
        inline float1 Evaluate(float3 norm) const noexcept { return Evaluate(float4(norm, 1)); };
        inline float Evaluate(Float3 norm) const noexcept { return (float)Evaluate(float4(norm, 1)); };

        void CovertFromSH(const SH2& sh) noexcept;
        void CovertFromPreMulSH(const SH2& sh) noexcept;
    };

    struct SH1ColorShaderConstants
    {
        float4 Ar, Ag, Ab;

        inline float3 Evaluate(float4 norm) const noexcept;
        inline float3 Evaluate(float3 norm) const noexcept { return Evaluate(float4(norm, 1)); };
        inline Float3 Evaluate(Float3 norm) const noexcept { return (Float3)Evaluate(float4(norm, 1)); };

        void CovertFromSH(const SH1Color& sh) noexcept;
        void CovertFromPreMulSH(const SH1Color& sh) noexcept;
    };

    struct SH2ColorShaderConstants
    {
        float4 Ar, Ag, Ab;
        float4 Br, Bg, Bb;
        float4 C;

        inline float3 Evaluate(float4 norm) const noexcept;
        inline float3 Evaluate(float3 norm) const noexcept { return Evaluate(float4(norm, 1)); };
        inline Float3 Evaluate(Float3 norm) const noexcept { return (Float3)Evaluate(float4(norm, 1)); };

        void CovertFromSH(const SH2Color& sh) noexcept;
        void CovertFromPreMulSH(const SH2Color& sh) noexcept;
    };
}

#include "SphericalHarmonicImpl.h"