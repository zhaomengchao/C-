/*���ַ�����ַ���*/
/*����һ�����֣����ǰ������¹����������Ϊ�ַ�����0 ����� ��a�� ��1 ����� ��b����������11 ����� ��l����������25 ����� ��z����
һ�����ֿ����ж�����롣����ʵ��һ����������������һ�������ж����ֲ�ͬ�ķ��뷽����
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