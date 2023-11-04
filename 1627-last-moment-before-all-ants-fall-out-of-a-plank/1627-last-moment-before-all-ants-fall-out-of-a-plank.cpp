class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int ans=INT_MIN;

        for (int i=0; i<left.size(); i++) {
            if (left[i] > ans) ans = left[i];
        }

        for (int i=0; i<right.size(); i++) {
            if ((n-right[i]) > ans) ans = n-right[i];
        }

        return ans;
    }
};