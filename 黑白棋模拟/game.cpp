#include "game.h"
#include "graphics.h"
game::game()
{
}

game::~game()
{
}
void game::drawchessboard()
{
	int x1,y1,x2,y2;
	
	x1 = xbegin;
	x2 = xbegin + width;	
	for(int i=0; i<=gridsize; ++i)
	{
		y1 = y2 = ybegin + i * gridh;
		line(x1,y1,x2,y2);
	}
		
	y1 = ybegin;
	y2 = ybegin + hight;
	for(int j=0; j<=gridsize; ++j)
	{
		x1 = x2 = xbegin + gridw * j;
		line(x1,y1,x2,y2);
	}
}
POS game::getmousepos()
{
	
	POS pos;
	mouse_msg msg = {0};
	while(1)
	{
		msg = getmouse();
		if(msg.is_left()&&msg.is_down()&&
		msg.x > xbegin && msg.x < xbegin + width &&
		msg.y > ybegin && msg.y <ybegin +hight)
		{
			pos.col = (msg.x - xbegin)/gridw;
			pos.row = (msg.y - ybegin)/gridh;
			break;
		}
	}
	return pos;

}
void game::getdown()
{
	POS pos =getmousepos();
  		
  	setcolor(WHITE);
  	setfillcolor(WHITE);
  		
  	xyprintf(0,0,"%d,%d",pos.row,pos.col);
  	fillellipse(pos.col*gridw + xbegin + gridw/2,
		        pos.row*gridh + ybegin + gridh/2,
				gridw*2/5,gridh*2/5);
}
void game::getdown1()
{
	POS pos =getmousepos();
  		
  	setcolor(BLACK);
  	setfillcolor(BLACK);
  		
  	xyprintf(0,0,"%d,%d",pos.row,pos.col);
  	fillellipse(pos.col*gridw + xbegin + gridw/2,
		        pos.row*gridh + ybegin + gridh/2,
				gridw*2/5,gridh*2/5);
} 
