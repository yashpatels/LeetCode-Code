class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        // cout<<nums;
        set<vector<int>> s;

        for (int i=0; i<nums.size();i++){
            // if (i!=0 && nums[i]==nums[i-1]){
            //     continue;
            // }
            int target = (nums[i])*(-1);
            int left = i+1;
            int right = n-1;
 
            while (left<right) {
                if (nums[left]+nums[right] == target) {
                    vector<int> v{nums[i], nums[left], nums[right]};
                    left++;
                    right--;
                    s.insert(v);
                    // break;
                } else if (nums[left]+nums[right] > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};