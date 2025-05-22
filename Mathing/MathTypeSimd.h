#pragma once

#include"./DirectXMath/Inc/DirectXMath.h"
#include"./DirectXMath/Inc/DirectXPackedVector.h"
#include"SimdIntger.h"
#include"SwizzleSimd.h"

namespace Math
{
	template<typename T, size_t Dim>
	struct SimdVector
	{
        
	};

    // float vectors
    template<>
    struct SimdVector<float, 1>
    {
        union {
            DirectX::XMVECTOR Packed;
            float v[1];
        };

        SimdVector() = default;
        explicit inline SimdVector(float val) noexcept { Packed = DirectX::XMVectorReplicate(val); }
        explicit inline SimdVector(int val) noexcept { Packed = DirectX::XMVectorReplicate((float)val); }
        inline SimdVector(const SimdVector& val) noexcept { Packed = val.Packed; }

        template<uint32_t X>
        inline SimdVector(const SimdSwizzle<float, X>& s) noexcept;

        template<uint32_t X>
        inline SimdVector& operator=(const SimdSwizzle<float, X>& s) noexcept;

        inline SimdVector& operator=(float val) noexcept { Packed = DirectX::XMVectorReplicate(val); return *this; };

        explicit inline operator float() noexcept { return v[0]; }
    };

    template<>
    struct SimdVector<float, 2>
    {
        union 
        {
            float v[2];
            DirectX::XMVECTOR Packed;            
            MATH_SIMD_SWIZZLE_VEC2
        };

        inline SimdVector() = default;
        explicit inline SimdVector(float val) noexcept { Packed = DirectX::XMVectorSet(val, val, 0, 0); }
        explicit inline SimdVector(int val) noexcept { Packed = DirectX::XMVectorSet((float)val, (float)val, 0, 0); }
        inline SimdVector(float vx, float vy) noexcept { Packed = DirectX::XMVectorSet(vx, vy, 0, 0); }
        inline SimdVector(const SimdVector<float, 1>& val) noexcept { Packed = val.Packed; }
        inline SimdVector(const SimdVector<float, 2>& val) noexcept { Packed = val.Packed; }
        inline SimdVector(const SimdVector<float, 1>& vx, const SimdVector<float, 1>& vy) noexcept { Packed = DirectX::XMVectorPermute<0, 4, 1, 5>(vx.Packed, vy.Packed); }
        inline SimdVector(const SimdVector<float, 1>& vx, float vy) noexcept { Packed = DirectX::XMVectorSet(vx.v[0], vy, 0, 0); }
        //inline SimdVector(float vx, const SimdVector<float, 1>& vy) noexcept { Packed = DirectX::XMVectorSet(vx, vy.v[0], 0, 0); }
        explicit inline SimdVector(const float* v) noexcept { Packed = DirectX::XMVectorSet((float)v[0], (float)v[1], 0, 0); }

        template<typename T>
        inline SimdVector(const MathVector<T, 2>& v) noexcept { Packed = DirectX::XMVectorSet((float)v.x, (float)v.y, 0, 0); }

        template<typename T>
        inline SimdVector& operator=(const MathVector<T, 2>& v) noexcept { Packed = DirectX::XMVectorSet((float)v.x, (float)v.y, 0, 0); return *this; }
    
        template<uint32_t X>
        inline SimdVector(const SimdSwizzle<float, X>& s) noexcept;

        template<uint32_t X>
        inline SimdVector& operator=(const SimdSwizzle<float, X>& s) noexcept;

        template<uint32_t X, uint32_t Y>
        inline SimdVector(const SimdSwizzle<float, X, Y>& s) noexcept;

        template<uint32_t X, uint32_t Y>
        inline SimdVector& operator=(const SimdSwizzle<float, X, Y>& s) noexcept;

        inline SimdVector& operator=(float val) noexcept { Packed = DirectX::XMVectorSet(val, val, 0, 0); return *this; };

        template<typename T>
        explicit inline operator MathVector<T, 2>() noexcept {
            DirectX::XMFLOAT2 f2;
            DirectX::XMStoreFloat2(&f2, Packed);
            return MathVector<T, 2>((T)f2.x, (T)f2.y);
        }

        inline void CleanUnused(float f) noexcept { DirectX::XMVectorSetZ(Packed, f); DirectX::XMVectorSetW(Packed, f); }
    };
    

    template<>
    struct SimdVector<float, 3>
    {
        union 
        {
            float v[3];
            DirectX::XMVECTOR Packed;
            MATH_SIMD_SWIZZLE_VEC3
        };

        inline SimdVector() = default;
        explicit inline SimdVector(float val) noexcept { Packed = DirectX::XMVectorSet(val, val, val, 0); }
        explicit inline SimdVector(int val) noexcept { Packed = DirectX::XMVectorSet((float)val, (float)val, (float)val, 0); }
        inline SimdVector(float vx, float vy, float vz) noexcept { Packed = DirectX::XMVectorSet(vx, vy, vz, 0); }
        inline SimdVector(const SimdVector<float, 1>& val) noexcept { Packed = val.Packed; }
        inline SimdVector(const SimdVector<float, 3>& val) noexcept { Packed = val.Packed; }
        inline SimdVector(const SimdVector<float, 1>& vx, const SimdVector<float, 2>& vyz) noexcept { Packed = DirectX::XMVectorPermute<0, 4, 5, 6>(vx.Packed, vyz.Packed); }
        inline SimdVector(const SimdVector<float, 2>& vxy, const SimdVector<float, 1>& vz) noexcept { Packed = DirectX::XMVectorPermute<0, 1, 4, 5>(vxy.Packed, vz.Packed); }
        //inline SimdVector(const SimdVector<float, 1>& vx, const SimdVector<float, 1>& vy, const SimdVector<float, 1>& vz) noexcept { Packed = DirectX::XMVectorSet(vx.v[0], vy.v[0], vz.v[0], 0); }
        inline SimdVector(float vx, const SimdVector<float, 2>& vyz) noexcept { Packed = DirectX::XMVectorSet(vx, vyz.v[0], vyz.v[1], 0); }
        inline SimdVector(const SimdVector<float, 2>& vxy, float vz) noexcept { Packed = DirectX::XMVectorSet(vxy.v[0], vxy.v[1], vz, 0); }
        explicit inline SimdVector(const float* v) noexcept { Packed = DirectX::XMVectorSet((float)v[0], (float)v[1], (float)v[2], 0); }

        template<typename T>
        inline SimdVector(const MathVector<T, 3>& v) noexcept { Packed = DirectX::XMVectorSet((float)v.x, (float)v.y, (float)v.z, 0); }

        template<typename T0, typename T1>
        inline SimdVector(const MathVector<T0, 2>& vxy, T1 vz) noexcept { Packed = DirectX::XMVectorSet((float)vxy.x, (float)vxy.y, (float)vz, 0); }

        template<typename T0, typename T1>
        inline SimdVector(T1 vx, const MathVector<T1, 2>& vyz) noexcept { Packed = DirectX::XMVectorSet((float)vx, (float)vyz.x, (float)vyz.y, 0); }

        template<typename T>
        inline SimdVector& operator=(const MathVector<T, 3>& v) noexcept { Packed = DirectX::XMVectorSet((float)v.x, (float)v.y, (float)v.z, 0); return *this; }

        template<uint32_t X>
        inline SimdVector(const SimdSwizzle<float, X>& s) noexcept;

        template<uint32_t X>
        inline SimdVector& operator=(const SimdSwizzle<float, X>& s) noexcept;

        template<uint32_t X, uint32_t Y, uint32_t Z>
        inline SimdVector(const SimdSwizzle<float, X, Y, Z>& s) noexcept;

        template<uint32_t X, uint32_t Y, uint32_t Z>
        inline SimdVector& operator=(const SimdSwizzle<float, X, Y, Z>& s) noexcept;

        inline SimdVector& operator=(float val) noexcept { Packed = DirectX::XMVectorSet(val, val, val, 0); return *this; };

        template<typename T>
        explicit inline operator MathVector<T, 3>() noexcept {
            DirectX::XMFLOAT3 f3;
            DirectX::XMStoreFloat3(&f3, Packed);
            return MathVector<T, 3>((T)f3.x, (T)f3.y, (T)f3.z);
        }

        inline void CleanUnused(float f) noexcept { DirectX::XMVectorSetW(Packed, f); }
    };

    template<>
    struct SimdVector<float, 4>
    {
        union
        {
            float v[4];
            DirectX::XMVECTOR Packed;
            MATH_SIMD_SWIZZLE_VEC4
        };

        inline SimdVector() = default;
        explicit inline SimdVector(float val) noexcept { Packed = DirectX::XMVectorReplicate(val); }
        explicit inline SimdVector(int val) noexcept { Packed = DirectX::XMVectorReplicate((float)val); }
        inline SimdVector(float vx, float vy, float vz, float vw) noexcept { Packed = DirectX::XMVectorSet(vx, vy, vz, vw); }
        inline SimdVector(const SimdVector<float, 1>& val) noexcept { Packed = val.Packed; }
        inline SimdVector(const SimdVector<float, 4>& val) noexcept { Packed = val.Packed; }
        inline SimdVector(const SimdVector<float, 2>& vxy, const SimdVector<float, 2>& vzw) noexcept { Packed = DirectX::XMVectorPermute<0, 1, 4, 5>(vxy.Packed, vzw.Packed); }
        inline SimdVector(const SimdVector<float, 1>& vx, const SimdVector<float, 3>& vyzw) noexcept { Packed = DirectX::XMVectorPermute<0, 4, 5, 6>(vx.Packed, vyzw.Packed); }
        inline SimdVector(const SimdVector<float, 3>& vxyz, const SimdVector<float, 1>& vw) noexcept { Packed = DirectX::XMVectorPermute<0, 1, 2, 4>(vxyz.Packed, vw.Packed); }
        inline SimdVector(float vx, const SimdVector<float, 3>& vyzw) noexcept { Packed = DirectX::XMVectorSet(vx, vyzw.v[0], vyzw.v[1], vyzw.v[2]); }
        inline SimdVector(const SimdVector<float, 3>& vxyz, float vw) noexcept { Packed = DirectX::XMVectorSet(vxyz.v[0], vxyz.v[1], vxyz.v[2], vw); }
        inline SimdVector(float vx, const SimdVector<float, 2>& vyz, float vw) noexcept { Packed = DirectX::XMVectorSet(vx, vyz.v[0], vyz.v[1], vw); }
        inline SimdVector(const SimdVector<float, 2>& vxy, float vz, float vw) noexcept { Packed = DirectX::XMVectorSet(vxy.v[0], vxy.v[1], vz, vw); }
        inline SimdVector(float vx, float vy, const SimdVector<float, 2>& vzw) noexcept { Packed = DirectX::XMVectorSet(vx, vy, vzw.v[0], vzw.v[1]); }
        explicit inline SimdVector(const float* v) noexcept { Packed = DirectX::XMLoadFloat4((DirectX::XMFLOAT4*)(v)); }
        
        template<typename T>
        inline SimdVector(const MathVector<T, 4>& v) noexcept { Packed = DirectX::XMVectorSet((float)v.x, (float)v.y, (float)v.z, (float)v.w); }

        template<>
        inline SimdVector(const MathVector<float, 4>& v) noexcept { Packed = DirectX::XMLoadFloat4((const DirectX::XMFLOAT4*)(&v)); }

        template<typename T0, typename T1>
        inline SimdVector(const MathVector<T0, 3>& vxyz, T1 vw) noexcept { Packed = DirectX::XMVectorSet((float)vxyz.x, (float)vxyz.y, (float)vxyz.z, (float)vw); }

        template<typename T0, typename T1>
        inline SimdVector(T1 vx, const MathVector<T1, 3>& vyzw) noexcept { Packed = DirectX::XMVectorSet((float)vx, (float)vyzw.x, (float)vyzw.y, (float)vyzw.z); }

        template<typename T>
        inline SimdVector& operator=(const MathVector<T, 4>& v) noexcept { Packed = DirectX::XMVectorSet((float)v.x, (float)v.y, (float)v.z, (float)v.w); return *this; }

        template<>
        inline SimdVector& operator=(const MathVector<float, 4>& v) noexcept { Packed = DirectX::XMLoadFloat4((const DirectX::XMFLOAT4*)(&v)); return *this; }

        template<uint32_t X>
        inline SimdVector(const SimdSwizzle<float, X>& s) noexcept;

        template<uint32_t X>
        inline SimdVector& operator=(const SimdSwizzle<float, X>& s) noexcept;

        template<uint32_t X, uint32_t Y, uint32_t Z, uint32_t W>
        inline SimdVector(const SimdSwizzle<float, X, Y, Z, W>& s) noexcept;

        template<uint32_t X, uint32_t Y, uint32_t Z, uint32_t W>
        inline SimdVector& operator=(const SimdSwizzle<float, X, Y, Z, W>& s) noexcept;

        inline SimdVector& operator=(float val) noexcept { Packed = DirectX::XMVectorSet(val, val, val, val); return *this; };

        template<typename T>
        explicit inline operator MathVector<T, 4>() noexcept {
            DirectX::XMFLOAT4 f4;
            DirectX::XMStoreFloat4(&f4, Packed);
            return MathVector<T, 4>((T)f4.x, (T)f4.y, (T)f4.z, (T)f4.w);
        }
    };

    // int vectors
    template<>
    struct SimdVector<int32_t, 1>
    {
        union {
            SIMDVECTORI Packed;
            int32_t v[1];
        };

        SimdVector() = default;
        inline SimdVector(int32_t val) noexcept { Packed = SMVectorIntReplicate(val); }
        //inline SimdVector(int32_t* p) noexcept { Packed = DirectX::XMVectorReplicate(val); }
        inline SimdVector(const SimdVector& val) noexcept { Packed = val.Packed; }

        template<uint32_t X>
        inline SimdVector(const SimdSwizzle<uint32_t, X>& s) noexcept;

        template<uint32_t X>
        inline SimdVector& operator=(const SimdSwizzle<float, X>& s) noexcept;

        inline SimdVector& operator=(int32_t val) noexcept { Packed = SMVectorIntReplicate(val); return *this; };

        inline operator int32_t() noexcept { return v[0]; }
    };

    template<>
    struct SimdVector<int32_t, 2>
    {
        union {
            SIMDVECTORI Packed;
            int32_t v[2];
        };
    };

    template<>
    struct SimdVector<int32_t, 3>
    {
        union {
            SIMDVECTORI Packed;
            int32_t v[3];
        };
    };

    template<>
    struct SimdVector<int32_t, 4>
    {
        union {
            SIMDVECTORI Packed;
            int32_t v[4];
        };
    };

    // uint vectors
    template<>
    struct SimdVector<uint32_t, 1>
    {
        union {
            SIMDVECTORU Packed;
            uint32_t v[1];
        };
    };

    template<>
    struct SimdVector<uint32_t, 2>
    {
        union {
            SIMDVECTORU Packed;
            uint32_t v[2];
        };
    };

    template<>
    struct SimdVector<uint32_t, 3>
    {
        union {
            SIMDVECTORU Packed;
            uint32_t v[3];
        };
    };

    template<>
    struct SimdVector<uint32_t, 4>
    {
        union {
            SIMDVECTORU Packed;
            int32_t v[4];
        };
    };

    // bool vectors
    template<>
    struct SimdVector<bool, 1>
    {
        union {
            SIMDVECTORU Packed;
            BOOL v[1];
        };
    };

    template<>
    struct SimdVector<bool, 2>
    {
        union {
            SIMDVECTORU Packed;
            BOOL v[2];
        };
    };

    template<>
    struct SimdVector<bool, 3>
    {
        union {
            SIMDVECTORU Packed;
            BOOL v[3];
        };
    };

    template<>
    struct SimdVector<bool, 4>
    {
        union {
            SIMDVECTORU Packed;
            BOOL v[4];
        };
    };


    using float1 = SimdVector<float, 1>;
    using float2 = SimdVector<float, 2>;
    using float3 = SimdVector<float, 3>;
    using float4 = SimdVector<float, 4>;

    using bool1 = SimdVector<bool, 1>;
    using bool2 = SimdVector<bool, 2>;
    using bool3 = SimdVector<bool, 3>;
    using bool4 = SimdVector<bool, 4>;

    using int1 = SimdVector<int32_t, 1>;
    using int2 = SimdVector<int32_t, 2>;
    using int3 = SimdVector<int32_t, 3>;
    using int4 = SimdVector<int32_t, 4>;

    using uint1 = SimdVector<uint32_t, 1>;
    using uint2 = SimdVector<uint32_t, 2>;
    using uint3 = SimdVector<uint32_t, 3>;
    using uint4 = SimdVector<uint32_t, 4>;
}

#include"SwizzleSimdImpl.h"