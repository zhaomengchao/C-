//顺时针打印矩阵
class Printer {
public:
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
        vector<int> res;
        //定义左上和右下
        int left=0;
        int right= m -1;
        int top=0;
        int bottom=n-1;
        while(left<=right&&top<=bottom){
            //从左到右
            for(int i=left;i<=right;i++)
                res.push_back(mat[top][i]);
            //从上到下,注意，有一个元素已经访问过了，要过滤掉
            for(int i=top+1;i<=bottom;i++)
                res.push_back(mat[i][right]);
            //从右到左，不过要做单行判断
            if(top!=bottom)
                for(int i=right-1;i>=left;i--)
                    res.push_back(mat[bottom][i]);
            //从下到上，有两个元素被访问过了，过滤掉
            if(left!=right)
                for(int i=bottom-1;i>top;i--)
                    res.push_back(mat[i][left]);
            //一圈之后，行列都缩小
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};