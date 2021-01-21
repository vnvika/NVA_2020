#include "pch.h"
#include "stdafx.h"
#include <iostream>
#include <ctime>
extern "C"
{

	int __stdcall power(int a, int b)
	{
		return pow(a, b);
	}
	int __stdcall random(int a)
	{
		if (a < 0)
			a = -a;
		if (a == 0)
			return 0;
		srand(time(NULL));
		int k = -a + (rand() % (a * 2));
		return k;
	}
	int __stdcall lenght(char* str)
	{
		if (str == nullptr)
			return 0;
		int len = 0;
		for (int i = 0; i < 256; i++)
			if (str[i] == '\0')
			{
				len = i;
				break;
			}
		return len;
	}

	char* __stdcall concat(char* str, char* s1, char* s2)
	{
		int i = 0;
		for (int length1 = 0; s1[length1] != '\0'; length1++);
		for (int lenght2 = 0; s2[lenght2] != '\0'; lenght2++);

		for (int j = 0; s1[j] != '\0'; j++)
		{
			if (i == 255) break;
			str[i++] = s1[j];
		}
		for (int j = 0; s2[j] != '\0'; j++)
		{
			if (i == 255) break;
			str[i++] = s2[j];
		}
		str[i] = '\0';
		return str;
	}

	int __stdcall outnum(int value)
	{
		std::cout << value;
		return 0;
	}
	int __stdcall outstr(char* ptr)
	{
		if (ptr == nullptr)
		{
			std::cout << std::endl;
		}
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];
		return 0;
	}
	int __stdcall outnumline(int value)
	{
		std::cout << value << std::endl;
		return 0;
	}
	int __stdcall outstrline(char* ptr)
	{
		if (ptr == nullptr)
		{
			std::cout << std::endl;
		}
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];
		std::cout << std::endl;
		return 0;
	}
	int __stdcall system_pause()
	{
		system("pause");
		return 0;
	}
}