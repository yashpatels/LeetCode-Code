class Solution {
public:
    long long minEnd(int n, int x) {
        if (n==1) return x;
        long long ans=0;
        n--;
        int power=0;
        int cnt=n;
        while (n!=0) {

            int rem = x%2;
            x=x/2;
            if (rem == 0) {
                int toAddBit = n%2;
                n=n/2;
                if (toAddBit==1) {
                    ans+=pow(2, power);
                }
            } else {
                ans+=pow(2, power);
            }
            power++;
        }  

        while  (x!=0) {
            int rem = x%2;
            x=x/2;
            if (rem==1) {
                ans+=pow(2, power);
            }
            power++;
        }
        return ans;
    }
};


