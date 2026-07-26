class Solution {
public:
    int maxArea(vector<int>& height) {

        int res = 0;
        int j = height.size() - 1;
        int i = 0;

        while (j >= i) {
            int area = (j - i) * min(height[j], height[i]);

            if (height[j] < height[i])
                j--;
            else
                i++;

            res = max(area, res);
        }

        return res;
    }
};