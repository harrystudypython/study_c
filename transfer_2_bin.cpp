#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	printf("start\n");

	int i = 8;
	while (i--)
	{
		if (1 << i & -11)
			cout << "1";
		else
			cout << "0";

		if (i % 4 == 0)
			cout << " ";
	}
	putchar(10);
	printf("end");

	return 0;
}

