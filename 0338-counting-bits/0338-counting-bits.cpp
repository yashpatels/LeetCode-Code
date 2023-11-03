class Solution {
public:
    vector<int> countBits(int x) {
        vector<int> ans;
        for (int i=0; i<=x; i++){
            int count = 0;
            int n=i;
            while (n) {
                count += n & 1;
                n >>= 1;
            }
            ans.push_back(count);
        }

        return ans;
    }
};