#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int n,m,k;
  double double_vv[20][20];  // �ո���
  bool bool_vv[20][20];  // Ģ������
  while(cin >> n >> m >> k)
  {
    for(int i=0;i<n;++i)
    {
      for(int j=0;j<m;++j)
      {
        double_vv[i][j]=0;//��ʼ��
        bool_vv[i][j]=false;
      }
    }
    
    int xt,yt;//Ģ�����ֵ�����
    while(k--)
    {
      cin >> xt >> yt;
      bool_vv[xt-1][yt-1]=true;//��Ģ�����ֵĵط���ǳ���
    }
    
    for(int i=0;i<n;++i)
    {
      for(int j=0;j<m;++j)
      {
        if(i==0&&j==0)      // ��һ������
        {
          double_vv[0][0]=1;
          continue;
        }
        if(bool_vv[i][j])     // Ģ������
          double_vv[i][j]=0;
        else if(i==0 && n>1)       // �ϱ߽�
        {
          double_vv[i][j]=0.5*double_vv[i][j-1];
        }
        else if(j==0 && m>1)       // ��߽�
        {
          double_vv[i][j]=0.5*double_vv[i-1][j];
        }
        
        else if(i==n-1 && j<m-1)      // �±߽�
        {
          double_vv[i][j]=double_vv[i][j-1]+0.5*double_vv[i-1][j];
        }
        else if(j==m-1 && i<n-1)      // �ұ߽�
        {
          double_vv[i][j]=double_vv[i-1][j]+0.5*double_vv[i][j-1];
        }
        else if(i==n-1 && j==m-1)     // �����յ�
        {
          double_vv[i][j]=double_vv[i-1][j]+double_vv[i][j-1];
        }
        else                // �м�Ľ��
        {
          double_vv[i][j]=0.5*double_vv[i][j-1]+0.5*double_vv[i-1][j];
        }
      }
    }
    printf("%.2lf\n",double_vv[n-1][m-1]);
  }
  return 0;
}