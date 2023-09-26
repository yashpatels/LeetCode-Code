class Solution {
public:
    int jump(vector<int>& nums) {
        int total = 0;

        if (nums.size()==1){
            return 0;
        }
        
        for (int i=0; i<nums.size(); ){
            if (i + nums[i]+1 >= nums.size()){
                total++;
                return total;
            }
            int temp = 0;
            int j = i+1;
            int jumpIndex = 0;
            int maxJump = 0;
            while (temp < nums[i] && j<nums.size()){
                if (nums[j] + temp > maxJump){
                    maxJump = nums[j] + temp;
                    jumpIndex = j;
                }
                j++;
                temp++;
            }
            i=jumpIndex;
            total++;
        }

        return total;
        
    }
};