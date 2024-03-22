#include <iostream>
#include <cmath>

using namespace std; // Добавим комментарий =)

float Perimeter(float length, float width) // Вычисляет периметр прямоугольника
{
	return (length * 2 + width * 2); // я люблю пельмени
}

float Area(float length, float width) // Вычисляет площадь прямоугольника
{
	return (length * width);
}

float Diagonal(float length, float width) // Вычисляет диагональ прямоугольника
{
	return (sqrt(length * length + width * width));
}
float PrTriang(float leg1, float leg2, float leg3) // Вычисляет периметр треугольника
{
	return (leg1 + leg2 + leg3);
}
float AreaTriang(float leg1, float leg2, float leg3, float perimeter) // Вычисляет площадь нашего треугольника
{
	return sqrt((perimeter / 2) * (perimeter / 2 - leg1) * (perimeter / 2 - leg2) * (perimeter / 2 - leg3));
}
int IsoTriang(float leg1, float leg2, float leg3) // Проверяет треугольник на равнобедренность
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

float TzoidPerimeter(float base_1, float base_2, float side_l, float side_r) { // Вычисляет периметр трапеции
	return (base_1 + base_2 + side_l + side_r);
}

float TzoidArea(float base_1, float base_2, float side_l, float side_r) { // Вычисляет площадь трапеции
	float hight = (sqrt(pow(side_l, 2) - pow((base_2 - base_1) / 2, 2)));
	return (((base_1 + base_2) / 2) * hight);
}

float TzoidAverage(float base_1, float base_2) { // Вычисляет среднюю линию трапеции
	return ((base_1 + base_2) / 2);
}

int main()
{
	cout << "Choose a shape" << endl;
	cout << "1 - Rectangle" << endl;
	cout << "2 - Triangle" << endl;
	cout << "3 - Trapeziod" << endl;
	char var;
	float leg1, leg2, leg3;  // Параметры треугольника
	float width, length; // Параметры прямоугольника
	float bases_a, bases_b, side_l, side_r; // Параметры трапеции
	cin >> var;
	switch (var) { // Выбор фигуры
	case('1'): // Прямоугольник:
		cout << "Please insert rectangle length: \n";
		cin >> length;
		cout << "Please insert rectangle width: \n";
		cin >> width;
		if (length < 0 || width < 0) // Проверка параметров
		{
			cout << "Please enter valid parameters.\n";
			return 0;
		}
		else // Вывод функций
		{
			cout << "\nRectangle parameters: ";
			cout << "\nPerimeter of Rectangle: " << Perimeter(length, width);
			cout << "\nArea of Rectangle: " << Area(length, width);
			cout << "\nDiagonal of Rectangle: " << Diagonal(length, width) << endl;
		}
		break;
	case('2'): // Треугольник
		cout << "Please insert triangle legs: \n"; 
		cin >> leg1 >> leg2 >> leg3;
		if (((leg1 + leg2 < leg3) || (leg1 + leg3 < leg2) || (leg2 + leg3 < leg1)) || (leg1 < 1 || leg2 < 1 || leg3 < 1)) // Проверка параметров
		{
			cout << "Please enter valid parameters.\n";
			return 0;
		}
		else  // Вывод функций
		{
			float perimeter = PrTriang(leg1, leg2, leg3);
			cout << "Triangle results: " << endl;
			cout << "Perimeter of Triangle: " << perimeter << endl;
			cout << "Area of Triangle(Geroin): " << AreaTriang(leg1, leg2, leg3, perimeter) << endl;
			cout << "Isosceles of Triangle: ";
			if (IsoTriang(leg1, leg2, leg3) == 1)
			{
				cout << "True" << endl;
			}
			else
			{
				cout << "False" << endl;
			}
		}
		break;
	case('3'): // Трапеция
		cout << "Please insert trapezoid bases: \n";
		cin >> bases_a >> bases_b;
		cout << "Please insert the sides of the trapezoid: \n";
		cin >> side_l >> side_r;
		if (bases_a < 0 || bases_b < 0 || side_l < 0 || side_r < 0) // Проверка параметров
		{
			cout << "Please enter valid parameters.\n";
			return 0;
		}
		else // Вывод функций
		{
			cout << "Trapezoid results:" << endl; //hochu spat
			cout << "Perimeter of Trapezoid: " << TzoidPerimeter(bases_a, bases_b, side_l, side_r) << endl;
			cout << "Area of Trapezoid: " << TzoidArea(bases_a, bases_b, side_l, side_r) << endl;
			cout << "Average of Trapezoid: " << TzoidAverage(bases_a, bases_b) << endl;
			break;
		}
	default: // Ошибка при выборе несуществующей фигуры
		cout << "Please enter a valid number" << endl;
	}
}
