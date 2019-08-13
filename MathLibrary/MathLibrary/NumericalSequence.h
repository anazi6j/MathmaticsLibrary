#pragma once
#include <cmath>
class NumericalSequence
{
public:
	int term;

	int initterm;

	int difference;


	//boolにして,メンバ変数に「等差数列を計算するか」のbool変数を加える。それがtrueでこちらもtrueを返したら、等差数列を計算するようにする？
	int Tousa_Suretsu_GetNumofterm(int kou,int syokou,int kousa)
	{
		int result=0;

		result = syokou + (kou - 1) * kousa;

		return result;
	}

	//一般項と併用

	int 等差数列_初項から最終項の和(int finalterm, int init_Tnum, int difference)
	{
		return 2 * init_Tnum + (finalterm - 1) * difference;
	}

	int 等比数列_一般項の数(int in_term, int in_initTerm, int ratio)
	{
		return in_initTerm * pow(ratio, in_term - 1);
	}

	int 等比数列_初項からn項までの和の公式(int in_initTerm, int ratio, int in_term)
	{
		if (ratio != 1)
		{
			return in_initTerm * (pow(ratio, in_term));
		}
		else
		{
			return in_term * in_initTerm;
		}
	}

	int Sigma(int Sigma_below, int Sigma_above, int fomula)
	{

		int sum = 0;
		for (int i = 0; i <= Sigma_above; i++)
		{
			sum += fomula;
		}

	}

	float Sigma_MultiplyK_1(int Sigma_above)
	{
		return Sigma_above * (Sigma_above + 1) / 2;
	}

	float Sigma_MultiplyK_2(int Sigma_above)
	{

		return Sigma_above * (Sigma_above + 1) * ((2 * Sigma_above) + 1) / 6;
	}

	float Sigma_MultiplyK_3(int Sigma_above)
	{
		((Sigma_above * Sigma_above) * (Sigma_above + 1) * (Sigma_above + 1)) / 4;
	}

	float Sigma_value(int Sigma_above, int num)
	{
		return Sigma_above * num;
	}
};

