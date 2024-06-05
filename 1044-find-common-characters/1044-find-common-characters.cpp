class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;

        map<char, int> m;
        for (char x: words[0]) {
            m[x]++;
        }

        for (int i=1; i<words.size(); i++) {
            map<char, int> temp;

            for (char x: words[i]) {
                if (m.find(x) != m.end()) {
                    m[x]--;
                    if (m[x]>=0) temp[x]++;
                }
            }
            m=temp;
        }

        for (auto x: m) {
            int temp = x.second;
            while(temp--) {
                ans.push_back(string(1, x.first));
            }
            // cout << x.first << " ";
        }
        return ans;
    }
};