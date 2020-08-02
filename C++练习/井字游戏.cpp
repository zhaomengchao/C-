/*
������Ϸ
��Ϊ��N x N�ķ������̣���һ�α����п��Զ��С����С��������Խ��߽�����͡�
"X"�ͻ�"O"��ʤ�������ǣ����=N��"X"��"O"��
û�л�ʤѡ�ֵ�������ж������Ƿ����������ж�ƽ�ֻ������

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
            sum_dia_left += board[i][i];           //���Խ����
            sum_dia_right += board[i][bSize-1-i];  //���Խ����
            for(int j=0; j<bSize; j++)
			{
                sum_row += board[i][j]; //�����
                sum_col += board[j][i];;//�����
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
        if(isFull){ //û��ѡ�ֻ�ʤ
            return string("Draw");
        }else{
            return string("Pending");
        }
    }
};
