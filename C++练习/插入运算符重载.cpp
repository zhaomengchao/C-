#include <iostream>
using namespace std ;
class Date
{
	private:
 	   int year; 	   
	   int month;
 	   int day;
 	public:
 		Date(int y=1900,int m=1,int d=1)
 		{
 			year=y; month=m; day=d;
		 }
		friend ostream &operator<<( ostream &out, const Date &d ) 
		{
			out<<d.year<<"Äê"<<d.month<<"ÔÂ"<<d.day<<"ÈÕ"<<endl;
			return out;
		}
};
int main() {
	Date d1(1998,4,15),d2;
	cout<<d1;
	cout<<d2;
	return 0;
}
