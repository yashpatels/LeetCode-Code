class Solution {
public:
    vector<vector<int>> ans;
    void help(vector<int>& c, vector<int>& temp, int target, int current, int index) {
        if (current == target) {
            ans.push_back(temp);
            return;
        }
        
        if (current > target) {
            return;
        }

        for (int i=index; i<c.size(); i++) {
            temp.push_back(c[i]);
            current+=c[i];
            help(c, temp, target, current, i);
            temp.pop_back();
            current-=c[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> temp;
        help(c,temp, t, 0, 0);
        // set<vector<int>> s;

        // for (auto x: ans) {
        //     sort(x.begin(), x.end());
        //     s.insert(x);
        // }
        // vector<vector<int>> anss{s.begin(), s.end()};
        return ans;
    }
};