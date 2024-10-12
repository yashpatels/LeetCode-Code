class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> m;

        sort(intervals.begin(), intervals.end());

        for (auto x: intervals) {
            m[x[0]]++;
            m[x[1]+1]--;
        }

        int ans=0;
        int cur=0;
        for (auto x: m) {
            cur+=x.second;
            ans=max(ans, cur);
        }
        if (ans==0) return 1;
        return ans;
    }
};