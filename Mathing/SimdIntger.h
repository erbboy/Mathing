#pragma once

#if defined(_XM_ARM_NEON_INTRINSICS_)
    #define cv4f(x, y, z, w)     ((const float32x4_t) { (x), (y), (z), (w) })
    #define cv4i(x, y, z, w)     ((const int32x4_t) { (int) (x), (int) (y), (int) (z), (int) (w) })
#endif

namespace Math
{
    //------------------------------------------------------------------------------
    // Vector intrinsic: Four 32 bit floating point components aligned on a 16 byte
    // boundary and mapped to hardware vector registers
#if defined(_XM_SSE_INTRINSICS_) && !defined(_XM_NO_INTRINSICS_)
    using SIMDVECTORI = __m128i;
    using SIMDVECTORU = __m128i;
#elif defined(_XM_ARM_NEON_INTRINSICS_) && !defined(_XM_NO_INTRINSICS_)
    using SIMDVECTORI = int32x4_t;
    using SIMDVECTORU = uint32x4_t;
#else
    struct __vector4
    {
        union
        {
            float       vector4_f32[4];
            int32_t     vector4_i32[4];
            uint32_t    vector4_u32[4];
        };
    };
    using SIMDVECTORI = Math::__vector4;
    using SIMDVECTORU = Math::__vector4;
#endif

    struct __SIMDVECTORI
    {
        union
        {
            int32_t i[4];
            SIMDVECTORI v;
        };
    };

    struct __SIMDVECTORU
    {
        union
        {
            uint32_t u[4];
            SIMDVECTORU vu;
        };
    };

    inline SIMDVECTORI SMVectorIntAdd(const SIMDVECTORI V1, const SIMDVECTORI V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI Result = { { {
                V1.vector4_i32[0] + V2.vector4_i32[0],
                V1.vector4_i32[1] + V2.vector4_i32[1],
                V1.vector4_i32[2] + V2.vector4_i32[2],
                V1.vector4_i32[3] + V2.vector4_i32[3]
            } } };
        return Result.v;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vaddq_s32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_add_epi32(V1, V2);
#endif
    }

    inline SIMDVECTORU SMVectorUIntAdd(const SIMDVECTORU V1, const SIMDVECTORU V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORU Result = { { {
                V1.vector4_u32[0] + V2.vector4_u32[0],
                V1.vector4_u32[1] + V2.vector4_u32[1],
                V1.vector4_u32[2] + V2.vector4_u32[2],
                V1.vector4_u32[3] + V2.vector4_u32[3]
            } } };
        return Result.vu;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vaddq_u32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_add_epi32(V1, V2);
#endif
    }

    inline SIMDVECTORI SMVectorIntSubtract(const SIMDVECTORI V1, const SIMDVECTORI V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI Result = { { {
                V1.vector4_i32[0] - V2.vector4_i32[0],
                V1.vector4_i32[1] - V2.vector4_i32[1],
                V1.vector4_i32[2] - V2.vector4_i32[2],
                V1.vector4_i32[3] - V2.vector4_i32[3]
            } } };
        return Result.v;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vsubq_s32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_sub_epi32(V1, V2);
#endif
    }

    inline SIMDVECTORU SMVectorUIntSubtract(const SIMDVECTORU V1, const SIMDVECTORU V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORU Result = { { {
                V1.vector4_u32[0] - V2.vector4_u32[0],
                V1.vector4_u32[1] - V2.vector4_u32[1],
                V1.vector4_u32[2] - V2.vector4_u32[2],
                V1.vector4_u32[3] - V2.vector4_u32[3]
            } } };
        return Result.vu;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vsubq_u32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_sub_epi32(V1, V2);
#endif
    }

    inline SIMDVECTORI SMVectorIntMultiply(const SIMDVECTORI V1, const SIMDVECTORI V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI Result = { { {
                V1.vector4_i32[0] * V2.vector4_i32[0],
                V1.vector4_i32[1] * V2.vector4_i32[1],
                V1.vector4_i32[2] * V2.vector4_i32[2],
                V1.vector4_i32[3] * V2.vector4_i32[3]
            } } };
        return Result.v;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vmulq_s32(V1, V2);
#elif defined(_XM_SSE4_INTRINSICS_)
        return _mm_mullo_epi32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        /*__SIMDVECTORI v1, v2;
        v1.v = V1; v2.v = V2;
        __SIMDVECTORI Result = { { {
                v1.i[0] * v2.i[0],
                v1.i[1] * v2.i[1],
                v1.i[2] * v2.i[2],
                v1.i[3] * v2.i[3]
            } } };
        return Result.v;*/
        __m128i a_high = _mm_srli_epi64(V1, 32);
        __m128i low = _mm_mul_epu32(V1, V2);
        __m128i b_high = _mm_srli_epi64(V2, 32);
        __m128i high = _mm_mul_epu32(a_high, b_high);
        low = _mm_shuffle_epi32(low, _MM_SHUFFLE(0, 0, 2, 0));
        high = _mm_shuffle_epi32(high, _MM_SHUFFLE(0, 0, 2, 0));
        return _mm_unpacklo_epi32(low, high);
#endif
    }

    inline SIMDVECTORU SMVectorUIntMultiply(const SIMDVECTORU V1, const SIMDVECTORU V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORU Result = { { {
                V1.vector4_u32[0] * V2.vector4_u32[0],
                V1.vector4_u32[1] * V2.vector4_u32[1],
                V1.vector4_u32[2] * V2.vector4_u32[2],
                V1.vector4_u32[3] * V2.vector4_u32[3]
            } } };
        return Result.vu;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vmulq_u32(V1, V2);
#elif defined(_XM_SSE4_INTRINSICS_)
        return _mm_mullo_epi32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        __m128i a_high = _mm_srli_epi64(V1, 32);
        __m128i low = _mm_mul_epu32(V1, V2);
        __m128i b_high = _mm_srli_epi64(V2, 32);
        __m128i high = _mm_mul_epu32(a_high, b_high);
        low = _mm_shuffle_epi32(low, _MM_SHUFFLE(0, 0, 2, 0));
        high = _mm_shuffle_epi32(high, _MM_SHUFFLE(0, 0, 2, 0));
        return _mm_unpacklo_epi32(low, high);
#endif
    }

    inline SIMDVECTORI SMVectorIntDivide(const SIMDVECTORI V1, const SIMDVECTORI V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI Result = { { {
                V1.vector4_i32[0] / V2.vector4_i32[0],
                V1.vector4_i32[1] / V2.vector4_i32[1],
                V1.vector4_i32[2] / V2.vector4_i32[2],
                V1.vector4_i32[3] / V2.vector4_i32[3]
            } } };
        return Result.v;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
        __SIMDVECTORI v1, v2;
        v1.v = V1; v2.v = V2;
        __SIMDVECTORI Result = { { {
                v1.i[0] / v2.i[0],
                v1.i[1] / v2.i[1],
                v1.i[2] / v2.i[2],
                v1.i[3] / v2.i[3]
            } } };
        return Result.v;
#elif defined(_XM_SSE_INTRINSICS_)
        __SIMDVECTORI v1, v2;
        v1.v = V1; v2.v = V2;
        __SIMDVECTORI Result = { { {
                v1.i[0] / v2.i[0],
                v1.i[1] / v2.i[1],
                v1.i[2] / v2.i[2],
                v1.i[3] / v2.i[3]
            } } };
        return Result.v;
#endif
    }

    inline SIMDVECTORU SMVectorUIntDivide(const SIMDVECTORU V1, const SIMDVECTORU V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORU Result = { { {
                V1.vector4_u32[0] / V2.vector4_u32[0],
                V1.vector4_u32[1] / V2.vector4_u32[1],
                V1.vector4_u32[2] / V2.vector4_u32[2],
                V1.vector4_u32[3] / V2.vector4_u32[3]
            } } };
        return Result.vu;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
        __SIMDVECTORU v1, v2;
        v1.vu = V1; v2.vu = V2;
        __SIMDVECTORU Result = { { {
                v1.u[0] / v2.u[0],
                v1.u[1] / v2.u[1],
                v1.u[2] / v2.u[2],
                v1.u[3] / v2.u[3]
            } } };
        return Result.vu;
#elif defined(_XM_SSE_INTRINSICS_)
        __SIMDVECTORU v1, v2;
        v1.vu = V1; v2.vu = V2;
        __SIMDVECTORU Result = { { {
                v1.u[0] / v2.u[0],
                v1.u[1] / v2.u[1],
                v1.u[2] / v2.u[2],
                v1.u[3] / v2.u[3]
             } } };
        return Result.vu;
#endif
    }

    SIMDVECTORI SMVectorIntMod(const SIMDVECTORI V1, const SIMDVECTORI V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI Result = { { {
                V1.vector4_i32[0] % V2.vector4_i32[0],
                V1.vector4_i32[1] % V2.vector4_i32[1],
                V1.vector4_i32[2] % V2.vector4_i32[2],
                V1.vector4_i32[3] % V2.vector4_i32[3]
            } } };
        return Result.v;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        __SIMDVECTORI v1, v2;
        v1.v = V1; v2.v = V2;
        __SIMDVECTORI Result = { { {
                v1.i[0] % v2.i[0],
                v1.i[1] % v2.i[1],
                v1.i[2] % v2.i[2],
                v1.i[3] % v2.i[3]
            } } };
        return Result.v;
#elif defined(_XM_SSE_INTRINSICS_)
        __SIMDVECTORI v1, v2;
        v1.v = V1; v2.v = V2;
        __SIMDVECTORI Result = { { {
                v1.i[0] % v2.i[0],
                v1.i[1] % v2.i[1],
                v1.i[2] % v2.i[2],
                v1.i[3] % v2.i[3]
            } } };
        return Result.v;
#endif
    }

    SIMDVECTORU SMVectorUIntMod(const SIMDVECTORU V1, const SIMDVECTORU V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORU Result = { { {
                V1.vector4_u32[0] % V2.vector4_u32[0],
                V1.vector4_u32[1] % V2.vector4_u32[1],
                V1.vector4_u32[2] % V2.vector4_u32[2],
                V1.vector4_u32[3] % V2.vector4_u32[3]
            } } };
        return Result.vu;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        __SIMDVECTORU v1, v2;
        v1.vu = V1; v2.vu = V2;
        __SIMDVECTORU Result = { { {
                v1.u[0] % v2.u[0],
                v1.u[1] % v2.u[1],
                v1.u[2] % v2.u[2],
                v1.u[3] % v2.u[3]
             } } };
        return Result.vu;
#elif defined(_XM_SSE_INTRINSICS_)
        __SIMDVECTORU v1, v2;
        v1.vu = V1; v2.vu = V2;
        __SIMDVECTORU Result = { { {
                v1.u[0] % v2.u[0],
                v1.u[1] % v2.u[1],
                v1.u[2] % v2.u[2],
                v1.u[3] % v2.u[3]
             } } };
        return Result.vu;
#endif
    }

    inline SIMDVECTORI SMVectorIntNegate(const SIMDVECTORI V) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI Result = { { {
                -V.vector4_i32[0],
                -V.vector4_i32[1],
                -V.vector4_i32[2],
                -V.vector4_i32[3]
            } } };
        return Result.v;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vnegq_s32(V);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_sub_epi32(_mm_setzero_si128(), V);
#endif
    }

    inline SIMDVECTORI SMVectorIntReplicate(int32_t Value) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI vResult;
        vResult.i[0] =
            vResult.i[1] =
            vResult.i[2] =
            vResult.i[3] = Value;
        return vResult.v;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vdupq_n_s32(Value);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_set1_epi32(Value);
#endif
    }

    inline SIMDVECTORU SMVectorUIntReplicate(uint32_t Value) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORU vResult;
        vResult.u[0] =
            vResult.u[1] =
            vResult.u[2] =
            vResult.u[3] = Value;
        return vResult.vu;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vdupq_n_u32(Value);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_set1_epi32((int32_t)(Value));
#endif
    }

    inline SIMDVECTORI SMVectorIntSet(int32_t x, int32_t y, int32_t z, int32_t w) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI vResult = { { { x, y, z, w } } };
        return vResult.v;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
        int32_t XM_ALIGNED_STRUCT(16) data[4] = { x, y, z, w };
        return vld1q_s32(data);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_set_epi32(x, y, z, w);
#endif
    }

    inline SIMDVECTORU SMVectorUIntSet(uint32_t x, uint32_t y, uint32_t z, uint32_t w) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORU vResult = { { { x, y, z, w } } };
        return vResult.vu;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
        uint32_t XM_ALIGNED_STRUCT(16) data[4] = { x, y, z, w };
        return vld1q_u32(data);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_set_epi32((int32_t)(x), (int32_t)(y), (int32_t)(z), (int32_t)(w));
#endif
    }


    inline SIMDVECTORI SMVectorIntAnd(const SIMDVECTORI V1, const SIMDVECTORI V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI Result = { { {
                V1.vector4_i32[0] & V2.vector4_i32[0],
                V1.vector4_i32[1] & V2.vector4_i32[1],
                V1.vector4_i32[2] & V2.vector4_i32[2],
                V1.vector4_i32[3] & V2.vector4_i32[3]
            } } };
        return Result.v;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vandq_s32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_and_si128(V1, V2);
#endif
    }

    inline SIMDVECTORU SMVectorUIntAnd(const SIMDVECTORU V1, const SIMDVECTORU V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORIU Result = { { {
                V1.vector4_u32[0] & V2.vector4_u32[0],
                V1.vector4_u32[1] & V2.vector4_u32[1],
                V1.vector4_u32[2] & V2.vector4_u32[2],
                V1.vector4_u32[3] & V2.vector4_u32[3]
            } } };
        return Result.vu;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vandq_u32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_and_si128(V1, V2);
#endif
    }

    //inline SIMDVECTORI     XMVectorAndCInt(FXMVECTOR V1, FXMVECTOR V2) noexcept;

    inline SIMDVECTORI SMVectorIntOr(const SIMDVECTORI V1, const SIMDVECTORI V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI Result = { { {
                V1.vector4_i32[0] | V2.vector4_i32[0],
                V1.vector4_i32[1] | V2.vector4_i32[1],
                V1.vector4_i32[2] | V2.vector4_i32[2],
                V1.vector4_i32[3] | V2.vector4_i32[3]
            } } };
        return Result;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vorrq_s32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_or_si128(V1, V2);
#endif
    }

    inline SIMDVECTORU SMVectorUIntOr(const SIMDVECTORU V1, const SIMDVECTORU V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORIU Result = { { {
                V1.vector4_u32[0] | V2.vector4_u32[0],
                V1.vector4_u32[1] | V2.vector4_u32[1],
                V1.vector4_u32[2] | V2.vector4_u32[2],
                V1.vector4_u32[3] | V2.vector4_u32[3]
            } } };
        return Result.vu;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return vorrq_u32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_or_si128(V1, V2);
#endif
    }

    inline SIMDVECTORI SMVectorIntXor(const SIMDVECTORI V1, const SIMDVECTORI V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI Result = { { {
                V1.vector4_i32[0] ^ V2.vector4_i32[0],
                V1.vector4_i32[1] ^ V2.vector4_i32[1],
                V1.vector4_i32[2] ^ V2.vector4_i32[2],
                V1.vector4_i32[3] ^ V2.vector4_i32[3]
            } } };
        return Result.v;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return veorq_s32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_xor_si128(V1, V2);
#endif
    }

    inline SIMDVECTORU SMVectorUIntXor(const SIMDVECTORU V1, const SIMDVECTORU V2) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORIU Result = { { {
                V1.vector4_u32[0] ^ V2.vector4_u32[0],
                V1.vector4_u32[1] ^ V2.vector4_u32[1],
                V1.vector4_u32[2] ^ V2.vector4_u32[2],
                V1.vector4_u32[3] ^ V2.vector4_u32[3]
            } } };
        return Result.vu;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return veorq_u32(V1, V2);
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_xor_si128(V1, V2);
#endif
    }

    inline SIMDVECTORI SMVectorIntNot(const SIMDVECTORI V) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORI Result = { { {
                ~V.vector4_i32[0],
                ~V.vector4_i32[1],
                ~V.vector4_i32[2],
                ~V.vector4_i32[3]
            } } };
        return Result.v;
#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return veorq_s32(V, cv4i(~0, ~0, ~0, ~0));
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_xor_si128(V, _mm_set_epi32(~0, ~0, ~0, ~0));
#endif
    }

    inline SIMDVECTORU SMVectorUIntNot(const SIMDVECTORU V) noexcept
    {
#if defined(_XM_NO_INTRINSICS_)
        __SIMDVECTORIU Result = { { {
                ~V.vector4_u32[0],
                ~V.vector4_u32[1],
                ~V.vector4_u32[2],
                ~V.vector4_u32[3]
            } } };
        return Result.vu;

#elif defined(_XM_ARM_NEON_INTRINSICS_)
        return veorq_u32(V, cv4i(~0, ~0, ~0, ~0));
#elif defined(_XM_SSE_INTRINSICS_)
        return _mm_xor_si128(V, _mm_set_epi32(~0, ~0, ~0, ~0));
#endif
    }
}