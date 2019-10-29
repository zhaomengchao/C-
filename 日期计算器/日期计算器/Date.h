#pragma once
#include<iostream>

using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		if ((year < 1990) && (month < 1) && (month >13))
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
	Date(int year = 1990, int month = 1, int day = 1)
	{
		int days = GetMonthDay(year, month);
		if (day == -1 || day < 1 || day >days)
		{
			exit(-1);
		}
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	/*~Date()
	{
	free();
	}*/

	bool operator <(const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day < d._day)
				{
					return true;
				}
			}
		}
		return false;
	}


	bool operator >(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
			}
		}
		return false;
	}


	bool operator <=(const Date& d)
	{
		return !(*this > d);
	}


	bool operator >=(const Date& d)
	{
		return !(*this < d);
	}

	bool operator ==(const Date& d)
	{
		return (_year == d._year) && (_month == d._month)
			&& (_day == d._day);
	}
	Date& operator = (const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		return *this;
	}

	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	Date& operator +(int day)
	{
		Date tmp = *this;
		tmp._day += day;
		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
		{
			tmp._day = tmp._day - GetMonthDay(tmp._year, tmp._month);
			tmp._month++;
			if (tmp._month > 12)
			{
				tmp._month = tmp._month - 12;
				tmp._year++;
			}
		}
		return tmp;
	}


	Date& operator -(int day)
	{
		Date tmp = *this;
		tmp._day = tmp._day - day;
		while (tmp._day < 1)
		{
			tmp._month--;
			if (tmp._month-- < 1)
			{
				tmp._month = 12;
				tmp._year--;
			}
			tmp._day = tmp._day + GetMonthDay(tmp._year, tmp._month);
		}
		return tmp;

	}


	Date operator +=(int day)
	{
		_day = _day + day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day = _day - GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_month = _month - 12;
				_year++;
			}
		}
		return *this;
	}
	Date operator -=(int day)
	{
		_day = _day - day;
		while (_day < 1)
		{
			_month--;
			if (_month < 1)
			{
				_month = 12;
				_year--;
			}
			_day = _day + GetMonthDay(_year, _month);
		}
		return *this;
	}


	// ++d d.operator++(&d)
	Date operator++();
	// d++ d.operator++(&d, 0)
	Date operator++(int);


private:
	int _year;
	int _month;
	int _day;
};

