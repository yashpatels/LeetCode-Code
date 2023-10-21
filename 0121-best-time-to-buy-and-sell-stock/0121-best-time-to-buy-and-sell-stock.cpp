class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int mins=INT_MAX;
        for (int i=0; i<prices.size(); i++){
            mins = min(mins, prices[i]);
            ans = max(ans, prices[i] - mins);
        }
        return ans;
    }
};