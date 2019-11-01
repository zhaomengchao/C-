#ifndef GAME_H
#define GAME_H
struct POS
{
	int row;
	int col;
};
class game
{
	public:
		game();
		~game();
		void drawchessboard();
		struct POS getmousepos();
		void getdown();
		void getdown1();
	private:
		const int winw = 640;
		const int winh = 480;
     
		const int width=400;
		const int hight=400;
	
		const int gridsize=8;
		int gridw = width / gridsize;
		int gridh = hight / gridsize;
	
		int xbegin = (winw-width) / 2;
		int ybegin = (winh-hight) / 2;
};

#endif
