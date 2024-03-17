#include <iostream>
#include <math.h>

using namespace std;

float Perimeter(float length, float width)
{
	return (length * 2 + width * 2);
}

float Area(float length, float width)
{
	return (length * width);
}

float Diagonal(float length, float width)
{
	return (sqrt(length * length + width * width));
}
float PrTriang(float leg1, float leg2,float leg3)
{
	return (leg1 + leg2 + leg3);
}
float AreaTriang(float leg1, float leg2,float leg3, float perimeter)
{
	return sqrt((perimeter / 2) * ( perimeter / 2 - leg1) * ( perimeter / 2 - leg2) * ( perimeter / 2 - leg3));
}
int IsoTriang(float leg1,float leg2,float leg3)
{
	if ((leg1 == leg2) || (leg2 == leg3) || (leg1 == leg3))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	float leg1, leg2, leg3;
	float width, length;
	cout << "Please insert rectangle length: \n";
	scanf_s("%f", &length);
	cout << "Please insert rectangle width: \n";
	scanf_s("%f", &width);
	cout << "Please insert triangle legs: \n";
	cin >> leg1 >>  leg2 >> leg3;

	if ((length < 0 || width < 0) && ((leg1 + leg2 < leg3) || (leg1 + leg3 < leg2) || (leg2 + leg3 < leg1)) && (leg1 < 0 || leg2 < 0 || leg3 < 0))
	{
		cout << "Please enter valid parameters.\n";
		return 0;
	}
	else
	{
		float perimeter = PrTriang(leg1, leg2, leg3);
		cout << "\nRectangle parameters: ";
		cout << "\nPerimeter of Rectangle: " << Perimeter(length, width);
		cout << "\nArea of Rectangle: " << Area(length, width);
		cout << "\nDiagonal of Rectangle: " << Diagonal(length, width) << endl;
		cout << "Triangle results: " << endl;
		cout << "Perimeter of Triangle: " << perimeter << endl;
		cout << "Area of Triangle(Geroin): " << AreaTriang(leg1, leg2, leg3, perimeter) << endl;
		cout << "Isosceles of Triangle: ";
		if (IsoTriang) 
		{ 
			cout << "True" << endl;
		}
		else
		{
			cout << "False" << endl;
		}

	}
}
