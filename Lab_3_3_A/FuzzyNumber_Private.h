#pragma once
#include "FuzzyNumber.h"

class FuzzyNumber_Private : private FuzzyNumber
{
public:

	using FuzzyNumber::GetX;
	using FuzzyNumber::GetL;
	using FuzzyNumber::GetR;

	using FuzzyNumber::SetX;
	using FuzzyNumber::SetL;
	using FuzzyNumber::SetR;

	using FuzzyNumber::FuzzyNumber;

	FuzzyNumber_Private();
	FuzzyNumber_Private(double x, double l, double r);
	FuzzyNumber_Private(const FuzzyNumber_Private& v);

	FuzzyNumber_Private& operator =(const FuzzyNumber_Private& n);
	operator string() const;

	FuzzyNumber_Private& operator --();
	FuzzyNumber_Private& operator ++();
	FuzzyNumber_Private operator --(int);
	FuzzyNumber_Private operator ++(int);

	friend FuzzyNumber_Private operator + (FuzzyNumber_Private a, FuzzyNumber_Private b);
	friend FuzzyNumber_Private operator * (FuzzyNumber_Private a, FuzzyNumber_Private b);

	friend ostream& operator <<(ostream& out, const FuzzyNumber_Private& a);
	friend istream& operator >>(istream& in, FuzzyNumber_Private& a);
};