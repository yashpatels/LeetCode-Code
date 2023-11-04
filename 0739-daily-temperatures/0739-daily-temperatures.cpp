class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size(), -1);

        stack<int> s;
        s.push(0);

        for (int i=1; i<t.size(); i++) {
            
            if (t[s.top()] > t[i]) {
                s.push(i);
            } else {
                while (!s.empty() && t[s.top()] < t[i]) {
                    ans[s.top()] = i-s.top();
                    s.pop();
                }
                s.push(i);
            }
        }

        while (!s.empty()) {
            ans[s.top()] = 0;
            s.pop();
        }

        return ans;
    }
};