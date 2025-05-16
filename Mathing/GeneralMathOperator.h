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

#define MathVector_PerComp_BinaryOperator(OP) \
template<typename T> \
inline MathVector<T, 2> operator OP (const MathVector<T, 2>& a, const MathVector<T, 2>& b) noexcept\
{\
    MathVector<T, 2> ret;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    return ret;\
}\
 template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 2>operator OP (const MathVector<T, 2>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 2> ret;\
    T b = (T)ob;\
    ret.x = a.x OP b;\
    ret.y = a.y OP b;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 2>operator OP (const VTOth& ob, const MathVector<T, 2>& a) noexcept\
{\
    MathVector<T, 2> ret;\
    T b = (T)ob;\
    ret.x = b OP a.x;\
    ret.y = b OP a.y;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 2>>::value, bool> = true> \
inline MathVector<T, 2>operator OP (const MathVector<T, 2>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 2> ret;\
    MathVector<T, 2> b = ob;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 2>>::value, bool> = true> \
inline MathVector<T, 2>operator OP (const VTOth& ob, const MathVector<T, 2>& a) noexcept\
{\
    MathVector<T, 2> ret;\
    MathVector<T, 2> b = ob;\
    ret.x = b.x OP a.x;\
    ret.y = b.y OP a.y;\
    return ret;\
}\
template<typename T, size_t SDimA, size_t IndexsA0, size_t IndexsA1, size_t SDimB, size_t IndexsB0, size_t IndexsB1>\
inline MathVector<T, 2> operator OP (const Swizzle<T, SDimA, IndexsA0, IndexsA1>& sa, const Swizzle<T, SDimB, IndexsB0, IndexsB1>& sb) noexcept\
{\
    MathVector<T, 2> ret;\
    ret.x = sa.V[IndexsA0] OP sb.V[IndexsB0];\
    ret.y = sa.V[IndexsA1] OP sb.V[IndexsB1];\
    return ret;\
}\
template<typename T> \
inline MathVector<T, 3> operator OP (const MathVector<T, 3>& a, const MathVector<T, 3>& b) noexcept\
{\
    MathVector<T, 3> ret;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 3>operator OP (const MathVector<T, 3>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 3> ret;\
    T b = (T)ob;\
    ret.x = a.x OP b;\
    ret.y = a.y OP b;\
    ret.z = a.z OP b;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 3>operator OP (const VTOth& ob, const MathVector<T, 3>& a) noexcept\
{\
    MathVector<T, 3> ret;\
    T b = (T)ob;\
    ret.x = b OP a.x;\
    ret.y = b OP a.y;\
    ret.z = b OP a.z;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 3>>::value, bool> = true> \
inline MathVector<T, 3>operator OP (const MathVector<T, 3>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 3> ret;\
    MathVector<T, 3> b = ob;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 3>>::value, bool> = true> \
inline MathVector<T, 3>operator OP (const VTOth& ob, const MathVector<T, 3>& a) noexcept\
{\
    MathVector<T, 3> ret;\
    MathVector<T, 3> b = ob;\
    ret.x = b.x OP a.x;\
    ret.y = b.y OP a.y;\
    ret.z = b.z OP a.z;\
    return ret;\
}\
template<typename T, size_t SDimA, size_t IndexsA0, size_t IndexsA1, size_t IndexsA2, size_t SDimB, size_t IndexsB0, size_t IndexsB1, size_t IndexsB2>\
inline MathVector<T, 3> operator OP (const Swizzle<T, SDimA, IndexsA0, IndexsA1, IndexsA2>& sa, const Swizzle<T, SDimB, IndexsB0, IndexsB1, IndexsB2>& sb) noexcept\
{\
    MathVector<T, 3> ret;\
    ret.x = sa.V[IndexsA0] OP sb.V[IndexsB0];\
    ret.y = sa.V[IndexsA1] OP sb.V[IndexsB1];\
    ret.z = sa.V[IndexsA2] OP sb.V[IndexsB2];\
    return ret;\
}\
template<typename T> \
inline MathVector<T, 4> operator OP (const MathVector<T, 4>& a, const MathVector<T, 4>& b) noexcept\
{\
    MathVector<T, 4> ret;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    ret.w = a.w OP b.w;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 4>operator OP (const MathVector<T, 4>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 4> ret;\
    T b = (T)ob;\
    ret.x = a.x OP b;\
    ret.y = a.y OP b;\
    ret.z = a.z OP b;\
    ret.w = a.w OP b;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 4>operator OP (const VTOth& ob, const MathVector<T, 4>& a) noexcept\
{\
    MathVector<T, 4> ret;\
    T b = (T)ob;\
    ret.x = b OP a.x;\
    ret.y = b OP a.y;\
    ret.z = b OP a.z;\
    ret.w = b OP a.w;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 4>>::value, bool> = true> \
inline MathVector<T, 4>operator OP (const MathVector<T, 4>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 4> ret;\
    MathVector<T, 4> b = ob;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    ret.w = a.w OP b.w;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 4>>::value, bool> = true> \
inline MathVector<T, 4>operator OP (const VTOth& ob, const MathVector<T, 4>& a) noexcept\
{\
    MathVector<T, 4> ret;\
    MathVector<T, 4> b = ob;\
    ret.x = b.x OP a.x;\
    ret.y = b.y OP a.y;\
    ret.z = b.z OP a.z;\
    ret.w = b.w OP a.w;\
    return ret;\
}\
template<typename T, size_t SDimA, size_t IndexsA0, size_t IndexsA1, size_t IndexsA2, size_t IndexsA3, size_t SDimB, size_t IndexsB0, size_t IndexsB1, size_t IndexsB2, size_t IndexsB3>\
inline MathVector<T, 4> operator OP (const Swizzle<T, SDimA, IndexsA0, IndexsA1, IndexsA2, IndexsA3>& sa, const Swizzle<T, SDimB, IndexsB0, IndexsB1, IndexsB2, IndexsB3>& sb) noexcept\
{\
    MathVector<T, 4> ret;\
    ret.x = sa.V[IndexsA0] OP sb.V[IndexsB0];\
    ret.y = sa.V[IndexsA1] OP sb.V[IndexsB1];\
    ret.z = sa.V[IndexsA2] OP sb.V[IndexsB2];\
    ret.w = sa.V[IndexsA3] OP sb.V[IndexsB3];\
    return ret;\
}\


#define MathVector_PerComp_BinaryIntegerOperator(OP) \
template<typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true> \
inline MathVector<T, 2> operator OP (const MathVector<T, 2>& a, const MathVector<T, 2>& b) noexcept\
{\
    MathVector<T, 2> ret;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 2>operator OP (const MathVector<T, 2>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 2> ret;\
    T b = (T)ob;\
    ret.x = a.x OP b;\
    ret.y = a.y OP b;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 2>operator OP (const VTOth& ob, const MathVector<T, 2>& a) noexcept\
{\
    MathVector<T, 2> ret;\
    T b = (T)ob;\
    ret.x = b OP a.x;\
    ret.y = b OP a.y;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, MathVector<T, 2>>::value, bool> = true> \
inline MathVector<T, 2>operator OP (const MathVector<T, 2>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 2> ret;\
    MathVector<T, 2> b = ob;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, MathVector<T, 2>>::value, bool> = true> \
inline MathVector<T, 2>operator OP (const VTOth& ob, const MathVector<T, 2>& a) noexcept\
{\
    MathVector<T, 2> ret;\
    MathVector<T, 2> b = ob;\
    ret.x = b.x OP a.x;\
    ret.y = b.y OP a.y;\
    return ret;\
}\
template<typename T, size_t SDimA, size_t IndexsA0, size_t IndexsA1, size_t SDimB, size_t IndexsB0, size_t IndexsB1\
, std::enable_if_t<std::is_integral<T>::value, bool> = true>\
inline MathVector<T, 2> operator OP (const Swizzle<T, SDimA, IndexsA0, IndexsA1>& sa, const Swizzle<T, SDimB, IndexsB0, IndexsB1>& sb) noexcept\
{\
    MathVector<T, 2> ret;\
    ret.x = sa.V[IndexsA0] OP sb.V[IndexsB0];\
    ret.y = sa.V[IndexsA1] OP sb.V[IndexsB1];\
    return ret;\
}\
template<typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true> \
inline MathVector<T, 3> operator OP (const MathVector<T, 3>& a, const MathVector<T, 3>& b) noexcept\
{\
    MathVector<T, 3> ret;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 3>operator OP (const MathVector<T, 3>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 3> ret;\
    T b = (T)ob;\
    ret.x = a.x OP b;\
    ret.y = a.y OP b;\
    ret.z = a.z OP b;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 3>operator OP (const VTOth& ob, const MathVector<T, 3>& a) noexcept\
{\
    MathVector<T, 3> ret;\
    T b = (T)ob;\
    ret.x = b OP a.x;\
    ret.y = b OP a.y;\
    ret.z = b OP a.z;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, MathVector<T, 3>>::value, bool> = true> \
inline MathVector<T, 3>operator OP (const MathVector<T, 3>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 3> ret;\
    MathVector<T, 3> b = ob;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, MathVector<T, 3>>::value, bool> = true> \
inline MathVector<T, 3>operator OP (const VTOth& ob, const MathVector<T, 3>& a) noexcept\
{\
    MathVector<T, 3> ret;\
    MathVector<T, 3> b = ob;\
    ret.x = b.x OP a.x;\
    ret.y = b.y OP a.y;\
    ret.z = b.z OP a.z;\
    return ret;\
}\
template<typename T, size_t SDimA, size_t IndexsA0, size_t IndexsA1, size_t IndexsA2, size_t SDimB, size_t IndexsB0, size_t IndexsB1, size_t IndexsB2,\
 std::enable_if_t<std::is_integral<T>::value, bool> = true>\
inline MathVector<T, 3> operator OP (const Swizzle<T, SDimA, IndexsA0, IndexsA1, IndexsA2>& sa, const Swizzle<T, SDimB, IndexsB0, IndexsB1, IndexsB2>& sb) noexcept\
{\
    MathVector<T, 3> ret;\
    ret.x = sa.V[IndexsA0] OP sb.V[IndexsB0];\
    ret.y = sa.V[IndexsA1] OP sb.V[IndexsB1];\
    ret.z = sa.V[IndexsA2] OP sb.V[IndexsB2];\
    return ret;\
}\
template<typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true> \
inline MathVector<T, 4> operator OP (const MathVector<T, 4>& a, const MathVector<T, 4>& b) noexcept\
{\
    MathVector<T, 4> ret;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    ret.w = a.w OP b.w;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 4>operator OP (const MathVector<T, 4>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 4> ret;\
    T b = (T)ob;\
    ret.x = a.x OP b;\
    ret.y = a.y OP b;\
    ret.z = a.z OP b;\
    ret.w = a.w OP b;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, 4>operator OP (const VTOth& ob, const MathVector<T, 4>& a) noexcept\
{\
    MathVector<T, 4> ret;\
    T b = (T)ob;\
    ret.x = b OP a.x;\
    ret.y = b OP a.y;\
    ret.z = b OP a.z;\
    ret.w = b OP a.w;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, MathVector<T, 4>>::value, bool> = true> \
inline MathVector<T, 4>operator OP (const MathVector<T, 4>& a, const VTOth& ob) noexcept\
{\
    MathVector<T, 4> ret;\
    MathVector<T, 4> b = ob;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    ret.w = a.w OP b.w;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, MathVector<T, 4>>::value, bool> = true> \
inline MathVector<T, 4>operator OP (const VTOth& ob, const MathVector<T, 4>& a) noexcept\
{\
    MathVector<T, 4> ret;\
    MathVector<T, 4> b = ob;\
    ret.x = b.x OP a.x;\
    ret.y = b.y OP a.y;\
    ret.z = b.z OP a.z;\
    ret.w = b.w OP a.w;\
    return ret;\
}\
template<typename T, size_t SDimA, size_t IndexsA0, size_t IndexsA1, size_t IndexsA2, size_t IndexsA3,\
 size_t SDimB, size_t IndexsB0, size_t IndexsB1, size_t IndexsB2, size_t IndexsB3, \
 std::enable_if_t<std::is_integral<T>::value, bool> = true>\
inline MathVector<T, 4> operator OP (const Swizzle<T, SDimA, IndexsA0, IndexsA1, IndexsA2, IndexsA3>& sa, const Swizzle<T, SDimB, IndexsB0, IndexsB1, IndexsB2, IndexsB3>& sb) noexcept\
{\
    MathVector<T, 4> ret;\
    ret.x = sa.V[IndexsA0] OP sb.V[IndexsB0];\
    ret.y = sa.V[IndexsA1] OP sb.V[IndexsB1];\
    ret.z = sa.V[IndexsA2] OP sb.V[IndexsB2];\
    ret.w = sa.V[IndexsA3] OP sb.V[IndexsB3];\
    return ret;\
}\

#define MathVector_PerComp_BinaryCompareOperator(OP) \
template<typename T> \
inline Bool2 operator OP (const MathVector<T, 2>& a, const MathVector<T, 2>& b) noexcept\
{\
    Bool2 ret;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline Bool2 operator OP (const MathVector<T, 2>& a, const VTOth& ob) noexcept\
{\
    Bool2 ret;\
    T b = (T)ob;\
    ret.x = a.x OP b;\
    ret.y = a.y OP b;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline Bool2 operator OP (const VTOth& ob, const MathVector<T, 2>& a) noexcept\
{\
    Bool2 ret;\
    T b = (T)ob;\
    ret.x = b OP a.x;\
    ret.y = b OP a.y;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 2>>::value, bool> = true> \
inline Bool2 operator OP (const MathVector<T, 2>& a, const VTOth& ob) noexcept\
{\
    Bool2 ret;\
    MathVector<T, 2> b = ob;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 2>>::value, bool> = true> \
inline Bool2 operator OP (const VTOth& ob, const MathVector<T, 2>& a) noexcept\
{\
    Bool2 ret;\
    MathVector<T, 2> b = ob;\
    ret.x = b.x OP a.x;\
    ret.y = b.y OP a.y;\
    return ret;\
}\
template<typename T, size_t SDimA, size_t IndexsA0, size_t IndexsA1, size_t SDimB, size_t IndexsB0, size_t IndexsB1>\
inline Bool2 operator OP (const Swizzle<T, SDimA, IndexsA0, IndexsA1>& sa, const Swizzle<T, SDimB, IndexsB0, IndexsB1>& sb) noexcept\
{\
    Bool2 ret;\
    ret.x = sa.V[IndexsA0] OP sb.V[IndexsB0];\
    ret.y = sa.V[IndexsA1] OP sb.V[IndexsB1];\
    return ret;\
}\
template<typename T> \
inline Bool3 operator OP (const MathVector<T, 3>& a, const MathVector<T, 3>& b) noexcept\
{\
    Bool3 ret;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline Bool3 operator OP (const MathVector<T, 3>& a, const VTOth& ob) noexcept\
{\
    Bool3 ret;\
    T b = (T)ob;\
    ret.x = a.x OP b;\
    ret.y = a.y OP b;\
    ret.z = a.z OP b;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline Bool3 operator OP (const VTOth& ob, const MathVector<T, 3>& a) noexcept\
{\
    Bool3 ret;\
    T b = (T)ob;\
    ret.x = b OP a.x;\
    ret.y = b OP a.y;\
    ret.z = b OP a.z;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 3>>::value, bool> = true> \
inline Bool3 operator OP (const MathVector<T, 3>& a, const VTOth& ob) noexcept\
{\
    Bool3 ret;\
    MathVector<T, 3> b = ob;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 3>>::value, bool> = true> \
inline Bool3 operator OP (const VTOth& ob, const MathVector<T, 3>& a) noexcept\
{\
    Bool3 ret;\
    MathVector<T, 3> b = ob;\
    ret.x = b.x OP a.x;\
    ret.y = b.y OP a.y;\
    ret.z = b.z OP a.z;\
    return ret;\
}\
template<typename T, size_t SDimA, size_t IndexsA0, size_t IndexsA1, size_t IndexsA2, size_t SDimB, size_t IndexsB0, size_t IndexsB1, size_t IndexsB2>\
inline Bool3 operator OP (const Swizzle<T, SDimA, IndexsA0, IndexsA1, IndexsA2>& sa, const Swizzle<T, SDimB, IndexsB0, IndexsB1, IndexsB2>& sb) noexcept\
{\
    Bool3 ret;\
    ret.x = sa.V[IndexsA0] OP sb.V[IndexsB0];\
    ret.y = sa.V[IndexsA1] OP sb.V[IndexsB1];\
    ret.z = sa.V[IndexsA2] OP sb.V[IndexsB2];\
    return ret;\
}\
template<typename T> \
inline Bool4 operator OP (const MathVector<T, 4>& a, const MathVector<T, 4>& b) noexcept\
{\
    Bool4 ret;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    ret.w = a.w OP b.w;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline Bool4 operator OP (const MathVector<T, 4>& a, const VTOth& ob) noexcept\
{\
    Bool4 ret;\
    T b = (T)ob;\
    ret.x = a.x OP b;\
    ret.y = a.y OP b;\
    ret.z = a.z OP b;\
    ret.w = a.w OP b;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline Bool4 operator OP (const VTOth& ob, const MathVector<T, 4>& a) noexcept\
{\
    Bool4 ret;\
    T b = (T)ob;\
    ret.x = b OP a.x;\
    ret.y = b OP a.y;\
    ret.z = b OP a.z;\
    ret.w = b OP a.w;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 4>>::value, bool> = true> \
inline Bool4 operator OP (const MathVector<T, 4>& a, const VTOth& ob) noexcept\
{\
    Bool4 ret;\
    MathVector<T, 4> b = ob;\
    ret.x = a.x OP b.x;\
    ret.y = a.y OP b.y;\
    ret.z = a.z OP b.z;\
    ret.w = a.w OP b.w;\
    return ret;\
}\
template<typename T, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, 4>>::value, bool> = true> \
inline Bool4 operator OP (const VTOth& ob, const MathVector<T, 4>& a) noexcept\
{\
    Bool4 ret;\
    MathVector<T, 4> b = ob;\
    ret.x = b.x OP a.x;\
    ret.y = b.y OP a.y;\
    ret.z = b.z OP a.z;\
    ret.w = b.w OP a.w;\
    return ret;\
}\
template<typename T, size_t SDimA, size_t IndexsA0, size_t IndexsA1, size_t IndexsA2, size_t IndexsA3, size_t SDimB, size_t IndexsB0, size_t IndexsB1, size_t IndexsB2, size_t IndexsB3>\
inline Bool4 operator OP (const Swizzle<T, SDimA, IndexsA0, IndexsA1, IndexsA2, IndexsA3>& sa, const Swizzle<T, SDimB, IndexsB0, IndexsB1, IndexsB2, IndexsB3>& sb) noexcept\
{\
    Bool4 ret;\
    ret.x = sa.V[IndexsA0] OP sb.V[IndexsB0];\
    ret.y = sa.V[IndexsA1] OP sb.V[IndexsB1];\
    ret.z = sa.V[IndexsA2] OP sb.V[IndexsB2];\
    ret.w = sa.V[IndexsA3] OP sb.V[IndexsB3];\
    return ret;\
}\

#define MathVector_PerComp_SelfOperator(OP, OPBase) \
template<typename T, size_t Dim> \
inline MathVector<T, Dim>& operator OP (MathVector<T, Dim>& a, const MathVector<T, Dim>& b) noexcept\
{\
    a = a OPBase b;\
    return a;\
}\
template<typename T, size_t Dim, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, Dim>& operator OP (MathVector<T, Dim>& a, const VTOth& ob) noexcept\
{\
    a = a OPBase ob;\
    return a;\
}\
template<typename T, size_t Dim, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, Dim>>::value, bool> = true> \
inline MathVector<T, Dim>& operator OP (MathVector<T, Dim>& a, const VTOth& ob) noexcept\
{\
    a = a OPBase ob;\
    return a;\
}\
template<typename T, size_t SDim, size_t... Indexs, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<T, sizeof...(Indexs)>>::value, bool> = true> \
inline Swizzle<T, SDim, Indexs...>& operator OP (Swizzle<T, SDim, Indexs...>& s, const VTOth& ob) noexcept\
{\
    MathVector<T, sizeof...(Indexs)> b = ob;\
    s = s OPBase b;\
    return s;\
}\


#define MathVector_PerComp_SelfIntegerOperator(OP, OPBase) \
template<typename T, size_t Dim, std::enable_if_t<std::is_integral<T>::value, bool> = true> \
inline MathVector<T, Dim>& operator OP (MathVector<T, Dim>& a, const MathVector<T, Dim>& b) noexcept\
{\
    a = a OPBase b;\
    return a;\
}\
template<typename T, size_t Dim, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, T>::value, bool> = true> \
inline MathVector<T, Dim>& operator OP (MathVector<T, Dim>& a, const VTOth& ob) noexcept\
{\
    a = a OPBase ob;\
    return a;\
}\
template<typename T, size_t Dim, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, MathVector<T, Dim>>::value, bool> = true> \
inline MathVector<T, Dim>& operator OP (MathVector<T, Dim>& a, const VTOth& ob) noexcept\
{\
    a = a OPBase ob;\
    return a;\
}\
template<typename T, size_t SDim, size_t... Indexs, typename VTOth, std::enable_if_t<std::is_integral<T>::value && std::is_convertible<VTOth&, MathVector<T, sizeof...(Indexs)>>::value, bool> = true> \
inline Swizzle<T, SDim, Indexs...>& operator OP (Swizzle<T, SDim, Indexs...>& s, const VTOth& ob) noexcept\
{\
    MathVector<T, sizeof...(Indexs)> b = ob;\
    s = s OPBase b;\
    return s;\
}\

namespace Math
{
    // operator +
    MathVector_PerComp_BinaryOperator(+);

    // operator -
    MathVector_PerComp_BinaryOperator(-);

    // operator *
    MathVector_PerComp_BinaryOperator(*);

    // operator /
    MathVector_PerComp_BinaryOperator(/);

    // operator %
    MathVector_PerComp_BinaryIntegerOperator(%);

    template<size_t Dim>
    MathVector<Float, Dim> operator%(const MathVector<Float, Dim>& a, const MathVector<Float, Dim>& b)
    {
        return Fmod(a, b);
    }
    template<size_t Dim>
    MathVector<Double, Dim> operator%(const MathVector<Double, Dim>& a, const MathVector<Double, Dim>& b)
    {
        return Fmod(a, b);
    }
    template<size_t Dim, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<Float, Dim>>::value, bool> = true>
    MathVector<Float, Dim> operator%(const MathVector<Float, Dim>& a, const VTOth& ob)
    {
        MathVector<Float, Dim> b = (MathVector<Float, Dim>)ob;
        return Fmod(a, b);
    }
    template<size_t Dim, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<Double, Dim>>::value, bool> = true>
    MathVector<Double, Dim> operator%(const MathVector<Double, Dim>& a, const VTOth& ob)
    {
        MathVector<Double, Dim> b = (MathVector<Double, Dim>)ob;
        return Fmod(a, b);
    }
    template<size_t Dim, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<Float, Dim>>::value, bool> = true>
    MathVector<Float, Dim> operator%(const VTOth& ob, const MathVector<Float, Dim>& a)
    {
        MathVector<Float, Dim> b = (MathVector<Float, Dim>)ob;
        return Fmod(b, a);
    }
    template<size_t Dim, typename VTOth, std::enable_if_t<std::is_convertible<VTOth&, MathVector<Double, Dim>>::value, bool> = true>
    MathVector<Double, Dim> operator%(const VTOth& ob, const MathVector<Double, Dim>& a)
    {
        MathVector<Double, Dim> b = (MathVector<Double, Dim>)ob;
        return Fmod(b, a);
    }
    template<size_t SDim0, size_t... Indexs0, typename T, size_t SDim1, size_t... Indexs1,
        std::enable_if_t<std::is_floating_point<T>::value && sizeof...(Indexs0) == sizeof...(Indexs1), bool> = true>
    inline MathVector<T, sizeof...(Indexs0)> operator%(const Swizzle<T, SDim0, Indexs0...>& sa, const Swizzle<T, SDim1, Indexs1...>& sb)
    {
        MathVector<T, sizeof...(Indexs0)> a = sa;
        MathVector<T, sizeof...(Indexs0)> b = sb;
        return Fmod(a, b);
    }

    //template<size_t Dim>
    //MathVector<Float, Dim>& operator%=(MathVector<Float, Dim>& a, MathVector<Float, Dim> b)
    //{
    //    a = Fmod(a, b);
    //    return a;
    //}
    //template<size_t Dim>
    //MathVector<Double, Dim>& operator%=(MathVector<Double, Dim>& a, MathVector<Double, Dim> b)
    //{
    //    a = Fmod(a, b);
    //    return a;
    //}

    // operator +=
    MathVector_PerComp_SelfOperator(+=, +);

    // operator -=
    MathVector_PerComp_SelfOperator(-=, -);

    // operator *=
    MathVector_PerComp_SelfOperator(*=, *);

    // operator /=
    MathVector_PerComp_SelfOperator(/=, /);

    // operator %=
    MathVector_PerComp_SelfOperator(%=, %);

    // operator -V
    template<typename T>
    inline MathVector<T, 2> operator-(const MathVector<T, 2>& a)
    {
        MathVector<T, 2> ret;
        ret.x = -a.x;
        ret.y = -a.y;
        return ret;
    }
    template<typename T>
    inline MathVector<T, 3> operator-(const MathVector<T, 3>& a)
    {
        MathVector<T, 3> ret;
        ret.x = -a.x;
        ret.y = -a.y;
        ret.z = -a.z;
        return ret;
    }
    template<typename T>
    inline MathVector<T, 4> operator-(const MathVector<T, 4>& a)
    {
        MathVector<T, 4> ret;
        ret.x = -a.x;
        ret.y = -a.y;
        ret.z = -a.z;
        ret.w = -a.w;
        return ret;
    }
    template<typename T, size_t SDim, size_t... Indexs>
    inline MathVector<T, sizeof...(Indexs)> operator-(const Swizzle<T, SDim, Indexs...>& a)
    {
        MathVector<T, sizeof...(Indexs)> ret = a;
        return -ret;
    }

    // operator ~V
    template<typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    inline MathVector<T, 2> operator~(const MathVector<T, 2>& a)
    {
        MathVector<T, 2> ret;
        ret.x = ~a.x;
        ret.y = ~a.y;
        return ret;
    }
    template<typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    inline MathVector<T, 3> operator~(const MathVector<T, 3>& a)
    {
        MathVector<T, 3> ret;
        ret.x = ~a.x;
        ret.y = ~a.y;
        ret.z = ~a.z;
        return ret;
    }
    template<typename T, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    inline MathVector<T, 4> operator~(const MathVector<T, 4>& a)
    {
        MathVector<T, 4> ret;
        ret.x = ~a.x;
        ret.y = ~a.y;
        ret.z = ~a.z;
        ret.w = ~a.w;
        return ret;
    }
    template<typename T, size_t SDim, size_t... Indexs, std::enable_if_t<std::is_integral<T>::value, bool> = true>
    inline MathVector<T, sizeof...(Indexs)> operator~(const Swizzle<T, SDim, Indexs...>& a)
    {
        MathVector<T, sizeof...(Indexs)> ret = a;
        return ~ret;
    }

    // operator ++V
    template<typename T>
    inline MathVector<T, 2>& operator++(MathVector<T, 2>& a)
    {
        MathVector<T, 2> ret;
        ++a.x;
        ++a.y;
        return a;
    }
    template<typename T>
    inline MathVector<T, 3>& operator++(MathVector<T, 3>& a)
    {
        ++a.x;
        ++a.y;
        ++a.z;
        return a;
    }
    template<typename T>
    inline MathVector<T, 4>& operator++(MathVector<T, 4>& a)
    {
        ++a.x;
        ++a.y;
        ++a.z;
        ++a.w;
        return a;
    }
    template<typename T, size_t SDim, size_t... Indexs>
    inline Swizzle<T, SDim, Indexs...>& operator++(Swizzle<T, SDim, Indexs...>& a)
    {
        MathVector<T, sizeof...(Indexs)> v = a;
        a = ++v;
        return a;
    }

    // operator --V
    template<typename T>
    inline MathVector<T, 2>& operator--(MathVector<T, 2>& a)
    {
        MathVector<T, 2> ret;
        --a.x;
        --a.y;
        return a;
    }
    template<typename T>
    inline MathVector<T, 3>& operator--(MathVector<T, 3>& a)
    {
        --a.x;
        --a.y;
        --a.z;
        return a;
    }
    template<typename T>
    inline MathVector<T, 4>& operator--(MathVector<T, 4>& a)
    {
        --a.x;
        --a.y;
        --a.z;
        --a.w;
        return a;
    }
    template<typename T, size_t SDim, size_t... Indexs>
    inline Swizzle<T, SDim, Indexs...>& operator--(Swizzle<T, SDim, Indexs...>& a)
    {
        MathVector<T, sizeof...(Indexs)> v = a;
        a = --v;
        return a;
    }

    // operator V++
    template<typename T>
    inline MathVector<T, 2> operator++(MathVector<T, 2>& a, int)
    {
        MathVector<T, 2> ret = a;
        ++a.x;
        ++a.y;
        return ret;
    }
    template<typename T>
    inline MathVector<T, 3> operator++(MathVector<T, 3>& a, int)
    {
        MathVector<T, 3> ret = a;
        ++a.x;
        ++a.y;
        ++a.z;
        return ret;
    }
    template<typename T>
    inline MathVector<T, 4> operator++(MathVector<T, 4>& a, int)
    {
        MathVector<T, 4> ret = a;
        ++a.x;
        ++a.y;
        ++a.z;
        ++a.w;
        return ret;
    }
    template<typename T, size_t SDim, size_t... Indexs>
    inline MathVector<T, sizeof...(Indexs)> operator++(Swizzle<T, SDim, Indexs...>& a, int)
    {
        MathVector<T, sizeof...(Indexs)> v = a;
        a = ++v;
        return v;
    }

    // operator !
    inline Bool2 operator!(const Bool2& a)
    {
        Bool2 ret;
        ret.x = !a.x;
        ret.y = !a.y;
        return ret;
    }
    inline Bool3 operator!(const Bool3& a)
    {
        Bool3 ret;
        ret.x = !a.x;
        ret.y = !a.y;
        ret.z = !a.z;
        return ret;
    }
    inline Bool4 operator!(const Bool4& a)
    {
        Bool4 ret;
        ret.x = !a.x;
        ret.y = !a.y;
        ret.z = !a.z;
        ret.w = !a.w;
        return ret;
    }
    template<typename Bool, size_t SDim, size_t... Indexs>
    inline MathVector<Bool, sizeof...(Indexs)> operator~(const Swizzle<Bool, SDim, Indexs...>& a)
    {
        MathVector<Bool, sizeof...(Indexs)> ret = a;
        return !ret;
    }

    // operator &
    MathVector_PerComp_BinaryIntegerOperator(&);

    // operator |
    MathVector_PerComp_BinaryIntegerOperator(|);

    // operator ^
    MathVector_PerComp_BinaryIntegerOperator(^);

    // operator <<
    MathVector_PerComp_BinaryIntegerOperator(<<);

    // operator >>
    MathVector_PerComp_BinaryIntegerOperator(>>);

    // operator &=
    MathVector_PerComp_SelfIntegerOperator(&=, &);

    // operator |=
    MathVector_PerComp_SelfIntegerOperator(|=, |);

    // operator ^=
    MathVector_PerComp_SelfIntegerOperator(^=, ^);

    // operator <<=
    MathVector_PerComp_SelfIntegerOperator(<<=, <<);

    // operator >>=
    MathVector_PerComp_SelfIntegerOperator(>>=, >>);

    // operator ==
    MathVector_PerComp_BinaryCompareOperator(==)

    // operator !=
    MathVector_PerComp_BinaryCompareOperator(!=);

    // operator <
    MathVector_PerComp_BinaryCompareOperator(<);

    // operator >
    MathVector_PerComp_BinaryCompareOperator(>);

    // operator <=
    MathVector_PerComp_BinaryCompareOperator(<=);

    // operator >=
    MathVector_PerComp_BinaryCompareOperator(>=);

}