class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for (string x: words) {
            if (x.substr(0, pref.size()) == pref ) ans++;
        }
        return ans;
    }
};