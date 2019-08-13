#pragma once
class Matrix4x4
{
public:
	float m00, m01, m02, m03;
	float m10, m11, m12, m13;
	float m20, m21, m22, m23;
	float m30, m31, m32, m33;

	Matrix4x4():m00(0),m01(0),m02(0),m03(0), m10(0), m11(0), m12(0), m13(0),m20(0), m21(0), m22(0), m23(0),
m30(0), m31(0), m32(0), m33(0)
	{};
	Matrix4x4(float inm00, float inm01, float inm02, float inm03, float inm10, float inm11, float inm12, float inm13,
		float inm20, float inm21, float inm22, float inm23, float inm30, float inm31, float inm32, float inm33)
	{
		m00 = inm00;
		m01 = inm01;
		m02 = inm02;
		m03 = inm03;

		m10 = inm10;
		m11 = inm11;
		m12 = inm12;
		m13 = inm13;

		m20 = inm20;
		m21 = inm21;
		m22 = inm22;
		m23 = inm23;


		m30 = inm30;
		m31 = inm31;
		m32 = inm32;
		m33 = inm33;
	}


	Matrix4x4 Identity();
	Matrix4x4& operator*(const Matrix4x4& in)const;
	
	void TransposeMatirix(Matrix4x4& out);
};

