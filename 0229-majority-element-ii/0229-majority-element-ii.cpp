class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> r;
        float x = floor(nums.size()/3);
        cout << x;
        int val = nums[0];
        int cnt=1;
        
        for (int i=1; i<nums.size(); i++){
            if (val == nums[i]){
                cnt++;
            } else {
                if (cnt > x){
                    r.push_back(val);
                }
                cnt = 1;
                val = nums[i];
            }
        }
        if (cnt > x){
            r.push_back(val);
        }
        return r;
    }
};