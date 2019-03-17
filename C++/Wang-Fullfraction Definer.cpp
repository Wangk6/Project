#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;

namespace wang
{
	class FullFraction
	{
		int numerator;
		int denominator;
		int gcd(int x, int y);
	public:
		FullFraction();
		FullFraction(int n, int d);
		FullFraction add(FullFraction rop);
		FullFraction subtract(FullFraction rop);
		FullFraction multiply(FullFraction rop);
		FullFraction divide(FullFraction rop);
		int getNumerator() const;
		void setFullFraction(int numerator, int denominator);
		int getDenominator() const;
		float getDecimal() const;
		std::string toString();
	};

	FullFraction::FullFraction()
	{
		numerator =0; 
		denominator = 1;
	}
	FullFraction::FullFraction(int n, int d)
	{
		numerator = n;
		denominator = d;
	}

	FullFraction FullFraction::add(FullFraction rop)
	{
		int num = ((numerator * rop.getDenominator()) + (rop.getNumerator() * denominator));
		int den = (denominator * rop.getDenominator());

		return FullFraction(num/gcd(num,den), den / gcd(num, den));
	}
	FullFraction FullFraction::subtract(FullFraction rop)
	{
		int num = ((numerator * rop.getDenominator()) - (rop.getNumerator() *denominator));
		int den = (denominator * rop.getDenominator());
		return FullFraction(num / gcd(num, den), den / gcd(num, den));
	}
	FullFraction FullFraction::multiply(FullFraction rop)
	{
		int num = ((numerator * rop.getNumerator()));
		int den = ((denominator * rop.getDenominator()));
		return FullFraction(num / gcd(num, den), den / gcd(num, den));
	}
	FullFraction FullFraction::divide(FullFraction rop)
	{
		int num = (numerator * rop.getDenominator());
		int den = (denominator * rop.getNumerator());
		return FullFraction(num / gcd(num, den), den / gcd(num, den));
	}
	int FullFraction::getNumerator() const
	{
		return numerator;
	}
	void FullFraction::setFullFraction(int num, int den)
	{
		numerator = num;
		denominator = den;
	}
	int FullFraction::getDenominator() const
	{
		return denominator;
	}
	float FullFraction::getDecimal() const
	{
		return (float)numerator / denominator;
	}
	std::string FullFraction::toString()
	{
		std::ostringstream ss;
		ss << numerator << "/" << denominator;
		return ss.str();
	}
	int FullFraction::gcd(int x, int y)
	{
		if (x <= 1 || y <= 1)
			return 1;
		while (x != y)
		{
			if (x > y)
			{
				if (0 == (x = x % y))
					return y;
			}
			else
			{
				if (0 == (y = y % x))
					return x;
			}
		}
		return x;
	}

	static int assign_FullFraction()
	{
		FullFraction f0;
		FullFraction f1(2, 2);
		FullFraction f2(2, 7);
		FullFraction f3(1, -3);
		cout << f1.toString() << " + " << f0.toString() << " = " << f1.add(f0).toString() << endl;
		cout << f0.toString() << " + " << f1.toString() << " = " << f0.add(f1).toString() << endl;
		cout << f1.toString() << " * " << f2.toString() << " = " << f1.multiply(f2).toString() << endl;
		cout << f1.toString() << " / " << f3.toString() << " = " << f1.divide(f3).toString() << endl;
		cout << f2.toString() << " + " << f3.toString() << " = " << f2.add(f3).toString() << endl;
		cout << f2.toString() << " - " << f3.toString() << " = " << f2.subtract(f3).toString() << endl;
		cout << f2.toString() << " * " << f3.toString() << " = " << f2.multiply(f3).toString() << endl;
		cout << f3.toString() << " / " << f2.toString() << " = " << f3.divide(f2).toString() << endl;
		cout << f2.toString() << " / " << f3.toString() << " = " << f2.divide(f3).toString() << endl;
		cout << "the numerator of " << f3.toString() << " is " << f3.getNumerator() << endl;
		cout << "the denominator of " << f3.toString() << " is " << f3.getDenominator() << endl;
		cout << "the decimal value of " << f3.toString() << " is " << f3.getDecimal() << endl;
		/*The output of the test driver is :

		1 + 0 = 1
		0 + 1 = 1
		1 * 2 / 7 = 2 / 7
		1 / -1 / 3 = -3
		2 / 7 + -1 / 3 = -1 / 21
		2 / 7 - -1 / 3 = 13 / 21
		2 / 7 * -1 / 3 = -2 / 21
		- 1 / 3 / 2 / 7 = -1 1 / 6
		2 / 7 / -1 / 3 = -6 / 7
		the numerator of - 1 / 3 is - 1
		the denominator of - 1 / 3 is 3
		the decimal value of - 1 / 3 is - 0.333333 */
		return 0;
	}

	static int(*currentAssignment)() = assign_FullFraction; // name is whatever the assignment is named
	int classname()
	{
		return currentAssignment();
	}
}

