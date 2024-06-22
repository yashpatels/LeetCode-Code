class Solution {
public:
    double myPow(double x, double n) {
        double ans=1;
        long long pow = abs(n);
        double base = x;
        while(pow) {
            if (pow%2 == 1) ans*=base;
            base*=base;
            pow=pow/2;
        }
        if (n<0) return 1/ans;
        return ans;
    }
};
