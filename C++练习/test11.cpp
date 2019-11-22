//计算日期到天数的转换
//根据输入的日期判断是这一年的第几天


#include<iostream>
using namespace std;

int GetMonthDay(int year, int month)
    {
        if ((month < 1) && (month >13))
        {
            return -1;
        }

        static int array[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        {
            return 29;
        }
        else
        {
            return array[month];
        }
    }

static int getDay(int year,int month,int day)
{
    int days = 0;
    for(int i = 1; i < month;i++)
    {
        days += GetMonthDay(year,i);
    }
    days += day;
    return days;
}


int main()
{
    int year,month,day;
    while(cin >> year >> month >> day)
    {
        cout << getDay(year,month,day)<<endl;
    }
    return 0;