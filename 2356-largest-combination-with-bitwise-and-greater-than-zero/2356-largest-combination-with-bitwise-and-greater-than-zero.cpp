class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        int toAnd=1;

        int x=24;
        while (x--) {
            int cnt=0;
            for (int i=0; i<candidates.size(); i++) {
                // cout << (candidates[i]&toAnd) << endl;
                if ((candidates[i]&toAnd) == toAnd) {
                    cnt++;
                }
            }
            // cout << toAnd << " here " << x << endl;
            ans=max(ans, cnt);
            toAnd=toAnd<<1;
        }
        return ans;
    }
};