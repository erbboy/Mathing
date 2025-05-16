#pragma once

namespace Math
{
    // float1
    template<uint32_t X>
    inline SimdVector<float, 1>::SimdVector(const SimdSwizzle<float, X>& s) noexcept
    {
        Packed = Swizzler<X>(s.Packed);
    }

    template<uint32_t X>
    inline SimdVector<float, 1>& SimdVector<float, 1>::operator=(const SimdSwizzle<float, X>& s) noexcept
    {
        Packed = Swizzler<X>(s.Packed);
        return *this;
    }

    // swz1
    template<uint32_t X>
    inline SimdSwizzle<float, X>& SimdSwizzle<float, X>::operator=(const SimdVector<float, 1>& oth) noexcept
    {
        V[X] = oth.v[0];
        return *this;
    }


    // float2
    template<uint32_t X>
    inline SimdVector<float, 2>::SimdVector(const SimdSwizzle<float, X>& s) noexcept
    {
        Packed = Swizzler<X>(s.Packed);
    }

    template<uint32_t X>
    inline SimdVector<float, 2>& SimdVector<float, 2>::operator=(const SimdSwizzle<float, X>& s) noexcept
    {
        Packed = Swizzler<X>(s.Packed);
        return *this;
    }

    template<uint32_t X, uint32_t Y>
    inline SimdVector<float, 2>::SimdVector(const SimdSwizzle<float, X, Y>& s) noexcept
    {
        Packed = Swizzler<X, Y>(s.Packed);
    }

    template<uint32_t X, uint32_t Y>
    inline SimdVector<float, 2>& SimdVector<float, 2>::operator=(const SimdSwizzle<float, X, Y>& s) noexcept
    {
        Packed = Swizzler<X, Y>(s.Packed);
        return *this;
    }

    // swz2
    template<uint32_t X, uint32_t Y>
    inline SimdSwizzle<float, X, Y>& SimdSwizzle<float, X, Y>::operator =(const SimdVector<float, 1>& oth) noexcept
    {
        using PN = AssignSingleToPermute2<X, Y, 0>;
        Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
        return *this;
    }

    template<uint32_t X, uint32_t Y>
    inline SimdSwizzle<float, X, Y>& SimdSwizzle<float, X, Y>::operator =(const SimdVector<float, 2>& oth) noexcept
    {
        using PN = AssignToPermute2<X, Y, 0, 1>;
        Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
        return *this;
    }

    // float3
    template<uint32_t X>
    inline SimdVector<float, 3>::SimdVector(const SimdSwizzle<float, X>& s) noexcept
    {
        Packed = Swizzler<X>(s.Packed);
    }

    template<uint32_t X>
    inline SimdVector<float, 3>& SimdVector<float, 3>::operator=(const SimdSwizzle<float, X>& s) noexcept
    {
        Packed = Swizzler<X>(s.Packed);
        return *this;
    }

    template<uint32_t X, uint32_t Y, uint32_t Z>
    inline SimdVector<float, 3>::SimdVector(const SimdSwizzle<float, X, Y, Z>& s) noexcept
    {
        Packed = Swizzler<X, Y, Z>(s.Packed);
    }

    template<uint32_t X, uint32_t Y, uint32_t Z>
    inline SimdVector<float, 3>& SimdVector<float, 3>::operator=(const SimdSwizzle<float, X, Y, Z>& s) noexcept
    {
        Packed = Swizzler<X, Y, Z>(s.Packed);
        return *this;
    }

    // swz3
    template<uint32_t X, uint32_t Y, uint32_t Z>
    inline SimdSwizzle<float, X, Y, Z>& SimdSwizzle<float, X, Y, Z>::operator =(const SimdVector<float, 1>& oth) noexcept
    {
        using PN = AssignSingleToPermute3<X, Y, Z, 0>;
        Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
        return *this;
    }

    template<uint32_t X, uint32_t Y, uint32_t Z>
    inline SimdSwizzle<float, X, Y, Z>& SimdSwizzle<float, X, Y, Z>::operator =(const SimdVector<float, 3>& oth) noexcept
    {
        using PN = AssignToPermute3<X, Y, Z, 0, 1, 2>;
        Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
        return *this;
    }
    
    // float4
    template<uint32_t X>
    inline SimdVector<float, 4>::SimdVector(const SimdSwizzle<float, X>& s) noexcept
    {
        Packed = Swizzler<X>(s.Packed);
    }

    template<uint32_t X>
    inline SimdVector<float, 4>& SimdVector<float, 4>::operator=(const SimdSwizzle<float, X>& s) noexcept
    {
        Packed = Swizzler<X>(s.Packed);
        return *this;
    }

    template<uint32_t X, uint32_t Y, uint32_t Z, uint32_t W>
    inline SimdVector<float, 4>::SimdVector(const SimdSwizzle<float, X, Y, Z, W>& s) noexcept
    {
        Packed = Swizzler<X, Y, Z, W>(s.Packed);
    }

    template<uint32_t X, uint32_t Y, uint32_t Z, uint32_t W>
    inline SimdVector<float, 4>& SimdVector<float, 4>::operator=(const SimdSwizzle<float, X, Y, Z, W>& s) noexcept
    {
        Packed = Swizzler<X, Y, Z, W>(s.Packed);
        return *this;
    }

    // swz4
    template<uint32_t X, uint32_t Y, uint32_t Z, uint32_t W>
    inline SimdSwizzle<float, X, Y, Z, W>& SimdSwizzle<float, X, Y, Z, W>::operator =(const SimdVector<float, 1>& oth) noexcept
    {
        using PN = AssignSingleToPermute4<X, Y, Z, W, 0>;
        Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
        return *this;
    }

    template<uint32_t X, uint32_t Y, uint32_t Z, uint32_t W>
    inline SimdSwizzle<float, X, Y, Z, W>& SimdSwizzle<float, X, Y, Z, W>::operator =(const SimdVector<float, 4>& oth) noexcept
    {
        using PN = AssignToPermute4<X, Y, Z, W, 0, 1, 2, 3>;
        Packed = DirectX::XMVectorPermute<PN::Permute0, PN::Permute1, PN::Permute2, PN::Permute3>(Packed, oth.Packed);
        return *this;
    }
}