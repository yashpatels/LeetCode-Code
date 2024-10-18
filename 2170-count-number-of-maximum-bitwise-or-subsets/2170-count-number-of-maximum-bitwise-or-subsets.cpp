class Solution {
public:
    int ans=0;
    void helper(vector<int>& nums, int index, int maxSize, int currentSize, int currentVal, int target) {

        if (maxSize == currentSize && currentVal == target) {
            ans++;
            return;
        }

        if (maxSize == currentSize) {
            return;
        }

        for (int i=index+1; i<nums.size(); i++) {
            helper(nums, i, maxSize, currentSize+1, currentVal|nums[i], target);
        }

    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        sort(nums.begin(), nums.end());
        for (int x: nums) {
            maxOr=maxOr|x;
            // cout << maxOr << " ";
        }

        // helper(nums, current, maxOr);

        for (int i=1; i<=nums.size(); i++) {

            for (int j=0; j<nums.size(); j++) {

                helper(nums, j, i, 1, nums[j], maxOr);

            }

        }

        return ans;
    }
};