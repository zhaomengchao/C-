class Solution {
public:
    bool isNumber(string s) {
        //1������βѰ��s�в�Ϊ�ո���βλ�ã�Ҳ����ȥ����β�ո�
        int i=s.find_first_not_of(' ');
        if(i==string::npos)return false;
        int j=s.find_last_not_of(' ');
        s=s.substr(i,j-i+1);
        if(s.empty())return false;

        //2������e�����ֵ�����ָ��
        int e=s.find('e');

        //3��ָ��Ϊ�գ��жϵ���
        if(e==string::npos)return judgeP(s);

        //4��ָ����Ϊ�գ��жϵ�����ָ��
        else return judgeP(s.substr(0,e))&&judgeS(s.substr(e+1));
    }

    bool judgeP(string s)//�жϵ����Ƿ�Ϸ�
    {
        bool result=false,point=false;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(s[i]=='+'||s[i]=='-'){//����λ���ڵ�һλ������false
                if(i!=0)return false;
            }
            else if(s[i]=='.'){
                if(point)return false;//�ж��С���㣬����false
                point=true;
            }
            else if(s[i]<'0'||s[i]>'9'){//�Ǵ����֣�����false
                return false;
            }
            else{
                result=true;
            }
        }
        return result;
    }

    bool judgeS(string s)//�ж�ָ���Ƿ�Ϸ�
    {   
        bool result=false;
        //ע��ָ�����ܳ���С���㣬���Գ��ֳ�����λ�ķǴ����ֱ�ʾָ�����Ϸ�
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='+'||s[i]=='-'){//����λ���ڵ�һλ������false
                if(i!=0)return false;
            }
            else if(s[i]<'0'||s[i]>'9'){//�Ǵ����֣�����false
                return false;
            }
            else{
                result=true;
            }
        }
        return result;
    }
};
