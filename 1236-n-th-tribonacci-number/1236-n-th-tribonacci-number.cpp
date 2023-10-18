class Solution {
public:
    int tribonacci(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        if (n==2) return 1;

        vector<int> a;

        a.push_back(0);
        a.push_back(1);
        a.push_back(1);

        for (int i=3; i<=n; i++){
            a.push_back(a[i-1] + a[i-2] + a[i-3]);
        }
        return a[n];

        // return tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);

    }
};