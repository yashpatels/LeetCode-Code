class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> ans;
        vector<int> prefix;
        prefix.push_back(1);
        for (int i=1; i<nums.size(); i++){
            prefix.push_back(prefix[i-1]*nums[i-1]);
        }
        int temp = nums[nums.size()-1];
        ans.insert(ans.begin(), prefix[nums.size()-1]);
        for (int i=nums.size()-2; i>=0; i--){
            ans.push_back(prefix[i]*temp);
            temp = temp*nums[i];
        }
        vector<int> ret;
        for (int i=ans.size()-1; i>=0; i--){
            ret.push_back(ans[i]);
        }
        return ret;
    }
};