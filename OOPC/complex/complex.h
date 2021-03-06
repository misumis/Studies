#include <iostream>
#include <math.h>
	
using namespace std;
	
class Complex
{
	private:
		double Real, Imag;
	public:
		Complex (double Real, double Imag);
		Complex & operator= (const Complex & s);
		Complex operator- () const;
		Complex & operator= (double co);
		Complex operator+ (const Complex& co) const;
		Complex & operator-= (const Complex& co);
		Complex & operator+= (const Complex& co);
		friend Complex operator / (const Complex& c1,const Complex& c2);
		friend Complex operator * (const Complex& c1,const Complex& c2);
		friend Complex operator - (Complex, Complex);
		friend ostream & operator << (ostream & s, const Complex & c);
		double getReal(void);
		double getImaginary(void);
		double amplitude(void);
		double phase(void);
		Complex conjugate(void);
		Complex& operator *= (const Complex& s2);
		Complex& operator/=(const Complex& co);
		bool operator == (const Complex& co);
	
};
double Complex::getReal(void)
{
		return Real;
}
double Complex::getImaginary(void)
{
		return Imag;
}
ostream & operator << (ostream & s, const Complex & c)
{
		s << "(" << c.Real << "," << c.Imag << ")";
		return s;
};
inline Complex operator - (Complex c1, Complex c2)
{
	Complex temp (c1);
	return temp -= c2;
}
Complex operator * (const Complex& c1,const Complex& c2)
{
	Complex temp(c1);
	return temp*=c2;
}
Complex operator / (const Complex& c1,const Complex& c2)
{
	Complex temp(c1);
	return temp /= c2;
}

Complex::Complex (double Real = 0, double Imag = 0)
{
		this->Real = Real;
		this->Imag = Imag;
};
Complex & Complex::operator= (const Complex & s)
{
		Real = s.Real;
		Imag = s.Imag;
		return *this;
};
Complex & Complex::operator= (double co)
{
		Real = co;
		Imag = 0;
		return *this;
};
Complex Complex::operator+ (const Complex& co) const
{
		Complex temp;
		temp.Real = this->Real + co.Real;
		temp.Imag = this->Imag + co.Imag;
		return temp;
};
Complex Complex::operator- () const
{
		return Complex(-Real,-Imag);
};
Complex & Complex::operator-= (const Complex& co)
{
		Real -= co.Real;
		Imag -= co.Imag;
		return *this;
};
Complex & Complex::operator+= (const Complex& co)
{
		Real += co.Real;
		Imag += co.Imag;
		return *this;
};
Complex& Complex::operator/=(const Complex& co)
{
		double result1, result2, demon ;
		demon = ((co.Real * co.Real) + (co.Imag * co.Imag));
		result1 = ((Real * co.Real) + (Imag * co.Imag)) / demon;
		result2 = ((Imag * co.Real) - (Real * co.Imag)) / demon;
		Real = result1;
		Imag = result2;
		return *this;
}
Complex& Complex::operator *= (const Complex& c2)
{
		double tmpReal, tmpImag;
		tmpReal = Real*c2.Real-Imag*c2.Imag;
		tmpImag = Real*c2.Imag + c2.Real*Imag;
		Real = tmpReal;
		Imag = tmpImag;
		return * this;    
}
double Complex::phase(void)
{
		double phase = ((atan(Imag / Real))*180/M_PI);
		if(Real==0)
		{
			return M_PI;
		}
		if(Real<0)
		{
			phase+=180;
		}
		return phase;
}
double Complex::amplitude(void)
{
		return (Real*Real+Imag*Imag);;
};
Complex Complex::conjugate(void)
{
		Complex temp (Real, -Imag);
		return temp;
};
bool Complex::operator == (const Complex& co)
{
		if(Real == co.Real && Imag == co.Imag)
		{
				return true;
		}
		else
		{
				return false;
		}
}


