﻿题目描述
1
111
12321
1367631
14101619161041
以上三角形的数阵,第一行只有一个数1,以下每行的每个数,是
恰好是它上面的数,左上角数到右上角的数,3个数之和(如果不
存在某个数,认为该数就是0)。
求第n行第一个偶数出现的位置。如果没有偶数,则输出-1。例如
输入3,则输出2,输入4则输出3
输入n(n<=0000000)

#include<iostream>

using namespace std;
int main()
{
    int row;
    while(cin >> row)
    {
        if(row < 3)
        {
            cout << '-1' << endl;//如果输入的行数小于三，则输出-1
        }
        if(row % 2)
        {
            cout << '2' << endl;//如果输入的是奇数行，第一个偶数出现的位置是2
        }
        if(row % 4 == 0)
        {
            cout << '3' << endl;//如果输入的是一个偶数，并且能被4整除，那么输出是3
        }
        if(row % 4 == 2）//如果输入的是偶数但不能被4整除，那么输出是4
        {
            cout << '4' << endl;
        }
    }
    return 0;
}