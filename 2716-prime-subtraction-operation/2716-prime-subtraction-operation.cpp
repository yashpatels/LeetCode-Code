class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxVal=INT_MIN;

        for (int x: nums) {
            maxVal=max(maxVal, x);
        }

        vector<int> primes;

        for (int i=2; i<=maxVal; i++) {
            int cnt=0;
            for (int j=1; j<=i; j++) {
                if (i%j==0) cnt++;
            }
            if (cnt==2) primes.push_back(i);
        }

        for (int x: primes) {
            cout << x << " ";
        }

        for (int i=nums.size()-2; i>=0; i--) {
            
            if (nums[i] >= nums[i+1]) {
                int diff = nums[i]-nums[i+1];
                int toDelete=INT_MIN;
                for (auto x: primes) {
                    if (x>diff) {
                        toDelete=x;
                        break;
                    }
                }
                if (toDelete==INT_MIN) return false;
                nums[i]=nums[i]-toDelete;
                if (nums[i]<=0) return false;
            }
        }
        return true;
    }
};