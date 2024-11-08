class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;

        int current=0;
        int target = pow(2, maximumBit)-1;

        for (int i=0; i<nums.size(); i++) {
            current = current^nums[i];
            ans.push_back(current^target);
        }
        int left=0;
        int right=nums.size()-1;

        while (left<right) {
            swap(ans[left], ans[right]);
            left++;
            right--;
        }
        return ans;
    }
};