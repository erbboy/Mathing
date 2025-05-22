//#pragma once

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
*   normalize - float
*   reflect - float
*   refract - float
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
*   inverse
* 
* Transform
*   Translation
*   Rotation
*   Scale
*   Decompose
*   View
*   Project
*/


/* ------------- From C and Oth -------------
*  copysign - float
*  NextPowof2 - uint
*  ClosestPowof2 - uint
*  IsPowof2
*/

#define Vector2Math1To1(T, func) inline MathVector<T, 2> func(MathVector<T, 2> v) noexcept\
{\
    MathVector<T, 2> ret; \
    ret.x = func(v.x); \
    ret.y = func(v.y); \
    return ret; \
}\

#define Vector3Math1To1(T, func) inline MathVector<T, 3> func(MathVector<T, 3> v) noexcept\
{\
    MathVector<T, 3> ret; \
    ret.x = func(v.x); \
    ret.y = func(v.y); \
    ret.z = func(v.z); \
    return ret; \
}\

#define Vector4Math1To1(T, func) inline MathVector<T, 4> func(MathVector<T, 4> v) noexcept\
{\
    MathVector<T, 4> ret; \
    ret.x = func(v.x); \
    ret.y = func(v.y); \
    ret.z = func(v.z); \
    ret.w = func(v.w); \
    return ret; \
}\

#define Vector2Math1To1_FULL(T, T0, func) inline MathVector<T, 2> func(MathVector<T0, 2> v) noexcept\
{\
    MathVector<T, 2> ret; \
    ret.x = func(v.x); \
    ret.y = func(v.y); \
    return ret; \
}\

#define Vector3Math1To1_FULL(T, T0, func) inline MathVector<T, 3> func(MathVector<T0, 3> v) noexcept\
{\
    MathVector<T, 3> ret; \
    ret.x = func(v.x); \
    ret.y = func(v.y); \
    ret.z = func(v.z); \
    return ret; \
}\

#define Vector4Math1To1_FULL(T, T0, func) inline MathVector<T, 4> func(MathVector<T0, 4> v) noexcept\
{\
    MathVector<T, 4> ret; \
    ret.x = func(v.x); \
    ret.y = func(v.y); \
    ret.z = func(v.z); \
    ret.w = func(v.w); \
    return ret; \
}\

#define Vector2Math2To1(T, func) inline MathVector<T, 2> func(MathVector<T, 2> a, MathVector<T, 2> b) noexcept\
{\
    MathVector<T, 2> ret; \
    ret.x = func(a.x, b.x); \
    ret.y = func(a.y, b.y); \
    return ret; \
}\

#define Vector3Math2To1(T, func) inline MathVector<T, 3> func(MathVector<T, 3> a, MathVector<T, 3> b) noexcept\
{\
    MathVector<T, 3> ret; \
    ret.x = func(a.x, b.x); \
    ret.y = func(a.y, b.y); \
    ret.z = func(a.z, b.z); \
    return ret; \
}\

#define Vector4Math2To1(T, func) inline MathVector<T, 4> func(MathVector<T, 4> a, MathVector<T, 4> b) noexcept\
{\
    MathVector<T, 4> ret; \
    ret.x = func(a.x, b.x); \
    ret.y = func(a.y, b.y); \
    ret.z = func(a.z, b.z); \
    ret.w = func(a.w, b.w); \
    return ret; \
}\

#define Vector2Math2To1_FULL(T, T0, T1, func) inline MathVector<T, 2> func(MathVector<T0, 2> a, MathVector<T1, 2>& b) noexcept\
{\
    MathVector<T, 2> ret; \
    ret.x = func(a.x, b.x); \
    ret.y = func(a.y, b.y); \
    return ret; \
}\

#define Vector3Math2To1_FULL(T, T0, T1, func) inline MathVector<T, 3> func(MathVector<T0, 3> a, MathVector<T1, 3>& b) noexcept\
{\
    MathVector<T, 3> ret; \
    ret.x = func(a.x, b.x); \
    ret.y = func(a.y, b.y); \
    ret.z = func(a.z, b.z); \
    return ret; \
}\

#define Vector4Math2To1_FULL(T, T0, T1, func) inline MathVector<T, 4> func(MathVector<T0, 4> a, MathVector<T1, 4>& b) noexcept\
{\
    MathVector<T, 4> ret; \
    ret.x = func(a.x, b.x); \
    ret.y = func(a.y, b.y); \
    ret.z = func(a.z, b.z); \
    ret.w = func(a.w, b.w); \
    return ret; \
}\

#define Vector2Math3To1(T, func) inline MathVector<T, 2> func(MathVector<T, 2> a, MathVector<T, 2> b, MathVector<T, 2> c) noexcept\
{\
    MathVector<T, 2> ret; \
    ret.x = func(a.x, b.x, c.x); \
    ret.y = func(a.y, b.y, c.y); \
    return ret; \
}\

#define Vector3Math3To1(T, func) inline MathVector<T, 3> func(MathVector<T, 3> a, MathVector<T, 3> b, MathVector<T, 3> c) noexcept\
{\
    MathVector<T, 3> ret; \
    ret.x = func(a.x, b.x, c.x); \
    ret.y = func(a.y, b.y, c.y); \
    ret.z = func(a.z, b.z, c.z); \
    return ret; \
}\

#define Vector4Math3To1(T, func) inline MathVector<T, 4> func(MathVector<T, 4> a, MathVector<T, 4> b, MathVector<T, 4> c) noexcept\
{\
    MathVector<T, 4> ret; \
    ret.x = func(a.x, b.x, c.x); \
    ret.y = func(a.y, b.y, c.y); \
    ret.z = func(a.z, b.z, c.z); \
    ret.w = func(a.w, b.w, c.w); \
    return ret; \
}\

namespace Math
{
// abs
inline Float Abs(Float val) noexcept 
{
    return fabsf(val);
}
Vector2Math1To1(Float, Abs);
Vector3Math1To1(Float, Abs);
Vector4Math1To1(Float, Abs);

inline Double Abs(Double val) noexcept
{
    return fabs(val);
}
Vector2Math1To1(Double, Abs);
Vector3Math1To1(Double, Abs);
Vector4Math1To1(Double, Abs);


// ceil
inline Float Ceil(Float val) noexcept
{
    return ceilf(val);
}
Vector2Math1To1(float, Ceil)
Vector3Math1To1(float, Ceil)
Vector4Math1To1(float, Ceil)

inline Double Ceil(Double val) noexcept
{
    return ceil(val);
}
Vector2Math1To1(double, Ceil)
Vector3Math1To1(double, Ceil)
Vector4Math1To1(double, Ceil)

// min
template<typename T>
inline T Min(T a, T b) noexcept
{
    return a < b ? a : b;
}
template<typename T>
Vector2Math2To1(T, Min)
template<typename T>
Vector3Math2To1(T, Min)
template<typename T>
Vector4Math2To1(T, Min)

// max 
template<typename T>
inline T Max(T a, T b) noexcept
{
    return a > b ? a : b;
}
template<typename T>
Vector2Math2To1(T, Max)
template<typename T>
Vector3Math2To1(T, Max)
template<typename T>
Vector4Math2To1(T, Max)

// clamp
template<typename T>
inline T Clamp(T v, T clampMin, T clampMax) noexcept
{
    T ret;
    ret = Max(clampMin, v);
    ret = Min(clampMax, ret);
    return ret;
}
template<typename T>
Vector2Math3To1(T, Clamp)
template<typename T>
Vector3Math3To1(T, Clamp)
template<typename T>
Vector4Math3To1(T, Clamp)

// exp
inline Float Exp(Float val) noexcept
{
    return expf(val);
}
Vector2Math1To1(Float, Exp);
Vector3Math1To1(Float, Exp);
Vector4Math1To1(Float, Exp);

inline Double Exp(Double val) noexcept
{
    return exp(val);
}
Vector2Math1To1(Double, Exp);
Vector3Math1To1(Double, Exp);
Vector4Math1To1(Double, Exp);

// exp2
inline Float Exp2(Float val) noexcept
{
    return exp2f(val);
}
Vector2Math1To1(Float, Exp2);
Vector3Math1To1(Float, Exp2);
Vector4Math1To1(Float, Exp2);

inline Double Exp2(Double val) noexcept
{
    return exp2(val);
}
Vector2Math1To1(Double, Exp2);
Vector3Math1To1(Double, Exp2);
Vector4Math1To1(Double, Exp2);

// floor
inline Float Floor(Float val) noexcept
{
    return floorf(val);
}
Vector2Math1To1(Float, Floor);
Vector3Math1To1(Float, Floor);
Vector4Math1To1(Float, Floor);

inline Double Floor(Double val) noexcept
{
    return floor(val);
}
Vector2Math1To1(Double, Floor);
Vector3Math1To1(Double, Floor);
Vector4Math1To1(Double, Floor);

// fmod
inline Float Fmod(Float x, Float y) noexcept
{
    return fmodf(x, y);
}
Vector2Math2To1(Float, Fmod);
Vector3Math2To1(Float, Fmod);
Vector4Math2To1(Float, Fmod);

inline Double Fmod(Double x, Double y) noexcept
{
    return fmod(x, y);
}
Vector2Math2To1(Double, Fmod);
Vector3Math2To1(Double, Fmod);
Vector4Math2To1(Double, Fmod);

// frac 
// Note: frac(-0.9) = 0.1
inline Float Frac(Float val) noexcept
{
    return val - floorf(val);
}
Vector2Math1To1(Float, Frac);
Vector3Math1To1(Float, Frac);
Vector4Math1To1(Float, Frac);

inline Double Frac(Double val) noexcept
{
    return val - floor(val);
}
Vector2Math1To1(Double, Frac);
Vector3Math1To1(Double, Frac);
Vector4Math1To1(Double, Frac);

// frexp
inline Float Frexp(Float val, Int& E) noexcept
{
    int e;
    float ret = frexpf(val, &e);
    E = (Int)e;
    return ret;
}
Vector2Math2To1_FULL(Float, Float, Int, Frexp);
Vector3Math2To1_FULL(Float, Float, Int, Frexp);
Vector4Math2To1_FULL(Float, Float, Int, Frexp);

inline Double Frexp(Double val, Long& E) noexcept
{
    int e;
    double ret = frexp(val, &e);
    E = e;
    return ret;
}
Vector2Math2To1_FULL(Double, Double, Long, Frexp);
Vector3Math2To1_FULL(Double, Double, Long, Frexp);
Vector4Math2To1_FULL(Double, Double, Long, Frexp);

// isfinite 
inline Bool IsFinite(Float val)
{
    return isfinite(val);
}
Vector2Math1To1_FULL(Bool, Float, IsFinite);
Vector3Math1To1_FULL(Bool, Float, IsFinite);
Vector4Math1To1_FULL(Bool, Float, IsFinite);

inline Bool IsFinite(Double val) noexcept
{
    return isfinite(val);
}
Vector2Math1To1_FULL(Bool, Double, IsFinite);
Vector3Math1To1_FULL(Bool, Double, IsFinite);
Vector4Math1To1_FULL(Bool, Double, IsFinite);

// isinf 
inline Bool IsInf(Float val) noexcept
{
    return isinf(val);
}
Vector2Math1To1_FULL(Bool, Float, IsInf);
Vector3Math1To1_FULL(Bool, Float, IsInf);
Vector4Math1To1_FULL(Bool, Float, IsInf);

inline Bool IsInf(Double val) noexcept
{
    return isinf(val);
}
Vector2Math1To1_FULL(Bool, Double, IsInf);
Vector3Math1To1_FULL(Bool, Double, IsInf);
Vector4Math1To1_FULL(Bool, Double, IsInf);

// isnan 
inline Bool IsNan(Float val) noexcept
{
    return isnan(val);
}
Vector2Math1To1_FULL(Bool, Float, IsNan);
Vector3Math1To1_FULL(Bool, Float, IsNan);
Vector4Math1To1_FULL(Bool, Float, IsNan);

inline Bool IsNan(Double val) noexcept
{
    return isnan(val);
}
Vector2Math1To1_FULL(Bool, Double, IsNan);
Vector3Math1To1_FULL(Bool, Double, IsNan);
Vector4Math1To1_FULL(Bool, Double, IsNan);

// log 
inline Float Log(Float val) noexcept
{
    return logf(val);
}
Vector2Math1To1(Float, Log);
Vector3Math1To1(Float, Log);
Vector4Math1To1(Float, Log);

inline Double Log(Double val) noexcept
{
    return log(val);
}
Vector2Math1To1(Double, Log);
Vector3Math1To1(Double, Log);
Vector4Math1To1(Double, Log);

// log10 
inline Float Log10(Float val) noexcept
{
    return log10f(val);
}
Vector2Math1To1(Float, Log10);
Vector3Math1To1(Float, Log10);
Vector4Math1To1(Float, Log10);

inline Double Log10(Double val) noexcept
{
    return log10(val);
}
Vector2Math1To1(Double, Log10);
Vector3Math1To1(Double, Log10);
Vector4Math1To1(Double, Log10);

// log2 
inline Float Log2(Float val) noexcept
{
    return log2f(val);
}
Vector2Math1To1(Float, Log2);
Vector3Math1To1(Float, Log2);
Vector4Math1To1(Float, Log2);

inline Double Log2(Double val) noexcept
{
    return log2(val);
}
Vector2Math1To1(Double, Log2);
Vector3Math1To1(Double, Log2);
Vector4Math1To1(Double, Log2);

// mad
// x * a + b
template<typename T>
inline T Mad(T x, T a, T b) noexcept
{
    return  x * a + b;
}
template<typename T>
Vector2Math3To1(T, Mad);
template<typename T>
Vector3Math3To1(T, Mad);
template<typename T>
Vector4Math3To1(T, Mad);

// modf 
inline Float Modf(Float val, Float& I) noexcept
{
    return modff(val, &I);
}
Vector2Math2To1_FULL(Float, Float, Float, Modf);
Vector3Math2To1_FULL(Float, Float, Float, Modf);
Vector4Math2To1_FULL(Float, Float, Float, Modf);

inline Double Modf(Double val, Double& I) noexcept
{
    return modf(val, &I);
}
Vector2Math2To1_FULL(Double, Double, Double, Modf);
Vector3Math2To1_FULL(Double, Double, Double, Modf);
Vector4Math2To1_FULL(Double, Double, Double, Modf);

// pow
inline Float Pow(Float x, Float y) noexcept
{
    return powf(x, y);
}
Vector2Math2To1(Float, Pow);
Vector3Math2To1(Float, Pow);
Vector4Math2To1(Float, Pow);

inline Double Pow(Double x, Double y) noexcept
{
    return pow(x, y);
}
Vector2Math2To1(Double, Pow);
Vector3Math2To1(Double, Pow);
Vector4Math2To1(Double, Pow);

// rcp
inline Float Rcp(Float val) noexcept
{
    return 1.0f / val;
}
Vector2Math1To1(Float, Rcp);
Vector3Math1To1(Float, Rcp);
Vector4Math1To1(Float, Rcp);

inline Double Rcp(Double val) noexcept
{
    return 1.0 / val;
}
Vector2Math1To1(Double, Rcp);
Vector3Math1To1(Double, Rcp);
Vector4Math1To1(Double, Rcp);

// round
inline Float Round(Float val) noexcept
{
    return roundf(val);
}
Vector2Math1To1(Float, Round);
Vector3Math1To1(Float, Round);
Vector4Math1To1(Float, Round);

inline Double Round(Double val) noexcept
{
    return round(val);
}
Vector2Math1To1(Double, Round);
Vector3Math1To1(Double, Round);
Vector4Math1To1(Double, Round);

// rsqrt
inline Float RSqrt(Float val) noexcept
{
    return 1.0f / sqrtf(val);
}
Vector2Math1To1(Float, RSqrt);
Vector3Math1To1(Float, RSqrt);
Vector4Math1To1(Float, RSqrt);

inline Double RSqrt(Double val) noexcept
{
    return 1.0 / sqrt(val);
}
Vector2Math1To1(Double, RSqrt);
Vector3Math1To1(Double, RSqrt);
Vector4Math1To1(Double, RSqrt);

// saturate
// x * a + b
template<typename T>
inline T Saturate(T x) noexcept
{
    return Clamp(x, 0, 1);
}
template<typename T>
Vector2Math1To1(T, Saturate);
template<typename T>
Vector3Math1To1(T, Saturate);
template<typename T>
Vector4Math1To1(T, Saturate);

// sign
inline Float Sign(Float val) noexcept
{
    return val == 0 ? 0 : (std::signbit(val) ? 1.0f : -1.0f);
}
Vector2Math1To1(Float, Sign);
Vector3Math1To1(Float, Sign);
Vector4Math1To1(Float, Sign);

inline Double Sign(Double val) noexcept
{
    return val == 0 ? 0 : (std::signbit(val) ? 1.0 : -1.0);
}
Vector2Math1To1(Double, Sign);
Vector3Math1To1(Double, Sign);
Vector4Math1To1(Double, Sign);

// copysign
inline Float CopySign(Float x, Float s) noexcept
{
    return copysignf(x, s);
}
Vector2Math2To1(Float, CopySign);
Vector3Math2To1(Float, CopySign);
Vector4Math2To1(Float, CopySign);

inline Double CopySign(Double x, Double s) noexcept
{
    return copysign(x, s);
}
Vector2Math2To1(Double, CopySign);
Vector3Math2To1(Double, CopySign);
Vector4Math2To1(Double, CopySign);

// sqrt
inline Float Sqrt(Float val) noexcept
{
    return sqrtf(val);
}
Vector2Math1To1(Float, Sqrt);
Vector3Math1To1(Float, Sqrt);
Vector4Math1To1(Float, Sqrt);

inline Double Sqrt(Double val)
{
    return sqrt(val);
}
Vector2Math1To1(Double, Sqrt);
Vector3Math1To1(Double, Sqrt);
Vector4Math1To1(Double, Sqrt);

// step
inline Float Step(Float y, Float x) noexcept
{
    return (x >= y) ? 1.0f : 0.0f;
}
Vector2Math2To1(Float, Step);
Vector3Math2To1(Float, Step);
Vector4Math2To1(Float, Step);

inline Double Step(Double y, Double x) noexcept
{
    return (x >= y) ? 1.0 : 0.0;
}
Vector2Math2To1(Double, Step);
Vector3Math2To1(Double, Step);
Vector4Math2To1(Double, Step);

// trunc
inline Float Trunc(Float val) noexcept
{
    return truncf(val);
}
Vector2Math1To1(Float, Trunc);
Vector3Math1To1(Float, Trunc);
Vector4Math1To1(Float, Trunc);

inline Double Trunc(Double val) noexcept
{
    return trunc(val);
}
Vector2Math1To1(Double, Trunc);
Vector3Math1To1(Double, Trunc);
Vector4Math1To1(Double, Trunc);

// acos
inline Float Acos(Float val) noexcept
{
    return acosf(val);
}
Vector2Math1To1(Float, Acos);
Vector3Math1To1(Float, Acos);
Vector4Math1To1(Float, Acos);

inline Double Acos(Double val) noexcept
{
    return acos(val);
}
Vector2Math1To1(Double, Acos);
Vector3Math1To1(Double, Acos);
Vector4Math1To1(Double, Acos);

// asin
inline Float Asin(Float val) noexcept
{
    return asinf(val);
}
Vector2Math1To1(Float, Asin);
Vector3Math1To1(Float, Asin);
Vector4Math1To1(Float, Asin);

inline Double Asin(Double val) noexcept
{
    return asin(val);
}
Vector2Math1To1(Double, Asin);
Vector3Math1To1(Double, Asin);
Vector4Math1To1(Double, Asin);

// atan
inline Float Atan(Float val) noexcept
{
    return atanf(val);
}
Vector2Math1To1(Float, Atan);
Vector3Math1To1(Float, Atan);
Vector4Math1To1(Float, Atan);

inline Double Atan(Double val) noexcept
{
    return atan(val);
}
Vector2Math1To1(Double, Atan);
Vector3Math1To1(Double, Atan);
Vector4Math1To1(Double, Atan);

// atan2
inline Float Atan2(Float y, Float x) noexcept
{
    return atan2f(y, x);
}
Vector2Math2To1(Float, Atan2);
Vector3Math2To1(Float, Atan2);
Vector4Math2To1(Float, Atan2);

inline Double Atan2(Double y, Double x) noexcept
{
    return atan2(y, x);
}
Vector2Math2To1(Double, Atan2);
Vector3Math2To1(Double, Atan2);
Vector4Math2To1(Double, Atan2);

// cos
inline Float Cos(Float val) noexcept
{
    return cosf(val);
}
Vector2Math1To1(Float, Cos);
Vector3Math1To1(Float, Cos);
Vector4Math1To1(Float, Cos);

inline Double Cos(Double val) noexcept
{
    return cos(val);
}
Vector2Math1To1(Double, Cos);
Vector3Math1To1(Double, Cos);
Vector4Math1To1(Double, Cos);

// cosh
inline Float Cosh(Float val) noexcept
{
    return coshf(val);
}
Vector2Math1To1(Float, Cosh);
Vector3Math1To1(Float, Cosh);
Vector4Math1To1(Float, Cosh);

inline Double Cosh(Double val) noexcept
{
    return cosh(val);
}
Vector2Math1To1(Double, Cosh);
Vector3Math1To1(Double, Cosh);
Vector4Math1To1(Double, Cosh);

// degrees
inline Float Degrees(Float val) noexcept
{
    return val * (180.0f / M_PI);
}
Vector2Math1To1(Float, Degrees);
Vector3Math1To1(Float, Degrees);
Vector4Math1To1(Float, Degrees);

inline Double Degrees(Double val) noexcept
{
    return val * (180.0f / M_PI);
}
Vector2Math1To1(Double, Degrees);
Vector3Math1To1(Double, Degrees);
Vector4Math1To1(Double, Degrees);

// radians
inline Float Radians(Float val) noexcept
{
    return val * (M_PI / 180.0f);
}
Vector2Math1To1(Float, Radians);
Vector3Math1To1(Float, Radians);
Vector4Math1To1(Float, Radians);

inline Double Radians(Double val) noexcept
{
    return val * (M_PI / 180.0f);
}
Vector2Math1To1(Double, Radians);
Vector3Math1To1(Double, Radians);
Vector4Math1To1(Double, Radians);

// sin
inline Float Sin(Float val) noexcept
{
    return sinf(val);
}
Vector2Math1To1(Float, Sin);
Vector3Math1To1(Float, Sin);
Vector4Math1To1(Float, Sin);

inline Double Sin(Double val) noexcept
{
    return sin(val);
}
Vector2Math1To1(Double, Sin);
Vector3Math1To1(Double, Sin);
Vector4Math1To1(Double, Sin);

// sincos
inline void SinCos(Float val, Float& x, Float& y) noexcept
{
    x = sinf(val); y = cosf(val);
}
inline void SinCos(Float2 a, Float2& s, Float2& c) noexcept
{
    SinCos(a.x, s.x, c.x);
    SinCos(a.y, s.y, c.y);
}
inline void SinCos(Float3 a, Float3& s, Float3& c) noexcept
{
    SinCos(a.x, s.x, c.x);
    SinCos(a.y, s.y, c.y);
    SinCos(a.z, s.z, c.z);
}
inline void SinCos(Float4 a, Float4& s, Float4& c) noexcept
{
    SinCos(a.x, s.x, c.x);
    SinCos(a.y, s.y, c.y);
    SinCos(a.z, s.z, c.z);
    SinCos(a.w, s.w, c.w);
}

inline void SinCos(Double val, Double& x, Double& y) noexcept
{
    x = sin(val); y = cos(val);
}
inline void SinCos(Double2 a, Double2& s, Double2& c) noexcept
{
    SinCos(a.x, s.x, c.x);
    SinCos(a.y, s.y, c.y);
}
inline void SinCos(Double3 a, Double3& s, Double3& c) noexcept
{
    SinCos(a.x, s.x, c.x);
    SinCos(a.y, s.y, c.y);
    SinCos(a.z, s.z, c.z);
}
inline void SinCos(Double4 a, Double4& s, Double4& c) noexcept
{
    SinCos(a.x, s.x, c.x);
    SinCos(a.y, s.y, c.y);
    SinCos(a.z, s.z, c.z);
    SinCos(a.w, s.w, c.w);
}

// sinh
inline Float Sinh(Float val) noexcept
{
    return sinhf(val);
}
Vector2Math1To1(Float, Sinh);
Vector3Math1To1(Float, Sinh);
Vector4Math1To1(Float, Sinh);

inline Double Sinh(Double val) noexcept
{
    return sinh(val);
}
Vector2Math1To1(Double, Sinh);
Vector3Math1To1(Double, Sinh);
Vector4Math1To1(Double, Sinh);

// tan
inline Float Tan(Float val) noexcept
{
    return tanf(val);
}
Vector2Math1To1(Float, Tan);
Vector3Math1To1(Float, Tan);
Vector4Math1To1(Float, Tan);

inline Double Tan(Double val) noexcept
{
    return tan(val);
}
Vector2Math1To1(Double, Tan);
Vector3Math1To1(Double, Tan);
Vector4Math1To1(Double, Tan);

// tanh
inline Float Tanh(Float val) noexcept
{
    return tanhf(val);
}
Vector2Math1To1(Float, Tanh);
Vector3Math1To1(Float, Tanh);
Vector4Math1To1(Float, Tanh);

inline Double Tanh(Double val) noexcept
{
    return tanh(val);
}
Vector2Math1To1(Double, Tanh);
Vector3Math1To1(Double, Tanh);
Vector4Math1To1(Double, Tanh);

// all
template<typename T>
inline bool All(T val) noexcept
{
    return val != 0;
}
template<typename T>
inline bool All(MathVector<T, 2> v) noexcept
{
    return v.x != 0 && v.y != 0;
}
template<typename T>
inline bool All(MathVector<T, 3> v) noexcept
{
    return v.x != 0 && v.y != 0 && v.z != 0;
}
template<typename T>
inline bool All(MathVector<T, 4> v) noexcept
{
    return v.x != 0 && v.y != 0 && v.z != 0 && v.w != 0;
}

// any
template<typename T>
inline bool Any(T val) noexcept
{
    return val != 0;
}
template<typename T>
inline bool Any(MathVector<T, 2> v) noexcept
{
    return v.x != 0 || v.y != 0;
}
template<typename T>
inline bool Any(MathVector<T, 3> v) noexcept
{
    return v.x != 0 || v.y != 0 || v.z != 0;
}
template<typename T>
inline bool Any(MathVector<T, 4> v) noexcept
{
    return v.x != 0 || v.y != 0 || v.z != 0 || v.w != 0;
}


// f16tof32
inline Float F16toF32(Half val) noexcept
{
    return float(val);
}
Vector2Math1To1_FULL(Float, Half, F16toF32);
Vector3Math1To1_FULL(Float, Half, F16toF32);
Vector4Math1To1_FULL(Float, Half, F16toF32);

// f32tof16
inline Half F16toF32(Float val) noexcept
{
    return Half(val);
}
Vector2Math1To1_FULL(Half, Float, F16toF32);
Vector3Math1To1_FULL(Half, Float, F16toF32);
Vector4Math1To1_FULL(Half, Float, F16toF32);

// asdouble - uint lowbits, uint highbits
inline Double AsDouble(UInt low, UInt high) noexcept
{
    Long D = (Long)low & ((Long)high << 32);
    return *((Double*)(& D));
}

// asdouble - long bits
inline Double AsDouble(ULong d) noexcept
{
    return *((Double*)(&d));
}
Vector2Math1To1_FULL(Double, ULong, AsDouble);
Vector3Math1To1_FULL(Double, ULong, AsDouble);
Vector4Math1To1_FULL(Double, ULong, AsDouble);

// asfloat 
inline Float AsFloat(UInt d) noexcept
{
    return *((Float*)(&d));
}
Vector2Math1To1_FULL(Float, UInt, AsFloat);
Vector3Math1To1_FULL(Float, UInt, AsFloat);
Vector4Math1To1_FULL(Float, UInt, AsFloat);

inline Float AsFloat(Int d) noexcept
{
    return *((Float*)(&d));
}
Vector2Math1To1_FULL(Float, Int, AsFloat);
Vector3Math1To1_FULL(Float, Int, AsFloat);
Vector4Math1To1_FULL(Float, Int, AsFloat);

// asint
inline Int AsInt(UInt d) noexcept
{
    return *((Int*)(&d));
}
Vector2Math1To1_FULL(Int, UInt, AsInt);
Vector3Math1To1_FULL(Int, UInt, AsInt);
Vector4Math1To1_FULL(Int, UInt, AsInt);

inline Int AsInt(Float d) noexcept
{
    return *((Int*)(&d));
}
Vector2Math1To1_FULL(Int, Float, AsInt);
Vector3Math1To1_FULL(Int, Float, AsInt);
Vector4Math1To1_FULL(Int, Float, AsInt);

// asuint
inline UInt AsUInt(Int d) noexcept
{
    return *((UInt*)(&d));
}
Vector2Math1To1_FULL(UInt, Int, AsUInt);
Vector3Math1To1_FULL(UInt, Int, AsUInt);
Vector4Math1To1_FULL(UInt, Int, AsUInt);

inline UInt AsUInt(Float d) noexcept
{
    return *((UInt*)(&d));
}
Vector2Math1To1_FULL(UInt, Float, AsUInt);
Vector3Math1To1_FULL(UInt, Float, AsUInt);
Vector4Math1To1_FULL(UInt, Float, AsUInt);

// asuint - double, uint, uint
void AsUInt(Double d, UInt& low, UInt& high) noexcept
{
    Long L = *((Long*)(&d));
    high = L >> 32;
    low = (L << 32) >> 32;
}

// countbits - uint
UInt CountBits(UInt v) noexcept
{
    // From http://www-graphics.stanford.edu/~seander/bithacks.html#CountBitsSetParallel
    v = v - ((v >> 1) & 0x55555555);
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
    return (((v + (v >> 4)) & 0xF0F0F0F) * 0x1010101) >> 24;
}
Vector2Math1To1(UInt, CountBits);
Vector3Math1To1(UInt, CountBits);
Vector4Math1To1(UInt, CountBits);

ULong CountBits(ULong v) noexcept
{
    // From http://www-graphics.stanford.edu/~seander/bithacks.html#CountBitsSetParallel
    v = v - ((v >> 1) & (uint64_t)~(uint64_t)0 / 3);
    v = (v & (uint64_t)~(uint64_t)0 / 15 * 3) + ((v >> 2) & (uint64_t)~(uint64_t)0 / 15 * 3);
    v = (v + (v >> 4)) & (uint64_t)~(uint64_t)0 / 255 * 15;
    return (uint64_t)(v * ((uint64_t)~(uint64_t)0 / 255)) >> (sizeof(uint64_t) - 1) * CHAR_BIT;
}
Vector2Math1To1(ULong, CountBits);
Vector3Math1To1(ULong, CountBits);
Vector4Math1To1(ULong, CountBits);

// firstbithigh - int
constexpr signed char gHighestBitLut[] = { -1, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3 };
Int FirstBitHigh(UInt v) noexcept
{
    if (v == 0)
        return -1;
    Int base = 0;

    if (v & 0xffff0000)
    {
        base = 16;
        v >>= 16;
    }
    if (v & 0x0000ff00)
    {
        base += 8;
        v >>= 8;
    }
    if (v & 0x000000f0)
    {
        base += 4;
        v >>= 4;
    }

    return base + gHighestBitLut[v];
}
Vector2Math1To1_FULL(Int, UInt, FirstBitHigh);
Vector3Math1To1_FULL(Int, UInt, FirstBitHigh);
Vector4Math1To1_FULL(Int, UInt, FirstBitHigh);

Int FirstBitHigh(ULong v) noexcept
{
    if (v == 0)
        return -1;

    if (v & 0xffffffff00000000ULL)
    {
        return 32 + FirstBitHigh((UInt)(v >> 32));
    }
    return FirstBitHigh((UInt)v);
}
Vector2Math1To1_FULL(Int, ULong, FirstBitHigh);
Vector3Math1To1_FULL(Int, ULong, FirstBitHigh);
Vector4Math1To1_FULL(Int, ULong, FirstBitHigh);

// firstbitlow - int
constexpr signed char gLowestBitLut[] = { -1, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0 };
inline Int LowestBit8(uint8_t mask) noexcept
{
    Int base = 0;
    if ((mask & 0x000f) == 0)
    {
        base += 4;
        mask >>= 4;
    }
    return base + gLowestBitLut[mask & 15];
}

Int FirstBitLow(UInt v) noexcept
{
    if (v == 0)
        return -1;

    int base = 0;

    if ((v & 0xffff) == 0)
    {
        base = 16;
        v >>= 16;
    }
    if ((v & 0x00ff) == 0)
    {
        base += 8;
        v >>= 8;
    }
    return base + LowestBit8((uint8_t)v);
}
Vector2Math1To1_FULL(Int, UInt, FirstBitLow);
Vector3Math1To1_FULL(Int, UInt, FirstBitLow);
Vector4Math1To1_FULL(Int, UInt, FirstBitLow);

Int FirstBitLow(ULong v) noexcept
{
    if (v == 0)
        return -1;

    int base = 0;
    if ((v & 0xffffffff) == 0)
    {
        base += 32;
        v >>= 32;
    }
    return base + FirstBitLow((UInt)v);
}
Vector2Math1To1_FULL(Int, ULong, FirstBitLow);
Vector3Math1To1_FULL(Int, ULong, FirstBitLow);
Vector4Math1To1_FULL(Int, ULong, FirstBitLow);

// reversebits - uint
UInt ReverseBits(UInt v) noexcept
{
    uint32_t mask = v;
    mask = ((mask >> 1) & 0x55555555) | ((mask << 1) & 0xaaaaaaaa);
    mask = ((mask >> 2) & 0x33333333) | ((mask << 2) & 0xcccccccc);
    mask = ((mask >> 4) & 0x0f0f0f0f) | ((mask << 4) & 0xf0f0f0f0);
    mask = ((mask >> 8) & 0x00ff00ff) | ((mask << 8) & 0xff00ff00);
    mask = ((mask >> 16) & 0x0000ffff) | ((mask << 16) & 0xffff0000);
    return mask;
}
Vector2Math1To1(UInt, ReverseBits);
Vector3Math1To1(UInt, ReverseBits);
Vector4Math1To1(UInt, ReverseBits);

ULong ReverseBits(ULong v) noexcept
{
    UInt low = ReverseBits((UInt)v);
    UInt high = ReverseBits((UInt)(v >> 32));
    return (ULong)high & ((ULong)low << 32);
}
Vector2Math1To1(ULong, ReverseBits);
Vector3Math1To1(ULong, ReverseBits);
Vector4Math1To1(ULong, ReverseBits);

// ispowof2
template<typename T>
inline Bool IsPowerOf2(T mask) noexcept
{
    return (mask & (mask - 1)) == 0;
}
template<typename T>
Vector2Math1To1_FULL(Bool, T, IsPowerOf2)
template<typename T>
Vector3Math1To1_FULL(Bool, T, IsPowerOf2)
template<typename T>
Vector4Math1To1_FULL(Bool, T, IsPowerOf2)

// nextpowof2
inline UInt NextPowOf2(UInt v) noexcept
{
    v -= 1;
    v |= v >> 16;
    v |= v >> 8;
    v |= v >> 4;
    v |= v >> 2;
    v |= v >> 1;
    return v + 1;
}
Vector2Math1To1(UInt, NextPowOf2);
Vector3Math1To1(UInt, NextPowOf2);
Vector4Math1To1(UInt, NextPowOf2);

inline ULong NextPowOf2(ULong v) noexcept
{
    v -= 1;
    v |= v >> 32;
    v |= v >> 16;
    v |= v >> 8;
    v |= v >> 4;
    v |= v >> 2;
    v |= v >> 1;
    return v + 1;
}
Vector2Math1To1(ULong, NextPowOf2);
Vector3Math1To1(ULong, NextPowOf2);
Vector4Math1To1(ULong, NextPowOf2);

// closestpowof2
inline UInt ClosestPowOf2(UInt v) noexcept
{
    UInt nextPower = NextPowOf2(v);
    UInt prevPower = nextPower >> 1;
    if (v - prevPower < nextPower - v)
        return prevPower;
    else
        return nextPower;
}
Vector2Math1To1(UInt, ClosestPowOf2);
Vector3Math1To1(UInt, ClosestPowOf2);
Vector4Math1To1(UInt, ClosestPowOf2);

inline ULong ClosestPowOf2(ULong v) noexcept
{
    ULong nextPower = NextPowOf2(v);
    ULong prevPower = nextPower >> 1;
    if (v - prevPower < nextPower - v)
        return prevPower;
    else
        return nextPower;
}
Vector2Math1To1(ULong, ClosestPowOf2);
Vector3Math1To1(ULong, ClosestPowOf2);
Vector4Math1To1(ULong, ClosestPowOf2);


// cross
template<typename T>
MathVector<T, 2> Cross(MathVector<T, 2> V1, MathVector<T, 2> V2) noexcept
{
    return MathVector<T, 2>(V1.x * V2.y - V1.y * V2.x, V1.x * V2.y - V1.y * V2.x);
}
template<typename T>
MathVector<T, 3> Cross(MathVector<T, 3> V1, MathVector<T, 3> V2) noexcept
{
    return MathVector<T, 3>(V1.y * V2.z - V1.z * V2.y, V1.z * V2.x - V1.x * V2.z, V1.x * V2.y - V1.y * V2.x);
}
template<typename T>
MathVector<T, 4> Cross(MathVector<T, 4> v1, MathVector<T, 4> v2, MathVector<T, 4> v3) noexcept
{
    return MathVector<T, 4>(
           ((v2.z*v3.w-v2.w*v3.z)*v1.y)-((v2.y*v3.w-v2.w*v3.y)*v1.z)+((v2.y*v3.z-v2.z*v3.y)*v1.w),
           ((v2.w*v3.z-v2.z*v3.w)*v1.x)-((v2.w*v3.x-v2.x*v3.w)*v1.z)+((v2.z*v3.x-v2.x*v3.z)*v1.w),
           ((v2.y*v3.w-v2.w*v3.y)*v1.x)-((v2.x*v3.w-v2.w*v3.x)*v1.y)+((v2.x*v3.y-v2.y*v3.x)*v1.w),
           ((v2.z*v3.y-v2.y*v3.z)*v1.x)-((v2.z*v3.x-v2.x*v3.z)*v1.y)+((v2.y*v3.x-v2.x*v3.y)*v1.z) );
}

// dot
template<typename T>
T Dot(MathVector<T, 2> V1, MathVector<T, 2> V2) noexcept
{
    return V1.x * V2.x + V1.y * V2.y;
}
template<typename T>
T  Dot(MathVector<T, 3> V1, MathVector<T, 3> V2) noexcept
{
    return V1.x * V2.x + V1.y * V2.y + V1.z * V2.z;
}
template<typename T>
T  Dot(MathVector<T, 4> V1, MathVector<T, 4> V2) noexcept
{
    return V1.x * V2.x + V1.y * V2.y + V1.z * V2.z + V1.w * V2.w;
}

// length
template<typename T>
T Length(MathVector<T, 2> v) noexcept
{
    return Sqrt(Dot(v, v));
}
template<typename T>
T Length(MathVector<T, 3> v) noexcept
{
    return Sqrt(Dot(v, v));
}
template<typename T>
T Length(MathVector<T, 4> v) noexcept
{
    return Sqrt(Dot(v, v));
}

// distance
template<typename T>
T Distance(MathVector<T, 2> V1, MathVector<T, 2> V2) noexcept
{
    return Length(V1 - V2);
}
template<typename T>
T  Distance(MathVector<T, 3> V1, MathVector<T, 3> V2) noexcept
{
    return Length(V1 - V2);
}
template<typename T>
T  Distance(MathVector<T, 4> V1, MathVector<T, 4> V2) noexcept
{
    return Length(V1 - V2);
}

//normalize
template<typename T>
T Normalize(MathVector<T, 2> v) noexcept
{
    return v * RSqrt(Dot(v, v));
}
template<typename T>
T Normalize(MathVector<T, 3> v) noexcept
{
    return v * RSqrt(Dot(v, v));
}
template<typename T>
T Normalize(MathVector<T, 4> v) noexcept
{
    return v * RSqrt(Dot(v, v));
}

// faceforward
template<typename T>
MathVector<T, 2> FaceForward(MathVector<T, 2> N, MathVector<T, 2> I, MathVector<T, 2> Ref) noexcept
{
    return Dot(Ref, I) < 0 ? N : -N;
}
template<typename T>
MathVector<T, 3> FaceForward(MathVector<T, 3> N, MathVector<T, 3> I, MathVector<T, 3> Ref) noexcept
{
    return Dot(Ref, I) < 0 ? N : -N;
}
template<typename T>
MathVector<T, 4> FaceForward(MathVector<T, 4> N, MathVector<T, 4> I, MathVector<T, 4> Ref) noexcept
{
    return Dot(Ref, I) < 0 ? N : -N;
}

// reflect
template<typename T>
MathVector<T, 2> Reflect(MathVector<T, 2> I, MathVector<T, 2> N) noexcept
{
    return I - (2 * Dot(I, N)) * N;
}
template<typename T>
MathVector<T, 3> Reflect(MathVector<T, 3> I, MathVector<T, 3> N) noexcept
{
    return I - (2 * Dot(I, N)) * N;
}
template<typename T>
MathVector<T, 4> Reflect(MathVector<T, 4> I, MathVector<T, 4> N) noexcept
{
    return I - (2 * Dot(I, N)) * N;
}

// refract
template<typename T>
MathVector<T, 2> Refract(MathVector<T, 2> I, MathVector<T, 2> N, T Index) noexcept
{
    T dotIN = Dot(I, N);
    T R = 1.0f - Index * Index * (1.0f - dotIN * dotIN);
    if (R <= 0)
        return 0;
    else
    {
        R = Index * dotIN + Sqrt(R);
        return Index * I - N * R;
    }
}
template<typename T>
MathVector<T, 3> Refract(MathVector<T, 3> I, MathVector<T, 3> N, T Index) noexcept
{
    T dotIN = Dot(I, N);
    T R = 1.0f - Index * Index * (1.0f - dotIN * dotIN);
    if (R <= 0)
        return 0;
    else
    {
        R = Index * dotIN + Sqrt(R);
        return Index * I - N * R;
    }
}
template<typename T>
MathVector<T, 4> Refract(MathVector<T, 4> I, MathVector<T, 4> N, T Index) noexcept
{
    T dotIN = Dot(I, N);
    T R = 1.0f - Index * Index * (1.0f - dotIN * dotIN);
    if (R <= 0)
        return 0;
    else
    {
        R = Index * dotIN + Sqrt(R);
        return Index * I - N * R;
    }
}

// mul
template<typename T, size_t Row, size_t Col>
inline MathVector<T, Col> Mul(const MathVector<T, Row>& v, const MathMatrix<T, Row, Col>& m) noexcept
{
    MathVector<T, Col> ret = v[0] * m.v[0];
    for (size_t i = 1; i < Row; i++)
        ret += v[i] * m.v[i];
    
    return ret;
}

template<typename T, size_t Row, size_t Col>
inline MathVector<T, Col> Mul(const T* v, const MathMatrix<T, Row, Col>& m) noexcept
{
    MathVector<T, Col> ret = v[0] * m.v[0];
    for (size_t i = 1; i < Row; i++)
        ret += v[i] * m.v[i];

    return ret;
}

template<typename T, size_t Row, size_t Col>
inline MathVector<T, Row> Mul(const MathMatrix<T, Row, Col>& m, const MathVector<T, Col>& v) noexcept
{
    MathVector<T, Row> ret;
    for (size_t i = 0; i < Row; i++)
        ret[i] = Dot(v, m.v[i]);

    return ret;
}

template<typename T, size_t Row, size_t Col>
inline MathMatrix<T, Row, Row> Mul(const MathMatrix<T, Row, Col>& a, const MathMatrix<T, Col, Row>& b) noexcept
{
    MathMatrix<T, Row, Row> ret;
    for (size_t i = 0; i < Row; i++)
    {
        ret.v[i] = Mul(a.v[i], b);
    }
    return ret;
}


// transpose
template<typename T, size_t Row, size_t Col>
inline MathMatrix<T, Col, Row> Transpose(const MathMatrix<T, Row, Col>& m) noexcept
{
    MathMatrix<T, Col, Row> ret;
    for (size_t i = 0; i < Row; i++)
    {
        for (size_t j = 0; j < Col; j++)
        {
            ret[j][i] = m[i][j];
        }
    }
    return ret;
}

// determinant
template<typename T>
inline T Determinant(const MathMatrix<T, 4, 4>& M) noexcept
{
    return	M[0][0] * (
        M[1][1] * (M[2][2] * M[3][3] - M[2][3] * M[3][2]) -
        M[2][1] * (M[1][2] * M[3][3] - M[1][3] * M[3][2]) +
        M[3][1] * (M[1][2] * M[2][3] - M[1][3] * M[2][2])
        ) -
        M[1][0] * (
            M[0][1] * (M[2][2] * M[3][3] - M[2][3] * M[3][2]) -
            M[2][1] * (M[0][2] * M[3][3] - M[0][3] * M[3][2]) +
            M[3][1] * (M[0][2] * M[2][3] - M[0][3] * M[2][2])
            ) +
        M[2][0] * (
            M[0][1] * (M[1][2] * M[3][3] - M[1][3] * M[3][2]) -
            M[1][1] * (M[0][2] * M[3][3] - M[0][3] * M[3][2]) +
            M[3][1] * (M[0][2] * M[1][3] - M[0][3] * M[1][2])
            ) -
        M[3][0] * (
            M[0][1] * (M[1][2] * M[2][3] - M[1][3] * M[2][2]) -
            M[1][1] * (M[0][2] * M[2][3] - M[0][3] * M[2][2]) +
            M[2][1] * (M[0][2] * M[1][3] - M[0][3] * M[1][2])
            );
}

template<typename T>
inline T Determinant(const MathMatrix<T, 3, 3>& M) noexcept
{
    return
        M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]) -
        M[1][0] * (M[0][1] * M[2][2] - M[0][2] * M[2][1]) +
        M[2][0] * (M[0][1] * M[1][2] - M[0][2] * M[1][1]);
}

// inverse
template<typename T>
inline MathMatrix<T, 4, 4> Inverse(const MathMatrix<T, 4, 4>& M) noexcept
{
    float Det[4];
    Float4x4 Tmp;
    Tmp[0][0] = M[2][2] * M[3][3] - M[2][3] * M[3][2];
    Tmp[0][1] = M[1][2] * M[3][3] - M[1][3] * M[3][2];
    Tmp[0][2] = M[1][2] * M[2][3] - M[1][3] * M[2][2];

    Tmp[1][0] = M[2][2] * M[3][3] - M[2][3] * M[3][2];
    Tmp[1][1] = M[0][2] * M[3][3] - M[0][3] * M[3][2];
    Tmp[1][2] = M[0][2] * M[2][3] - M[0][3] * M[2][2];

    Tmp[2][0] = M[1][2] * M[3][3] - M[1][3] * M[3][2];
    Tmp[2][1] = M[0][2] * M[3][3] - M[0][3] * M[3][2];
    Tmp[2][2] = M[0][2] * M[1][3] - M[0][3] * M[1][2];

    Tmp[3][0] = M[1][2] * M[2][3] - M[1][3] * M[2][2];
    Tmp[3][1] = M[0][2] * M[2][3] - M[0][3] * M[2][2];
    Tmp[3][2] = M[0][2] * M[1][3] - M[0][3] * M[1][2];

    Det[0] = M[1][1] * Tmp[0][0] - M[2][1] * Tmp[0][1] + M[3][1] * Tmp[0][2];
    Det[1] = M[0][1] * Tmp[1][0] - M[2][1] * Tmp[1][1] + M[3][1] * Tmp[1][2];
    Det[2] = M[0][1] * Tmp[2][0] - M[1][1] * Tmp[2][1] + M[3][1] * Tmp[2][2];
    Det[3] = M[0][1] * Tmp[3][0] - M[1][1] * Tmp[3][1] + M[2][1] * Tmp[3][2];

    const T determinant = M[0][0] * Det[0] - M[1][0] * Det[1] + M[2][0] * Det[2] - M[3][0] * Det[3];
    const T	RDet = T(1) / determinant;

    MathMatrix<T, 4, 4> Result;
    Result[0][0] = RDet * Det[0];
    Result[0][1] = -RDet * Det[1];
    Result[0][2] = RDet * Det[2];
    Result[0][3] = -RDet * Det[3];
    Result[1][0] = -RDet * (M[1][0] * Tmp[0][0] - M[2][0] * Tmp[0][1] + M[3][0] * Tmp[0][2]);
    Result[1][1] = RDet * (M[0][0] * Tmp[1][0] - M[2][0] * Tmp[1][1] + M[3][0] * Tmp[1][2]);
    Result[1][2] = -RDet * (M[0][0] * Tmp[2][0] - M[1][0] * Tmp[2][1] + M[3][0] * Tmp[2][2]);
    Result[1][3] = RDet * (M[0][0] * Tmp[3][0] - M[1][0] * Tmp[3][1] + M[2][0] * Tmp[3][2]);
    Result[2][0] = RDet * (
        M[1][0] * (M[2][1] * M[3][3] - M[2][3] * M[3][1]) -
        M[2][0] * (M[1][1] * M[3][3] - M[1][3] * M[3][1]) +
        M[3][0] * (M[1][1] * M[2][3] - M[1][3] * M[2][1])
        );
    Result[2][1] = -RDet * (
        M[0][0] * (M[2][1] * M[3][3] - M[2][3] * M[3][1]) -
        M[2][0] * (M[0][1] * M[3][3] - M[0][3] * M[3][1]) +
        M[3][0] * (M[0][1] * M[2][3] - M[0][3] * M[2][1])
        );
    Result[2][2] = RDet * (
        M[0][0] * (M[1][1] * M[3][3] - M[1][3] * M[3][1]) -
        M[1][0] * (M[0][1] * M[3][3] - M[0][3] * M[3][1]) +
        M[3][0] * (M[0][1] * M[1][3] - M[0][3] * M[1][1])
        );
    Result[2][3] = -RDet * (
        M[0][0] * (M[1][1] * M[2][3] - M[1][3] * M[2][1]) -
        M[1][0] * (M[0][1] * M[2][3] - M[0][3] * M[2][1]) +
        M[2][0] * (M[0][1] * M[1][3] - M[0][3] * M[1][1])
        );
    Result[3][0] = -RDet * (
        M[1][0] * (M[2][1] * M[3][2] - M[2][2] * M[3][1]) -
        M[2][0] * (M[1][1] * M[3][2] - M[1][2] * M[3][1]) +
        M[3][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1])
        );
    Result[3][1] = RDet * (
        M[0][0] * (M[2][1] * M[3][2] - M[2][2] * M[3][1]) -
        M[2][0] * (M[0][1] * M[3][2] - M[0][2] * M[3][1]) +
        M[3][0] * (M[0][1] * M[2][2] - M[0][2] * M[2][1])
        );
    Result[3][2] = -RDet * (
        M[0][0] * (M[1][1] * M[3][2] - M[1][2] * M[3][1]) -
        M[1][0] * (M[0][1] * M[3][2] - M[0][2] * M[3][1]) +
        M[3][0] * (M[0][1] * M[1][2] - M[0][2] * M[1][1])
        );
    Result[3][3] = RDet * (
        M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]) -
        M[1][0] * (M[0][1] * M[2][2] - M[0][2] * M[2][1]) +
        M[2][0] * (M[0][1] * M[1][2] - M[0][2] * M[1][1])
        );
    return Result;
}

template<typename T>
inline bool InverseSafe(const MathMatrix<T, 4, 4>& M, MathMatrix<T, 4, 4>& Result) noexcept
{
    float Det[4];
    Float4x4 Tmp;
    Tmp[0][0] = M[2][2] * M[3][3] - M[2][3] * M[3][2];
    Tmp[0][1] = M[1][2] * M[3][3] - M[1][3] * M[3][2];
    Tmp[0][2] = M[1][2] * M[2][3] - M[1][3] * M[2][2];

    Tmp[1][0] = M[2][2] * M[3][3] - M[2][3] * M[3][2];
    Tmp[1][1] = M[0][2] * M[3][3] - M[0][3] * M[3][2];
    Tmp[1][2] = M[0][2] * M[2][3] - M[0][3] * M[2][2];

    Tmp[2][0] = M[1][2] * M[3][3] - M[1][3] * M[3][2];
    Tmp[2][1] = M[0][2] * M[3][3] - M[0][3] * M[3][2];
    Tmp[2][2] = M[0][2] * M[1][3] - M[0][3] * M[1][2];

    Tmp[3][0] = M[1][2] * M[2][3] - M[1][3] * M[2][2];
    Tmp[3][1] = M[0][2] * M[2][3] - M[0][3] * M[2][2];
    Tmp[3][2] = M[0][2] * M[1][3] - M[0][3] * M[1][2];

    Det[0] = M[1][1] * Tmp[0][0] - M[2][1] * Tmp[0][1] + M[3][1] * Tmp[0][2];
    Det[1] = M[0][1] * Tmp[1][0] - M[2][1] * Tmp[1][1] + M[3][1] * Tmp[1][2];
    Det[2] = M[0][1] * Tmp[2][0] - M[1][1] * Tmp[2][1] + M[3][1] * Tmp[2][2];
    Det[3] = M[0][1] * Tmp[3][0] - M[1][1] * Tmp[3][1] + M[2][1] * Tmp[3][2];

    const T determinant = M[0][0] * Det[0] - M[1][0] * Det[1] + M[2][0] * Det[2] - M[3][0] * Det[3];
    if (determinant == 0.0f || !std::isfinite(determinant))
        return false;

    const T	RDet = T(1) / determinant;
    MathMatrix<T, 4, 4> Result;
    Result[0][0] = RDet * Det[0];
    Result[0][1] = -RDet * Det[1];
    Result[0][2] = RDet * Det[2];
    Result[0][3] = -RDet * Det[3];
    Result[1][0] = -RDet * (M[1][0] * Tmp[0][0] - M[2][0] * Tmp[0][1] + M[3][0] * Tmp[0][2]);
    Result[1][1] = RDet * (M[0][0] * Tmp[1][0] - M[2][0] * Tmp[1][1] + M[3][0] * Tmp[1][2]);
    Result[1][2] = -RDet * (M[0][0] * Tmp[2][0] - M[1][0] * Tmp[2][1] + M[3][0] * Tmp[2][2]);
    Result[1][3] = RDet * (M[0][0] * Tmp[3][0] - M[1][0] * Tmp[3][1] + M[2][0] * Tmp[3][2]);
    Result[2][0] = RDet * (
        M[1][0] * (M[2][1] * M[3][3] - M[2][3] * M[3][1]) -
        M[2][0] * (M[1][1] * M[3][3] - M[1][3] * M[3][1]) +
        M[3][0] * (M[1][1] * M[2][3] - M[1][3] * M[2][1])
        );
    Result[2][1] = -RDet * (
        M[0][0] * (M[2][1] * M[3][3] - M[2][3] * M[3][1]) -
        M[2][0] * (M[0][1] * M[3][3] - M[0][3] * M[3][1]) +
        M[3][0] * (M[0][1] * M[2][3] - M[0][3] * M[2][1])
        );
    Result[2][2] = RDet * (
        M[0][0] * (M[1][1] * M[3][3] - M[1][3] * M[3][1]) -
        M[1][0] * (M[0][1] * M[3][3] - M[0][3] * M[3][1]) +
        M[3][0] * (M[0][1] * M[1][3] - M[0][3] * M[1][1])
        );
    Result[2][3] = -RDet * (
        M[0][0] * (M[1][1] * M[2][3] - M[1][3] * M[2][1]) -
        M[1][0] * (M[0][1] * M[2][3] - M[0][3] * M[2][1]) +
        M[2][0] * (M[0][1] * M[1][3] - M[0][3] * M[1][1])
        );
    Result[3][0] = -RDet * (
        M[1][0] * (M[2][1] * M[3][2] - M[2][2] * M[3][1]) -
        M[2][0] * (M[1][1] * M[3][2] - M[1][2] * M[3][1]) +
        M[3][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1])
        );
    Result[3][1] = RDet * (
        M[0][0] * (M[2][1] * M[3][2] - M[2][2] * M[3][1]) -
        M[2][0] * (M[0][1] * M[3][2] - M[0][2] * M[3][1]) +
        M[3][0] * (M[0][1] * M[2][2] - M[0][2] * M[2][1])
        );
    Result[3][2] = -RDet * (
        M[0][0] * (M[1][1] * M[3][2] - M[1][2] * M[3][1]) -
        M[1][0] * (M[0][1] * M[3][2] - M[0][2] * M[3][1]) +
        M[3][0] * (M[0][1] * M[1][2] - M[0][2] * M[1][1])
        );
    Result[3][3] = RDet * (
        M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]) -
        M[1][0] * (M[0][1] * M[2][2] - M[0][2] * M[2][1]) +
        M[2][0] * (M[0][1] * M[1][2] - M[0][2] * M[1][1])
        );
    return true;
}

//identity
template<typename T>
inline MathMatrix<T, 3, 3> MathMatrix<T, 3, 3>::Identity() noexcept
{
    MathMatrix<T, 3, 3> M;
    M.m[0][0] = 1.0f;
    M.m[0][1] = 0.0f;
    M.m[0][2] = 0.0f;

    M.m[1][0] = 0.0f;
    M.m[1][1] = 1.0f;
    M.m[1][2] = 0.0f;

    M.m[2][0] = 0.0f;
    M.m[2][1] = 0.0f;
    M.m[2][2] = 1.0f;

    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Identity() noexcept
{
    MathMatrix<T, 4, 4> M;
    M.m[0][0] = 1.0f;
    M.m[0][1] = 0.0f;
    M.m[0][2] = 0.0f;
    M.m[0][3] = 0.0f;

    M.m[1][0] = 0.0f;
    M.m[1][1] = 1.0f;
    M.m[1][2] = 0.0f;
    M.m[1][3] = 0.0f;

    M.m[2][0] = 0.0f;
    M.m[2][1] = 0.0f;
    M.m[2][2] = 1.0f;
    M.m[2][3] = 0.0f;

    M.m[3][0] = 0.0f;
    M.m[3][1] = 0.0f;
    M.m[3][2] = 0.0f;
    M.m[3][3] = 1.0f;
    return M;
}


//translate
template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Translate(T OffsetX, T OffsetY, T OffsetZ) noexcept
{
    MathMatrix<T, 4, 4> M;
    M.m[0][0] = 1.0f;
    M.m[0][1] = 0.0f;
    M.m[0][2] = 0.0f;
    M.m[0][3] = 0.0f;

    M.m[1][0] = 0.0f;
    M.m[1][1] = 1.0f;
    M.m[1][2] = 0.0f;
    M.m[1][3] = 0.0f;

    M.m[2][0] = 0.0f;
    M.m[2][1] = 0.0f;
    M.m[2][2] = 1.0f;
    M.m[2][3] = 0.0f;

    M.m[3][0] = OffsetX;
    M.m[3][1] = OffsetY;
    M.m[3][2] = OffsetZ;
    M.m[3][3] = 1.0f;
    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Translate(const MathVector<T, 4>& Offset) noexcept
{
    return MathMatrix<T, 4, 4>::Translate(Offset.x, Offset.y, Offset.z);
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Translate(const MathVector<T, 3>& Offset) noexcept
{
    return MathMatrix<T, 4, 4>::Translate(Offset.x, Offset.y, Offset.z);
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Translate(const T* Offset) noexcept
{
    return MathMatrix<T, 4, 4>::Translate(Offset[0], Offset[1], Offset[2]);
}

template<typename T>
inline MathMatrix<T, 3, 3> MathMatrix<T, 3, 3>::Translate(T OffsetX, T OffsetY) noexcept
{
    MathMatrix<T, 3, 3> M;
    M.m[0][0] = 1.0f;
    M.m[0][1] = 0.0f;
    M.m[0][2] = 0.0f;

    M.m[1][0] = 0.0f;
    M.m[1][1] = 1.0f;
    M.m[1][2] = 0.0f;

    M.m[2][0] = OffsetX;
    M.m[2][1] = OffsetY;
    M.m[2][2] = 1.0f;

    return M;
}

template<typename T>
inline MathMatrix<T, 3, 3> MathMatrix<T, 3, 3>::Translate(const MathVector<T, 2>& Offset) noexcept
{
    return MathMatrix<T, 3, 3>::Translate(Offset.x, Offset.y);
}

template<typename T>
inline MathMatrix<T, 3, 3> MathMatrix<T, 3, 3>::Translate(const T* Offset) noexcept
{
    return MathMatrix<T, 3, 3>::Translate(Offset[0], Offset[1]);
}

//scale
template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Scaling(T ScaleX, T ScaleY, T ScaleZ) noexcept
{
    MathMatrix<T, 4, 4> M;
    M.m[0][0] = ScaleX;
    M.m[0][1] = 0.0f;
    M.m[0][2] = 0.0f;
    M.m[0][3] = 0.0f;

    M.m[1][0] = 0.0f;
    M.m[1][1] = ScaleY;
    M.m[1][2] = 0.0f;
    M.m[1][3] = 0.0f;

    M.m[2][0] = 0.0f;
    M.m[2][1] = 0.0f;
    M.m[2][2] = ScaleZ;
    M.m[2][3] = 0.0f;

    M.m[3][0] = 0.0f;
    M.m[3][1] = 0.0f;
    M.m[3][2] = 0.0f;
    M.m[3][3] = 1.0f;
    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Scaling(const MathVector<T, 4>& Scale) noexcept
{
    return MathMatrix<T, 4, 4>::Translate(Scale.x, Scale.y, Scale.z);
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Scaling(const MathVector<T, 3>& Scale) noexcept
{
    return MathMatrix<T, 4, 4>::Translate(Scale.x, Scale.y, Scale.z);
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Scaling(const T* Scale) noexcept
{
    return MathMatrix<T, 4, 4>::Translate(Scale[0], Scale[1], Scale[2]);
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Scaling(const T Scale) noexcept
{
    return MathMatrix<T, 4, 4>::Translate(Scale, Scale, Scale);
}

template<typename T>
inline MathMatrix<T, 3, 3> MathMatrix<T, 3, 3>::Scaling(T ScaleX, T ScaleY) noexcept
{
    MathMatrix<T, 3, 3> M;
    M.m[0][0] = ScaleX;
    M.m[0][1] = 0.0f;
    M.m[0][2] = 0.0f;

    M.m[1][0] = 0.0f;
    M.m[1][1] = ScaleY;
    M.m[1][2] = 0.0f;

    M.m[2][0] = 0.0f;
    M.m[2][1] = 0.0f;
    M.m[2][2] = 1.0f;

    return M;
}

template<typename T>
inline MathMatrix<T, 3, 3> MathMatrix<T, 3, 3>::Scaling(const MathVector<T, 2>& Scale) noexcept
{
    return MathMatrix<T, 3, 3>::Scaling(Scale.x, Scale.y);
}

template<typename T>
inline MathMatrix<T, 3, 3> MathMatrix<T, 3, 3>::Scaling(const T* Scale) noexcept
{
    return MathMatrix<T, 3, 3>::Scaling(Scale[0], Scale[1]);
}

template<typename T>
inline MathMatrix<T, 3, 3> MathMatrix<T, 3, 3>::Scaling(T Scale) noexcept
{
    return MathMatrix<T, 3, 3>::Scaling(Scale, Scale);
}

//rotation
template<typename T>
inline static MathMatrix<T, 3, 3> MathMatrix<T, 3, 3>::Rotation(T Radian) noexcept
{
    T RotSin;
    T RotCos;
    SinCos(Radian, &RotSin, &RotCos);

    MathMatrix<T, 3, 3> M;
    M.m[0][0] = RotCos;
    M.m[0][1] = RotSin;
    M.m[0][2] = 0.0f;

    M.m[1][0] = -RotSin;
    M.m[1][1] = RotCos;
    M.m[1][2] = 0.0f;

    M.m[2][0] = 0.0f;
    M.m[2][1] = 0.0f;
    M.m[2][2] = 1.0f;
    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::RotationX(T Radian) noexcept
{
    T RotSin;
    T RotCos;
    SinCos(Radian, &RotSin, &RotCos);

    MathMatrix<T, 4, 4> M;
    M.m[0][0] = 1.0f;
    M.m[0][1] = 0.0f;
    M.m[0][2] = 0.0f;
    M.m[0][3] = 0.0f;

    M.m[1][0] = 0.0f;
    M.m[1][1] = RotCos;
    M.m[1][2] = RotSin;
    M.m[1][3] = 0.0f;

    M.m[2][0] = 0.0f;
    M.m[2][1] = -RotSin;
    M.m[2][2] = RotCos;
    M.m[2][3] = 0.0f;

    M.m[3][0] = 0.0f;
    M.m[3][1] = 0.0f;
    M.m[3][2] = 0.0f;
    M.m[3][3] = 1.0f;
    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::RotationY(T Radian) noexcept
{
    T RotSin;
    T RotCos;
    SinCos(Radian, &RotSin, &RotCos);

    MathMatrix<T, 4, 4> M;
    M.m[0][0] = RotCos;
    M.m[0][1] = 0.0f;
    M.m[0][2] = -RotSin;
    M.m[0][3] = 0.0f;

    M.m[1][0] = 0.0f;
    M.m[1][1] = 1.0f;
    M.m[1][2] = 0.0f;
    M.m[1][3] = 0.0f;

    M.m[2][0] = RotSin;
    M.m[2][1] = 0.0f;
    M.m[2][2] = RotCos;
    M.m[2][3] = 0.0f;

    M.m[3][0] = 0.0f;
    M.m[3][1] = 0.0f;
    M.m[3][2] = 0.0f;
    M.m[3][3] = 1.0f;
    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::RotationZ(T Radian) noexcept
{
    T RotSin;
    T RotCos;
    SinCos(Radian, &RotSin, &RotCos);

    MathMatrix<T, 4, 4> M;
    M.m[0][0] = RotCos;
    M.m[0][1] = RotSin;
    M.m[0][2] = 0.0f;
    M.m[0][3] = 0.0f;

    M.m[1][0] = -RotSin;
    M.m[1][1] = RotCos;
    M.m[1][2] = 0.0f;
    M.m[1][3] = 0.0f;

    M.m[2][0] = 0.0f;
    M.m[2][1] = 0.0f;
    M.m[2][2] = 1.0f;
    M.m[2][3] = 0.0f;

    M.m[3][0] = 0.0f;
    M.m[3][1] = 0.0f;
    M.m[3][2] = 0.0f;
    M.m[3][3] = 1.0f;
    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::RotationRollPitchYaw(T Pitch, T Yaw, T Roll) noexcept
{
    T cp = Cos(Pitch);
    T sp = Sin(Pitch);

    T cy = Cos(Yaw);
    T sy = Sin(Yaw);

    T cr = Cos(Roll);
    T sr = Sin(Roll);

    MathMatrix<T, 4, 4> M;
    M.m[0][0] = cr * cy + sr * sp * sy;
    M.m[0][1] = sr * cp;
    M.m[0][2] = sr * sp * cy - cr * sy;
    M.m[0][3] = 0.0f;

    M.m[1][0] = cr * sp * sy - sr * cy;
    M.m[1][1] = cr * cp;
    M.m[1][2] = sr * sy + cr * sp * cy;
    M.m[1][3] = 0.0f;

    M.m[2][0] = cp * sy;
    M.m[2][1] = -sp;
    M.m[2][2] = cp * cy;
    M.m[2][3] = 0.0f;

    M.m[3][0] = 0.0f;
    M.m[3][1] = 0.0f;
    M.m[3][2] = 0.0f;
    M.m[3][3] = 1.0f;
    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::RotationAxis(const MathVector<T, 3>& Axis, T Radian) noexcept
{
    T    fSinAngle;
    T    fCosAngle;
    SinCos(Radian, &fSinAngle, &fCosAngle);

    MathVector<T, 3> C2 = 1.0f - fCosAngle;
    MathVector<T, 3> C1 = fCosAngle;
    MathVector<T, 3> C0 = fSinAngle;

    MathVector<T, 3> N0 = Axis.yzx;
    MathVector<T, 3> N1 = Axis.zxy;

    MathVector<T, 3> V0 = C2 * N0;
    V0 = V0 * N1;

    MathVector<T, 3> R0 = C2 * Axis;
    R0 = Mad(R0, Axis, C1);

    MathVector<T, 3> R1 = Mad(C0, Axis, V0);
    MathVector<T, 3> R2 = V0 - C0 * Axis;

    V0 = R0;
    MathVector<T, 4> V1 = MathVector<T, 4>(R1.z, R2.y, R2.z, R1.x);
    MathVector<T, 2> V2 = MathVector<T, 2>(R1.y, R2.x);

    MathMatrix<T, 4, 4> M;
    M[0] = MathVector<T, 4>(V0.x, V1.x, V1.y, 0);
    M[1] = MathVector<T, 4>(V1.z, V0.y, V1.w, 0);
    M[2] = MathVector<T, 4>(V2.x, V2.y, V0.z, 0);
    M[3] = MathVector<T, 4>(0, 0, 0, 1);
    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::RotationQuat(const MathVector<T, 4>& Quat) noexcept
{
    T qx = Quat[0];
    T qxx = qx * qx;

    T qy = Quat[1];
    T qyy = qy * qy;

    T qz = Quat[2];
    T qzz = qz * qz;

    T qw = Quat[3];

    MathMatrix<T, 4, 4> M;
    M.m[0][0] = 1.f - 2.f * qyy - 2.f * qzz;
    M.m[0][1] = 2.f * qx * qy + 2.f * qz * qw;
    M.m[0][2] = 2.f * qx * qz - 2.f * qy * qw;
    M.m[0][3] = 0.f;

    M.m[1][0] = 2.f * qx * qy - 2.f * qz * qw;
    M.m[1][1] = 1.f - 2.f * qxx - 2.f * qzz;
    M.m[1][2] = 2.f * qy * qz + 2.f * qx * qw;
    M.m[1][3] = 0.f;

    M.m[2][0] = 2.f * qx * qz + 2.f * qy * qw;
    M.m[2][1] = 2.f * qy * qz - 2.f * qx * qw;
    M.m[2][2] = 1.f - 2.f * qxx - 2.f * qyy;
    M.m[2][3] = 0.f;

    M.m[3][0] = 0.f;
    M.m[3][1] = 0.f;
    M.m[3][2] = 0.f;
    M.m[3][3] = 1.0f;
    return M;
}

//transform
template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Transform(const MathVector<T, 3>& Scale, const MathVector<T, 4>& RotQuat, const MathVector<T, 3>& Translation) noexcept
{
    // M = MScaling * MRotation * MTranslation;

    MathMatrix<T, 4, 4> M = MathMatrix<T, 4, 4>::Scaling(Scale);
    M = Mul(M, MathMatrix<T, 4, 4>::RotationQuat(RotQuat));
    M[3].xyz = Translation;
    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Transform(const MathVector<T, 3>& Scale, const MathVector<T, 3>& RotOrigin, const MathVector<T, 4>& RotQuat, const MathVector<T, 3>& Translation) noexcept
{
    // M = MScaling * Inverse(MRotationOrigin) * MRotation * MRotationOrigin * MTranslation;

    MathMatrix<T, 4, 4> M = MathMatrix<T, 4, 4>::Scaling(Scale);
    M[3].xyz -= RotOrigin;
    M = Mul(M, MathMatrix<T, 4, 4>::RotationQuat(RotQuat));
    M[3].xyz += RotOrigin;
    M[3].xyz += Translation;
    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::Transform(const MathVector<T, 3>& ScaleOrigin, const MathVector<T, 4>& ScalingOrientationQuat, const MathVector<T, 3>& Scale, const MathVector<T, 3>& RotOrigin, const MathVector<T, 4>& RotQuat, const MathVector<T, 3>& Translation) noexcept
{
    // M = Inverse(MScalingOrigin) * Transpose(MScalingOrientation) * MScaling * MScalingOrientation *
    //         MScalingOrigin * Inverse(MRotationOrigin) * MRotation * MRotationOrigin * MTranslation;

    MathMatrix<T, 4, 4> MScalingOrientation = RotationQuat(ScalingOrientationQuat);
    MathMatrix<T, 4, 4> MScalingOrientationT = Transpose(MScalingOrientation);
    MathMatrix<T, 4, 4> M = Mul(Translate(-ScaleOrigin), MScalingOrientationT);
    M = Mul(M, Scaling(Scale));
    M = Mul(M, MScalingOrientation);
    M[3].xyz += ScaleOrigin;
    M[3].xyz -= RotOrigin;
    M = Mul(M, MathMatrix<T, 4, 4>::RotationQuat(RotQuat));
    M[3].xyz += RotOrigin;
    M[3].xyz += Translation;
    return M;
}

//camera
template<typename T>
inline static MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::ViewAt(const MathVector<T, 3>& Eye, const MathVector<T, 3>& Focus, const MathVector<T, 3>& Up) noexcept
{
    return ViewTo(Eye, Normalize(Focus - Eye), Up);
}

template<typename T>
inline static MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::ViewTo(const MathVector<T, 3>& Eye, const MathVector<T, 3>& Direction, const MathVector<T, 3>& Up) noexcept
{
    MathVector<T, 3> R2 = Direction;
    MathVector<T, 3> R0 = Normalize(Cross(Up, R2));
    MathVector<T, 3> R1 = Normalize(R2, R0);

    MathVector<T, 3> NegEyePosition = -Eye;
    MathVector<T, 3> D0 = Dot(R0, NegEyePosition);
    MathVector<T, 3> D1 = Dot(R1, NegEyePosition);
    MathVector<T, 3> D2 = Dot(R2, NegEyePosition);

    MathMatrix<T, 4, 4> M;
    M[0].xyz = D0; M[0].w = 0;
    M[1].xyz = D1; M[0].w = 0;
    M[2].xyz = D2; M[0].w = 0;
    M[3].xyz = 0; M[0].w = 1;
    return M;
}

//projection
template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::ProjPerspective(T ViewWidth, T ViewHeight, T NearZ, T FarZ) noexcept
{
    T TwoNearZ = NearZ + NearZ;
    T fRange = FarZ / (NearZ - FarZ);

    MathMatrix<T, 4, 4> M;
    M[0].x = TwoNearZ / ViewWidth;
    M[0].yzw = (T)0;
    M[1].y = TwoNearZ / ViewHeight;
    M[1].xzw = (T)0;
    M[2].z = fRange;
    M[2].xy = (T)0;
    M[2].w = (T)1;
    M[3].z = -fRange * NearZ;
    M[3].xyw = (T)0;
    return M;
}

template<typename T>
inline MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::ProjPerspectiveFov(T FovRadianY, T AspectRatio, T NearZ, T FarZ) noexcept
{
    T    SinFov;
    T    CosFov;
    SinCos(&SinFov, &CosFov, (T)0.5 * FovRadianY);
    T Height = CosFov / SinFov;
    T Width  = Height / AspectRatio;
    T fRange = FarZ / (FarZ - NearZ);

    MathMatrix<T, 4, 4> M;
    M[0].x   = Width;
    M[0].yzw = (T)0;
    M[1].y   = Height;
    M[1].xzw = (T)0;
    M[2].z   = fRange;
    M[2].xy  = (T)0;
    M[2].w   = (T)1;
    M[0].z   = -fRange * NearZ;
    M[0].xyw = (T)0;
    return M;
}

template<typename T>
inline static MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::ProjPerspectiveOffCenter(T ViewLeft, T ViewRight, T ViewBottom, T ViewTop, T NearZ, T FarZ) noexcept
{
    T TwoNearZ = NearZ + NearZ;
    T ReciprocalWidth = (T)1.0 / (ViewRight - ViewLeft);
    T ReciprocalHeight = (T)1.0 / (ViewTop - ViewBottom);
    T fRange = FarZ / (FarZ - NearZ);

    MathMatrix<T, 4, 4> M;
    M[0].x   = TwoNearZ * ReciprocalWidth;
    M[0].yzw = (T)0;
    M[1].y   = TwoNearZ * ReciprocalHeight;
    M[1].xzw = (T)0;
    M[2].x   = -(ViewLeft + ViewRight) * ReciprocalWidth;
    M[2].y   = -(ViewTop + ViewBottom) * ReciprocalHeight;
    M[2].z   = fRange;
    M[2].w   = (T)1;
    M[0].z   = -fRange * NearZ;
    M[0].xyw = (T)0;
    return M;
}

template<typename T>
inline static MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::ProjOrthographic(T ViewWidth, T ViewHeight, T NearZ, T FarZ) noexcept
{
    T fRange = (T)1.0 / (FarZ - NearZ);

    MathMatrix<T, 4, 4> M;
    M[0].x   = (T)2.0 / ViewWidth;;
    M[0].yzw = (T)0;
    M[1].y   = (T)2.0 / ViewHeight;
    M[1].xzw = (T)0;
    M[2].z   = fRange;
    M[2].xyw = (T)0;
    M[3].xy  = (T)0;
    M[3].z   = -fRange * NearZ;
    M[3].w   = (T)1;
    return M;
}

template<typename T>
inline static MathMatrix<T, 4, 4> MathMatrix<T, 4, 4>::ProjOrthographicOffCenter(T ViewLeft, T ViewRight, T ViewBottom, T ViewTop, T NearZ, T FarZ) noexcept
{
    T ReciprocalWidth = (T)1.0 / (ViewRight - ViewLeft);
    T ReciprocalHeight = (T)1.0 / (ViewTop - ViewBottom);
    T fRange = (T)1.0 / (FarZ - NearZ);

    MathMatrix<T, 4, 4> M;
    M[0].x   = ReciprocalWidth + ReciprocalWidth;
    M[0].yzw = (T)0;
    M[1].y   = ReciprocalHeight + ReciprocalHeight;
    M[1].xzw = (T)0;
    M[2].z   = fRange;
    M[2].xyw = (T)0;
    M[3].x   = -(ViewLeft + ViewRight) * ReciprocalWidth;
    M[3].y   = -(ViewTop + ViewBottom) * ReciprocalHeight;
    M[3].z   = -fRange * NearZ;
    M[3].w   = (T)1;
    return M;
}

}