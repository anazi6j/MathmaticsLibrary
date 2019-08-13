#pragma once

#include <cmath>
#include "Vector2.h"
class CalCulus
{
	struct PartialDerivative
	{
		float Const;
		Vector2 Value;
		float pow;

		Vector2 Partial_derivative(const PartialDerivative& f)
		{

			return Vector2(CalCulus::SimpleDifferential(f.Const,f.Value.x,f.pow), CalCulus::SimpleDifferential(f.Const, f.Value.y, f.pow));
		}

	};
	struct Function
	{
	

		float realnum;
		float value;
		float pow;
		Function() : realnum(0), value(0), pow(0) {};
		Function(float in_num,float in_value,float in_pow)
			:realnum(in_num),value(in_value),pow(in_pow)
		{}

		static float GetFunction(const Function& in)
		{
			return in.realnum * powf(in.value, in.pow);
		}
	};

	
	//もしかしたら間違っているかもしれない。チェックしておく
	static float SimpleDifferential(const Function& f)
	{
		if (f.pow == 0)
		{
			return (1 * f.realnum);
		}

		return (f.pow * f.realnum) * pow(f.value, f.pow - 1);
	}

	static float SimpleDifferential(float realnum,float value,float in_pow)
	{
		

		return (in_pow *realnum ) * powf(value, in_pow - 1);
	}


	float SimpleIntegral(const Function& f)
	{
		return(1 / f.realnum + 1) * powf(f.value, f.pow + 1);
	}

	float SimpleIntegral(float realnum, float value, float pow)
	{
		return(1 / realnum + 1) * powf(value, pow + 1);
	}

	float Simple_DifinateIntegral(float in, float a, float b, float pow)
	{
		float alpha = SimpleIntegral(in, a, pow);
		float beta = SimpleIntegral(in, b, pow);

		return alpha - beta;
	}
	//マクローリン展開

	float Maclaurinsexpansion(Function& f, int num)
	{
		f.value = 0;
		float out=0;
		float temp=0;
	
		for (int i = 0; i < num;i++)
		{
			temp = SimpleDifferential(f) / 1;//階乗のアルゴリズムを考える
				out += temp;
		}
		return out;
	}
	
	
	
};

