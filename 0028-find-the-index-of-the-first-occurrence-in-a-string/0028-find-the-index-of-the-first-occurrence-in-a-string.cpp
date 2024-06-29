class Solution {
public:
    int strStr(string haystack, string needle) {
        int x=0;
        for (int i=0; i<haystack.size();i++){

            for (int j=0; j<needle.size();j++){
                if (needle[j] == haystack[j+i]){
                    x=1;
                } else {
                    x=0;
                    break;
                }

            }
            if (x==1)
            {
                return i;
            }
        }
        return -1;
    }
};