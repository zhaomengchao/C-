 //是将一段字符串中的前后单词交换，以单词为单位逆置。


#include <iostream> 
#include <string>
 using namespace std; // cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
 int main()
 {    
    string s1, s2;
    cin >> s2;
    while (cin >> s1)
        s2 = s1  + " " + s2;
    cout << s2 << endl; 
   return 0; 
} 
