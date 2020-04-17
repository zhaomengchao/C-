/*数字翻译成字符串*/
/*给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
*/


class Solution {
public:
    int translateNum(int num) {
       if(num<0){
           return 0;
       }
       string numstring=to_string(num);
        return getcount(numstring);
    }
    int getcount(const string&numstring){
        int len=numstring.size();
        int count=0;
        vector<int>vec(len);
        for(int i=len-1;i>=0;i--){
            count=0;
            if(i<len-1){
                count=vec[i+1];
            }
            else{
                count=1;
            }
            if(i<len-1){
                int num=numstring[i]-'0';
                int num1=numstring[i+1]-'0';
                int result=num*10+num1;
                if(result>=10&&result<=25){
                    if(i<len-2){
                        count+=vec[i+2];
                    }
                    else{
                        count+=1;
                    }
                }
            }
            vec[i]=count;
        }
        return vec[0];
    }
};