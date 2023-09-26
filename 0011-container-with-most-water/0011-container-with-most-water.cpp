class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size()-1;

        int maxArea = 0;

        while (left < right){

            int curArea = min(height[left], height[right]) * (right - left);

            cout << curArea;

            if (curArea > maxArea){
                cout << maxArea;
                maxArea = curArea;
            }

            if(height[left] < height[right]){
                // cout <<"left:"<< left<<"\n";
                left++;
            } else {
                right--;
            }

        }

        return maxArea;
        
    }
};