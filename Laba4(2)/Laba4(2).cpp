// Laba4(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
// библиотека для работы с потоками 
#include <thread>
// библиотека для работы со временем 
#include<chrono>

#include<math.h>
using namespace std;

void DoWork(float &a) //для нечётных
{
	float n1 = 100;
	int k1 = 1;

	int p1 = 1;
	float step1;
	float sum1 = 0;
	int i1;

	while (n1 > 0.001)
	{
		step1 = pow(a, k1);
		//g = k;
		for (i1 = 0; i1 < k1; i1++)
		{
			p1 = p1 * (i1 + 1);
		}
		n1 = step1 / p1;
		sum1 = sum1 + n1;

		k1 = k1 + 2;
		p1 = 1;

	}

	a = sum1;



}


int main()
{
	setlocale(LC_ALL,"ru");
	float f;
	cout << "Введите целую степень числа е" << endl;
	cin >> f;
	cout << "Точность вычислений 0.001" << endl;
	float n = 100;
	float k = f;
	float f3 = f;
	int g = 2;
	int p = 1;
	float sum = 1;
	float step;
	thread th(DoWork, std::ref(f));
	while (n > 0.001)
	{
		step = pow(k, g);
		//g = k;
		for (int i = 0; i < g; i++)
		{
			p = p * (i + 1);
		}
		n = step / p;
		sum = sum + n;

		g = g + 2;
		p = 1;

	}
	th.join();
	cout << f+sum<<endl;
	

	float n3 = 100;
	int k3 = 1;
	int p3 = 1;
	float step3;
	float sum3 = 1;
	cout << "Один поток" << endl;
	while (n3 > 0.001)
	{
		step3 = pow(f3, k3);

		for (int i3 = 0; i3 < k3; i3++)
		{
			p3 = p3 * (i3 + 1);
		}
		n3 = step3 / p3;
		sum3 = sum3 + n3;
		k3++;
		p3 = 1;

	}

	cout << "Полученное число" << " " << sum3 << endl;

	system("pause");
}
