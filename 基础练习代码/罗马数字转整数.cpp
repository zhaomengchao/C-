//例如， 罗马数字 2 写做?II?，即为两个并列的 1。12 写做?XII?，
//即为?X?+?II?。 27 写做??XXVII, 即为?XX?+?V?+?II?。

//通常情况下，罗马数字中小的数字在大的数字的右边。
//但也存在特例，例如 4 不写做?IIII，而是?IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为?IX。这个特殊的规则只适用于以下六种情况：

//I?可以放在?V?(5) 和?X?(10) 的左边，来表示 4 和 9。
//X?可以放在?L?(50) 和?C?(100) 的左边，来表示 40 和?90。?
//C?可以放在?D?(500) 和?M?(1000) 的左边，来表示?400 和?900。
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int len = s.length();
        int tmp = 0;
        for(int i = 0; i < len; i++)
        {
            if(i<len-1)
            {
                if(s[i]=='I' && s[i+1]=='V')
                {
                    tmp += 4;
                    i++;
                }
                else if(s[i]=='I' && s[i+1]=='X'){
                    tmp += 9;
                    i++;
                }
                else if(s[i]=='X' && s[i+1]=='L')
                {
                    tmp += 40;
                    i++;
                }else if(s[i]=='X' && s[i+1]=='C'){
                    tmp += 90;
                    i++;
                }else if(s[i]=='C' && s[i+1]=='D'){
                    tmp += 400;
                    i++;
                }else if(s[i]=='C' && s[i+1]=='M'){
                    tmp += 900;
                    i++;
                }
                else
                {
                    tmp += mp[s[i]];
                }
            }
            else
            {
                tmp += mp[s[i]];
            }
        }
        return tmp;
    }
};
   
