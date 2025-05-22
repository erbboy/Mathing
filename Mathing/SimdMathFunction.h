#pragma once

/* ------------- From Hlsl -------------
*  --- https://learn.microsoft.com/zh-cn/windows/win32/direct3dhlsl/dx-graphics-hlsl-intrinsic-functions
*
* General
*   abs - float/int
*   ceil - float
*   clamp - float/int
*   exp - float
*   exp2 - float
*   f16tof32 - uint -> float
*   f32tof16 - float -> uint
*   floor - float
*   fmod - float
*   frac - float
*   frexp - float
*   isfinite - float -> bool
*   isinf - float -> bool
*   isnan - float -> bool
*   log - float
*   log10 - float
*   log2 - float
*   mad - float/int
*   max - float/int
*   min - float/int
*   modf - float
*   pow - float
*   rcp - float
*   round - float
*   rsqrt - float
*   saturate - float
*   sign - float/int
*   sqrt - float
*   step - float
*   trunc - float
*
* Trigonometric
*   acos - float
*   asin - float
*   atan - float
*   atan2 - float
*   cos - float
*   cosh - float
*   degrees - float
*   radians - float
*   sin - float
*   sincos - float
*   sinh - float
*   tan - float
*   tanh - float
*
* Boolen
*   all - float/int/bool
*   any - float/int/bool
*
* BitCast
*   asdouble - uint lowbits, uint highbits
*   asdouble - long bits
*   asfloat - int
*   asint - float/uint
*   asuint - float/int
*   asuint - double, uint, uint
*   countbits - uint
*   firstbithigh - int
*   firstbitlow - int
*   reversebits - uint
*
* Geometry
*   cross - float
*   distance - float
*   dot - float
*   faceforward - float
*   length - float
*   reflect - float
*   refract - float
*	normalize - float
*
* Interpolation
*   lerp - float
*   smoothstep - float
*
*
* Matrix
*   determinant - matrix
*   mul
*   transpose
*
*
*
*/


/* ------------- From C and Oth -------------
*  copysign - float
*  nextPowof2 - uint
*  closestPowof2 - uint
*  isPowof2
*  select
*  hermite
*  sum
*/

namespace Math
{
	// abs
	template<uint32_t Dim>
	inline SimdVector<float, Dim> abs(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorAbs(v.Packed);
		return ret;
	}
	template<uint32_t ...S>
	inline SimdVector<float, sizeof...(S)> abs(const SimdSwizzle<float, S...>& v) noexcept
	{
		SimdVector<float, sizeof...(S)> a = v;
		return abs(a);
	}

	// ceil
	template<uint32_t Dim>
	inline SimdVector<float, Dim> ceil(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorCeiling(v.Packed);
		return ret;
	}
	template<uint32_t ...S>
	inline SimdVector<float, sizeof...(S)> ceil(const SimdSwizzle<float, S...>& v) noexcept
	{
		SimdVector<float, sizeof...(S)> a = v;
		return abs(v);
	}

	// clamp
	template<uint32_t Dim>
	inline SimdVector<float, Dim> clamp(const SimdVector<float, Dim>& v, const SimdVector<float, Dim>& vmin, const SimdVector<float, Dim>& vmax) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorClamp(v.Packed, vmin.Packed, vmax.Packed);
		return ret;
	}

	// exp
	template<uint32_t Dim>
	inline SimdVector<float, Dim> exp(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorExpE(v.Packed);
		return ret;
	}

	// exp2
	template<uint32_t Dim>
	inline SimdVector<float, Dim> exp2(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorExp2(v.Packed);
		return ret;
	}

	// exp10
	template<uint32_t Dim>
	inline SimdVector<float, Dim> exp10(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorExp10(v.Packed);
		return ret;
	}

	// f16tof32 todo

	// f32tof16 todo

	// floor
	template<uint32_t Dim>
	inline SimdVector<float, Dim> floor(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorFloor(v.Packed);
		return ret;
	}

	// fmod
	template<uint32_t Dim>
	inline SimdVector<float, Dim> fmod(const SimdVector<float, Dim>& v1, const SimdVector<float, Dim>& v2) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorMod(v1.Packed, v2.Packed);
		return ret;
	}

	// frac
	template<uint32_t Dim>
	inline SimdVector<float, Dim> frac(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorSubtract(v.Packed, DirectX::XMVectorFloor(v.Packed));
		return ret;
	}

	// frexp todo

	// isfinite todo bool type?
	// isinf todo bool type?
	// isnan todo bool type?

	// log
	template<uint32_t Dim>
	inline SimdVector<float, Dim> log(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorLogE(v.Packed);
		return ret;
	}

	// log10
	template<uint32_t Dim>
	inline SimdVector<float, Dim> log10(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorLog10(v.Packed);
		return ret;
	}

	// log2
	template<uint32_t Dim>
	inline SimdVector<float, Dim> log2(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorLog2(v.Packed);
		return ret;
	}

	// mad
	template<uint32_t Dim>
	inline SimdVector<float, Dim> mad(const SimdVector<float, Dim>& v1, const SimdVector<float, Dim>& v2, const SimdVector<float, Dim>& v3) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorMultiplyAdd(v1.Packed, v2.Packed, v3.Packed);
		return ret;
	}

	// max
	template<uint32_t Dim>
	inline SimdVector<float, Dim> max(const SimdVector<float, Dim>& v1, const SimdVector<float, Dim>& v2) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorMax(v1.Packed, v2.Packed);
		return ret;
	}

	// min
	template<uint32_t Dim>
	inline SimdVector<float, Dim> min(const SimdVector<float, Dim>& v1, const SimdVector<float, Dim>& v2) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorMin(v1.Packed, v2.Packed);
		return ret;
	}

	// modf todo

	// pow
	template<uint32_t Dim>
	inline SimdVector<float, Dim> pow(const SimdVector<float, Dim>& v1, const SimdVector<float, Dim>& v2) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorPow(v1.Packed, v2.Packed);
		return ret;
	}

	// rcp
	template<uint32_t Dim>
	inline SimdVector<float, Dim> rcp(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorReciprocalEst(v.Packed);
		return ret;
	}

	// round
	template<uint32_t Dim>
	inline SimdVector<float, Dim> round(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorRound(v.Packed);
		return ret;
	}

	// rsqrt
	template<uint32_t Dim>
	inline SimdVector<float, Dim> rsqrt(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorReciprocalSqrtEst(v.Packed);
		return ret;
	}

	// saturate
	template<uint32_t Dim>
	inline SimdVector<float, Dim> saturate(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorSaturate(v.Packed);
		return ret;
	}

	// sign todo

	// sqrt
	template<uint32_t Dim>
	inline SimdVector<float, Dim> sqrt(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorSqrt(v.Packed);
		return ret;
	}

	// step todo

	// trunc
	template<uint32_t Dim>
	inline SimdVector<float, Dim> trunc(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorTruncate(v.Packed);
		return ret;
	}

	// acos
	template<uint32_t Dim>
	inline SimdVector<float, Dim> acos(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorACos(v.Packed);
		return ret;
	}
	// acosfast
	template<uint32_t Dim>
	inline SimdVector<float, Dim> acosfast(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorACosEst(v.Packed);
		return ret;
	}

	// asin
	template<uint32_t Dim>
	inline SimdVector<float, Dim> asin(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorASin(v.Packed);
		return ret;
	}
	// asinfast
	template<uint32_t Dim>
	inline SimdVector<float, Dim> asinfast(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorASinEst(v.Packed);
		return ret;
	}

	// atan
	template<uint32_t Dim>
	inline SimdVector<float, Dim> atan(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorATan(v.Packed);
		return ret;
	}
	// atanfast
	template<uint32_t Dim>
	inline SimdVector<float, Dim> atanfast(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorATanEst(v.Packed);
		return ret;
	}

	// atan2
	template<uint32_t Dim>
	inline SimdVector<float, Dim> atan2(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorATan2(v.Packed);
		return ret;
	}
	// atan2fast
	template<uint32_t Dim>
	inline SimdVector<float, Dim> atan2fast(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorATan2Est(v.Packed);
		return ret;
	}

	// cos
	template<uint32_t Dim>
	inline SimdVector<float, Dim> cos(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorCos(v.Packed);
		return ret;
	}
	// cosfast
	template<uint32_t Dim>
	inline SimdVector<float, Dim> cosfast(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorCosEst(v.Packed);
		return ret;
	}

	// cosh
	template<uint32_t Dim>
	inline SimdVector<float, Dim> cosh(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorCosH(v.Packed);
		return ret;
	}

	// sin
	template<uint32_t Dim>
	inline SimdVector<float, Dim> sin(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorSin(v.Packed);
		return ret;
	}
	// sinfast
	template<uint32_t Dim>
	inline SimdVector<float, Dim> sinfast(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorSinEst(v.Packed);
		return ret;
	}

	// sinh
	template<uint32_t Dim>
	inline SimdVector<float, Dim> sinh(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorSinH(v.Packed);
		return ret;
	}

	// sincos
	template<uint32_t Dim>
	inline void sincos(const SimdVector<float, Dim>& v, SimdVector<float, Dim>& s, SimdVector<float, Dim>& c) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorSinCos(&s.Packed, &c.Packed, v.Packed);
		return ret;
	}
	// sincosfast
	template<uint32_t Dim>
	inline void sincosfast(const SimdVector<float, Dim>& v, SimdVector<float, Dim>& s, SimdVector<float, Dim>& c) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorSinCosEst(&s.Packed, &c.Packed, v.Packed);
		return ret;
	}

	// tan
	template<uint32_t Dim>
	inline SimdVector<float, Dim> tan(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorTan(v.Packed);
		return ret;
	}
	// tanfast
	template<uint32_t Dim>
	inline SimdVector<float, Dim> tanfast(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorTanEst(v.Packed);
		return ret;
	}

	// tanh
	template<uint32_t Dim>
	inline SimdVector<float, Dim> tanh(const SimdVector<float, Dim>& v) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorTanH(v.Packed);
		return ret;
	}

	// degrees
	template<uint32_t Dim>
	inline SimdVector<float, Dim> degrees(const SimdVector<float, Dim>& v) noexcept
	{
		return v * FRadian2Degree;
	}

	// radians
	template<uint32_t Dim>
	inline SimdVector<float, Dim> radians(const SimdVector<float, Dim>& v) noexcept
	{
		return v * FDegree2Radian;
	}

	// cross
	inline SimdVector<float, 3> cross(const SimdVector<float, 3>& v1, const SimdVector<float, 3>& v2) noexcept
	{
		SimdVector<float, 3> ret;
		ret.Packed = DirectX::XMVector3Cross(v1.Packed, v2.Packed);
		return ret;
	}

	// length
	inline SimdVector<float, 1> length(const SimdVector<float, 2>& v) noexcept
	{
		SimdVector<float, 1> ret;
		ret.Packed = DirectX::XMVector2Length(v.Packed);
		return ret;
	}
	inline SimdVector<float, 1> length(const SimdVector<float, 3>& v) noexcept
	{
		SimdVector<float, 1> ret;
		ret.Packed = DirectX::XMVector3Length(v.Packed);
		return ret;
	}
	inline SimdVector<float, 1> length(const SimdVector<float, 4>& v) noexcept
	{
		SimdVector<float, 1> ret;
		ret.Packed = DirectX::XMVector4Length(v.Packed);
		return ret;
	}

	// distance
	template<uint32_t Dim>
	inline SimdVector<float, 1> distance(const SimdVector<float, Dim>& v1, const SimdVector<float, Dim>& v2) noexcept
	{
		return length(v1 - v2);
	}

	// dot
	inline SimdVector<float, 1> dot(const SimdVector<float, 2>& v1, const SimdVector<float, 2>& v2) noexcept
	{
		SimdVector<float, 1> ret;
		ret.Packed = DirectX::XMVector2Dot(v1.Packed, v2.Packed);
		return ret;
	}
	inline SimdVector<float, 1> dot(const SimdVector<float, 3>& v1, const SimdVector<float, 3>& v2) noexcept
	{
		SimdVector<float, 1> ret;
		ret.Packed = DirectX::XMVector3Dot(v1.Packed, v2.Packed);
		return ret;
	}
	inline SimdVector<float, 1> dot(const SimdVector<float, 4>& v1, const SimdVector<float, 4>& v2) noexcept
	{
		SimdVector<float, 1> ret;
		ret.Packed = DirectX::XMVector4Dot(v1.Packed, v2.Packed);
		return ret;
	}

	// normalize
	inline SimdVector<float, 1> normalize(const SimdVector<float, 2>& v) noexcept
	{
		SimdVector<float, 1> ret;
		ret.Packed = DirectX::XMVector2Normalize(v.Packed);
		return ret;
	}
	inline SimdVector<float, 1> normalize(const SimdVector<float, 3>& v) noexcept
	{
		SimdVector<float, 1> ret;
		ret.Packed = DirectX::XMVector3Normalize(v.Packed);
		return ret;
	}
	inline SimdVector<float, 1> normalize(const SimdVector<float, 4>& v) noexcept
	{
		SimdVector<float, 1> ret;
		ret.Packed = DirectX::XMVector4Normalize(v.Packed);
		return ret;
	}

	// reflect
	inline SimdVector<float, 2> reflect(const SimdVector<float, 2>& v1, const SimdVector<float, 2>& v2) noexcept
	{
		SimdVector<float, 2> ret;
		ret.Packed = DirectX::XMVector2Reflect(v1.Packed, v2.Packed);
		return ret;
	}
	inline SimdVector<float, 3> reflect(const SimdVector<float, 3>& v1, const SimdVector<float, 3>& v2) noexcept
	{
		SimdVector<float, 3> ret;
		ret.Packed = DirectX::XMVector3Reflect(v1.Packed, v2.Packed);
		return ret;
	}
	inline SimdVector<float, 4> reflect(const SimdVector<float, 4>& v1, const SimdVector<float, 4>& v2) noexcept
	{
		SimdVector<float, 4> ret;
		ret.Packed = DirectX::XMVector4Reflect(v1.Packed, v2.Packed);
		return ret;
	}

	// refract
	inline SimdVector<float, 2> refract(const SimdVector<float, 2>& v1, const SimdVector<float, 2>& v2, float RefractionIndex) noexcept
	{
		SimdVector<float, 2> ret;
		ret.Packed = DirectX::XMVector2Refract(v1.Packed, v2.Packed, RefractionIndex);
		return ret;
	}
	inline SimdVector<float, 3> refract(const SimdVector<float, 3>& v1, const SimdVector<float, 3>& v2, float RefractionIndex) noexcept
	{
		SimdVector<float, 3> ret;
		ret.Packed = DirectX::XMVector3Refract(v1.Packed, v2.Packed, RefractionIndex);
		return ret;
	}
	inline SimdVector<float, 4> refract(const SimdVector<float, 4>& v1, const SimdVector<float, 4>& v2, float RefractionIndex) noexcept
	{
		SimdVector<float, 4> ret;
		ret.Packed = DirectX::XMVector4Refract(v1.Packed, v2.Packed, RefractionIndex);
		return ret;
	}
	inline SimdVector<float, 2> refract(const SimdVector<float, 2>& v1, const SimdVector<float, 2>& v2, const SimdVector<float, 2>& RefractionIndex) noexcept
	{
		SimdVector<float, 2> ret;
		ret.Packed = DirectX::XMVector2RefractV(v1.Packed, v2.Packed, RefractionIndex.Packed);
		return ret;
	}
	inline SimdVector<float, 3> refract(const SimdVector<float, 3>& v1, const SimdVector<float, 3>& v2, const SimdVector<float, 3>& RefractionIndex) noexcept
	{
		SimdVector<float, 3> ret;
		ret.Packed = DirectX::XMVector3RefractV(v1.Packed, v2.Packed, RefractionIndex.Packed);
		return ret;
	}
	inline SimdVector<float, 4> refract(const SimdVector<float, 4>& v1, const SimdVector<float, 4>& v2, const SimdVector<float, 4>& RefractionIndex) noexcept
	{
		SimdVector<float, 4> ret;
		ret.Packed = DirectX::XMVector4RefractV(v1.Packed, v2.Packed, RefractionIndex.Packed);
		return ret;
	}

	// faceforward
	template<uint32_t Dim>
	inline SimdVector<float, Dim> faceforward(const SimdVector<float, Dim>& v, const SimdVector<float, Dim>& ref) noexcept
	{
		// todo
	}


}