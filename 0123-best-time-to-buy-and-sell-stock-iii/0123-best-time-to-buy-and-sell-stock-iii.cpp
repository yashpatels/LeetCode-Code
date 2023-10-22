class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems/


        // T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
        // T[i][k][1] = max(T[i-1][k][1], T[i-1][k-1][0] - prices[i])


        int buy1=INT_MIN;
        int buy2=INT_MIN;
        int sell1=0;
        int sell2=0;


        for (int i=0; i<prices.size(); i++){
            sell2 = max(sell2, buy2+prices[i]);
            buy2 = max(buy2, sell1-prices[i]);


            sell1 = max(sell1, buy1+prices[i]);
            buy1 = max(buy1, -prices[i]);

        }
        return sell2;
    }
};