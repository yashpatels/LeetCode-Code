class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans(nums.size(), -1);
        int index = nums.size()-1;
        int current=0;
        int target = pow(2, maximumBit)-1;

        for (int i=0; i<nums.size(); i++) {
            current = current^nums[i];
            ans[index] = (current^target);
            index--;
        }
        return ans;
    }
};