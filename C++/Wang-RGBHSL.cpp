#include <iostream>
#include <sstream>
#include <string>
#include <fstream> 
#include <iomanip>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::stringstream;
using std::setw;

namespace wang
{
	class RGBColor
	{
		short red;
		short green;
		short blue;
		std::string name;
	public:
		RGBColor(std::string n, int r, int g, int b);
		short getRed() const;
		short getGreen() const;
		short getBlue() const;
		std::string getName();
		std::string toString();
	};

	RGBColor::RGBColor(std::string n, int r, int g, int b)
	{
		red = r;
		green = g;
		blue = b;
		name = n;
	}
	short RGBColor::getRed() const
	{
		return red;
	}
	short RGBColor::getGreen() const
	{
		return green;
	}
	short RGBColor::getBlue() const
	{
		return blue;
	}
	string RGBColor::getName()
	{
		return name;
	}
	string RGBColor::toString()
	{
		std::ostringstream rgb;
		rgb << "RGB=( " << setw(4) << red << ", " << setw(4) << green << ", " << setw(4)<< blue << ")";
		return rgb.str();
	}

	class HSLColor
	{
		float hue;
		float sat;
		float light;
		std::string name;
		void rgb2hsl(RGBColor& clr);
	public:
		HSLColor(RGBColor& clr);
		float getHue();
		float getSaturation();
		float getLuminance();
		std::string getName();
		std::string toString();
	};
	HSLColor::HSLColor(RGBColor& clr)
	{
		hue = clr.getRed();
		sat = clr.getGreen();
		light = clr.getBlue();
	}
	void HSLColor::rgb2hsl(RGBColor& clr)
	{
		float min, max, s, d;

		//Convert RGB between 0-1
		hue = hue / 255;
		sat = sat / 255;
		light = light / 255;

		//Find max and min values
		if (hue > sat && hue > light)
			max = hue;
		else if (sat > hue && sat > light)
			max = sat;
		else if (light > hue && light > sat)
			max = light;
		if (hue < sat && hue < light)
			min = hue;
		else if (sat < hue && sat < light)
			min = sat;
		else if (light < hue && light < sat)
			min = light;
		//Compute the sum S and the difference D of the maximum and minimum values.
		s = max + min;
		d = max - min;

		//The luminance value is the average of the min and max(ie. (min + max) / 2).
		light = s / 2;

		//If the min and max are equal, hue and saturation are both 0.0, and the conversion is complete
		if (min == max)
			hue = 0.0;
			sat = 0.0;
		if (hue == max) 		//if red was the maximum, hue is(green - blue) / D
			hue = (sat - light) / d;
		if (sat == max)		//if green was the maximum, hue is 2.0 + (blue - red) / D
			hue = 2.0f + (light - hue) / d;
		if (light == max) 		//if blue was the maximum, hue is 4.0 + (red - green) / D
			hue = 4.0f + (hue - sat) / d;

		//Multiple hue by 60.0 to convert it to degrees.
		hue = hue * 60.0f;
		//If Negative add 360
		if (hue < 0)
			hue = hue + 360.0f;
	}
	float HSLColor::getHue()
	{
		return hue;
	}
	float HSLColor::getSaturation()
	{
		return sat;
	}
	float HSLColor::getLuminance()
	{
		return light;
	}
	string HSLColor::getName()
	{
		return name;
	}
	string HSLColor::toString()
	{
		std::ostringstream hsl;
		hsl << "HSL=( " << setw(6) << hue << ", " << setw(6) << sat << ", " << setw(6) << light << ")";
		return hsl.str();
	}

	static int assign_colors()
	{
		float red, green, blue;
		int rcd;
		string name;
		RGBColor *rgb;
		HSLColor *hsl;

		ifstream ifs;
		string fileName = "C:\\Users\\mcdar\\Desktop\\College\\Computer_Class\\Homework to submit\\RGB\\testcolors.txt";
		ifs.open(fileName);
		if (!ifs) {
			cout << "error opening " << fileName << endl;
			return -1;
		}
		ifs >> red;
		while (!ifs.eof())
		{
			++rcd;
			ifs >> green >> blue >> name;
			rgb = new RGBColor(name, red, green, blue);
			hsl = new HSLColor(*rgb);
			cout << rgb->toString() << " = " << hsl->toString() << " " << rgb->getName() << endl;
			ifs >> red;
			return 0;
		}
	}

static int(*currentAssignment)() = assign_RGBHSL; // name is whatever the assignment is named
int bcs230()
{
	return currentAssignment();
}
}
