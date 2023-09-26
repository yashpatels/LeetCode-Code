class Solution {
public:
    int maxVowels(string s, int k) {

        vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

        int i=0;
        int j=0;
        int cnt = 0;
        int max = -1;

        while (j < s.size()){
            if (std::find(vowels.begin(), vowels.end(), s[j]) != vowels.end()){
                cnt++;
            }
            if (j-i+1 == k){
                if (cnt > max){
                    max = cnt;
                }
                if (std::find(vowels.begin(), vowels.end(), s[i]) != vowels.end()){
                    cnt--;
                }
                i++;
                j++;
            }
            if (j-i+1 < k){
                j++;
            }
            if (max == k){
                return k;
            }
        }
        return max;
    }
};