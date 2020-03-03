//月份为素数的时候，当月每天能赚一元钱，否则每天能赚2元
/*
输入： 2000 1 1 2000 1 31
	   2000 2 1 2000 2 29
输出： 62
	   29*/

// write your code here cpp
#include<iostream>

using namespace std;
int SR(int month)
{
    int a[12] = {2, 1, 1, 2 ,1, 2, 1 ,2 , 2, 2 ,1 , 2};
    return a[month-1];
}
int Days(int year, int month)
{
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        a[1] = 29;
    }
    return a[month-1];
}

int main()
{
    int year,month,day;
    int year1,month1,day1;
    
    while(cin >> year >> month >> day >> year1 >> month1 >> day1)
    {
        int sum = 0;
        //如果年相等，月相等，天相等
        if(year == year1 && month == month1 && day == day1)
        {
            sum += SR(month);
        }
        //如果年相等，月相等，天不相等
        if(year == year1 && month == month1 && day != day1)
        {
            sum += (day1- day + 1)*SR(month);
        }
        //如果年相等，月不想等
        if(year == year1 && month != month1)
        {
            sum += (Days(year, month) - day + 1)*SR(month);
            month++;
            while(month < month1)//计算两个月间相差的天数
            {
                sum += SR(month);
                ++month;
            }
            sum += day1 * SR(month1);
        }
        
        //年不相等
        if(year != year1)
        {
            sum += (Days(year,month) - day + 1)*SR(month);
            ++month;
            if(month == 13)
            {
                ++year;
                month = 1;
            }
            while(year <= year1)
            {
                sum += Days(year , month)* SR(month);
                ++month;
                if(month == 13)
                {
                    ++year;
                    month = 1;
                }
            }
            
            
        }
        cout << sum << endl;
    }
    
    
    
    return 0;
}