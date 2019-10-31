#include<iostream>
#include<vector>

using namespace std;


//�������
//1
//1 1
//1 2 1
//1 3 3 1


//��ά����
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;

		//���ٿռ�
		vv.resize(numRows);
		for (size_t i = 1; i <= numRows; ++i)
		{
			vv[i - 1].resize(i, 0);

			//ÿһ�еĵ�һ�������һ����Ϊ1
			vv[i - 1][0] = 1;
			vv[i - 1][i - 1] = 1;
		}

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j< vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}
		return vv;
	}
};
/
