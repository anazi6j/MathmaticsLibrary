#include "Vector3.h"


inline float Vector3::Dot(const Vector3& in_l, const Vector3& in_r)
{

	return in_l.x * in_r.x + in_l.y * in_r.y + in_l.z * in_r.z;
}

Vector3& Vector3::operator+(const Vector3& in)const
{
	return Vector3(x + in.x, y + in.y, z + in.z);

}

Vector3& Vector3::operator-(const Vector3& in)const
{

	return Vector3(x - in.x, y - in.y, z - in.z);
}

Vector3& Vector3::operator*(const Vector3& in)const
{
	return Vector3(x * in.x, y * in.y, z * in.z);
}

Vector3 operator*(float value, const Vector3& in)
{

	return Vector3(in.x * value, in.y * value, in.z * value);
}
float Vector3::GetMagnitude() const
{
	return sqrtf(x * x + y * y+z*z);
}

void Vector3::Normalize()
{
	float mag = GetMagnitude();

	x /= mag; y /= mag; z /= mag;
}