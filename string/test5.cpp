//判断密码的安全级别
//长度小于等于4  score += 5;
//长度大于等于8   += 25；
//长度大于等于4 到 8   += 10


#include<iostream>
#include<string>
using namespace std;

int main()
{
    string password;;
    while(getline(cin, password))
    {
        int score = 0;//长度得分
        if(password.size() <= 4)
        {
            score += 5;
        }
        else if(password.size() >= 8)
        {
            score += 25;
        }
        else{
            score += 10;
        }
        //字母、数字、符号统计
        int Alpha = 0,alpha = 0
        int number = 0,number_count = 0;
        int ch = 0,ch_count = 0;
        for(int i = 0; i < password.size(); i++)
        {
            if(password[i] > 'a' && password[i] < 'z')
            {
                alpha = 1;//如果是小写字母，赋值为1
            }
            else if(password[i] > 'A' && password[i] < 'Z')
            {
                Alpha = 1;//如果是大写字母，赋值为1
            }
            else if(isdigit(password[i]))//主要用于检查其参数是否为十进制数字字符。
            {
                number = 1;
                number_count++;//计数
            }
            else{
                ch = 1;
                ch_count++;
            }
        }
        if((Alpha == 1 && alpha == 0) || (Alpha == 0 && alpha == 1))
        {
            score += 10;//如果只有小写或者只有大写加10
        }
        else if(Alpha == 1 && alpha == 1)
        {
            score += 20;//如果大写和小写字母都有加20
        }
        //数字得分
        if(number_count > 1)
        {
            score += 20;
        }
        else if(number)
        {
            score += 10;
        }
        //符号得分
        if(ch_count > 1)
        {
            score += 25;
        }
        else if(ch)
        {
            score += 10;
        }
        
        //奖励
        if(alpha && Alpha && number && ch)
        {
            score += 5;
        }
        else if((alpha || Alpha) && number && ch)
        {
            score += 3;
        }
        else if((alpha || Alpha) && number){
            score += 2;
        }
        
        if(score >= 90)
        {
            cout << "VERY_SECURE"<<endl;
        }
        else if(score >= 80)
        {
            cout << "SECURE" <<endl;
        }
        else if(score >= 70)
        {
            cout << "VERY_STRONG" <<endl;
        }
        else if(score >= 60)
        {
            cout << "STRONG" << endl;
        }
        else if(score >= 50)
        {
            cout << "AVERAGE" <<endl;
        }
        else if(score >= 25)
        {
            cout << "WEAK" <<endl;
        }
        else{
            cout << "VERY_WEAK" <<endl;
        }
    }
    return 0;
}
