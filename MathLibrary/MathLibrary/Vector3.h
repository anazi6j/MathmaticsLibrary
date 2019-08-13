#pragma once
#include <cmath>
class Vector3
{

public:
	float x;
	float y;
	float z;
	Vector3():x(0),y(0),z(0) {};
	Vector3(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	Vector3& operator+(const Vector3& in)const;
	 Vector3& operator-(const Vector3& in)const;
	 Vector3& operator*(const Vector3& in)const;
	 friend Vector3 operator*(float value, const Vector3& in);
	 float GetMagnitude()const; 
	  void Normalize();
	  inline float Dot(const Vector3& in_l, const Vector3& in_r);

};

