//盛水最多的容器
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int heightSize = int(height.size());
        int leftIndex = 0;
        int rightIndex = heightSize - 1;

        while (leftIndex != rightIndex)
        {
            int tmpHeight;
            int tmpWidth = rightIndex - leftIndex;
            //较短的一侧向中间移动
            if (height[leftIndex] < height[rightIndex])
            {
                tmpHeight = height[leftIndex];
                leftIndex++;
            }
            else
            {
                tmpHeight = height[rightIndex];
                rightIndex--;
            }
            int tmpResult = tmpWidth * tmpHeight;
            if (tmpResult > result)
            {
                result = tmpResult;
            }
        }
        return result;
    }

};