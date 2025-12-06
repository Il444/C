#include <math.h>
#include <iostream>

using namespace std;

/*Программа находит простые числа которые остаются простыми при перевороте цифр, в диапазоне от заданной нижней границы до 1000*/

void main() // по стандарту С++ main должен возврашщать int
{
	int lower_border, clone_i = 0, flip = 0;
	cout << "lower_border=";
	cin >> lower_border;
	const int UPPER_BORDER = 1000;
	bool a[UPPER_BORDER] = { 0 };

	for (int i = 2; i < UPPER_BORDER; i++)
		a[i] = true;

	unsigned int n = sqrt(double(UPPER_BORDER));


	for (int i = 2; i <= n; i++)
		if (a[i])
			for (int j = i * 2; j < UPPER_BORDER; j += i)
				a[j] = false;
	for (int i = 2; i <= n; i++) //цикл избыточен, лучше сразу начинать с lower_border: int i = lower_border
		if ((a[i] and (i < lower_border)))
			a[i] = false;
	for (int i = lower_border; i < UPPER_BORDER - 1; i++)
	{
		clone_i = i;

		while (clone_i % 10 != 0) //некорректно, прекратит работу когда последняя цифра станет 0, но нуэно продолжать пока число не 0, лучше: while(clone_i > 0)
		{
			if (clone_i == i)
				flip = 0;
			flip = (flip * 10 + (clone_i % 10));
			clone_i = (clone_i - clone_i % 10) / 10;
			if (clone_i % 10 == 0)
			{
				clone_i = i;
				break;
			}
		}
		if (flip != i) //нужно проверять что простое ли flip число: if(!a[flip]) {...}
			a[i] = false;
	}
	for (int i = lower_border; i < UPPER_BORDER; i++)
		if (a[i])
			cout << i << "  ";

	cout << endl;
}