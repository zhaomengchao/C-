//������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ,���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ��
////m���뵽n�е�λ��Ϊi - j + 1
#include<iostream>
using namespace std;
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		m <<= j;//��m����jλ
		return n | m;//���
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
