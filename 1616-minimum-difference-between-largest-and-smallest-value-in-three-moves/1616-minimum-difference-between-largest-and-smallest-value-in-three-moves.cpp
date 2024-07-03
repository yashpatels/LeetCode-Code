class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        int n=nums.size();

        sort(nums.begin(), nums.end(), greater<int>());

        if (nums.size() <= 3) return 0;

        int x1=nums[3]-nums[n-1];
        int x2=nums[2]-nums[n-2];
        int x3=nums[1]-nums[n-3];
        int x4=nums[0]-nums[n-4];

        return min(min(x1, x2), min(x3, x4));
    }
};