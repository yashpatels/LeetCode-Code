class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;

        for (int i=0; i<n-k+1; i++) {
            // cout << "for " << i << endl;
            int prev = nums[i];
            int toPush=nums[i];
            for (int j=i+1; j-i<k; j++) {
                if (prev+1!=nums[j]){
                    toPush=-1;
                    break;
                } else {
                    prev=nums[j];
                    toPush=nums[j];
                }
            }
            ans.push_back(toPush);
            // cout << endl;
        }
        return ans;
    }
};