class Solution {
public:
    int minimumPushes(string word) {
        vector<int> m(26);

        for (int i=0; i<word.size(); i++) {
            m[word[i]-'a']++;
        }

        sort(m.begin(), m.end(), greater<int>());
        int ans=0;
        for (int i=0; i<26; i++) {
            // cout << i << " " << m[i] << endl;
            if (i<8) {
                ans+=m[i];
            }else if (i<16) {
                ans+=2*m[i];
            } else if(i<24) {
                ans+=3*m[i];
            } else {
                ans+=4*m[i];
            }
        }

        return ans;


    }
};