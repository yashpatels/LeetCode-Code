class Solution {
public:
    int rob(vector<int>& nums) {

        vector<int> dp;
        dp.push_back(0);
        for (int i=0; i<nums.size(); i++){
            if (i==0){
                dp.push_back(nums[i]);
            } else {
                dp.push_back(max(nums[i]+dp[i-1], dp[i]));
            }
        }
        return dp[nums.size()];
    }
};