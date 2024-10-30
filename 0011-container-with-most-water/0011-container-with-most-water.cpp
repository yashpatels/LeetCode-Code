class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;

        int length = height.size()-1;

        int left=0;
        int right=height.size()-1;

        while (left<right) {
            ans = max(ans, length*min(height[left], height[right]));


            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
            length--;
        }

        return ans;
    }
};