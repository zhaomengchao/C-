#include<iostream>
#include<string>

using namespace std;

//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和

class Solution {
public:
	string addStrings(string num1, string num2) {
		string str;//用于存放加后的string
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;

		int next = 0;//进位
		while (end1 >= 0 || end2 >= 0)
		{
			int val1, val2, add;
			//add 表示它们的和
			if (end1 >= 0)
			{
				val1 = num1[end1--] - '0';
			}
			else
			{
				val1 = 0;
			}
			if (end2 >= 0)
			{
				val2 = num2[end2--] - '0';
			}
			else
			{
				val2 = 0;
			}

			add = val1 + val2 + next;

			if (add > 9)
			{
				add -= 10;
				next = 1;
			}
			else
			{
				next = 0;
			}

			str.insert(str.begin(), add + '0');
		}
		if (next == 1)
		{
			str.insert(str.begin(), '1');
		}

		return str;
	}
};
