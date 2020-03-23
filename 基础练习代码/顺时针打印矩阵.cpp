//˳ʱ���ӡ����
class Printer {
public:
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
        vector<int> res;
        //�������Ϻ�����
        int left=0;
        int right= m -1;
        int top=0;
        int bottom=n-1;
        while(left<=right&&top<=bottom){
            //������
            for(int i=left;i<=right;i++)
                res.push_back(mat[top][i]);
            //���ϵ���,ע�⣬��һ��Ԫ���Ѿ����ʹ��ˣ�Ҫ���˵�
            for(int i=top+1;i<=bottom;i++)
                res.push_back(mat[i][right]);
            //���ҵ��󣬲���Ҫ�������ж�
            if(top!=bottom)
                for(int i=right-1;i>=left;i--)
                    res.push_back(mat[bottom][i]);
            //���µ��ϣ�������Ԫ�ر����ʹ��ˣ����˵�
            if(left!=right)
                for(int i=bottom-1;i>top;i--)
                    res.push_back(mat[i][left]);
            //һȦ֮�����ж���С
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};