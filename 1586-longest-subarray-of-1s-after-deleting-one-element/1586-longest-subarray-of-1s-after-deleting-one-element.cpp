class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int i=0;
        int j=0;

        int cnt = 0;
        int max = 0;

        bool changed = false;

        while (j<nums.size()){
            if (nums[j] == 1){
                cnt++;
                if (max < cnt){
                    max = cnt;
                }
                j++;
            } else {
                if (!changed){
                    changed = true;
                    j++;
                } else {
                    if (nums[i] == 0){
                        changed = false;
                    } else {
                        cnt--;
                    }
                    i++;
                }
            }
        }
        if (max < cnt){
            max = cnt;
        }
        if (!changed){
            max--;
        }
        return max;
        
    }
};