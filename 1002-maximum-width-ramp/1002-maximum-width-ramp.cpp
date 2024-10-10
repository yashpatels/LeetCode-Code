class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans=0;
        int left=0;
        int right=0;
        
        vector<int> pre(nums.size());
        pre[nums.size()-1]=nums[nums.size()-1];

        for (int i=nums.size()-2; i>=0; i--) {
            pre[i]=max(pre[i+1], nums[i]);
        }
        int n=nums.size();

        while (right<n) {
            while (left<right && nums[left]>pre[right]) {
                left++;
            }
            ans=max(ans, right-left);
            right++;
        }

        return ans;
    }
};