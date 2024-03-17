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


int main()
{
	float width, length;
	cout << "Please insert rectangle length: \n";
	scanf_s("%f", &length);
	cout << "Please insert rectangle width: \n";
	scanf_s("%f", &width);
	if (length < 0 or width < 0)
	{
		cout << "Please enter valid parameters.\n";
		return 0;
	}
	else
	{
		cout << "\nRectangle parameters: ";
		cout << "\nPerimeter: " << Perimeter(length, width);
		cout << "\nArea: " << Area(length, width);
		cout << "\nDiagonal: " << Diagonal(length, width) << endl;
	}
}
