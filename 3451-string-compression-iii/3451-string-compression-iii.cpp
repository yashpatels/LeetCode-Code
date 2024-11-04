class Solution {
public:
    string compressedString(string word) {
        char cur=word[0];
        int cnt=1;

        string comp;
        for (int i=1; i<word.size(); i++) {
            if (word[i]==cur) cnt++;
            else {
                comp+=(cnt+'0');
                cnt=1;
                comp+=cur;
                cur=word[i];
            }

            if (cnt > 9) {
                cnt = 1;
                comp+='9';
                comp+=cur;
            }
        }

        if (cnt > 9) {
                cnt = 1;
                comp+='9';
                comp+=cur;
            }
        comp+=(cnt+'0');
        cnt=1;
        comp+=cur;
        // cur=word[i];
        return comp;
    }
};