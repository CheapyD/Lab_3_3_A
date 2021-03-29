#include "FuzzyNumber_Public.h"

FuzzyNumber_Public::FuzzyNumber_Public()
	: FuzzyNumber(0, 0, 0)
{}

FuzzyNumber_Public::FuzzyNumber_Public(double X = 0, double L = 0, double R = 0)
	: FuzzyNumber(X, L, R)
{}

FuzzyNumber_Public::FuzzyNumber_Public(const FuzzyNumber_Public& v)
	: FuzzyNumber(v)
{}

FuzzyNumber_Public& FuzzyNumber_Public::operator = (const FuzzyNumber_Public& n)
{
	FuzzyNumber::operator = (n);
	return *this;
}

FuzzyNumber_Public& FuzzyNumber_Public::operator --()
{
	this->SetX(this->GetX() - 1);
	return *this;
}

FuzzyNumber_Public& FuzzyNumber_Public::operator ++()
{
	this->SetX(this->GetX() + 1);
	return *this;
}

FuzzyNumber_Public FuzzyNumber_Public::operator --(int)
{
	FuzzyNumber_Public a(*this);
	this->SetX(this->GetX() - 1);
	return a;
}

FuzzyNumber_Public FuzzyNumber_Public::operator ++(int)
{
	FuzzyNumber_Public a(*this);
	this->SetX(this->GetX() + 1);
	return a;
}

FuzzyNumber_Public operator + (FuzzyNumber_Public a, FuzzyNumber_Public b)
{
	FuzzyNumber_Public T(0, 0, 0);
	T.SetX(a.GetX() + b.GetX());
	T.SetL(a.GetX() + b.GetX() - a.GetL() - b.GetL());
	T.SetR(a.GetX() + b.GetX() + a.GetR() + b.GetR());
	return T;
}

FuzzyNumber_Public operator * (FuzzyNumber_Public a, FuzzyNumber_Public b)
{
	FuzzyNumber_Public N(0, 0, 0);
	N.SetX(a.GetX() * b.GetX());
	N.SetL(a.GetX() * b.GetX() - b.GetX() * a.GetL() - a.GetX() * b.GetL() - a.GetL() * b.GetL());
	N.SetR(a.GetX() * b.GetX() + b.GetX() * a.GetR() + a.GetX() * b.GetR() + a.GetR() * b.GetR());
	return N;
}