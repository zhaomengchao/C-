#include <iostream>

#include "graphics.h"//������Ҫ�������ͼ�ο� 
#include "game.h"
      

int main()
{
    initgraph(640, 480);   // ��ʼ������ʾһ��640*480�Ĵ��� 
    randomize();
  	setbkcolor(EGERGB(80,200,220));  //���ñ���ɫ 
  	setcolor(EGERGB(255,0,0));       //���ñ߽���ɫ
    game A;
  	A.drawchessboard();
  	
  	while(1)
  	{
  		A.getdown(); 
  		A.getdown1();
	}
	  
    getch();               // ��ͣһ��,�ȴ��û����� 
    closegraph();          // �رմ��� 
    return 0;
}
