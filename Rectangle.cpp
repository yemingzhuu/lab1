#include <iostream>
#include <cmath>

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

float TzoidPerimeter(float base_1, float base_2, float side_l, float side_r){
	return (base_1 + base_2 + side_l + side_r);
}

float TzoidArea(float base_1, float base_2, float side_l, float side_r){
	float hight = (sqrt(pow(side_l, 2) - pow((base_2 - base_1) / 2, 2)));
	return (((base_1 + base_2) / 2) * hight);
}

float TzoidAverage(float base_1, float base_2){
	return ((base_1 + base_2) / 2);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	float leg1, leg2, leg3;
	float width, length;
	float bases_a, bases_b, side_l, side_r;
	cout << "Please insert rectangle length: \n";
	cin >> length;
	cout << "Please insert rectangle width: \n";
	cin >> width;
	cout << "Please insert triangle legs: \n";
	cin >> leg1 >>  leg2 >> leg3;
	cout << "Please insert trapezoid bases: \n";
	cin >> bases_a >> bases_b;
	cout << "Please insert the sides of the trapezoid: \n";
	cin >> side_l >> side_r;

	if ((length < 1 || width < 1) || ((leg1 + leg2 < leg3) || (leg1 + leg3 < leg2) || (leg2 + leg3 < leg1)) || (leg1 < 1 || leg2 < 1 || leg3 < 1))
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
		cout << "Trapezoid results:" << endl;
		cout << "Perimeter of Trapezoid: " << TzoidPerimeter(bases_a, bases_b, side_l, side_r) << endl;
		cout << "Area of Trapezoid: " << TzoidArea(bases_a, bases_b, side_l, side_r) << endl;
		cout << "Average of Trapezoid: " << TzoidAverage(bases_a, bases_b) << endl;
	} return 0;
}