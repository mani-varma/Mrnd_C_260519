#include<iostream>
#include<stdio.h>
using namespace std;

char* minimizeString(char* str)
{
	int pos = 0, i = 0;
	while (str[i] != '\0')
	{
		int c = 1;
		if (str[i] != str[i + 1])
		{
			str[pos++] = str[i];
			i++;
			continue;
		}
		while (str[i] == str[i + 1])
		{
			c++;
			i++;
		}
		int n, d;
		n = c;
		while (n != 0)
		{
			pos++;
			n /= 10;
		}
		d = pos + 1;
		while (c != 0)
		{
			str[pos--] = '0' + c % 10;
			c /= 10;
		}
		str[pos] = str[i];
		pos = d;
		i++;
	}
	str[pos] = '\0';
	return str;
}

