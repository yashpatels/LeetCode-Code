class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int prevSum;

        // int dp[nums.size()];

        for (int i=0; i<nums.size(); i++){
            if (i==0) prevSum = nums[i];
            else {
                prevSum = max(nums[i], prevSum+nums[i]);
            }
            if (sum < prevSum) sum = prevSum;
        }

        return sum;
    }
};