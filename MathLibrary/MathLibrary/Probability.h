#pragma once
#include <cassert>
#include <cmath>
using namespace std;
namespace Probability
{
	

	int Permutation(int n,int r)
	{
		r = n - r;
		int temp = 1;

		for (int i = n; i <= n; i++)
		{
			temp *= (n - i);
		}

		return temp;
	}

	int Rec(int n)
	{
		if (n == 0)
		{
			return 1;
		}
		else
		{
			return n * Rec(n - 1);
		}
	}

	float Combination(int n, int r)
	{
		return Permutation(n, r) / Rec(r);
	}

	float Get_ExpectedValue(int elemNum, float Provalue[],float Probablity[])
	{
		float temp_ExV = 0;
		unsigned int i = 0;
		/*
        int ProValue_size = sizeof (Provalue) / sizeof Provalue[i];
		int Probablity_size = sizeof (Probablity) / sizeof Probablity[i];
		assert(ProValue_size != Probablity_size);
	     */	
		
		for (i = 0; i < elemNum; i++)
		{
			temp_ExV += Provalue[i] * Probablity[i];
		}

		return temp_ExV;
	}

	float Repeated_Trials(float prob_a, float prob_b, int times)
	{
		return pow(prob_a, times) * pow(prob_b, times);
	}

	struct ProValue
	{
		//実現値
		float Mvalue;

		void Set_Provalue(ProValue& proF,float value)
		{
			proF.Mvalue = value;

		}

		float Distribution_Function(const ProValue& proF)
		{

			//シグマを計算する
		}
	};
}