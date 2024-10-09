class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close=0;
        int ans=0;

        for (char x: s) {
            if (x=='(') open++;
            else open--;

            if (open<0) {
                ans++;
                open=0;
            }
        }
        ans+=open;
        return ans;
    }
};