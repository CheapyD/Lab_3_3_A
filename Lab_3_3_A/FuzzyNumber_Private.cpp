#include "FuzzyNumber_Private.h"

FuzzyNumber_Private::FuzzyNumber_Private()
	: FuzzyNumber(0, 0, 0)
{}

FuzzyNumber_Private::FuzzyNumber_Private(double X = 0, double L = 0, double R = 0)
	: FuzzyNumber(X, L, R)
{}


FuzzyNumber_Private::FuzzyNumber_Private(const FuzzyNumber_Private& v)
	: FuzzyNumber(v)
{}


FuzzyNumber_Private& FuzzyNumber_Private::operator = (const FuzzyNumber_Private& n)
{
	FuzzyNumber::operator = (n);
	return *this;
}

FuzzyNumber_Private::operator string () const
{
	stringstream ss;
	ss << "(" << GetL() << "; " << GetX() << "; " << GetR() << ")" << endl;
	return ss.str();
}

FuzzyNumber_Private& FuzzyNumber_Private::operator --()
{
	this->SetX(this->GetX() - 1);
	return *this;
}

FuzzyNumber_Private& FuzzyNumber_Private::operator ++()
{
	this->SetX(this->GetX() + 1);
	return *this;
}

FuzzyNumber_Private FuzzyNumber_Private::operator --(int)
{
	FuzzyNumber_Private a(*this);
	this->SetX(this->GetX() - 1);
	return a;
}

FuzzyNumber_Private FuzzyNumber_Private::operator ++(int)
{
	FuzzyNumber_Private a(*this);
	this->SetX(this->GetX() + 1);
	return a;
}

FuzzyNumber_Private operator + (FuzzyNumber_Private a, FuzzyNumber_Private b)
{
	FuzzyNumber_Private T(0, 0, 0);
	T.SetX(a.GetX() + b.GetX());
	T.SetL(a.GetX() + b.GetX() - a.GetL() - b.GetL());
	T.SetR(a.GetX() + b.GetX() + a.GetR() + b.GetR());
	return T;
}

FuzzyNumber_Private operator * (FuzzyNumber_Private a, FuzzyNumber_Private b)
{
	FuzzyNumber_Private N(0, 0, 0);
	N.SetX(a.GetX() * b.GetX());
	N.SetL(a.GetX() * b.GetX() - b.GetX() * a.GetL() - a.GetX() * b.GetL() - a.GetL() * b.GetL());
	N.SetR(a.GetX() * b.GetX() + b.GetX() * a.GetR() + a.GetX() * b.GetR() + a.GetR() * b.GetR());
	return N;
}

ostream& operator <<(ostream& out, const FuzzyNumber_Private& a)
{
	return out << string(a);
}

istream& operator >>(istream& in, FuzzyNumber_Private& a)
{
	int x, l, r;
	do
	{
		cout << "x = "; in >> x;
		cout << "l = "; in >> l;
		cout << "r = "; in >> r;
	} while (!(x > (x - l) && (x + r) > x));
	a.SetX(x); a.SetL(l); a.SetR(r);
	return in;
}