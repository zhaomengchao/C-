/*
井字游戏
因为是N x N的方格棋盘，在一次遍历中可以对行、对列、对主副对角线进行求和。
"X"和或"O"获胜的条件是：求和=N个"X"或"O"。
没有获胜选手的情况：判断棋盘是否填满，来判断平局或待定。

https://leetcode-cn.com/problems/tic-tac-toe-lcci/
*/
class Solution {
public:
    string tictactoe(vector<string>& board) {
        int bSize=board.size(), N = board.size();
        int sum_row=0, sum_col=0,sum_dia_right=0,sum_dia_left =0,isFull=1;
        for(int i=0;i<bSize;i++)
		{
            sum_row=0, sum_col=0;
            sum_dia_left += board[i][i];           //主对角相加
            sum_dia_right += board[i][bSize-1-i];  //副对角相加
            for(int j=0; j<bSize; j++)
			{
                sum_row += board[i][j]; //行相加
                sum_col += board[j][i];;//列相加
                if(board[i][j] == ' ') isFull =0;
            }
            if(sum_row == ((int)'X') * N || sum_col == ((int)'X') * N){
                return string("X");
            }
            if(sum_row == ((int)'O') * N || sum_col == ((int)'O') * N){
                return string("O");
            }
        }
        if(sum_dia_left == ((int)'X') * N || sum_dia_right == ((int)'X') * N){
                return string("X");
        }
        if(sum_dia_left == ((int)'O') * N || sum_dia_right == ((int)'O') * N){
                return string("O");
        }
        if(isFull){ //没有选手获胜
            return string("Draw");
        }else{
            return string("Pending");
        }
    }
};
