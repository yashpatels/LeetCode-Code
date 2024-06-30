class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;

        int ans=0;
        int zeros=0;

        int current = nums[0]%k;
        if (current<0) current+=k;
        m[current]++;
        if (current==0) zeros++;
        int rem=INT_MAX;

        for (int i=1; i<n; i++) {
            
            current+=nums[i];
            
            if (current<0) {
                while(current<0) current+=k;
            }
            
            rem = current%k;
            
            if (rem==0) zeros++;
            else if (m.find(rem) != m.end()) {
                ans+=m[rem];
                m[rem]++;
            } else {
                m[rem]++;
            }

        }
        if (zeros>0) ans+=(zeros*(zeros+1))/2;
        return  ans;
    }
};