class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int i=0;
        int j=0;
        int maxSize = word1.size()+word2.size();
        int cnt=0;

        string ans;


        while(cnt < maxSize){

            if (cnt % 2 == 0 && i < word1.size()){
                ans+=word1[i];
                i++;

            } else if ( cnt % 2 != 0 && j < word2.size()){
                ans+=word2[j];
                j++;

            } else if ( i>=word1.size() && j < word2.size()){
                ans+=word2[j];
                j++;

            } else if (j >= word2.size() && i < word1.size()){
                ans+=word1[i];
                i++;
            }
            cnt++;

        }
        
        return ans;
    }
};