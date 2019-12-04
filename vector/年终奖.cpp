//ÄêÖÕ½±
class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
           vector<vector<int>> vec( 6, vector<int>( 6, 0 ) ) ;
        vec[0][0] = board[0][0] ;
        
        for ( int i = 1; i < 6; ++ i ) {
            vec[i][0] = vec[i - 1][0] + board[i][0] ;
        }
        for ( int i = 1; i < 6; ++ i ) {
            vec[0][i] = vec[0][i - 1] + board[0][i] ;
        }
        
        for ( int i = 1; i < 6; ++ i ) {
            for ( int j = 1; j < 6; ++ j ) {
                int tmp = max( vec[i - 1][j] + board[i][j], vec[i][j - 1] + board[i][j] ) ;
                vec[i][j] = tmp ;
            }
        }
        
        return vec[5][5] ;
    }
};