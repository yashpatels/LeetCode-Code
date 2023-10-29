class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int current=1;
        int ans =0;
        while (current!=nums.size()+1){
            for (int i=0; i<=nums.size()-current; i++){
                // cout << i << " to " << i+current << endl;
                std::set<int> sa(nums.begin()+i, nums.begin()+i+current);
                // std::cout << sa.size() << std::endl;
                ans+=(sa.size()*sa.size());
            }
            // cout << endl;
            current++;
        }
        return ans;
    }
};