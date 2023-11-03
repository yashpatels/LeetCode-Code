class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;

        for(int i=0; i<nums.size(); i++) ans = ans^nums[i];

        int temp=ans;
        int i=1;
        while (1) {
            // cout << i << " " << (temp&i) << endl;
            if ((temp&i) == i) {
                // cout << "here";
                break;
            }
            i=i<<1;
            
        }
        // int mask = 1<<i;
        
        int x=0;
        for (int j=0; j<nums.size(); j++){
            if (nums[j]&i) x=x^nums[j];
        }

        vector<int> finalAns;
        finalAns.push_back(x);
        finalAns.push_back(x^ans);
        return finalAns;
    }
};