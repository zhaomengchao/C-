#include <iostream>

#include "graphics.h"//就是需要引用这个图形库 
#include "game.h"
      

int main()
{
    initgraph(640, 480);   // 初始化，显示一个640*480的窗口 
    randomize();
  	setbkcolor(EGERGB(80,200,220));  //设置背景色 
  	setcolor(EGERGB(255,0,0));       //设置边界颜色
    game A;
  	A.drawchessboard();
  	
  	while(1)
  	{
  		A.getdown(); 
  		A.getdown1();
	}
	  
    getch();               // 暂停一下,等待用户按键 
    closegraph();          // 关闭窗口 
    return 0;
}
