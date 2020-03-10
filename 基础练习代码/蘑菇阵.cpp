#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int n,m,k;
  double double_vv[20][20];  // 空格子
  bool bool_vv[20][20];  // 蘑菇格子
  while(cin >> n >> m >> k)
  {
    for(int i=0;i<n;++i)
    {
      for(int j=0;j<m;++j)
      {
        double_vv[i][j]=0;//初始化
        bool_vv[i][j]=false;
      }
    }
    
    int xt,yt;//蘑菇出现的坐标
    while(k--)
    {
      cin >> xt >> yt;
      bool_vv[xt-1][yt-1]=true;//将蘑菇出现的地方标记出来
    }
    
    for(int i=0;i<n;++i)
    {
      for(int j=0;j<m;++j)
      {
        if(i==0&&j==0)      // 第一个格子
        {
          double_vv[0][0]=1;
          continue;
        }
        if(bool_vv[i][j])     // 蘑菇格子
          double_vv[i][j]=0;
        else if(i==0 && n>1)       // 上边界
        {
          double_vv[i][j]=0.5*double_vv[i][j-1];
        }
        else if(j==0 && m>1)       // 左边界
        {
          double_vv[i][j]=0.5*double_vv[i-1][j];
        }
        
        else if(i==n-1 && j<m-1)      // 下边界
        {
          double_vv[i][j]=double_vv[i][j-1]+0.5*double_vv[i-1][j];
        }
        else if(j==m-1 && i<n-1)      // 右边界
        {
          double_vv[i][j]=double_vv[i-1][j]+0.5*double_vv[i][j-1];
        }
        else if(i==n-1 && j==m-1)     // 最后的终点
        {
          double_vv[i][j]=double_vv[i-1][j]+double_vv[i][j-1];
        }
        else                // 中间的结点
        {
          double_vv[i][j]=0.5*double_vv[i][j-1]+0.5*double_vv[i-1][j];
        }
      }
    }
    printf("%.2lf\n",double_vv[n-1][m-1]);
  }
  return 0;
}