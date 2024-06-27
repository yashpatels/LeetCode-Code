class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> m;

        for (int i=0; i<edges.size(); i++) {
            m[edges[i][0]]++;
            m[edges[i][1]]++;
        }   

        int current = INT_MIN;
        int ans;
        for (auto x: m) {
            if (x.second > current) {
                ans = x.first;
                current=x.second;
            }
        }
        return ans;
    }
};