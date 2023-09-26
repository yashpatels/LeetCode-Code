class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int cnt = 0;
        int left = 0;
        int right = nums.size()-1;

        while (left < right){
            if (nums[left]+nums[right] == k){
                left++;
                right--;
                cnt++;
            } else if (nums[left] + nums[right] > k){
                right--;
            } else{
                left++;
            }
        }
        return cnt;
    }
};