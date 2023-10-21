class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int min=INT_MAX;

        for (int i=0; i<prices.size(); i++){
            if (prices[i] < min){
                min = prices[i];
            }
            if (prices[i] - min > ans) ans = prices[i] - min;
        }
        return ans;

        // for (int i=0; i<prices.size(); i++){
        //     for (int j=i+1; j<prices.size(); j++){
        //         if (prices[j] - prices[i] > ans){
        //             ans = prices[j] - prices[i];
        //         }
        //     }
        // }
        // return ans;
        // int buy = INT_MIN;
        // int sell = 0;
        // for (int i=0; i<prices.size(); i++){
        //     buy = max(buy, sell-prices[i]);
        //     sell = max(sell, buy+prices[i]);

        //     cout << buy << " " << sell << endl;
        // }
        // return sell;
    }
};