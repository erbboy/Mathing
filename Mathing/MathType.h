#pragma once

#include<stdint.h>
#include<array>
#include<math.h>
#include<cmath>
#include"./DirectXMath/Inc/DirectXMath.h"
#include"./DirectXMath/Inc/DirectXPackedVector.h"

namespace Math
{
    constexpr float M_PI = 3.141592654f;
    constexpr float M_2PI = 6.283185307f;
    constexpr float M_1DIVPI = 0.318309886f;
    constexpr float M_1DIV2PI = 0.159154943f;
    constexpr float M_PIDIV2 = 1.570796327f;
    constexpr float M_PIDIV4 = 0.785398163f;

    struct float16
    {
        uint16_t Val;

        float16() = default;
        float16(float v) { Val = DirectX::PackedVector::XMConvertFloatToHalf(Val); }

        operator float() { return DirectX::PackedVector::XMConvertHalfToFloat(Val); }
        float16& operator=(float v) { Val = DirectX::PackedVector::XMConvertFloatToHalf(Val); }
    };

    template<typename T, size_t Dim>
    struct MathVector
    {
        T v[Dim];

    };

#include"Swizzle.h"

    template<typename T>
    struct MathVector<T, 2>
    {
        union {           
            struct {
                T x, y;
            };
            T v[2];
            struct {
                T r, g;
            };
            MATH_SWIZZLE_VEC2;
        };

        MathVector() {}
        MathVector(T val) :x(val), y(val) {}
        MathVector(T vx, T vy) :x(vx), y(vy){}
        MathVector(const MathVector& v) :x(v.x), y(v.y) {}

        inline T& operator[](size_t index) noexcept { return v[index]; }
    };

    template<typename T>
    struct MathVector<T, 3>
    {
        union {           
            struct {
                T x, y, z;
            };
            T v[3];
            struct {
                T r, g, b;
            };
            MATH_SWIZZLE_VEC3;
        };

        MathVector() {}
        MathVector(T val) :x(val), y(val), z(val) {}
        MathVector(T vx, T vy, T vz) :x(vx), y(vy), z(vz) {}
        MathVector(const MathVector& v) :x(v.x), y(v.y), z(v.z) {}
        MathVector(const MathVector<T, 2>& v, T vz) :x(v.x), y(v.y), z(vz) {}
        MathVector(T vx,const MathVector<T, 2>& v) :x(vx), y(v.x), z(v.y) {}

        inline T& operator[](size_t index) noexcept { return v[index]; }
    };

    template<typename T>
    struct MathVector<T, 4>
    {
        union {           
            struct {
                T x, y, z, w;
            };
            T v[4];
            struct {
                T r, g, b, a;
            };
            MATH_SWIZZLE_VEC4;
        };

        MathVector() {}
        MathVector(T val) :x(val), y(val), z(val), w(val) {}
        MathVector(T vx, T vy, T vz, T vw) :x(vx), y(vy), z(vz), w(vw) {}
        MathVector(const MathVector& v) :x(v.x), y(v.y), z(v.z), w(v.w) {}
        MathVector(const MathVector<T, 2>& v, T vz, T vw) :x(v.x), y(v.y), z(vz), w(vw) {}
        MathVector(T vx, const MathVector<T, 2>& v, T vw) :x(vx), y(v.x), z(v.y), w(vw) {}
        MathVector(T vx, T vy, const MathVector<T, 2>& v) :x(vx), y(vy), z(v.x), w(v.y) {}
        MathVector(const MathVector<T, 2>& v0, const MathVector<T, 2>& v1) :x(v0.x), y(v0.y), z(v1.x), w(v1.y) {}
        MathVector(const MathVector<T, 3>& v, T vw) :x(v.x), y(v.y), z(v.z), w(vw) {}
        MathVector(T vx, const MathVector<T, 3>& v) :x(vx), y(v.x), z(v.y), w(v.z) {}

        inline T& operator[](size_t index) noexcept { return v[index]; }
    };
    
    using Float = float;
    using Float2 = MathVector<Float, 2>;
    using Float3 = MathVector<Float, 3>;
    using Float4 = MathVector<Float, 4>;

    using Double = double;
    using Double2 = MathVector<Double, 2>;
    using Double3 = MathVector<Double, 3>;
    using Double4 = MathVector<Double, 4>;

    using Half = float16;
    using Half2 = MathVector<Half, 2>;
    using Half3 = MathVector<Half, 3>;
    using Half4 = MathVector<Half, 4>;

    using Int = int32_t;
    using Int2 = MathVector<Int, 2>;
    using Int3 = MathVector<Int, 3>;
    using Int4 = MathVector<Int, 4>;

    using UInt = uint32_t;
    using UInt2 = MathVector<UInt, 2>;
    using UInt3 = MathVector<UInt, 3>;
    using UInt4 = MathVector<UInt, 4>;

    using Short = int16_t;
    using Short2 = MathVector<Short, 2>;
    using Short3 = MathVector<Short, 3>;
    using Short4 = MathVector<Short, 4>;

    using UShort = uint16_t;
    using UShort2 = MathVector<UShort, 2>;
    using UShort3 = MathVector<UShort, 3>;
    using UShort4 = MathVector<UShort, 4>;

    using Long = int64_t;
    using Long2 = MathVector<Long, 2>;
    using Long3 = MathVector<Long, 3>;
    using Long4 = MathVector<Long, 4>;

    using ULong = uint64_t;
    using ULong2 = MathVector<ULong, 2>;
    using ULong3 = MathVector<ULong, 3>;
    using ULong4 = MathVector<ULong, 4>;

    using Byte = uint8_t;
    using Byte2 = MathVector<Byte, 2>;
    using Byte3 = MathVector<Byte, 3>;
    using Byte4 = MathVector<Byte, 4>;

    using SByte = int8_t;
    using SByte2 = MathVector<SByte, 2>;
    using SByte3 = MathVector<SByte, 3>;
    using SByte4 = MathVector<SByte, 4>;

    //using Bool = int8_t;
    using Bool = bool;
    using Bool2 = MathVector<Bool, 2>;
    using Bool3 = MathVector<Bool, 3>;
    using Bool4 = MathVector<Bool, 4>;

    using BOOL = uint32_t;
    using BOOL2 = MathVector<BOOL, 2>;
    using BOOL3 = MathVector<BOOL, 3>;
    using BOOL4 = MathVector<BOOL, 4>;

    template<typename T, size_t Row, size_t Col>
    struct MathMatrix
    {
        union{
            T m[Row][Col];
            MathVector<T, Col> v[Row];
        };  

        inline MathVector<T, Col>& operator[](size_t index) noexcept { return v[index]; }
    };

    template<typename T>
    struct MathMatrix<T, 3, 3>
    {
        union {
            struct
            {
                T _11, _12, _13;
                T _21, _22, _23;
                T _31, _32, _33;
            };
            T m[3][3];
            T f[9];
            MathVector<T, 3> v[3];
        };

        inline MathVector<T, 3>& operator[](size_t index) noexcept { return v[index]; }

        inline static MathMatrix<T, 3, 3> Identity() noexcept;

        inline static MathMatrix<T, 3, 3> Translate(T OffsetX, T OffsetY) noexcept;
        inline static MathMatrix<T, 3, 3> Translate(const MathVector<T, 2>& Offset) noexcept;
        inline static MathMatrix<T, 3, 3> Translate(const T* Offset) noexcept;

        inline static MathMatrix<T, 3, 3> Scaling(T ScaleX, T ScaleY) noexcept;
        inline static MathMatrix<T, 3, 3> Scaling(const MathVector<T, 2>& Scale) noexcept;
        inline static MathMatrix<T, 3, 3> Scaling(const T* Scale) noexcept;
        inline static MathMatrix<T, 3, 3> Scaling(T Scale) noexcept;

        inline static MathMatrix<T, 3, 3> Rotation(T Radian) noexcept;
        
    };

    template<typename T>
    struct MathMatrix<T, 4, 4>
    {
        union {
            struct
            {
                T _11, _12, _13, _14;
                T _21, _22, _23, _24;
                T _31, _32, _33, _34;
                T _41, _42, _43, _44;
            };
            T m[4][4];
            T f[16];
            MathVector<T, 4> v[4];
        };

        inline MathVector<T, 4>& operator[](size_t index) noexcept { return v[index]; }

        inline static MathMatrix<T, 4, 4> Identity() noexcept;

        inline static MathMatrix<T, 4, 4> Translate(T OffsetX, T OffsetY, T OffsetZ) noexcept;
        inline static MathMatrix<T, 4, 4> Translate(const MathVector<T, 4>& Offset) noexcept;
        inline static MathMatrix<T, 4, 4> Translate(const MathVector<T, 3>& Offset) noexcept;
        inline static MathMatrix<T, 4, 4> Translate(const T* Offset) noexcept;

        inline static MathMatrix<T, 4, 4> Scaling(T ScaleX, T ScaleY, T ScaleZ) noexcept;
        inline static MathMatrix<T, 4, 4> Scaling(const MathVector<T, 4>& Scale) noexcept;
        inline static MathMatrix<T, 4, 4> Scaling(const MathVector<T, 3>& Scale) noexcept;
        inline static MathMatrix<T, 4, 4> Scaling(const T* Scale) noexcept;
        inline static MathMatrix<T, 4, 4> Scaling(const T Scale) noexcept;

        inline static MathMatrix<T, 4, 4> RotationX(T Radian) noexcept;
        inline static MathMatrix<T, 4, 4> RotationY(T Radian) noexcept;
        inline static MathMatrix<T, 4, 4> RotationZ(T Radian) noexcept;
        // Rotates about y-axis (Radian.y), then x-axis (Radian.x), then z-axis (Radian.z)
        inline static MathMatrix<T, 4, 4> RotationRollPitchYaw(T Pitch, T Yaw, T Roll) noexcept;
        inline static MathMatrix<T, 4, 4> RotationAxis(const MathVector<T, 3>& Axis, T Radian) noexcept;
        inline static MathMatrix<T, 4, 4> RotationQuat(const MathVector<T, 4>& Quat) noexcept;
        
        inline static MathMatrix<T, 4, 4> Transform(const MathVector<T, 3>& Scale, const MathVector<T, 4>& RotQuat, const MathVector<T, 3>& Translation) noexcept;
        inline static MathMatrix<T, 4, 4> Transform(const MathVector<T, 3>& Scale, const MathVector<T, 3>& RotOrigin, const MathVector<T, 4>& RotQuat, const MathVector<T, 3>& Translation) noexcept;
        inline static MathMatrix<T, 4, 4> Transform(const MathVector<T, 3>& ScaleOrigin, const MathVector<T, 4>& ScalingOrientationQuat, const MathVector<T, 3>& Scale, const MathVector<T, 3>& RotOrigin, const MathVector<T, 4>& RotQuat, const MathVector<T, 3>& Translation) noexcept;

        inline static MathMatrix<T, 4, 4> ViewAt(const MathVector<T, 3>& Eye, const MathVector<T, 3>& Focus, const MathVector<T, 3>& Up) noexcept;
        inline static MathMatrix<T, 4, 4> ViewTo(const MathVector<T, 3>& Eye, const MathVector<T, 3>& Direction, const MathVector<T, 3>& Up) noexcept;

        inline static MathMatrix<T, 4, 4> ProjPerspective(T ViewWidth, T ViewHeight, T NearZ, T FarZ) noexcept;
        inline static MathMatrix<T, 4, 4> ProjPerspectiveFov(T FovRadianY, T AspectRatio, T NearZ, T FarZ) noexcept;
        inline static MathMatrix<T, 4, 4> ProjPerspectiveOffCenter(T ViewLeft, T ViewRight, T ViewBottom, T ViewTop, T NearZ, T FarZ) noexcept;

        inline static MathMatrix<T, 4, 4> ProjOrthographic(T ViewWidth, T ViewHeight, T NearZ, T FarZ) noexcept;
        inline static MathMatrix<T, 4, 4> ProjOrthographicOffCenter(T ViewLeft, T ViewRight, T ViewBottom, T ViewTop, T NearZ, T FarZ) noexcept;
    };

    using Float3x3 = MathMatrix<Float, 3, 3>;
    using Float4x4 = MathMatrix<Float, 4, 4>;
    
    using Double3x3 = MathMatrix<Double, 3, 3>;
    using Double4x4 = MathMatrix<Double, 4, 4>;

    /* Floating Consts */
    constexpr float  FSmallNum = 1.e-8f;
    constexpr float  FKindaSmallNum = 1.e-4f;
    constexpr float  FBigNum = 3.4e+38f;
    constexpr float  FEulersNum = 2.71828182845904523536f;
    constexpr float  FGoldenRatio = 1.6180339887498948482045868343656381f;	/* Also known as divine proportion, golden mean, or golden section - related to the Fibonacci Sequence = (1 + sqrt(5)) / 2 */
    constexpr float  FNoFractional = 8388608.f; /* All single-precision floating point numbers greater than or equal to this have no fractional value. */

    constexpr float  FPi = 3.1415926535897932f;
    constexpr float  FInvPi = 0.31830988618f;
    constexpr float  FHalfPi = 1.57079632679f;
    constexpr float  FTwoPi = 6.28318530717f;
    constexpr float  FPiSquare = 9.86960440108f;
    constexpr float  FRadian2Degree = 180.0f / FPi;
    constexpr float  FDegree2Radian = FPi / 180.0f;
};