class Solution {
public:
    bool rotateString(string s, string goal) {
        int len = s.size();

        while (len--) {
            
            if (s==goal) return true;

            char last = s[s.size()-1];
            s.pop_back();
            s=last+s;   

        }

        return false;
    }
};