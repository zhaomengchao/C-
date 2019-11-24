//È¡ÊÖÌ×
class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int min = 0;
        int lmin = 0,rmin = 0;
        int ln = 26;
        int rn = 26;
        for(int i = 0; i < n;i++)
        {
            if(left[i] == 0 || right[i] == 0)
            {
                min += left[i];
                min += right[i];
            }
            else{
                lmin += left[i];
                rmin += right[i];
                if(left[i] < ln)
                {
                    ln = left[i];
                }
                if(right[i] < rn)
                {
                    rn = right[i];
                }
            }
        }
        min += lmin > rmin ? (rmin -rn):(lmin - ln);
        return min + 2;
    }
};