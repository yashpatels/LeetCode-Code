class Solution {
public:

    int canDistribute(int k, vector<int>& quantities) {
        int current=0;

        for (auto x: quantities) {
            if (x%k!=0) current++;
            current+=x/k;
        }
        // cout << "for " << k << " " << current << endl;
        return current;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int start=1;
        int end=INT_MIN;
        for (auto x: quantities) {
            end=max(end, x);
        }
        int ans = INT_MAX;

        while(start<=end) {
            int middle = start+(end-start)/2;
            int current = canDistribute(middle, quantities);
            if (current <= n) {
                ans=min(middle, ans);
                end=middle-1;
            } else if (current>n){
                // ans=min(middle, ans);
                start=middle+1;
            } else {
                ans=min(middle, ans);
                end=middle-1;
            }
        }
        return ans;
    }
};