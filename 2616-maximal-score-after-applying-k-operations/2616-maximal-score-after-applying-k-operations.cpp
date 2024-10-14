class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;

        priority_queue<int> pq;

        for (int x: nums) pq.push(x);

        while (k--) {

            int temp = pq.top();
            pq.pop();

            ans+=temp;

            int toPush = ceil(double((double)temp/3));
            // cout << double((double)temp/3) << endl;
            pq.push(toPush);

        }
        return ans;
    }
};