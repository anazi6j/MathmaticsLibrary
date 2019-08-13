#pragma once
#include "Matrix4x4.h"

class LinearAlgebra
{
	
	float  GetDet(const Matrix4x4& input)
	{
		float DetA = 0;

		//A‚Ìdet‚ğ‹‚ß‚é
		float A00 = input.m00 * (input.m11 * input.m22 * input.m33
			+ input.m12 * input.m23 * input.m31
			+ input.m13 * input.m21 * input.m32 - input.m13 * input.m22 * input.m31
			- input.m11 * input.m23 * input.m32
			- input.m12 * input.m21 * input.m33);
		float A10 = input.m10 * (
			input.m01 * input.m22 * input.m33
			+ input.m02 * input.m23 * input.m31
			+ input.m03 * input.m21 * input.m32
			- input.m03 * input.m22 * input.m31
			- input.m02 * input.m21 * input.m33
			- input.m01 * input.m23 * input.m32);
		float A20 =  input.m20 * (
			  input.m01 * input.m12 * input.m33

			+ input.m02 * input.m13 * input.m31

			+ input.m03 * input.m11 * input.m32

			- input.m03 * input.m12 * input.m31

			- input.m02 * input.m11 * input.m33

			- input.m01 * input.m13 * input.m32
			
			);

		float A30= input.m30 * (
			input.m01 * input.m12 * input.m23

			+ input.m02 * input.m13 * input.m31

			+ input.m03 * input.m11 * input.m22

			- input.m03 * input.m12 * input.m31

			- input.m02 * input.m11 * input.m23

			- input.m01 * input.m13 * input.m22
			);

		DetA = A00 - A10 + A20 - A30;

		return DetA;
 }
	
	Matrix4x4 InverseMatrix(const Matrix4x4 in)
	{
		Matrix4x4 inverse;
		//A‚Ìdet‚ğ‹‚ß‚é
		float ADet = GetDet(in);
		//Še—v‘f‚ğŒvZ‚µ‚Ä‚¢‚­
		
		inverse.m00 = in.m11 * in.m22 * in.m33
			           + in.m12 * in.m23 * in.m31
			            + in.m13 * in.m21 * in.m32
			             - in.m13 * in.m22 * in.m31 
			              - in.m12 * in.m21 * in.m33
			       
			                 - in.m11 * in.m23 * in.m32;

		inverse.m01 = 
			//m10m22m33
	in.m10 * in.m22 * in.m33 
			//,32,23,30
	    + in.m12*in.m23*in.m30 
			//m13m20m32
		  + in.m13*in.m20*in.m32
			//m23m33m30
			  - in.m13*in.m22*in.m30 
			//m12m20m33
			    - in.m12*in.m20*in.m33 
			//m10m23m32
			      - in.m10*in.m23*in.m32;

		inverse.m02 =
			//m10m21m33
		in.m10 * in.m21 * in.m33 
			
			+ in.m11 * in.m23 * in.m30
			 + in.m13 * in.m20 * in.m31
			  - in.m13 * in.m22 * in.m30 
			    - in.m11 * in.m20 * in.m33 
			     - in.m10 * in.m23 * in.m31;

			inverse.m03 =
in.m10*in.m21*in.m32 

	+ in.m11*in.m22*in.m30

		+ in.m12*in.m20*in.m31

			- in.m12*in.m21*in.m30

				- in.m11*in.m20*in.m32

				 - in.m10*in.m22*in.m31;

		inverse.m10 = 
			in.m01*in.m22*in.m33

			 + in.m02*in.m23*in.m31

			  + in.m03*in.m21*in.m32

			    - in.m03*in.m22*in.m31

			      - in.m02*in.m21*in.m33

			       - in.m01*in.m23*in.m32;

		inverse.m11 = 
			in.m00*in.m22*in.m33 
+ in.m02*in.m23*in.m30
	+ in.m03*in.m20*in.m32
		- in.m03*in.m22*in.m30 
			- in.m02*in.m20*in.m33 
			 - in.m11*in.m23*in.m32;


		inverse.m12 = in.m00*in.m21*in.m33 + in.m01*in.m23*in.m30 + in.m03*in.m20*in.m31
			- in.m03*in.m21*in.m30 - in.m01*in.m20*in.m33 - in.m00*in.m23*in.m31;

			inverse.m13 = in.m00*in.m21*in.m32 + in.m01*in.m22*in.m30 + in.m02*in.m20*in.m31
			- in.m02*in.m21*in.m30 - in.m01*in.m20*in.m32 - in.m00*in.m22*in.m31;




			inverse.m20 = in.m01*in.m12*in.m33 + in.m02*in.m13*in.m31 + in.m03*in.m11*in.m32
			- in.m03*in.m12*in.m31 - in.m02*in.m11*in.m33 - in.m01*in.m13*in.m32;

			inverse.m21 = in.m00*in.m12*in.m33 + in.m02*in.m13*in.m30 + in.m03*in.m10*in.m32
			- in.m03*in.m12*in.m30 - in.m02*in.m10*in.m33 - in.m00*in.m13*in.m31;

			inverse.m22 = in.m00*in.m11*in.m33 + in.m01*in.m13*in.m30 + in.m03*in.m10*in.m31
			- in.m03*in.m11*in.m30 - in.m01*in.m10*in.m33 - in.m00*in.m13*in.m31;

			inverse.m23 = in.m00*in.m11*in.m32 + in.m01*in.m12*in.m30 + in.m02*in.m10*in.m31
			- in.m02*in.m11*in.m30 - in.m01*in.m10*in.m32 - in.m00*in.m12*in.m31;

			inverse.m30 = in.m01*in.m12*in.m23 + in.m02*in.m13*in.m21 + in.m03*in.m11*in.m22
			- in.m03*in.m12*in.m21 - in.m02*in.m11*in.m23 - in.m01*in.m13*in.m22;

			inverse.m31 = in.m00*in.m12*in.m23 + in.m02*in.m12*in.m20 + in.m03*in.m10*in.m22
			- in.m03*in.m12*in.m20 - in.m02*in.m10*in.m23 - in.m00*in.m13*in.m22;

			inverse.m32 = in.m00*in.m11*in.m23 + in.m01*in.m13*in.m20 + in.m03*in.m10*in.m21
			- in.m03*in.m11*in.m20 - in.m01*in.m10*in.m23 - in.m00*in.m13*in.m21;

			inverse.m33 = in.m00*in.m11*in.m22 + in.m01*in.m12*in.m20 + in.m02*in.m10*in.m21
			- in.m02*in.m11*in.m20 - in.m01*in.m10*in.m22 - in.m00*in.m12*in.m21;


			
			
			return Matrix4x4(1 / ADet * inverse.m00, 1 / ADet * inverse.m00, 1 / ADet * inverse.m00, 1 / ADet * inverse.m00,
				1 / ADet * inverse.m00, 1 / ADet * inverse.m00, 1 / ADet * inverse.m00, 1 / ADet * inverse.m00, 
				1 / ADet * inverse.m00, 1 / ADet * inverse.m00, 1 / ADet * inverse.m00, 1 / ADet * inverse.m00, 
				1 / ADet * inverse.m00, 1 / ADet * inverse.m00, 1 / ADet * inverse.m00, 1 / ADet * inverse.m00);
	}
	
};

