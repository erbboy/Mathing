#pragma once

namespace Math
{
    // General swizzle template
    template<uint32_t SwizzleX>
    inline DirectX::XMVECTOR Swizzler(DirectX::FXMVECTOR V) noexcept
    {
        return DirectX::XMVectorSwizzle<SwizzleX, SwizzleX, SwizzleX, SwizzleX>(V);
    }
    template<uint32_t SwizzleX, uint32_t SwizzleY>
    inline DirectX::XMVECTOR Swizzler(DirectX::FXMVECTOR V) noexcept
    {
        return DirectX::XMVectorSwizzle<SwizzleX, SwizzleY, 2, 3>(V);
    }
    template<uint32_t SwizzleX, uint32_t SwizzleY, uint32_t SwizzleZ>
    inline DirectX::XMVECTOR Swizzler(DirectX::FXMVECTOR V) noexcept
    {
        return DirectX::XMVectorSwizzle<SwizzleX, SwizzleY, SwizzleZ, 3>(V);
    }
    template<uint32_t SwizzleX, uint32_t SwizzleY, uint32_t SwizzleZ, uint32_t SwizzleW>
    inline DirectX::XMVECTOR Swizzler(DirectX::FXMVECTOR V) noexcept
    {
        return DirectX::XMVectorSwizzle<SwizzleX, SwizzleY, SwizzleZ, SwizzleW>(V);
    }

    template<uint32_t Dest0, uint32_t Src0>
    struct AssignToPermute1
    {
        static constexpr uint32_t Permute0 = Dest0 == 0 ? Src0 + 4 : 0;
        static constexpr uint32_t Permute1 = Dest0 == 1 ? Src0 + 4 : 1;
        static constexpr uint32_t Permute2 = Dest0 == 2 ? Src0 + 4 : 2;
        static constexpr uint32_t Permute3 = Dest0 == 3 ? Src0 + 4 : 3;
    };

    template<uint32_t Dest0, uint32_t Dest1, uint32_t Src0, uint32_t Src1>
    struct AssignToPermute2
    {
        static constexpr uint32_t Permute0 = Dest0 == 0 ? Src0 + 4 : (Dest1 == 0 ? Src1 + 4 : 0);
        static constexpr uint32_t Permute1 = Dest0 == 1 ? Src0 + 4 : (Dest1 == 1 ? Src1 + 4 : 1);
        static constexpr uint32_t Permute2 = Dest0 == 2 ? Src0 + 4 : (Dest1 == 2 ? Src1 + 4 : 2);
        static constexpr uint32_t Permute3 = Dest0 == 3 ? Src0 + 4 : (Dest1 == 3 ? Src1 + 4 : 3);
    };

    template<uint32_t Dest0, uint32_t Dest1, uint32_t Src0>
    struct AssignSingleToPermute2
    {
        static constexpr uint32_t Permute0 = Dest0 == 0 ? Src0 + 4 : (Dest1 == 0 ? Src0 + 4 : 0);
        static constexpr uint32_t Permute1 = Dest0 == 1 ? Src0 + 4 : (Dest1 == 1 ? Src0 + 4 : 1);
        static constexpr uint32_t Permute2 = Dest0 == 2 ? Src0 + 4 : (Dest1 == 2 ? Src0 + 4 : 2);
        static constexpr uint32_t Permute3 = Dest0 == 3 ? Src0 + 4 : (Dest1 == 3 ? Src0 + 4 : 3);
    };

    template<uint32_t Dest0, uint32_t Dest1, uint32_t Dest2, uint32_t Src0, uint32_t Src1, uint32_t Src2>
    struct AssignToPermute3
    {
        static constexpr uint32_t Permute0 = Dest0 == 0 ? Src0 + 4 : (Dest1 == 0 ? Src1 + 4 : (Dest2 == 0 ? Src2 + 4 : 0));
        static constexpr uint32_t Permute1 = Dest0 == 1 ? Src0 + 4 : (Dest1 == 1 ? Src1 + 4 : (Dest2 == 1 ? Src2 + 4 : 1));
        static constexpr uint32_t Permute2 = Dest0 == 2 ? Src0 + 4 : (Dest1 == 2 ? Src1 + 4 : (Dest2 == 2 ? Src2 + 4 : 2));
        static constexpr uint32_t Permute3 = Dest0 == 3 ? Src0 + 4 : (Dest1 == 3 ? Src1 + 4 : (Dest2 == 3 ? Src2 + 4 : 3));
    };

    template<uint32_t Dest0, uint32_t Dest1, uint32_t Dest2, uint32_t Src0>
    struct AssignSingleToPermute3
    {
        static constexpr uint32_t Permute0 = Dest0 == 0 ? Src0 + 4 : (Dest1 == 0 ? Src0 + 4 : (Dest2 == 0 ? Src0 + 4 : 0));
        static constexpr uint32_t Permute1 = Dest0 == 1 ? Src0 + 4 : (Dest1 == 1 ? Src0 + 4 : (Dest2 == 1 ? Src0 + 4 : 1));
        static constexpr uint32_t Permute2 = Dest0 == 2 ? Src0 + 4 : (Dest1 == 2 ? Src0 + 4 : (Dest2 == 2 ? Src0 + 4 : 2));
        static constexpr uint32_t Permute3 = Dest0 == 3 ? Src0 + 4 : (Dest1 == 3 ? Src0 + 4 : (Dest2 == 3 ? Src0 + 4 : 3));
    };

    template<uint32_t Dest0, uint32_t Dest1, uint32_t Dest2, uint32_t Dest3, uint32_t Src0, uint32_t Src1, uint32_t Src2, uint32_t Src3>
    struct AssignToPermute4
    {
        static constexpr uint32_t Permute0 = Dest0 == 0 ? Src0 + 4 : (Dest1 == 0 ? Src1 + 4 : (Dest2 == 0 ? Src2 + 4 : (Dest3 == 0 ? Src3 + 4 : 0)));
        static constexpr uint32_t Permute1 = Dest0 == 1 ? Src0 + 4 : (Dest1 == 1 ? Src1 + 4 : (Dest2 == 1 ? Src2 + 4 : (Dest3 == 1 ? Src3 + 4 : 1)));
        static constexpr uint32_t Permute2 = Dest0 == 2 ? Src0 + 4 : (Dest1 == 2 ? Src1 + 4 : (Dest2 == 2 ? Src2 + 4 : (Dest3 == 2 ? Src3 + 4 : 2)));
        static constexpr uint32_t Permute3 = Dest0 == 3 ? Src0 + 4 : (Dest1 == 3 ? Src1 + 4 : (Dest2 == 3 ? Src2 + 4 : (Dest3 == 3 ? Src3 + 4 : 3)));
    };

    template<uint32_t Dest0, uint32_t Dest1, uint32_t Dest2, uint32_t Dest3, uint32_t Src0>
    struct AssignSingleToPermute4
    {
        static constexpr uint32_t Permute0 = Dest0 == 0 ? Src0 + 4 : (Dest1 == 0 ? Src0 + 4 : (Dest2 == 0 ? Src0 + 4 : (Dest3 == 0 ? Src0 + 4 : 0)));
        static constexpr uint32_t Permute1 = Dest0 == 1 ? Src0 + 4 : (Dest1 == 1 ? Src0 + 4 : (Dest2 == 1 ? Src0 + 4 : (Dest3 == 1 ? Src0 + 4 : 1)));
        static constexpr uint32_t Permute2 = Dest0 == 2 ? Src0 + 4 : (Dest1 == 2 ? Src0 + 4 : (Dest2 == 2 ? Src0 + 4 : (Dest3 == 2 ? Src0 + 4 : 2)));
        static constexpr uint32_t Permute3 = Dest0 == 3 ? Src0 + 4 : (Dest1 == 3 ? Src0 + 4 : (Dest2 == 3 ? Src0 + 4 : (Dest3 == 3 ? Src0 + 4 : 3)));
    };


    template<typename TScalar, uint32_t... Indexs>
    struct SimdSwizzle
    {
        
    };

    template<typename T, size_t Dim>
    struct SimdVector;

    // .x .y .z
    template<uint32_t X>
    struct SimdSwizzle<float, X>
    {
        SimdSwizzle() = default;
        SimdSwizzle(const SimdSwizzle&) = delete;

        /*inline operator SimdVector<float, 1>() const noexcept
        {
            SimdVector<float, 1> ret;
            ret.Packed = Swizzler<X>(Packed);
            return ret;
        }*/

        inline operator float() const noexcept
        {
            float ret;
            DirectX::XMStoreFloat((float*)(&ret), Swizzler<X>(Packed));
            return ret;
        }
        
        // .x = .y
        template<uint32_t OthX>
        inline SimdSwizzle& operator =(const SimdSwizzle<float, OthX>& oth) noexcept
        {
            using PN = AssignToPermute1<X, OthX>;
            Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
            return *this;
        }

        // .x = float1
        inline SimdSwizzle& operator =(const SimdVector<float, 1>& oth) noexcept;

        // .x = 1.0f
        inline SimdSwizzle& operator =(float oth) noexcept
        {
            V[X] = oth;
            return *this;
        }

        union
        {
            DirectX::XMVECTOR Packed;
            float V[4];
        };
    };

    // .xy .zw .yy
    template<uint32_t X, uint32_t Y>
    struct SimdSwizzle<float, X, Y>
    {
        SimdSwizzle() = default;
        SimdSwizzle(const SimdSwizzle&) = delete;

        /*inline operator SimdVector<float, 2>() const noexcept
        {
            SimdVector<float, 2> ret;
            ret.Packed = Swizzler<X, Y>(Packed);
            return ret;
        }*/

        inline operator MathVector<float, 2>() const noexcept
        {
            MathVector<float, 2> ret;
            DirectX::XMStoreFloat2( (DirectX::XMFLOAT2*)(&ret), Swizzler<X, Y>(Packed));
            return ret;
        }

        // .xy = .zw
        template<uint32_t OthX, uint32_t OthY>
        inline SimdSwizzle& operator =(const SimdSwizzle<float, OthX, OthY>& oth) noexcept
        {
            using PN = AssignToPermute2<X, Y, OthX, OthY>;
            Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
            return *this;
        }

        // .xy = .y
        template<uint32_t OthX>
        inline SimdSwizzle& operator =(const SimdSwizzle<float, OthX>& oth) noexcept
        {
            using PN = AssignSingleToPermute2<X, Y, OthX>;
            Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
            return *this;
        }

        // .xy = float1
        inline SimdSwizzle& operator =(const SimdVector<float, 1>& oth) noexcept;

        // .xy = float2
        inline SimdSwizzle& operator =(const SimdVector<float, 2>& oth) noexcept;

        // .xy = float
        inline SimdSwizzle& operator =(float oth) noexcept
        {
            V[X] = oth;
            V[Y] = oth;
            return *this;
        }

        union
        {
            DirectX::XMVECTOR Packed;
            float V[4];
        };
    };

    // .xyz .zwx .yyy
    template<uint32_t X, uint32_t Y, uint32_t Z>
    struct SimdSwizzle<float, X, Y, Z>
    {
        SimdSwizzle() = default;
        SimdSwizzle(const SimdSwizzle&) = delete;

        /*inline operator SimdVector<float, 3>() const noexcept
        {
            SimdVector<float, 3> ret;
            ret.Packed = Swizzler<X, Y, Z>(Packed);
            return ret;
        }*/

        inline operator MathVector<float, 3>() const noexcept
        {
            MathVector<float, 3> ret;
            DirectX::XMStoreFloat3((DirectX::XMFLOAT3*)(&ret), Swizzler<X, Y, Z>(Packed));
            return ret;
        }

        // .xyz = .xzw
        template<uint32_t OthX, uint32_t OthY, uint32_t OthZ>
        inline SimdSwizzle& operator =(const SimdSwizzle<float, OthX, OthY, OthZ>& oth) noexcept
        {
            using PN = AssignToPermute3<X, Y, Z, OthX, OthY, OthZ>;
            Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
            return *this;
        }

        // .xyz = .y
        template<uint32_t OthX>
        inline SimdSwizzle& operator =(const SimdSwizzle<float, OthX>& oth) noexcept
        {
            using PN = AssignSingleToPermute3<X, Y, Z, OthX>;
            Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
            return *this;
        }

        // .xyz = float1
        inline SimdSwizzle& operator =(const SimdVector<float, 1>& oth) noexcept;

        // .xyz = float3
        inline SimdSwizzle& operator =(const SimdVector<float, 3>& oth) noexcept;

        // .xyz = float
        inline SimdSwizzle& operator =(float oth) noexcept
        {
            V[X] = oth;
            V[Y] = oth;
            V[Z] = oth;
            return *this;
        }

        union
        {
            DirectX::XMVECTOR Packed;
            float V[4];
        };
    };

    // .xyzw .zwxz .yyyy
    template<uint32_t X, uint32_t Y, uint32_t Z, uint32_t W>
    struct SimdSwizzle<float, X, Y, Z, W>
    {
        SimdSwizzle() = default;
        SimdSwizzle(const SimdSwizzle&) = delete;

        /*inline operator SimdVector<float, 4>() const noexcept
        {
            SimdVector<float, 4> ret;
            ret.Packed = Swizzler<X, Y, Z, W>(Packed);
            return ret;
        }*/

        inline operator MathVector<float, 4>() const noexcept
        {
            MathVector<float, 4> ret;
            DirectX::XMStoreFloat4((DirectX::XMFLOAT3*)(&ret), Swizzler<X, Y, Z, W>(Packed));
            return ret;
        }

        // .xyzw = .xzww
        template<uint32_t OthX, uint32_t OthY, uint32_t OthZ, uint32_t OthW>
        inline SimdSwizzle& operator =(const SimdSwizzle<float, OthX, OthY, OthZ, OthW>& oth) noexcept
        {
            using PN = AssignToPermute4<X, Y, Z, W, OthX, OthY, OthZ, OthW>;
            Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
            return *this;
        }

        // .xyzw = .y
        template<uint32_t OthX>
        inline SimdSwizzle& operator =(const SimdSwizzle<float, OthX>& oth) noexcept
        {
            using PN = AssignSingleToPermute4<X, Y, Z, W, OthX>;
            Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
            return *this;
        }

        // .xyzw = float1
        inline SimdSwizzle& operator =(const SimdVector<float, 1>& oth) noexcept;

        // .xyzw = float4
        inline SimdSwizzle& operator =(const SimdVector<float, 4>& oth) noexcept;

        // .xyzw = float
        inline SimdSwizzle& operator =(float oth) noexcept
        {
            V[X] = oth;
            V[Y] = oth;
            V[Z] = oth;
            V[W] = oth;
            return *this;
        }

        union
        {
            DirectX::XMVECTOR Packed;
            float V[4];
        };
    };

    #define MATH_SIMD_SWIZZLE_VEC2 \
    SimdSwizzle<float, 0> x; \
    SimdSwizzle<float, 1> y; \
    SimdSwizzle<float, 0, 0> xx; \
    SimdSwizzle<float, 1, 0> yx; \
    SimdSwizzle<float, 0, 1> xy; \
    SimdSwizzle<float, 1, 1> yy; \
    SimdSwizzle<float, 0, 0, 0> xxx; \
    SimdSwizzle<float, 1, 0, 0> yxx; \
    SimdSwizzle<float, 0, 1, 0> xyx; \
    SimdSwizzle<float, 1, 1, 0> yyx; \
    SimdSwizzle<float, 0, 0, 1> xxy; \
    SimdSwizzle<float, 1, 0, 1> yxy; \
    SimdSwizzle<float, 0, 1, 1> xyy; \
    SimdSwizzle<float, 1, 1, 1> yyy; \
    SimdSwizzle<float, 0, 0, 0, 0> xxxx; \
    SimdSwizzle<float, 1, 0, 0, 0> yxxx; \
    SimdSwizzle<float, 0, 1, 0, 0> xyxx; \
    SimdSwizzle<float, 1, 1, 0, 0> yyxx; \
    SimdSwizzle<float, 0, 0, 1, 0> xxyx; \
    SimdSwizzle<float, 1, 0, 1, 0> yxyx; \
    SimdSwizzle<float, 0, 1, 1, 0> xyyx; \
    SimdSwizzle<float, 1, 1, 1, 0> yyyx; \
    SimdSwizzle<float, 0, 0, 0, 1> xxxy; \
    SimdSwizzle<float, 1, 0, 0, 1> yxxy; \
    SimdSwizzle<float, 0, 1, 0, 1> xyxy; \
    SimdSwizzle<float, 1, 1, 0, 1> yyxy; \
    SimdSwizzle<float, 0, 0, 1, 1> xxyy; \
    SimdSwizzle<float, 1, 0, 1, 1> yxyy; \
    SimdSwizzle<float, 0, 1, 1, 1> xyyy; \
    SimdSwizzle<float, 1, 1, 1, 1> yyyy; \

    #define MATH_SIMD_SWIZZLE_VEC3 \
    SimdSwizzle<float, 0> x; \
    SimdSwizzle<float, 1> y; \
    SimdSwizzle<float, 2> z; \
    SimdSwizzle<float, 0, 0> xx; \
    SimdSwizzle<float, 1, 0> yx; \
    SimdSwizzle<float, 2, 0> zx; \
    SimdSwizzle<float, 0, 1> xy; \
    SimdSwizzle<float, 1, 1> yy; \
    SimdSwizzle<float, 2, 1> zy; \
    SimdSwizzle<float, 0, 2> xz; \
    SimdSwizzle<float, 1, 2> yz; \
    SimdSwizzle<float, 2, 2> zz; \
    SimdSwizzle<float, 0, 0, 0> xxx; \
    SimdSwizzle<float, 1, 0, 0> yxx; \
    SimdSwizzle<float, 2, 0, 0> zxx; \
    SimdSwizzle<float, 0, 1, 0> xyx; \
    SimdSwizzle<float, 1, 1, 0> yyx; \
    SimdSwizzle<float, 2, 1, 0> zyx; \
    SimdSwizzle<float, 0, 2, 0> xzx; \
    SimdSwizzle<float, 1, 2, 0> yzx; \
    SimdSwizzle<float, 2, 2, 0> zzx; \
    SimdSwizzle<float, 0, 0, 1> xxy; \
    SimdSwizzle<float, 1, 0, 1> yxy; \
    SimdSwizzle<float, 2, 0, 1> zxy; \
    SimdSwizzle<float, 0, 1, 1> xyy; \
    SimdSwizzle<float, 1, 1, 1> yyy; \
    SimdSwizzle<float, 2, 1, 1> zyy; \
    SimdSwizzle<float, 0, 2, 1> xzy; \
    SimdSwizzle<float, 1, 2, 1> yzy; \
    SimdSwizzle<float, 2, 2, 1> zzy; \
    SimdSwizzle<float, 0, 0, 2> xxz; \
    SimdSwizzle<float, 1, 0, 2> yxz; \
    SimdSwizzle<float, 2, 0, 2> zxz; \
    SimdSwizzle<float, 0, 1, 2> xyz; \
    SimdSwizzle<float, 1, 1, 2> yyz; \
    SimdSwizzle<float, 2, 1, 2> zyz; \
    SimdSwizzle<float, 0, 2, 2> xzz; \
    SimdSwizzle<float, 1, 2, 2> yzz; \
    SimdSwizzle<float, 2, 2, 2> zzz; \
    SimdSwizzle<float, 0, 0, 0, 0> xxxx; \
    SimdSwizzle<float, 1, 0, 0, 0> yxxx; \
    SimdSwizzle<float, 2, 0, 0, 0> zxxx; \
    SimdSwizzle<float, 0, 1, 0, 0> xyxx; \
    SimdSwizzle<float, 1, 1, 0, 0> yyxx; \
    SimdSwizzle<float, 2, 1, 0, 0> zyxx; \
    SimdSwizzle<float, 0, 2, 0, 0> xzxx; \
    SimdSwizzle<float, 1, 2, 0, 0> yzxx; \
    SimdSwizzle<float, 2, 2, 0, 0> zzxx; \
    SimdSwizzle<float, 0, 0, 1, 0> xxyx; \
    SimdSwizzle<float, 1, 0, 1, 0> yxyx; \
    SimdSwizzle<float, 2, 0, 1, 0> zxyx; \
    SimdSwizzle<float, 0, 1, 1, 0> xyyx; \
    SimdSwizzle<float, 1, 1, 1, 0> yyyx; \
    SimdSwizzle<float, 2, 1, 1, 0> zyyx; \
    SimdSwizzle<float, 0, 2, 1, 0> xzyx; \
    SimdSwizzle<float, 1, 2, 1, 0> yzyx; \
    SimdSwizzle<float, 2, 2, 1, 0> zzyx; \
    SimdSwizzle<float, 0, 0, 2, 0> xxzx; \
    SimdSwizzle<float, 1, 0, 2, 0> yxzx; \
    SimdSwizzle<float, 2, 0, 2, 0> zxzx; \
    SimdSwizzle<float, 0, 1, 2, 0> xyzx; \
    SimdSwizzle<float, 1, 1, 2, 0> yyzx; \
    SimdSwizzle<float, 2, 1, 2, 0> zyzx; \
    SimdSwizzle<float, 0, 2, 2, 0> xzzx; \
    SimdSwizzle<float, 1, 2, 2, 0> yzzx; \
    SimdSwizzle<float, 2, 2, 2, 0> zzzx; \
    SimdSwizzle<float, 0, 0, 0, 1> xxxy; \
    SimdSwizzle<float, 1, 0, 0, 1> yxxy; \
    SimdSwizzle<float, 2, 0, 0, 1> zxxy; \
    SimdSwizzle<float, 0, 1, 0, 1> xyxy; \
    SimdSwizzle<float, 1, 1, 0, 1> yyxy; \
    SimdSwizzle<float, 2, 1, 0, 1> zyxy; \
    SimdSwizzle<float, 0, 2, 0, 1> xzxy; \
    SimdSwizzle<float, 1, 2, 0, 1> yzxy; \
    SimdSwizzle<float, 2, 2, 0, 1> zzxy; \
    SimdSwizzle<float, 0, 0, 1, 1> xxyy; \
    SimdSwizzle<float, 1, 0, 1, 1> yxyy; \
    SimdSwizzle<float, 2, 0, 1, 1> zxyy; \
    SimdSwizzle<float, 0, 1, 1, 1> xyyy; \
    SimdSwizzle<float, 1, 1, 1, 1> yyyy; \
    SimdSwizzle<float, 2, 1, 1, 1> zyyy; \
    SimdSwizzle<float, 0, 2, 1, 1> xzyy; \
    SimdSwizzle<float, 1, 2, 1, 1> yzyy; \
    SimdSwizzle<float, 2, 2, 1, 1> zzyy; \
    SimdSwizzle<float, 0, 0, 2, 1> xxzy; \
    SimdSwizzle<float, 1, 0, 2, 1> yxzy; \
    SimdSwizzle<float, 2, 0, 2, 1> zxzy; \
    SimdSwizzle<float, 0, 1, 2, 1> xyzy; \
    SimdSwizzle<float, 1, 1, 2, 1> yyzy; \
    SimdSwizzle<float, 2, 1, 2, 1> zyzy; \
    SimdSwizzle<float, 0, 2, 2, 1> xzzy; \
    SimdSwizzle<float, 1, 2, 2, 1> yzzy; \
    SimdSwizzle<float, 2, 2, 2, 1> zzzy; \
    SimdSwizzle<float, 0, 0, 0, 2> xxxz; \
    SimdSwizzle<float, 1, 0, 0, 2> yxxz; \
    SimdSwizzle<float, 2, 0, 0, 2> zxxz; \
    SimdSwizzle<float, 0, 1, 0, 2> xyxz; \
    SimdSwizzle<float, 1, 1, 0, 2> yyxz; \
    SimdSwizzle<float, 2, 1, 0, 2> zyxz; \
    SimdSwizzle<float, 0, 2, 0, 2> xzxz; \
    SimdSwizzle<float, 1, 2, 0, 2> yzxz; \
    SimdSwizzle<float, 2, 2, 0, 2> zzxz; \
    SimdSwizzle<float, 0, 0, 1, 2> xxyz; \
    SimdSwizzle<float, 1, 0, 1, 2> yxyz; \
    SimdSwizzle<float, 2, 0, 1, 2> zxyz; \
    SimdSwizzle<float, 0, 1, 1, 2> xyyz; \
    SimdSwizzle<float, 1, 1, 1, 2> yyyz; \
    SimdSwizzle<float, 2, 1, 1, 2> zyyz; \
    SimdSwizzle<float, 0, 2, 1, 2> xzyz; \
    SimdSwizzle<float, 1, 2, 1, 2> yzyz; \
    SimdSwizzle<float, 2, 2, 1, 2> zzyz; \
    SimdSwizzle<float, 0, 0, 2, 2> xxzz; \
    SimdSwizzle<float, 1, 0, 2, 2> yxzz; \
    SimdSwizzle<float, 2, 0, 2, 2> zxzz; \
    SimdSwizzle<float, 0, 1, 2, 2> xyzz; \
    SimdSwizzle<float, 1, 1, 2, 2> yyzz; \
    SimdSwizzle<float, 2, 1, 2, 2> zyzz; \
    SimdSwizzle<float, 0, 2, 2, 2> xzzz; \
    SimdSwizzle<float, 1, 2, 2, 2> yzzz; \
    SimdSwizzle<float, 2, 2, 2, 2> zzzz; \

    #define MATH_SIMD_SWIZZLE_VEC4 \
    SimdSwizzle<float, 0> x; \
    SimdSwizzle<float, 1> y; \
    SimdSwizzle<float, 2> z; \
    SimdSwizzle<float, 3> w; \
    SimdSwizzle<float, 0, 0> xx; \
    SimdSwizzle<float, 1, 0> yx; \
    SimdSwizzle<float, 2, 0> zx; \
    SimdSwizzle<float, 3, 0> wx; \
    SimdSwizzle<float, 0, 1> xy; \
    SimdSwizzle<float, 1, 1> yy; \
    SimdSwizzle<float, 2, 1> zy; \
    SimdSwizzle<float, 3, 1> wy; \
    SimdSwizzle<float, 0, 2> xz; \
    SimdSwizzle<float, 1, 2> yz; \
    SimdSwizzle<float, 2, 2> zz; \
    SimdSwizzle<float, 3, 2> wz; \
    SimdSwizzle<float, 0, 3> xw; \
    SimdSwizzle<float, 1, 3> yw; \
    SimdSwizzle<float, 2, 3> zw; \
    SimdSwizzle<float, 3, 3> ww; \
    SimdSwizzle<float, 0, 0, 0> xxx; \
    SimdSwizzle<float, 1, 0, 0> yxx; \
    SimdSwizzle<float, 2, 0, 0> zxx; \
    SimdSwizzle<float, 3, 0, 0> wxx; \
    SimdSwizzle<float, 0, 1, 0> xyx; \
    SimdSwizzle<float, 1, 1, 0> yyx; \
    SimdSwizzle<float, 2, 1, 0> zyx; \
    SimdSwizzle<float, 3, 1, 0> wyx; \
    SimdSwizzle<float, 0, 2, 0> xzx; \
    SimdSwizzle<float, 1, 2, 0> yzx; \
    SimdSwizzle<float, 2, 2, 0> zzx; \
    SimdSwizzle<float, 3, 2, 0> wzx; \
    SimdSwizzle<float, 0, 3, 0> xwx; \
    SimdSwizzle<float, 1, 3, 0> ywx; \
    SimdSwizzle<float, 2, 3, 0> zwx; \
    SimdSwizzle<float, 3, 3, 0> wwx; \
    SimdSwizzle<float, 0, 0, 1> xxy; \
    SimdSwizzle<float, 1, 0, 1> yxy; \
    SimdSwizzle<float, 2, 0, 1> zxy; \
    SimdSwizzle<float, 3, 0, 1> wxy; \
    SimdSwizzle<float, 0, 1, 1> xyy; \
    SimdSwizzle<float, 1, 1, 1> yyy; \
    SimdSwizzle<float, 2, 1, 1> zyy; \
    SimdSwizzle<float, 3, 1, 1> wyy; \
    SimdSwizzle<float, 0, 2, 1> xzy; \
    SimdSwizzle<float, 1, 2, 1> yzy; \
    SimdSwizzle<float, 2, 2, 1> zzy; \
    SimdSwizzle<float, 3, 2, 1> wzy; \
    SimdSwizzle<float, 0, 3, 1> xwy; \
    SimdSwizzle<float, 1, 3, 1> ywy; \
    SimdSwizzle<float, 2, 3, 1> zwy; \
    SimdSwizzle<float, 3, 3, 1> wwy; \
    SimdSwizzle<float, 0, 0, 2> xxz; \
    SimdSwizzle<float, 1, 0, 2> yxz; \
    SimdSwizzle<float, 2, 0, 2> zxz; \
    SimdSwizzle<float, 3, 0, 2> wxz; \
    SimdSwizzle<float, 0, 1, 2> xyz; \
    SimdSwizzle<float, 1, 1, 2> yyz; \
    SimdSwizzle<float, 2, 1, 2> zyz; \
    SimdSwizzle<float, 3, 1, 2> wyz; \
    SimdSwizzle<float, 0, 2, 2> xzz; \
    SimdSwizzle<float, 1, 2, 2> yzz; \
    SimdSwizzle<float, 2, 2, 2> zzz; \
    SimdSwizzle<float, 3, 2, 2> wzz; \
    SimdSwizzle<float, 0, 3, 2> xwz; \
    SimdSwizzle<float, 1, 3, 2> ywz; \
    SimdSwizzle<float, 2, 3, 2> zwz; \
    SimdSwizzle<float, 3, 3, 2> wwz; \
    SimdSwizzle<float, 0, 0, 3> xxw; \
    SimdSwizzle<float, 1, 0, 3> yxw; \
    SimdSwizzle<float, 2, 0, 3> zxw; \
    SimdSwizzle<float, 3, 0, 3> wxw; \
    SimdSwizzle<float, 0, 1, 3> xyw; \
    SimdSwizzle<float, 1, 1, 3> yyw; \
    SimdSwizzle<float, 2, 1, 3> zyw; \
    SimdSwizzle<float, 3, 1, 3> wyw; \
    SimdSwizzle<float, 0, 2, 3> xzw; \
    SimdSwizzle<float, 1, 2, 3> yzw; \
    SimdSwizzle<float, 2, 2, 3> zzw; \
    SimdSwizzle<float, 3, 2, 3> wzw; \
    SimdSwizzle<float, 0, 3, 3> xww; \
    SimdSwizzle<float, 1, 3, 3> yww; \
    SimdSwizzle<float, 2, 3, 3> zww; \
    SimdSwizzle<float, 3, 3, 3> www; \
    SimdSwizzle<float, 0, 0, 0, 0> xxxx; \
    SimdSwizzle<float, 1, 0, 0, 0> yxxx; \
    SimdSwizzle<float, 2, 0, 0, 0> zxxx; \
    SimdSwizzle<float, 3, 0, 0, 0> wxxx; \
    SimdSwizzle<float, 0, 1, 0, 0> xyxx; \
    SimdSwizzle<float, 1, 1, 0, 0> yyxx; \
    SimdSwizzle<float, 2, 1, 0, 0> zyxx; \
    SimdSwizzle<float, 3, 1, 0, 0> wyxx; \
    SimdSwizzle<float, 0, 2, 0, 0> xzxx; \
    SimdSwizzle<float, 1, 2, 0, 0> yzxx; \
    SimdSwizzle<float, 2, 2, 0, 0> zzxx; \
    SimdSwizzle<float, 3, 2, 0, 0> wzxx; \
    SimdSwizzle<float, 0, 3, 0, 0> xwxx; \
    SimdSwizzle<float, 1, 3, 0, 0> ywxx; \
    SimdSwizzle<float, 2, 3, 0, 0> zwxx; \
    SimdSwizzle<float, 3, 3, 0, 0> wwxx; \
    SimdSwizzle<float, 0, 0, 1, 0> xxyx; \
    SimdSwizzle<float, 1, 0, 1, 0> yxyx; \
    SimdSwizzle<float, 2, 0, 1, 0> zxyx; \
    SimdSwizzle<float, 3, 0, 1, 0> wxyx; \
    SimdSwizzle<float, 0, 1, 1, 0> xyyx; \
    SimdSwizzle<float, 1, 1, 1, 0> yyyx; \
    SimdSwizzle<float, 2, 1, 1, 0> zyyx; \
    SimdSwizzle<float, 3, 1, 1, 0> wyyx; \
    SimdSwizzle<float, 0, 2, 1, 0> xzyx; \
    SimdSwizzle<float, 1, 2, 1, 0> yzyx; \
    SimdSwizzle<float, 2, 2, 1, 0> zzyx; \
    SimdSwizzle<float, 3, 2, 1, 0> wzyx; \
    SimdSwizzle<float, 0, 3, 1, 0> xwyx; \
    SimdSwizzle<float, 1, 3, 1, 0> ywyx; \
    SimdSwizzle<float, 2, 3, 1, 0> zwyx; \
    SimdSwizzle<float, 3, 3, 1, 0> wwyx; \
    SimdSwizzle<float, 0, 0, 2, 0> xxzx; \
    SimdSwizzle<float, 1, 0, 2, 0> yxzx; \
    SimdSwizzle<float, 2, 0, 2, 0> zxzx; \
    SimdSwizzle<float, 3, 0, 2, 0> wxzx; \
    SimdSwizzle<float, 0, 1, 2, 0> xyzx; \
    SimdSwizzle<float, 1, 1, 2, 0> yyzx; \
    SimdSwizzle<float, 2, 1, 2, 0> zyzx; \
    SimdSwizzle<float, 3, 1, 2, 0> wyzx; \
    SimdSwizzle<float, 0, 2, 2, 0> xzzx; \
    SimdSwizzle<float, 1, 2, 2, 0> yzzx; \
    SimdSwizzle<float, 2, 2, 2, 0> zzzx; \
    SimdSwizzle<float, 3, 2, 2, 0> wzzx; \
    SimdSwizzle<float, 0, 3, 2, 0> xwzx; \
    SimdSwizzle<float, 1, 3, 2, 0> ywzx; \
    SimdSwizzle<float, 2, 3, 2, 0> zwzx; \
    SimdSwizzle<float, 3, 3, 2, 0> wwzx; \
    SimdSwizzle<float, 0, 0, 3, 0> xxwx; \
    SimdSwizzle<float, 1, 0, 3, 0> yxwx; \
    SimdSwizzle<float, 2, 0, 3, 0> zxwx; \
    SimdSwizzle<float, 3, 0, 3, 0> wxwx; \
    SimdSwizzle<float, 0, 1, 3, 0> xywx; \
    SimdSwizzle<float, 1, 1, 3, 0> yywx; \
    SimdSwizzle<float, 2, 1, 3, 0> zywx; \
    SimdSwizzle<float, 3, 1, 3, 0> wywx; \
    SimdSwizzle<float, 0, 2, 3, 0> xzwx; \
    SimdSwizzle<float, 1, 2, 3, 0> yzwx; \
    SimdSwizzle<float, 2, 2, 3, 0> zzwx; \
    SimdSwizzle<float, 3, 2, 3, 0> wzwx; \
    SimdSwizzle<float, 0, 3, 3, 0> xwwx; \
    SimdSwizzle<float, 1, 3, 3, 0> ywwx; \
    SimdSwizzle<float, 2, 3, 3, 0> zwwx; \
    SimdSwizzle<float, 3, 3, 3, 0> wwwx; \
    SimdSwizzle<float, 0, 0, 0, 1> xxxy; \
    SimdSwizzle<float, 1, 0, 0, 1> yxxy; \
    SimdSwizzle<float, 2, 0, 0, 1> zxxy; \
    SimdSwizzle<float, 3, 0, 0, 1> wxxy; \
    SimdSwizzle<float, 0, 1, 0, 1> xyxy; \
    SimdSwizzle<float, 1, 1, 0, 1> yyxy; \
    SimdSwizzle<float, 2, 1, 0, 1> zyxy; \
    SimdSwizzle<float, 3, 1, 0, 1> wyxy; \
    SimdSwizzle<float, 0, 2, 0, 1> xzxy; \
    SimdSwizzle<float, 1, 2, 0, 1> yzxy; \
    SimdSwizzle<float, 2, 2, 0, 1> zzxy; \
    SimdSwizzle<float, 3, 2, 0, 1> wzxy; \
    SimdSwizzle<float, 0, 3, 0, 1> xwxy; \
    SimdSwizzle<float, 1, 3, 0, 1> ywxy; \
    SimdSwizzle<float, 2, 3, 0, 1> zwxy; \
    SimdSwizzle<float, 3, 3, 0, 1> wwxy; \
    SimdSwizzle<float, 0, 0, 1, 1> xxyy; \
    SimdSwizzle<float, 1, 0, 1, 1> yxyy; \
    SimdSwizzle<float, 2, 0, 1, 1> zxyy; \
    SimdSwizzle<float, 3, 0, 1, 1> wxyy; \
    SimdSwizzle<float, 0, 1, 1, 1> xyyy; \
    SimdSwizzle<float, 1, 1, 1, 1> yyyy; \
    SimdSwizzle<float, 2, 1, 1, 1> zyyy; \
    SimdSwizzle<float, 3, 1, 1, 1> wyyy; \
    SimdSwizzle<float, 0, 2, 1, 1> xzyy; \
    SimdSwizzle<float, 1, 2, 1, 1> yzyy; \
    SimdSwizzle<float, 2, 2, 1, 1> zzyy; \
    SimdSwizzle<float, 3, 2, 1, 1> wzyy; \
    SimdSwizzle<float, 0, 3, 1, 1> xwyy; \
    SimdSwizzle<float, 1, 3, 1, 1> ywyy; \
    SimdSwizzle<float, 2, 3, 1, 1> zwyy; \
    SimdSwizzle<float, 3, 3, 1, 1> wwyy; \
    SimdSwizzle<float, 0, 0, 2, 1> xxzy; \
    SimdSwizzle<float, 1, 0, 2, 1> yxzy; \
    SimdSwizzle<float, 2, 0, 2, 1> zxzy; \
    SimdSwizzle<float, 3, 0, 2, 1> wxzy; \
    SimdSwizzle<float, 0, 1, 2, 1> xyzy; \
    SimdSwizzle<float, 1, 1, 2, 1> yyzy; \
    SimdSwizzle<float, 2, 1, 2, 1> zyzy; \
    SimdSwizzle<float, 3, 1, 2, 1> wyzy; \
    SimdSwizzle<float, 0, 2, 2, 1> xzzy; \
    SimdSwizzle<float, 1, 2, 2, 1> yzzy; \
    SimdSwizzle<float, 2, 2, 2, 1> zzzy; \
    SimdSwizzle<float, 3, 2, 2, 1> wzzy; \
    SimdSwizzle<float, 0, 3, 2, 1> xwzy; \
    SimdSwizzle<float, 1, 3, 2, 1> ywzy; \
    SimdSwizzle<float, 2, 3, 2, 1> zwzy; \
    SimdSwizzle<float, 3, 3, 2, 1> wwzy; \
    SimdSwizzle<float, 0, 0, 3, 1> xxwy; \
    SimdSwizzle<float, 1, 0, 3, 1> yxwy; \
    SimdSwizzle<float, 2, 0, 3, 1> zxwy; \
    SimdSwizzle<float, 3, 0, 3, 1> wxwy; \
    SimdSwizzle<float, 0, 1, 3, 1> xywy; \
    SimdSwizzle<float, 1, 1, 3, 1> yywy; \
    SimdSwizzle<float, 2, 1, 3, 1> zywy; \
    SimdSwizzle<float, 3, 1, 3, 1> wywy; \
    SimdSwizzle<float, 0, 2, 3, 1> xzwy; \
    SimdSwizzle<float, 1, 2, 3, 1> yzwy; \
    SimdSwizzle<float, 2, 2, 3, 1> zzwy; \
    SimdSwizzle<float, 3, 2, 3, 1> wzwy; \
    SimdSwizzle<float, 0, 3, 3, 1> xwwy; \
    SimdSwizzle<float, 1, 3, 3, 1> ywwy; \
    SimdSwizzle<float, 2, 3, 3, 1> zwwy; \
    SimdSwizzle<float, 3, 3, 3, 1> wwwy; \
    SimdSwizzle<float, 0, 0, 0, 2> xxxz; \
    SimdSwizzle<float, 1, 0, 0, 2> yxxz; \
    SimdSwizzle<float, 2, 0, 0, 2> zxxz; \
    SimdSwizzle<float, 3, 0, 0, 2> wxxz; \
    SimdSwizzle<float, 0, 1, 0, 2> xyxz; \
    SimdSwizzle<float, 1, 1, 0, 2> yyxz; \
    SimdSwizzle<float, 2, 1, 0, 2> zyxz; \
    SimdSwizzle<float, 3, 1, 0, 2> wyxz; \
    SimdSwizzle<float, 0, 2, 0, 2> xzxz; \
    SimdSwizzle<float, 1, 2, 0, 2> yzxz; \
    SimdSwizzle<float, 2, 2, 0, 2> zzxz; \
    SimdSwizzle<float, 3, 2, 0, 2> wzxz; \
    SimdSwizzle<float, 0, 3, 0, 2> xwxz; \
    SimdSwizzle<float, 1, 3, 0, 2> ywxz; \
    SimdSwizzle<float, 2, 3, 0, 2> zwxz; \
    SimdSwizzle<float, 3, 3, 0, 2> wwxz; \
    SimdSwizzle<float, 0, 0, 1, 2> xxyz; \
    SimdSwizzle<float, 1, 0, 1, 2> yxyz; \
    SimdSwizzle<float, 2, 0, 1, 2> zxyz; \
    SimdSwizzle<float, 3, 0, 1, 2> wxyz; \
    SimdSwizzle<float, 0, 1, 1, 2> xyyz; \
    SimdSwizzle<float, 1, 1, 1, 2> yyyz; \
    SimdSwizzle<float, 2, 1, 1, 2> zyyz; \
    SimdSwizzle<float, 3, 1, 1, 2> wyyz; \
    SimdSwizzle<float, 0, 2, 1, 2> xzyz; \
    SimdSwizzle<float, 1, 2, 1, 2> yzyz; \
    SimdSwizzle<float, 2, 2, 1, 2> zzyz; \
    SimdSwizzle<float, 3, 2, 1, 2> wzyz; \
    SimdSwizzle<float, 0, 3, 1, 2> xwyz; \
    SimdSwizzle<float, 1, 3, 1, 2> ywyz; \
    SimdSwizzle<float, 2, 3, 1, 2> zwyz; \
    SimdSwizzle<float, 3, 3, 1, 2> wwyz; \
    SimdSwizzle<float, 0, 0, 2, 2> xxzz; \
    SimdSwizzle<float, 1, 0, 2, 2> yxzz; \
    SimdSwizzle<float, 2, 0, 2, 2> zxzz; \
    SimdSwizzle<float, 3, 0, 2, 2> wxzz; \
    SimdSwizzle<float, 0, 1, 2, 2> xyzz; \
    SimdSwizzle<float, 1, 1, 2, 2> yyzz; \
    SimdSwizzle<float, 2, 1, 2, 2> zyzz; \
    SimdSwizzle<float, 3, 1, 2, 2> wyzz; \
    SimdSwizzle<float, 0, 2, 2, 2> xzzz; \
    SimdSwizzle<float, 1, 2, 2, 2> yzzz; \
    SimdSwizzle<float, 2, 2, 2, 2> zzzz; \
    SimdSwizzle<float, 3, 2, 2, 2> wzzz; \
    SimdSwizzle<float, 0, 3, 2, 2> xwzz; \
    SimdSwizzle<float, 1, 3, 2, 2> ywzz; \
    SimdSwizzle<float, 2, 3, 2, 2> zwzz; \
    SimdSwizzle<float, 3, 3, 2, 2> wwzz; \
    SimdSwizzle<float, 0, 0, 3, 2> xxwz; \
    SimdSwizzle<float, 1, 0, 3, 2> yxwz; \
    SimdSwizzle<float, 2, 0, 3, 2> zxwz; \
    SimdSwizzle<float, 3, 0, 3, 2> wxwz; \
    SimdSwizzle<float, 0, 1, 3, 2> xywz; \
    SimdSwizzle<float, 1, 1, 3, 2> yywz; \
    SimdSwizzle<float, 2, 1, 3, 2> zywz; \
    SimdSwizzle<float, 3, 1, 3, 2> wywz; \
    SimdSwizzle<float, 0, 2, 3, 2> xzwz; \
    SimdSwizzle<float, 1, 2, 3, 2> yzwz; \
    SimdSwizzle<float, 2, 2, 3, 2> zzwz; \
    SimdSwizzle<float, 3, 2, 3, 2> wzwz; \
    SimdSwizzle<float, 0, 3, 3, 2> xwwz; \
    SimdSwizzle<float, 1, 3, 3, 2> ywwz; \
    SimdSwizzle<float, 2, 3, 3, 2> zwwz; \
    SimdSwizzle<float, 3, 3, 3, 2> wwwz; \
    SimdSwizzle<float, 0, 0, 0, 3> xxxw; \
    SimdSwizzle<float, 1, 0, 0, 3> yxxw; \
    SimdSwizzle<float, 2, 0, 0, 3> zxxw; \
    SimdSwizzle<float, 3, 0, 0, 3> wxxw; \
    SimdSwizzle<float, 0, 1, 0, 3> xyxw; \
    SimdSwizzle<float, 1, 1, 0, 3> yyxw; \
    SimdSwizzle<float, 2, 1, 0, 3> zyxw; \
    SimdSwizzle<float, 3, 1, 0, 3> wyxw; \
    SimdSwizzle<float, 0, 2, 0, 3> xzxw; \
    SimdSwizzle<float, 1, 2, 0, 3> yzxw; \
    SimdSwizzle<float, 2, 2, 0, 3> zzxw; \
    SimdSwizzle<float, 3, 2, 0, 3> wzxw; \
    SimdSwizzle<float, 0, 3, 0, 3> xwxw; \
    SimdSwizzle<float, 1, 3, 0, 3> ywxw; \
    SimdSwizzle<float, 2, 3, 0, 3> zwxw; \
    SimdSwizzle<float, 3, 3, 0, 3> wwxw; \
    SimdSwizzle<float, 0, 0, 1, 3> xxyw; \
    SimdSwizzle<float, 1, 0, 1, 3> yxyw; \
    SimdSwizzle<float, 2, 0, 1, 3> zxyw; \
    SimdSwizzle<float, 3, 0, 1, 3> wxyw; \
    SimdSwizzle<float, 0, 1, 1, 3> xyyw; \
    SimdSwizzle<float, 1, 1, 1, 3> yyyw; \
    SimdSwizzle<float, 2, 1, 1, 3> zyyw; \
    SimdSwizzle<float, 3, 1, 1, 3> wyyw; \
    SimdSwizzle<float, 0, 2, 1, 3> xzyw; \
    SimdSwizzle<float, 1, 2, 1, 3> yzyw; \
    SimdSwizzle<float, 2, 2, 1, 3> zzyw; \
    SimdSwizzle<float, 3, 2, 1, 3> wzyw; \
    SimdSwizzle<float, 0, 3, 1, 3> xwyw; \
    SimdSwizzle<float, 1, 3, 1, 3> ywyw; \
    SimdSwizzle<float, 2, 3, 1, 3> zwyw; \
    SimdSwizzle<float, 3, 3, 1, 3> wwyw; \
    SimdSwizzle<float, 0, 0, 2, 3> xxzw; \
    SimdSwizzle<float, 1, 0, 2, 3> yxzw; \
    SimdSwizzle<float, 2, 0, 2, 3> zxzw; \
    SimdSwizzle<float, 3, 0, 2, 3> wxzw; \
    SimdSwizzle<float, 0, 1, 2, 3> xyzw; \
    SimdSwizzle<float, 1, 1, 2, 3> yyzw; \
    SimdSwizzle<float, 2, 1, 2, 3> zyzw; \
    SimdSwizzle<float, 3, 1, 2, 3> wyzw; \
    SimdSwizzle<float, 0, 2, 2, 3> xzzw; \
    SimdSwizzle<float, 1, 2, 2, 3> yzzw; \
    SimdSwizzle<float, 2, 2, 2, 3> zzzw; \
    SimdSwizzle<float, 3, 2, 2, 3> wzzw; \
    SimdSwizzle<float, 0, 3, 2, 3> xwzw; \
    SimdSwizzle<float, 1, 3, 2, 3> ywzw; \
    SimdSwizzle<float, 2, 3, 2, 3> zwzw; \
    SimdSwizzle<float, 3, 3, 2, 3> wwzw; \
    SimdSwizzle<float, 0, 0, 3, 3> xxww; \
    SimdSwizzle<float, 1, 0, 3, 3> yxww; \
    SimdSwizzle<float, 2, 0, 3, 3> zxww; \
    SimdSwizzle<float, 3, 0, 3, 3> wxww; \
    SimdSwizzle<float, 0, 1, 3, 3> xyww; \
    SimdSwizzle<float, 1, 1, 3, 3> yyww; \
    SimdSwizzle<float, 2, 1, 3, 3> zyww; \
    SimdSwizzle<float, 3, 1, 3, 3> wyww; \
    SimdSwizzle<float, 0, 2, 3, 3> xzww; \
    SimdSwizzle<float, 1, 2, 3, 3> yzww; \
    SimdSwizzle<float, 2, 2, 3, 3> zzww; \
    SimdSwizzle<float, 3, 2, 3, 3> wzww; \
    SimdSwizzle<float, 0, 3, 3, 3> xwww; \
    SimdSwizzle<float, 1, 3, 3, 3> ywww; \
    SimdSwizzle<float, 2, 3, 3, 3> zwww; \
    SimdSwizzle<float, 3, 3, 3, 3> wwww; \


}