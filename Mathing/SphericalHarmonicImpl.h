#include "SphericalHarmonic.h"
#pragma once

namespace Math
{
	// https://cseweb.ucsd.edu/~ravir/papers/envmap/envmap.pdf
	// https://seblagarde.wordpress.com/2012/01/08/pi-or-not-to-pi-in-game-lighting-equation/
	template<typename T, size_t Order>
	inline SH<T, Order> SH<T, Order>::RadianceToIrradiance() const noexcept
	{
		SH<T, Order> ret;
		ret.V[0] = V[0] * L0IrradianceFactor;
		ret.V[1] = V[1] * L1IrradianceFactor;
		ret.V[2] = V[2] * L1IrradianceFactor;
		ret.V[3] = V[3] * L1IrradianceFactor;

		if constexpr (Order > 2)
		{
			ret.V[4] = V[4] * L2IrradianceFactor;
			ret.V[5] = V[5] * L2IrradianceFactor;
			ret.V[6] = V[6] * L2IrradianceFactor;
			ret.V[7] = V[7] * L2IrradianceFactor;
			ret.V[8] = V[8] * L2IrradianceFactor;
		}

		return ret;
	}

	template<typename T, size_t Order>
	inline SH<T, Order> SH<T, Order>::RadianceToDiffuseRadiance() const noexcept
	{
		SH<T, Order> ret;
		ret.V[0] = V[0];
		ret.V[1] = V[1] * L1DiffuseRadianceFactor;
		ret.V[2] = V[2] * L1DiffuseRadianceFactor;
		ret.V[3] = V[3] * L1DiffuseRadianceFactor;

		if constexpr (Order > 2)
		{
			ret.V[4] = V[4] * L2DiffuseRadianceFactor;
			ret.V[5] = V[5] * L2DiffuseRadianceFactor;
			ret.V[6] = V[6] * L2DiffuseRadianceFactor;
			ret.V[7] = V[7] * L2DiffuseRadianceFactor;
			ret.V[8] = V[8] * L2DiffuseRadianceFactor;
		}

		return ret;
	}

	template<typename T, size_t Order>
	inline SH<T, Order> SH<T, Order>::PreMultCoeffs() const noexcept
	{
		SH<T, Order> ret;
		ret.V[0] = V[0] * L0Basis;
		ret.V[1] = V[1] * -L1Basis;
		ret.V[2] = V[2] * L1Basis;
		ret.V[3] = V[3] * -L1Basis;

		if constexpr (Order > 2)
		{
			ret.V[4] = V[4] * L2xBasis;
			ret.V[5] = V[5] * -L2xBasis;
			ret.V[6] = V[6] * L20Basis;
			ret.V[7] = V[7] * -L2xBasis;
			ret.V[8] = V[8] * L22Basis;
		}

		return ret;
	}

	// Compress SHs
	// Precomputed Lighting Advances in Call of Duty: Modern Warfare
	// Store DC in FP(11f11f10f, half, bc6h...). Divide higher term by DC, store in ldr[-1, 1] or map to [0, 1]
	template<typename T, size_t Order>
	inline SH<T, Order> SH<T, Order>::CompressRaw() const noexcept // Compress Raw SH
	{
		T invDC = 1.0f / V[0];
		SH<T, Order> ret;
		ret.V[0] = V[0];
		T scale1 = invDC * L1RawCompressScale;
		ret.V[1] = Clamp<T>(V[1] * scale1, -1, 1);
		ret.V[2] = Clamp<T>(V[2] * scale1, -1, 1);
		ret.V[3] = Clamp<T>(V[3] * scale1, -1, 1);

		if constexpr (Order > 2)
		{
			T scale2 = invDC * L2RawCompressScale;
			ret.V[4] = Clamp<T>(V[4] * scale2, -1, 1);
			ret.V[5] = Clamp<T>(V[5] * scale2, -1, 1);
			ret.V[6] = Clamp<T>(V[6] * scale2, -1, 1);
			ret.V[7] = Clamp<T>(V[7] * scale2, -1, 1);
			ret.V[8] = Clamp<T>(V[8] * scale2, -1, 1);
		}

		return ret;
	}
	template<typename T, size_t Order>
	inline SH<T, Order> SH<T, Order>::CompressRawIrradiance() const noexcept // Compress Irradiance or DiffuseRadiance
	{
		T invDC = 1.0f / V[0];
		SH<T, Order> ret;
		ret.V[0] = V[0];
		T scale1 = invDC * L1RawIrradianceCompressScale;
		ret.V[1] = Clamp<T>(V[1] * scale1, -1, 1);
		ret.V[2] = Clamp<T>(V[2] * scale1, -1, 1);
		ret.V[3] = Clamp<T>(V[3] * scale1, -1, 1);

		if constexpr (Order > 2)
		{
			T scale2 = invDC * L2RawIrradianceCompressScale;
			ret.V[4] = Clamp<T>(V[4] * scale2, -1, 1);
			ret.V[5] = Clamp<T>(V[5] * scale2, -1, 1);
			ret.V[6] = Clamp<T>(V[6] * scale2, -1, 1);
			ret.V[7] = Clamp<T>(V[7] * scale2, -1, 1);
			ret.V[8] = Clamp<T>(V[8] * scale2, -1, 1);
		}

		return ret;
	}
	template<typename T, size_t Order>
	inline SH<T, Order> SH<T, Order>::CompressPreMul() const noexcept // Compress PreMuled SH
	{
		T invDC = 1.0f / V[0];
		SH<T, Order> ret;
		ret.V[0] = V[0];
		T scale1 = invDC * L1PreMulCompressScale;
		ret.V[1] = Clamp<T>(V[1] * scale1, -1, 1);
		ret.V[2] = Clamp<T>(V[2] * scale1, -1, 1);
		ret.V[3] = Clamp<T>(V[3] * scale1, -1, 1);

		if constexpr (Order > 2)
		{
			T scale2 = invDC * L2PreMulCompressScale;
			ret.V[4] = Clamp<T>(V[4] * scale2, -1, 1);
			ret.V[5] = Clamp<T>(V[5] * scale2, -1, 1);
			ret.V[6] = Clamp<T>(V[6] * scale2, -1, 1);
			ret.V[7] = Clamp<T>(V[7] * scale2, -1, 1);
			ret.V[8] = Clamp<T>(V[8] * scale2, -1, 1);
		}

		return ret;
	}
	template<typename T, size_t Order>
	inline SH<T, Order> SH<T, Order>::CompressPreMulIrradiance() const noexcept // Compress PreMuled Irradiance or DiffuseRadiance
	{
		T invDC = 1.0f / V[0];
		SH<T, Order> ret;
		ret.V[0] = V[0];
		T scale1 = invDC * L1PreMulIrradianceCompressScale;
		ret.V[1] = Clamp<T>(V[1] * scale1, -1, 1);
		ret.V[2] = Clamp<T>(V[2] * scale1, -1, 1);
		ret.V[3] = Clamp<T>(V[3] * scale1, -1, 1);

		if constexpr (Order > 2)
		{
			T scale2 = invDC * L2PreMulIrradianceCompressScale;
			ret.V[4] = Clamp<T>(V[4] * scale2, -1, 1);
			ret.V[5] = Clamp<T>(V[5] * scale2, -1, 1);
			ret.V[6] = Clamp<T>(V[6] * scale2, -1, 1);
			ret.V[7] = Clamp<T>(V[7] * scale2, -1, 1);
			ret.V[8] = Clamp<T>(V[8] * scale2, -1, 1);
		}

		return ret;
	}

	// https://www.ppsloan.org/publications/StupidSH36.pdf
	//inline SH ToShaderConstants() const noexcept
	//{

	//}

	template<typename T, size_t Order>
	SH<T, Order> SH<T, Order>::operator *(T f)
	{
		SH<T, Order> ret;
		for (size_t i = 0; i < BaseCount; i++)
			ret.V[i] = V[i] * f;
		return ret;
	}
	template<typename T, size_t Order>
	SH<T, Order> SH<T, Order>::operator /(T f)
	{
		SH<T, Order> ret;
		for (size_t i = 0; i < BaseCount; i++)
			ret.V[i] = V[i] / f;
		return ret;
	}

	template<typename T, size_t Order>
	SH<T, Order>& SH<T, Order>::operator *=(T f)
	{
		for (size_t i = 0; i < BaseCount; i++)
			V[i] *= f;
		return *this;
	}
	template<typename T, size_t Order>
	SH<T, Order>& SH<T, Order>::operator /=(T f)
	{
		for (size_t i = 0; i < BaseCount; i++)
			V[i] /= f;
		return *this;
	}

	template<typename T, size_t Order>
	SH<T, Order> SH<T, Order>::operator +(const SH& sh)
	{
		SH<T, Order> ret;
		for (size_t i = 0; i < BaseCount; i++)
			ret.V[i] = V[i] + sh.V[i];
		return ret;
	}
	template<typename T, size_t Order>
	SH<T, Order> SH<T, Order>::operator -(const SH& sh)
	{
		SH<T, Order> ret;
		for (size_t i = 0; i < BaseCount; i++)
			ret.V[i] = V[i] - sh.V[i];
		return ret;
	}

	template<typename T, size_t Order>
	SH<T, Order>& SH<T, Order>::operator +=(const SH& sh)
	{
		for (size_t i = 0; i < BaseCount; i++)
			V[i] += sh.V[i];
		return *this;
	}
	template<typename T, size_t Order>
	SH<T, Order>& SH<T, Order>::operator -=(const SH& sh)
	{
		for (size_t i = 0; i < BaseCount; i++)
			V[i] -= sh.V[i];
		return *this;
	}

	template<typename T, size_t Order>
	T SH<T, Order>::Dot(const SH& sh)
	{
		T ret = 0;
		for (size_t i = 0; i < BaseCount; i++)
			ret += V[i] * sh.V[i];
		return ret;
	}

	template<typename T, size_t Order>
	inline SH<T, Order> SH<T, Order>::Base(const MathVector<T, 3>& vector) noexcept
	{
		SH<T, Order> ret;
		ret.V[0] = SH::L0Base;
		ret.V[1] = -SH::L1Base * vector.y;
		ret.V[2] = SH::L1Base * vector.z;
		ret.V[3] = -SH::L1Base * vector.x;

		if constexpr (Order > 2)
		{
			MathVector<T, 3> v2 = vector * vector;
			ret.V[4] = SH::L2xBasis * vector.x * vector.y;
			ret.V[5] = -SH::L2xBasis * vector.y * vector.z;
			ret.V[6] = SH::L20BasisMul3 * v2.z - SH::L20Basis; //0.315392f * float(3.0f * VectorSquared.Z - 1.0f)
			ret.V[7] = -SH::L2xBasis * vector.x * vector.z;
			ret.V[8] = SH::L22Basis * (v2.x - v2.y);
		}
		return ret;
	}

	
	inline void SH1ShaderConstants::CovertFromSH(const SH1& sh) noexcept
	{
		CovertFromPreMulSH(sh.PreMultCoeffs());
	}

	inline void SH1ShaderConstants::CovertFromPreMulSH(const SH1& sh) noexcept
	{
		A = float4(sh.V[3], sh.V[1], sh.V[2], sh.V[0]);
	}

	inline float1 SH2ShaderConstants::Evaluate(float4 norm) const noexcept
	{
		// Linear + constant polynomial terms
		float1 ret = dot(A, norm);

		// 4 of the quadratic polynomials
		float4 vB = norm.xyzz * norm.yzzx;
		ret += dot(B, vB);

		// Final quadratic polynomial
		float1 vC = norm.x * norm.x - norm.y * norm.y;
		ret += C * vC;
		return ret;
	}

	void SH2ShaderConstants::CovertFromSH(const SH2& sh) noexcept
	{
		CovertFromPreMulSH(sh.PreMultCoeffs());
	}

	void SH2ShaderConstants::CovertFromPreMulSH(const SH2& sh) noexcept
	{
		A = float4(sh.V[3], sh.V[1], sh.V[2], sh.V[0] - sh.V[6]);
		B = float4(sh.V[4], sh.V[5], 3.0f * sh.V[6], sh.V[7]);
		C = sh.V[8];
	}

	inline float3 SH1ColorShaderConstants::Evaluate(float4 norm) const noexcept
	{
		float3 ret(0.0f);
		ret.x = dot(Ar, norm);
		ret.y = dot(Ag, norm);
		ret.z = dot(Ab, norm);
		return ret;
	}

	inline void SH1ColorShaderConstants::CovertFromSH(const SH1Color& sh) noexcept
	{
		SH1ShaderConstants cr, cg, cb;
		cr.CovertFromSH(sh.R);
		cg.CovertFromSH(sh.G);
		cb.CovertFromSH(sh.B);
		Ar = cr.A;
		Ag = cg.A;
		Ab = cb.A;
	}

	inline void SH1ColorShaderConstants::CovertFromPreMulSH(const SH1Color& sh) noexcept
	{
		SH1ShaderConstants cr, cg, cb;
		cr.CovertFromPreMulSH(sh.R);
		cg.CovertFromPreMulSH(sh.G);
		cb.CovertFromPreMulSH(sh.B);
		Ar = cr.A;
		Ag = cg.A;
		Ab = cb.A;
	}

	inline float3 SH2ColorShaderConstants::Evaluate(float4 norm) const noexcept
	{
		float3 x1, x2, x3;

		// Linear + constant polynomial terms
		x1.x = dot(Ar, norm);
		x1.y = dot(Ag, norm);
		x1.z = dot(Ab, norm);

		// 4 of the quadratic polynomials
		float4 vB = norm.xyzz * norm.yzzx;
		x2.x = dot(Br, vB);
		x2.y = dot(Bg, vB);
		x2.z = dot(Bb, vB);

		// Final quadratic polynomial
		float1 vC = norm.x * norm.x - norm.y * norm.y;
		x3 = C.xyz * vC;
		return x1 + x2 + x3;

	}

	inline void SH2ColorShaderConstants::CovertFromSH(const SH2Color& sh) noexcept
	{
		SH2Color preMul;
		preMul.R = sh.R.PreMultCoeffs();
		preMul.G = sh.G.PreMultCoeffs();
		preMul.B = sh.B.PreMultCoeffs();
		CovertFromPreMulSH(preMul);
	}

	inline void SH2ColorShaderConstants::CovertFromPreMulSH(const SH2Color& sh) noexcept
	{
		SH2ShaderConstants cr, cg, cb;
		cr.CovertFromPreMulSH(sh.R);
		cg.CovertFromPreMulSH(sh.G);
		cb.CovertFromPreMulSH(sh.B);
		Ar = cr.A;
		Ag = cg.A;
		Ab = cb.A;
		Br = cr.B;
		Bg = cg.B;
		Bb = cb.B;
		C.x = cr.C;
		C.y = cr.C;
		C.z = cr.C;
		C.w = 0;
	}
}