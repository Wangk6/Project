#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;



namespace wang
{
	class Fraction {
		int numerator = 0;
		int denominator = 1;
	public:
		Fraction add(Fraction rop);  // add the passed Fraction to this Fraction
		int getNumerator() const;  // numerator accessor
		void setFraction(int n, int d);  // set the numerator and the denominator from n and d
		int getDenominator() const;  // denominator accessor
		std::string toString();  // convert the Fraction to a string representation
	};

	Fraction Fraction::add(Fraction rop)
	{
		int num = ((numerator * rop.getDenominator()) + (rop.getNumerator() * denominator));
		int den = (denominator * rop.getDenominator());
		Fraction result;
		result.setFraction(num, den);
		return result;
	}
	int Fraction::getNumerator() const
	{
		return numerator;
	}
	void Fraction::setFraction(int num, int den)
	{
		int numerator = num,
			denominator = den;
	}
	int Fraction::getDenominator() const
	{
		return denominator;
	}
	std::string Fraction::toString()
	{
		stringstream ss;
		ss << numerator;
		string num = ss.str();

		stringstream ssd;
		ssd << denominator;
		string den = ssd.str();

		return num + "/" + den;


	}

	static int assign_fraction()
	{
		int n1 = 3, n2 = 1, d1 = 6, d2 = 4;
		Fraction f, g, s;
		f.setFraction(n1, d1);
		g.setFraction(n2, d2);
		s = f.add(g);
		cout << s.toString() << " = " << f.toString() << " + " << g.toString() << endl;
		f = g.add(s);
		cout << f.toString() << " = " << g.toString() << " + " << s.toString() << endl;
		return 0;
	}

	static int(*currentAssignment)() = assign_fraction; // name is whatever the assignment is named
	int classname()
	{
		return currentAssignment();
	}
}
