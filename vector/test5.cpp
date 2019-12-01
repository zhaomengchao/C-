//洗牌
题目描述
洗牌在生活中十分常见,现在需要写一个程序模拟洗牌的过程。现
在需要洗2n张牌,从上到下依次是第1张,第2张,第3张一直到第
2n张。首先,我们把这2n张牌分成两堆,左手拿着第1张到第n张
(上半堆),右手拿着第n+1张到第2n张(下半堆)。接着就开始
洗牌的过程,先放下右手的最后一张牌,再放下左手的最后一张
牌,接着放下右手的倒数第二张牌,再放下左手的倒数第二张牌,
直到最后放下左手的第一张牌。接着把牌合并起来就可以了。例如
有6张牌,最开始牌的序列是1,2,3,4,5,6。首先分成两组,左手拿着
1,2,3;右手拿着4,5,6在洗牌过程中按顺序放下了6,3,5,2,4,1。把
这六张牌再次合成一组牌之后,我们按照从上往下的顺序看这组
牌,就变成了序列1,4,2,5,3,6。现在给出一个原始牌组,请输出这
副牌洗牌k次之后从上往下的序列。
#include<iostream>
#include<vector>
using namespace std;

int main()
{
//k代表洗牌的次数
    int n,k,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int num = 2*n;
         vector<int> v(num);
        for(int i = 0; i < num; i++)
        {
            cin >> v[i];
        }
        //洗牌
        while(k--)
        {
            vector<int> n1(v.begin(),v.end());
            //如果当前数小于n，则出现在左手，位置为2*当前位置，相反与之对相应的位置为 i+n（表示右手的牌）位置也加1；
            for(int i = 0; i < n; ++i)
            {
                v[2*i] = n1[i];
                v[2*i + 1] = n1[i + n];
            }
        }
        for(int i = 0; i < num -1;i++)
        {
            cout << v[i] << " ";
        }
        cout << v[num - 1]<<endl;//行末无空格
        
    }
    return 0;
}