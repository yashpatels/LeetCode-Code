class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);

        int l=0;
        int r=nums.size()-1;
        bool lf=false;
        bool rf= false;

        while (l <= r) {
            if (nums[l] == target){
                ans[0]=l;
                lf=true;
            } else {
                l++;
            }

            if (nums[r] == target){
                ans[1]=r;
                rf=true;
            } else {
                r--;
            }

            if (lf && rf){
                break;
            }
        }
        return ans;
    }
};