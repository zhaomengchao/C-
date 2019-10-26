class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;  
        int end1 = num1.size()-1;
        int end2 = num2.size()-1;
        
        int next = 0;
        
        while(end1 >= 0 || end2 >=0)
        {
            int addret;//和
            int val1,val2;//表示对应字符串中的单个字符
            if(end1 >= 0)
            {
                val1 = num1[end1] - '0';
                --end1;
            }
            else
            {
                val1 = 0; 
            }
            if(end2 >= 0)
            {
                val2 = num2[end2] - '0';
                --end2;
            }
            else
            {
                val2 = 0;
            }
            addret = val1 + val2 + next;
            if(addret > 9)
            {
                addret -= 10;//取个位进位
                next = 1;
            }
            else
            {
                next = 0;
            }
            
            ret.insert(ret.begin(),addret + '0');//换成字符5
        }
        if(next == 1)
        {
            ret.insert(ret.begin(),'1');//999+1=1000考虑最后一个进位
        }
        
        return ret;
    }
};