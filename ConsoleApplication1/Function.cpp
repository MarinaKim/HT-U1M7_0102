#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<locale>
#include<time.h>
#include <stdarg.h>

enum type_number { possitive, negative, all };
enum sortirovka { ubivanie, vozrastanie };

using namespace std;

int prost(int l)
{
	int s = 0;
	int k = sqrt(l);
	for (int i = 2; i <= k; i++)
	{
		if (l%i == 0)
			s++;
	}
	return s;
}

int sluch_number(type_number tn, int start, int end)
{

	switch (tn) {
	case possitive:
		return (start + rand() % end);
		break;
	case negative:
		return (start*(-1) + rand() % end);
		break;
	case all:
		return rand();
	}
}

void massiv(int *a, int r, int start, int end, type_number tn)
{
	for (int i = 0; i < r; i++)
	{
		a[i] = sluch_number(tn, start, end);
	}

}

void print_massiv(int *a, int r)
{
	for (int i = 0; i < r; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

//2.	Написать функцию, реализующую алгоритм линейного поиска заданного ключа в одномерном массиве.
int lin_min(int*a, int r)
{
	int min = a[0];
	for (int i = 0; i < r; i++)
	{
		if (min > a[i])
			min = a[i];
	}
	return min;
}

void sort(int*a, int r, sortirovka k)
{
	switch (k) {
	case ubivanie: {
		int l;
		for (int i = 0; i < r - 1; i++)
		{
			for (int j = r - 1; j > i; j--)
			{
				if (a[j - 1] < a[j])
				{
					l = a[j - 1];
					a[j - 1] = a[j];
					a[j] = l;
				}
			}
		}
	}
	case vozrastanie: {
		int l;
		for (int i = 0; i < r - 1; i++)
		{
			for (int j = r - 1; j > i; j--)
			{
				if (a[j - 1] > a[j])
				{
					l = a[j - 1];
					a[j - 1] = a[j];
					a[j] = l;
				}
			}
		}
	}break;
	}
}

//3.	Написать функцию, реализующую алгоритм бинарного поиска заданного ключа в одномерном массиве.
int bin_chislo(int *a, int left, int right, int s)
{
	int mid = (left + right) / 2;
	if (a[mid] != s)
	{
		if (a[mid] < s)
		{
			left = mid;
		}
		else if (a[mid] > s)
		{
			right = mid;
		}
		bin_chislo(a, left, right, s);
	}
	else
		return mid;
	}


	