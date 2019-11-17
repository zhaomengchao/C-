//井字棋
//对角线/一行/一列全为相同数值时为true
class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        int row = board.size();
        int sum;
        //判断行
        for(int i = 0; i < row; ++i)
        {
            sum = 0;
            for(int j = 0; j < row; ++j)
            {
                sum += board[i][j];
            }
            if(sum == row)
            {
                return true;
            }
        }
        //判断列
        for(int i = 0; i < row; ++i)
        {
            sum = 0;
            for(int j = 0; j < row; ++j)
            {
                sum += board[j][i];
            }
            if(sum == row)
            {
                return true;
            }
        }
        //判断正对角
        sum = 0;
        for(int i = 0; i < row;++i)
        {
            sum += board[i][i];
        }
        if(sum == row)
        {
            return true;
        }
        
        //判断反对角
        sum = 0;
        for(int i = 0; i < row; ++i)
        {
            
            sum += board[i][row - i - 1];
        }
        if( sum == row)
        {
            return true;
        }
        return false;
    }
};
