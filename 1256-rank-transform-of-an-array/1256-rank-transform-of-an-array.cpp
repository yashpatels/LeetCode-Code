class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans=arr;
        map<int, int> m;
        sort(ans.begin(), ans.end());
        int itr=1;
        for (int i=0; i<ans.size(); i++) {
            if (m.find(ans[i]) == m.end()) {
                m[ans[i]]=itr;
                itr++;
            }
        }
        int i=0;
        for (auto x: arr) {
            ans[i]=m[x];
            i++;
        }
        return ans;
    }
};