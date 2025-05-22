// Mathing.cpp: 定义应用程序的入口点。
//

#include "Mathing.h"

#define ENABLE_SIMD_MATH
#include "Math.h"
#include "SphericalHarmonic.h"

using namespace std;

Math::Swizzle<float, 3, 0, 1, 2> S0;
Math::Swizzle<float, 4, 1, 1, 3> S1;
Math::Swizzle<float, 2, 1> S2;
Math::Swizzle<float, 2, 0> S3;

int main()
{
	cout << "Hello CMake." << endl;

	//Test Swizzle
	S0.V[0] = 1;
	S0.V[1] = 2;
	S0.V[2] = 3;

	S1.V[0] = 1;
	S1.V[1] = 2;
	S1.V[2] = 3;
	S1.V[3] = 4;

	S2.V[0] = 6;
	S2.V[1] = 7;

	S3.V[0] = 0;
	S3.V[1] = 0;

	S0 = S1;
	//S1 = S2;
	//S2 = S0;
	S3 = S2;

	//int x = S0;
	//int x = S2;
	//auto t = S0;
	auto& t = S0;

	/*Math::SwizzleGenerate(1);
	Math::SwizzleGenerate(2);
	Math::SwizzleGenerate(3);
	Math::SwizzleGenerate(4);*/

	/*Math::SimdSwizzleGenerate(1, "float");
	Math::SimdSwizzleGenerate(2, "float");
	Math::SimdSwizzleGenerate(3, "float");
	Math::SimdSwizzleGenerate(4, "float");*/

	Math::Float2 a(0, 1);
	Math::Float3 b(4, -5, 6);
	Math::Float3 bb(a, 0);

	a.yx += b.xy;

	a.y = b.z;
	a.yx = b.xz;
	b.yz = 89;

	//a %= a;
	a = a % a;
	//a = a + a;

	b.xz = -a;
	b.xy = -a.xx;

	++b.xy;
	a = 0.1f;

	auto com = b.xy > bb.yx;

	//auto pp = a + 1;
	//auto pp = 1 + a;
	//auto pp = a + b.xy;
	//auto pp = a + "aaddd";
	//auto pp = b + bb;
	auto sp = /*(Math::Float3)*/b.yxx % bb;
	sp = Math::Fmod(b.yxx, bb);

	sp = b.yxy % bb.xxx; // todo
	//sp = b.yxy % bb.xx;
	sp.zy = b.yx + bb.xx;
	sp = b.yxy + bb.xxx; // todo

	

	bool test_cov = std::is_convertible<Math::Swizzle<Math::Float, 3, 0, 1>, Math::Float2>();

	Math::Float4 c = { 0, 0, 1, 1 };
	c.xyz = Math::Float3( 3, 3, 4 );

	auto ab = Math::Abs(b);

	float tf = 1.0f;
	auto atf = Math::Abs(tf);
	double td = -3;
	auto atd = Math::Abs(td);

	//auto mtd = Math::Fmod(tf, td); todo ??

	{
		float a, b;
		cin >> a >> b;

		Math::float1 ssef1;
		Math::float2 ssef2(a, b);
		//Math::float3 ssef3 = ssef2.y;
		ssef1 = ssef2.y;
		ssef2 = ssef2.yx;
		//Math::float3 ssef3(ssef1, ssef2);
		//Math::float3 ssef3(1, ssef2);
		//Math::float3 ssef3(1, ssef1, 2);
		Math::float3 ssef3(1, (float)ssef1, ssef2.y);
		ssef3.xy = ssef2;
		ssef2.x = ssef1;
		Math::Float2 f2 = (Math::Float2)ssef2;
		f2 = ssef2.yx;
		Math::UInt2 i2 = (Math::UInt2)ssef2;
		cout << ssef1.v[0] << std::endl;
		cout << ssef2.v[0] << std::endl;
		cout << ssef2.v[1] << std::endl;

		Math::float2 ssef2_1(a, b);
		ssef2_1 = ssef2_1 + ssef2;
		cout << ssef2_1.v[0] << std::endl;
		cout << ssef2_1.v[1] << std::endl;
		ssef2_1 = ssef2_1 + ssef1;
		cout << ssef2_1.v[0] << std::endl;
		cout << ssef2_1.v[1] << std::endl;
		ssef2_1 = ssef2_1 + 0.5f;
		cout << ssef2_1.v[0] << std::endl;
		cout << ssef2_1.v[1] << std::endl;
		ssef2_1 = 1 + ssef2_1;
		cout << ssef2_1.v[0] << std::endl;
		cout << ssef2_1.v[1] << std::endl;
		ssef2_1 += ssef1;
		cout << ssef2_1.v[0] << std::endl;
		cout << ssef2_1.v[1] << std::endl;
		ssef2_1 += ssef2;
		cout << ssef2_1.v[0] << std::endl;
		cout << ssef2_1.v[1] << std::endl;
		ssef2_1 += 1;
		cout << ssef2_1.v[0] << std::endl;
		cout << ssef2_1.v[1] << std::endl;

		//auto t = Math::abs(ssef3);
		auto t = Math::abs(ssef3.yzz);

		ssef2_1 = ssef2_1 + 0;
		ssef2_1 = ssef2_1.yx + 1;
		ssef2_1.x *= ssef2_1.y;
		ssef2_1.xy -= ssef2_1;
	}

	return 0;
}


