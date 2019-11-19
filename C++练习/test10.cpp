//有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,其中二进制的位数从低位数到高位且以0开始。
////m插入到n中的位数为i - j + 1
#include<iostream>
using namespace std;
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		m <<= j;//将m左移j位
		return n | m;//相或
	}
};


int main()
{
	BinInsert B;
	int n, m, j, i;
	while (cin >> n >> m >> j >> i)
	{
		cout << B.binInsert(n, m, j, i) << endl;
	}
	system("pause");
	return 0;
}
