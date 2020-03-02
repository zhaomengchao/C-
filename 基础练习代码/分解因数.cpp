//分解因数
//分解因数，分解成 n = 1 < a1* <=a2*<= *a3

//10 = 2 * 5；
//18 = 2 * 3 * 3

#include<iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		cout << n << " = ";
		for (int i = 2; i <= n; i++)
		{
			while (n % i == 0)
			{
				if (n != i)
				{
					cout << i << " * ";
				}
				else
				{
					cout << n;
				}
				n = n / i;
			}
			
		}

	}
	return 0;
}
