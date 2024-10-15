class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int zeros=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='0') zeros++;
        }

        for (char x: s) {
            if (x=='1') ans+=zeros;
            else zeros--;
        }

        return ans;
    }
};