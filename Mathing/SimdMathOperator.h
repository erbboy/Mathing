#pragma once
/* *****************
* Operator
*   + - * / %
*   += -= *= /= %=
*   & | ^ << >>
*   &= |= ^= <<= >>=
*   ~
*   ++ --
*   !
*   == != < > <= >=
*/

#define SIMDVector_Swizzle_BinaryOperator(TYPE, OP) \
template<uint32_t S00, uint32_t S10>\
inline SimdVector<TYPE, 1> operator OP (const SimdSwizzle<TYPE, S00>& v0, const SimdSwizzle<TYPE, S10>& v1) noexcept\
{ \
	SimdVector<TYPE, 1> a(v0), b(v1);\
	return a OP b;\
}\
template<uint32_t S00>\
inline SimdVector<TYPE, 1> operator OP (const SimdSwizzle<TYPE, S00>& v0, const SimdVector<TYPE, 1>& v1) noexcept\
{\
	SimdVector<TYPE, 1> a(v0);\
	return a OP v1;\
}\
template<uint32_t S00>\
inline SimdVector<TYPE, 1> operator OP (const SimdSwizzle<TYPE, S00>& v0, TYPE v1) noexcept\
{\
	SimdVector<TYPE, 1> a(v0);\
	return a OP v1;\
}\
template<uint32_t S00>\
inline SimdVector<TYPE, 1> operator OP (TYPE v1, const SimdSwizzle<TYPE, S00>& v0) noexcept\
{\
	SimdVector<TYPE, 1> a(v0);\
	return a OP v1;\
}\
template<uint32_t S00>\
inline SimdVector<TYPE, 1> operator OP (const SimdVector<TYPE, 1>& v1, const SimdSwizzle<TYPE, S00>& v0) noexcept\
{\
	SimdVector<TYPE, 1> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S10, uint32_t S11>\
inline SimdVector<TYPE, 2> operator OP (const SimdSwizzle<TYPE, S00, S01>& v0, const SimdSwizzle<TYPE, S10, S11>& v1) noexcept\
{\
	SimdVector<TYPE, 2> a(v0), b(v1); \
	return a OP b; \
}\
template<uint32_t S00, uint32_t S01>\
inline SimdVector<TYPE, 2> operator OP (const SimdSwizzle<TYPE, S00, S01>& v0, const SimdVector<TYPE, 2>& v1) noexcept\
{\
	SimdVector<TYPE, 2> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01>\
inline SimdVector<TYPE, 2> operator OP (const SimdVector<TYPE, 2>& v1, const SimdSwizzle<TYPE, S00, S01>& v0) noexcept\
{\
	SimdVector<TYPE, 2> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01>\
inline SimdVector<TYPE, 2> operator OP (const SimdSwizzle<TYPE, S00, S01>& v0, TYPE v1) noexcept\
{\
	SimdVector<TYPE, 2> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01>\
inline SimdVector<TYPE, 2> operator OP (TYPE v1, const SimdSwizzle<TYPE, S00, S01>& v0) noexcept\
{\
	SimdVector<TYPE, 2> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01>\
inline SimdVector<TYPE, 2> operator OP (const SimdSwizzle<TYPE, S00, S01>& v0, const SimdVector<TYPE, 1>& v1) noexcept\
{\
	SimdVector<TYPE, 2> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01>\
inline SimdVector<TYPE, 2> operator OP (const SimdVector<TYPE, 1>& v1, const SimdSwizzle<TYPE, S00, S01>& v0) noexcept\
{\
	SimdVector<TYPE, 2> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S10>\
inline SimdVector<TYPE, 2> operator OP (const SimdSwizzle<TYPE, S00, S01>& v0, const SimdSwizzle<TYPE, S10>& v1) noexcept\
{\
	SimdVector<TYPE, 2> a(v0), b(v1); \
	return a OP b; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S10>\
inline SimdVector<TYPE, 2> operator OP (const SimdSwizzle<TYPE, S10>& v1, const SimdSwizzle<TYPE, S00, S01>& v0) noexcept\
{\
	SimdVector<TYPE, 2> a(v0), b(v1); \
	return a OP b; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S10, uint32_t S11, uint32_t S12>\
inline SimdVector<TYPE, 3> operator OP (const SimdSwizzle<TYPE, S00, S01, S02>& v0, const SimdSwizzle<TYPE, S10, S11, S12>& v1) noexcept\
{\
	SimdVector<TYPE, 3> a(v0), b(v1); \
	return a OP b; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02>\
inline SimdVector<TYPE, 3> operator OP (const SimdSwizzle<TYPE, S00, S01, S02>& v0, const SimdVector<TYPE, 3>& v1) noexcept\
{\
	SimdVector<TYPE, 3> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02>\
inline SimdVector<TYPE, 3> operator OP (const SimdVector<TYPE, 3>& v1, const SimdSwizzle<TYPE, S00, S01, S02>& v0) noexcept\
{\
	SimdVector<TYPE, 3> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02>\
inline SimdVector<TYPE, 3> operator OP (const SimdSwizzle<TYPE, S00, S01, S02>& v0, const SimdVector<TYPE, 1>& v1) noexcept\
{\
	SimdVector<TYPE, 3> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02>\
inline SimdVector<TYPE, 3> operator OP (const SimdVector<TYPE, 1>& v1, const SimdSwizzle<TYPE, S00, S01, S02>& v0) noexcept\
{\
	SimdVector<TYPE, 3> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02>\
inline SimdVector<TYPE, 3> operator OP (const SimdSwizzle<TYPE, S00, S01, S02>& v0, TYPE v1) noexcept\
{\
	SimdVector<TYPE, 3> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02>\
inline SimdVector<TYPE, 3> operator OP (TYPE v1, const SimdSwizzle<TYPE, S00, S01, S02>& v0) noexcept\
{\
	SimdVector<TYPE, 3> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S10>\
inline SimdVector<TYPE, 3> operator OP (const SimdSwizzle<TYPE, S00, S01, S02>& v0, const SimdSwizzle<TYPE, S10>& v1) noexcept\
{\
	SimdVector<TYPE, 3> a(v0), b(v1); \
	return a OP b; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S10>\
inline SimdVector<TYPE, 3> operator OP (const SimdSwizzle<TYPE, S10>& v1, const SimdSwizzle<TYPE, S00, S01, S02>& v0) noexcept\
{\
	SimdVector<TYPE, 3> a(v0), b(v1); \
	return a OP b; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03, uint32_t S10, uint32_t S11, uint32_t S12, uint32_t S13>\
inline SimdVector<TYPE, 4> operator OP (const SimdSwizzle<TYPE, S00, S01, S02, S03>& v0, const SimdSwizzle<TYPE, S10, S11, S12, S13>& v1) noexcept\
{\
	SimdVector<TYPE, 4> a(v0), b(v1); \
	return a OP b; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03>\
inline SimdVector<TYPE, 4> operator OP (const SimdSwizzle<TYPE, S00, S01, S02, S03>& v0, const SimdVector<TYPE, 4>& v1) noexcept\
{\
	SimdVector<TYPE, 4> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03>\
inline SimdVector<TYPE, 4> operator OP (const SimdVector<TYPE, 4>& v1, const SimdSwizzle<TYPE, S00, S01, S02, S03>& v0) noexcept\
{\
	SimdVector<TYPE, 4> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03>\
inline SimdVector<TYPE, 4> operator OP (const SimdSwizzle<TYPE, S00, S01, S02, S03>& v0, const SimdVector<TYPE, 1>& v1) noexcept\
{\
	SimdVector<TYPE, 4> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03>\
inline SimdVector<TYPE, 4> operator OP (const SimdVector<TYPE, 1>& v1, const SimdSwizzle<TYPE, S00, S01, S02, S03>& v0) noexcept\
{\
	SimdVector<TYPE, 4> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03>\
inline SimdVector<TYPE, 4> operator OP (const SimdSwizzle<TYPE, S00, S01, S02, S03>& v0, TYPE& v1) noexcept\
{\
	SimdVector<TYPE, 4> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03>\
inline SimdVector<TYPE, 4> operator OP (TYPE v1, const SimdSwizzle<TYPE, S00, S01, S02, S03>& v0) noexcept\
{\
	SimdVector<TYPE, 4> a(v0); \
	return a OP v1; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03, uint32_t S10>\
inline SimdVector<TYPE, 4> operator OP (const SimdSwizzle<TYPE, S00, S01, S02, S03>& v0, const SimdSwizzle<TYPE, S10>& v1) noexcept\
{\
	SimdVector<TYPE, 4> a(v0), b(v1); \
	return a OP b; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03, uint32_t S10>\
inline SimdVector<TYPE, 4> operator OP (const SimdSwizzle<TYPE, S10>& v1, const SimdSwizzle<TYPE, S00, S01, S02, S03>& v0) noexcept\
{\
	SimdVector<TYPE, 4> a(v0), b(v1); \
	return a OP b; \
}\


#define SIMDVector_Swizzle_SelfOperator(TYPE, OP) \
template<uint32_t S00, uint32_t S10>\
SimdSwizzle<TYPE, S00>& operator OP (SimdSwizzle<TYPE, S00>& v0, const SimdSwizzle<TYPE, S10>& v1) noexcept\
{\
	SimdVector<TYPE, 1> a(v0), b(v1);\
	a OP b;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00>\
SimdSwizzle<TYPE, S00>& operator OP (SimdSwizzle<TYPE, S00>& v0, const SimdVector<TYPE, 1>& v1) noexcept\
{\
	SimdVector<TYPE, 1> a(v0);\
	a OP v1;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00>\
SimdSwizzle<TYPE, S00>& operator OP (SimdSwizzle<TYPE, S00>& v0, TYPE v1) noexcept\
{\
	SimdVector<TYPE, 1> a(v0);\
	a OP v1;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00>\
SimdSwizzle<TYPE, S00>& operator OP (SimdVector<TYPE, 1>& v0, const SimdSwizzle<TYPE, S00>& v1) noexcept\
{\
	SimdVector<TYPE, 1> a(v1);\
	return v0 OP a;\
}\
template<uint32_t S00, uint32_t S01, uint32_t S10, uint32_t S11>\
SimdSwizzle<TYPE, S00, S01>& operator OP (SimdSwizzle<TYPE, S00, S01>& v0, const SimdSwizzle<TYPE, S01, S11>& v1) noexcept\
{\
	SimdVector<TYPE, 2> a(v0), b(v1);\
	a OP b;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00, uint32_t S01>\
SimdSwizzle<TYPE, S00, S01>& operator OP (SimdSwizzle<TYPE, S00, S01>& v0, const SimdVector<TYPE, 2>& v1) noexcept\
{\
	SimdVector<TYPE, 2> a(v0);\
	a OP v1;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00, uint32_t S01>\
SimdSwizzle<TYPE, S00, S01>& operator OP (SimdSwizzle<TYPE, S00, S01>& v0, const SimdVector<TYPE, 1>& v1) noexcept\
{\
	SimdVector<TYPE, 2> a(v0);\
	a OP v1;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00, uint32_t S01, uint32_t S10>\
SimdSwizzle<TYPE, S00, S01>& operator OP (SimdSwizzle<TYPE, S00, S01>& v0, const SimdSwizzle<TYPE, S01>& v1) noexcept\
{\
	SimdVector<TYPE, 2> a(v0), b(v1);\
	a OP b;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00, uint32_t S01>\
SimdSwizzle<TYPE, S00, S01>& operator OP (SimdSwizzle<TYPE, S00, S01>& v0, TYPE v1) noexcept\
{\
	SimdVector<TYPE, 2> a(v0);\
	a OP v1;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00, uint32_t S01>\
SimdVector<TYPE, 2>& operator OP (SimdVector<TYPE, 2>& v0, const SimdSwizzle<TYPE, S00, S01>& v1) noexcept\
{\
	SimdVector<TYPE, 2> a(v1);\
	return v0 OP a;\
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S10, uint32_t S11, uint32_t S12>\
SimdSwizzle<TYPE, S00, S01, S02>& operator OP (SimdSwizzle<TYPE, S00, S01, S02>& v0, const SimdSwizzle<TYPE, S01, S11, S12>& v1) noexcept\
{\
	SimdVector<TYPE, 3> a(v0), b(v1);\
	a OP b;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00, uint32_t S01, uint32_t S02>\
SimdSwizzle<TYPE, S00, S01, S02>& operator OP (SimdSwizzle<TYPE, S00, S01, S02>& v0, const SimdVector<TYPE, 3>& v1) noexcept\
{\
	SimdVector<TYPE, 3> a(v0);\
	a OP v1;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00, uint32_t S01, uint32_t S02>\
SimdSwizzle<TYPE, S00, S01, S02>& operator OP (SimdSwizzle<TYPE, S00, S01, S02>& v0, const SimdVector<TYPE, 1>& v1) noexcept\
{\
	SimdVector<TYPE, 3> a(v0);\
	a OP v1;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S10>\
SimdSwizzle<TYPE, S00, S01, S02>& operator OP (SimdSwizzle<TYPE, S00, S01, S02>& v0, const SimdSwizzle<TYPE, S01>& v1) noexcept\
{\
	SimdVector<TYPE, 3> a(v0), b(v1);\
	a OP b;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00, uint32_t S01, uint32_t S02>\
SimdSwizzle<TYPE, S00, S01, S02>& operator OP (SimdSwizzle<TYPE, S00, S01, S02>& v0, TYPE v1) noexcept\
{\
	SimdVector<TYPE, 3> a(v0);\
	a OP v1;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00, uint32_t S01, uint32_t S02>\
SimdVector<TYPE, 3>& operator OP (SimdVector<TYPE, 3>& v0, const SimdSwizzle<TYPE, S00, S01, S02>& v1) noexcept\
{\
	SimdVector<TYPE, 3> a(v1);\
	return v0 OP a;\
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03, uint32_t S10, uint32_t S11, uint32_t S12, uint32_t S13>\
SimdSwizzle<TYPE, S00, S01, S02, S03>& operator OP (SimdSwizzle<TYPE, S00, S01, S02, S03>& v0, const SimdSwizzle<TYPE, S01, S11, S12, S03>& v1) noexcept\
{\
	SimdVector<TYPE, 4> a(v0), b(v1);\
	a OP b;\
	v0 = a;\
	return v0;\
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03>\
SimdSwizzle<TYPE, S00, S01, S02, S03>& operator OP (SimdSwizzle<TYPE, S00, S01, S02, S03>& v0, const SimdVector<TYPE, 4>& v1) noexcept\
{\
	SimdVector<TYPE, 4> a(v0); \
	a OP v1; \
	v0 = a; \
	return v0; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03>\
SimdSwizzle<TYPE, S00, S01, S02, S03>& operator OP (SimdSwizzle<TYPE, S00, S01, S02, S03>& v0, const SimdVector<TYPE, 1>& v1) noexcept\
{\
	SimdVector<TYPE, 4> a(v0); \
	a OP v1; \
	v0 = a; \
	return v0; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03, uint32_t S10>\
SimdSwizzle<TYPE, S00, S01, S02, S03>& operator OP (SimdSwizzle<TYPE, S00, S01, S02, S03>& v0, const SimdSwizzle<TYPE, S01>& v1) noexcept\
{\
	SimdVector<TYPE, 4> a(v0), b(v1); \
	a OP b; \
	v0 = a; \
	return v0; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03>\
SimdSwizzle<TYPE, S00, S01, S02, S03>& operator OP (SimdSwizzle<TYPE, S00, S01, S02, S03>& v0, TYPE v1) noexcept\
{\
	SimdVector<TYPE, 4> a(v0); \
	a OP v1; \
	v0 = a; \
	return v0; \
}\
template<uint32_t S00, uint32_t S01, uint32_t S02, uint32_t S03>\
SimdVector<TYPE, 4>& operator OP (SimdVector<TYPE, 4>& v0, const SimdSwizzle<TYPE, S00, S01, S02, S03>& v1) noexcept\
{\
	SimdVector<TYPE, 4> a(v1); \
	return v0 OP a; \
}\


namespace Math
{

/*************************************************************************************************************************************************/
// operator -V
	template<uint32_t Dim0>
	inline SimdVector<float, Dim0> operator-(const SimdVector<float, Dim0>& a) noexcept
	{
		SimdVector<float, Dim0> ret;
		ret.Packed = DirectX::XMVectorNegate(a.Packed);
		return ret;
	}

	template<uint32_t ...S>
	inline SimdVector<float, sizeof...(S)> operator-(const SimdSwizzle<float, S ...>& a) noexcept
	{
		SimdVector<float, sizeof...(S)> ret(a);
		ret.Packed = DirectX::XMVectorNegate(ret.Packed);
		return ret;
	}

// +
	template<uint32_t Dim0, uint32_t Dim1, std::enable_if_t<(Dim0 == Dim1 || Dim0 == 1 || Dim1 == 1), bool> = true, uint32_t RDim = std::max(Dim0, Dim1) >
	SimdVector<float, RDim> operator + (const SimdVector<float, Dim0>& v0, const SimdVector<float, Dim1>& v1) noexcept
	{
		SimdVector<float, RDim> ret;
		ret.Packed = DirectX::XMVectorAdd(v0.Packed, v1.Packed);
		return ret;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim> operator + (const SimdVector<float, Dim>& v0, const OthType& v1) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorAdd(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return ret;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim> operator + (const OthType& v1, const SimdVector<float, Dim>& v0) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorAdd(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return ret;
	}

// -
	template<uint32_t Dim0, uint32_t Dim1, std::enable_if_t<(Dim0 == Dim1 || Dim0 == 1 || Dim1 == 1), bool> = true, uint32_t RDim = std::max(Dim0, Dim1) >
	SimdVector<float, RDim> operator - (const SimdVector<float, Dim0>& v0, const SimdVector<float, Dim1>& v1) noexcept
	{
		SimdVector<float, RDim> ret;
		ret.Packed = DirectX::XMVectorSubtract(v0.Packed, v1.Packed);
		return ret;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim> operator - (const SimdVector<float, Dim>& v0, const OthType& v1) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorSubtract(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return ret;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim> operator - (const OthType& v1, const SimdVector<float, Dim>& v0) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorSubtract(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return ret;
	}

// *
	template<uint32_t Dim0, uint32_t Dim1, std::enable_if_t<(Dim0 == Dim1 || Dim0 == 1 || Dim1 == 1), bool> = true, uint32_t RDim = std::max(Dim0, Dim1) >
	SimdVector<float, RDim> operator * (const SimdVector<float, Dim0>& v0, const SimdVector<float, Dim1>& v1) noexcept
	{
		SimdVector<float, RDim> ret;
		ret.Packed = DirectX::XMVectorMultiply(v0.Packed, v1.Packed);
		return ret;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim> operator * (const SimdVector<float, Dim>& v0, const OthType& v1) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorMultiply(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return ret;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim> operator * (const OthType& v1, const SimdVector<float, Dim>& v0) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorMultiply(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return ret;
	}

// /
	template<uint32_t Dim0, uint32_t Dim1, std::enable_if_t<(Dim0 == Dim1 || Dim0 == 1 || Dim1 == 1), bool> = true, uint32_t RDim = std::max(Dim0, Dim1) >
	SimdVector<float, RDim> operator / (const SimdVector<float, Dim0>& v0, const SimdVector<float, Dim1>& v1) noexcept
	{
		SimdVector<float, RDim> ret;
		ret.Packed = DirectX::XMVectorDivide(v0.Packed, v1.Packed);
		return ret;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim> operator / (const SimdVector<float, Dim>& v0, const OthType& v1) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorDivide(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return ret;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim> operator / (const OthType& v1, const SimdVector<float, Dim>& v0) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorDivide(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return ret;
	}

// %
	template<uint32_t Dim0, uint32_t Dim1, std::enable_if_t<(Dim0 == Dim1 || Dim0 == 1 || Dim1 == 1), bool> = true, uint32_t RDim = std::max(Dim0, Dim1) >
	SimdVector<float, RDim> operator % (const SimdVector<float, Dim0>& v0, const SimdVector<float, Dim1>& v1) noexcept
	{
		SimdVector<float, RDim> ret;
		ret.Packed = DirectX::XMVectorMod(v0.Packed, v1.Packed);
		return ret;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim> operator % (const SimdVector<float, Dim>& v0, const OthType& v1) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorMod(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return ret;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim> operator % (const OthType& v1, const SimdVector<float, Dim>& v0) noexcept
	{
		SimdVector<float, Dim> ret;
		ret.Packed = DirectX::XMVectorMod(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return ret;
	}

	SIMDVector_Swizzle_BinaryOperator(float, +)
	SIMDVector_Swizzle_BinaryOperator(float, -)
	SIMDVector_Swizzle_BinaryOperator(float, *)
	SIMDVector_Swizzle_BinaryOperator(float, /)
	SIMDVector_Swizzle_BinaryOperator(float, %)

/*************************************************************************************************************************************************/
// +=
	template<uint32_t Dim0, uint32_t Dim1, std::enable_if_t<(Dim0 == Dim1 || Dim1 == 1), bool> = true >
	SimdVector<float, Dim0>& operator += (SimdVector<float, Dim0>& v0, const SimdVector<float, Dim1>& v1) noexcept
	{
		v0.Packed = DirectX::XMVectorAdd(v0.Packed, v1.Packed);
		return v0;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim>& operator += (SimdVector<float, Dim>& v0, const OthType& v1) noexcept
	{
		v0.Packed = DirectX::XMVectorAdd(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return v0;
	}

// -=
 	template<uint32_t Dim0, uint32_t Dim1, std::enable_if_t<(Dim0 == Dim1 || Dim1 == 1), bool> = true >
	SimdVector<float, Dim0>& operator -= (SimdVector<float, Dim0>& v0, const SimdVector<float, Dim1>& v1) noexcept
	{
		v0.Packed = DirectX::XMVectorSubtract(v0.Packed, v1.Packed);
		return v0;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim>& operator -= (SimdVector<float, Dim>& v0, const OthType& v1) noexcept
	{
		v0.Packed = DirectX::XMVectorSubtract(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return v0;
	}

// *=
	template<uint32_t Dim0, uint32_t Dim1, std::enable_if_t<(Dim0 == Dim1 || Dim1 == 1), bool> = true >
	SimdVector<float, Dim0>& operator *= (SimdVector<float, Dim0>& v0, const SimdVector<float, Dim1>& v1) noexcept
	{
		v0.Packed = DirectX::XMVectorMultiply(v0.Packed, v1.Packed);
		return v0;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim>& operator *= (SimdVector<float, Dim>& v0, const OthType& v1) noexcept
	{
		v0.Packed = DirectX::XMVectorMultiply(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return v0;
	}

// /=
	template<uint32_t Dim0, uint32_t Dim1, std::enable_if_t<(Dim0 == Dim1 || Dim1 == 1), bool> = true >
	SimdVector<float, Dim0>& operator /= (SimdVector<float, Dim0>& v0, const SimdVector<float, Dim1>& v1) noexcept
	{
		v0.Packed = DirectX::XMVectorDivide(v0.Packed, v1.Packed);
		return v0;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim>& operator /= (SimdVector<float, Dim>& v0, const OthType& v1) noexcept
	{
		v0.Packed = DirectX::XMVectorDivide(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return v0;
	}

// %=
	template<uint32_t Dim0, uint32_t Dim1, std::enable_if_t<(Dim0 == Dim1 || Dim1 == 1), bool> = true >
	SimdVector<float, Dim0>& operator %= (SimdVector<float, Dim0>& v0, const SimdVector<float, Dim1>& v1) noexcept
	{
		v0.Packed = DirectX::XMVectorMod(v0.Packed, v1.Packed);
		return v0;
	}

	template<uint32_t Dim, typename OthType, std::enable_if_t<std::is_convertible<OthType, float>::value, bool> = true >
	SimdVector<float, Dim>& operator %= (SimdVector<float, Dim>& v0, const OthType& v1) noexcept
	{
		v0.Packed = DirectX::XMVectorMod(v0.Packed, DirectX::XMVectorReplicate((float)v1));
		return v0;
	}

	SIMDVector_Swizzle_SelfOperator(float, +=)
	SIMDVector_Swizzle_SelfOperator(float, -=)
	SIMDVector_Swizzle_SelfOperator(float, *=)
	SIMDVector_Swizzle_SelfOperator(float, /=)
	SIMDVector_Swizzle_SelfOperator(float, %=)


/*************************************************************************************************************************************************/
// ++v
	template<uint32_t Dim>
	inline SimdVector<float, Dim>& operator++(SimdVector<float, Dim>& a) noexcept
	{
		a.Packed = DirectX::XMVectorAdd(a.Packed, DirectX::XMVectorSplatOne());
		return a;
	}

// --v
	template<uint32_t Dim>
	inline SimdVector<float, Dim>& operator--(SimdVector<float, Dim>& a) noexcept
	{
		a.Packed = DirectX::XMVectorSubtract(a.Packed, DirectX::XMVectorSplatOne());
		return a;
	}

// v++
	template<uint32_t Dim>
	inline SimdVector<float, Dim> operator++(SimdVector<float, Dim>& a, int) noexcept
	{
		SimdVector<float, Dim> ret = a;
		a.Packed = DirectX::XMVectorAdd(a.Packed, DirectX::XMVectorSplatOne());
		return ret;
	}

// v--
	template<uint32_t Dim>
	inline SimdVector<float, Dim> operator--(SimdVector<float, Dim>& a, int) noexcept
	{
		SimdVector<float, Dim> ret = a;
		a.Packed = DirectX::XMVectorSubtract(a.Packed, DirectX::XMVectorSplatOne());
		return ret;
	}
}