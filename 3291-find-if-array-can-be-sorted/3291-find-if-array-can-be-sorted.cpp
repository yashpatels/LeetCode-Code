class Solution {
public:
    int getBits(int n) {
        int cnt=0;
        while (n!=0) {
            cnt+=(n%2);
            n=n/2;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        if (nums.size()==1) return true;
        int prevMax = nums[0];
        int prevMin = nums[0];
        int prevBits = getBits(nums[0]);
        int itr = 1;

        while (itr<nums.size() && prevBits==getBits(nums[itr])) {
            prevMax = max(prevMax, nums[itr]);
            prevMin = min(prevMin, nums[itr]);
            itr++;
        }
        if (itr==nums.size()) return true;
        int currentMax = nums[itr];
        int currentMin = nums[itr];
        int currentBits = getBits(nums[itr]);

        for (int i=itr; i<nums.size(); i++) {
            int currentBits = getBits(nums[i]);
            while (i<nums.size() && currentBits == getBits(nums[i])) {
                currentMax=max(currentMax, nums[i]);
                currentMin=min(currentMin, nums[i]);
                i++;
            }
            // cout << currentMax << " " << currentMin << " prev: " << prevMax << " " << prevMin << endl;
            // i--;
            if (i!=nums.size() && currentMin < prevMax) return false;

            if(i<nums.size()) {
                prevMax=currentMax;
                prevMin=currentMin;
            }
            if (i<nums.size()) {
                currentMax = nums[i];
                currentMin = nums[i];
                currentBits = getBits(nums[i]);
            }
            
            // cout << currentMax << " " << currentMin << " prev: " << prevMax << " " << prevMin << endl;
        }
        if (currentMin < prevMax) return false;
        return true;
    }
};