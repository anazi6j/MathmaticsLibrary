#include "Matrix4x4.h"


void Matrix4x4::TransposeMatirix(Matrix4x4& out)
{
	Matrix4x4 temp(out.m00, out.m01, out.m02, out.m03, out.m10, out.m11, out.m12, out.m13
		, out.m20, out.m21, out.m22, out.m23, out.m30, out.m31, out.m32, out.m33);

	out.m01 = temp.m10;
	out.m02 = temp.m20;
	out.m03 = temp.m30;

	out.m10 = temp.m01;
	out.m12 = temp.m21;
	out.m13 = temp.m31;

	out.m20 = temp.m02;
	out.m21 = temp.m12;
	out.m23 = temp.m32;

	out.m30 = temp.m03;
	out.m31 = temp.m13;
	out.m32 = temp.m23;
}






Matrix4x4 Matrix4x4::Identity()
{

	return Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

Matrix4x4& Matrix4x4::operator*(const Matrix4x4& in)const
{
	Matrix4x4 out;
	out.m00 = m00 * in.m00 + m01 * in.m01 + m02 * in.m02 + m03 * in.m03;
	out.m01 = m00 * in.m10 + m01 * in.m11 + m02 * in.m12 + m03 * in.m13;
	out.m02 = m00 * in.m20 + m01 * in.m21 + m02 * in.m22 + m03 * in.m23;
	out.m03 = m00 * in.m30 + m01 * in.m31 + m02 * in.m32 + m03 * in.m33;

	out.m10 = m10 * in.m00 + m11 * in.m01 + m12 * in.m02 + m13 * in.m03;
	out.m11 =m10* in.m10 + m11 * in.m11 + m12 * in.m12 + m13 * in.m13;
	out.m12 = m10 * in.m20 + m11 * in.m21 + m12 * in.m22 + m13 * in.m23;
	out.m13 = m10 * in.m30 + m11 * in.m31 + m12 * in.m32 + m13 * in.m33;

	
	out.m20 = m20 * in.m00 + m21 * in.m01 + m22 * in.m02 + m23 * in.m03;
	out.m21 = m20 * in.m10 + m21 * in.m11 + m22 * in.m12 + m23 * in.m13;
	out.m22 = m20 * in.m20 + m21 * in.m21 + m22 * in.m22 + m23 * in.m23;
	out.m23 = m20 * in.m30 + m21 * in.m31 + m22 * in.m32 + m23 * in.m33;

	out.m30 = m30 * in.m00 + m31 * in.m01 + m32 * in.m02 + m33 * in.m03;
	out.m31 = m30 * in.m10 + m31 * in.m11 + m32 * in.m12 + m33 * in.m13;
	out.m32 = m30 * in.m20 + m31 * in.m21 + m32 * in.m22 + m33 * in.m23;
	out.m33 = m30 * in.m30 + m31 * in.m31 + m32 * in.m32 + m33 * in.m33;

	return out;

}

Matrix4x4& Matrix4x4::operator*(const Matrix4x4& in,float value)
{

	





		Matrix4x4 out;

		out.m00 = value * in.m00;
		out.m01 = value * in.m01;
		out.m02 = value * in.m02;
		out.m03 = value * in.m03;

		out.m10 = value * in.m10;
		out.m11 = value * in.m11;
		out.m12 = value * in.m12;
		out.m13 = value * in.m13;

		out.m20 = value * in.m20;
		out.m21 = value * in.m21;
		out.m22 = value * in.m22;
		out.m23 = value * in.m23;

		out.m30 = value * in.m30;
		out.m31 = value * in.m31;
		out.m32 = value * in.m32;
		out.m33 = value * in.m33;

		return out;


	
}