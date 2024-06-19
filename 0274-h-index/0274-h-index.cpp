class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.rbegin(), c.rend());

        int ans=0;

        for (int i=0; i<c.size(); i++) {

            if (c[i] <= ans) {
                return ans;
            }
            ans++;

        }
        return ans;
    }
};