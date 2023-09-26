class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int i=0;
        int j=0;
        int sum = 0;
        int maxSum = INT_MIN;

        while(j<nums.size()){
            sum+=nums[j];
            if (j-i+1 == k){
                if (maxSum < sum){
                    maxSum = sum;
                }
                sum-=nums[i];
                j++;
                i++;
            } else if (j-i+1 < k){
                j++;
            }
        }
        return (double) maxSum/k;
        
    }
};