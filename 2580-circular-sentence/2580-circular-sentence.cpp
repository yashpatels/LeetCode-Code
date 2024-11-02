class Solution {
public:
    bool isCircularSentence(string s) {
        if (s[0] != s[s.size()-1]) return false;

        char prev=s[0];
        for (int i=1; i<s.size(); i++) {
            if (s[i] == ' ') {
                if (s[i+1] != prev) {
                    return false;
                }
            }
            prev=s[i];
        }
        return true;
    }
};