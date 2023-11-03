class Solution {
public:
    int minFlips(int a, int b, int c) {
        int i=32;
        int cnt=0;
        while (i) {
            if (((a&1) | (b&1)) != (c&1)) cnt++;
            if (((a&1)==1) && ((b&1)==1) && ((c&1)==0)) cnt++;
            a=a>>1;
            b=b>>1;
            c=c>>1;
            i--;
        }
        return cnt;

    }
};