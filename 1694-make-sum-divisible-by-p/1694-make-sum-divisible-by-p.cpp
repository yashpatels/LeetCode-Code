class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<long long> pre(nums.size()+1);
        pre[0]=0;
        pre[1]=nums[0];
        for (int i=1; i<nums.size(); i++) {
            pre[i+1]=(long long)pre[i]+nums[i];
        }
        long long sum=pre[nums.size()];
        if (sum%p==0) return 0;
        long long len=1;

        while (len < nums.size()) {
            int i=0;
            int j=len;

            for (;j<=nums.size(); j++,i++) {
                // cout << (sum-(pre[j]-pre[i])) << " ";
                if ((long long)(sum-(pre[j]-pre[i]))%p==0) return j-i;
            }
            cout << endl;
            len++;
        }

        return -1;


    }
};