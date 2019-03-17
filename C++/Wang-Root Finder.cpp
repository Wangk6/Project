#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using std::cout;
using std::string;
using std::ifstream;
using std::endl;
using std::sqrt;
using std::pow;

namespace wang
{
	//Read file coefficients A, B, C
	int readArray(ifstream& ifs, int num[], int sz)
	{
		int ix, value;
		while (!ifs.eof()) {
			for (ix = 0; ix < sz; ++ix)
			{
				ifs >> num[ix];
			}
		}
		value = num[ix];
		return value;
	}

	int quad(int a, int b, int c)
	{
		double det;
		det = sqrt(pow(b, 2) - 4.0*a*c);
		if (det > 0)
			return 1;
		else if (det == 0)
			return 2;
		else if (det < 0)
			return 3;
	}

	static int assign_quad()
	{
		const int COEFF = 3;
		int real = 0,
			imaginary = 0,
			zero = 0,
			num[COEFF],
			a = num[0],
			b = num[1],
			c = num[2];
		ifstream ifs;
		string path = "C:\\Users\\mcdar\\Desktop\\College\\Computer_Class\\Homework to submit\\quad.txt";
		ifs.open(path);
		//Check file
		if (!ifs) {
			cout << "Cannot open input file." << path << endl;
			return -1;
		}
		//Insert the int quad statement
		while (readArray(ifs, num, COEFF))
		{
			switch (quad(a, b, c))
			{
			case 1:
				real += 1;
				break;
			case 2:
				zero += 1;
				break;
			case 3:
				imaginary += 1;
				break;
			default:
				cout << "You tried";
				break;
			}
		}
		cout << "There are " << real << " real roots, " << imaginary << " imaginary roots, and " << zero << " zero roots." << endl;

		ifs.close();
		return 0;
	}

	static int(*currentAssignment)() = assign_quad; // name is whatever the assignment is named
	int classname()
	{
		return currentAssignment();
	}
}
