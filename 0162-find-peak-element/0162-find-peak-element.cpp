class Solution {
public:
    int size=0;
    int findPeakElement(vector<int>& nums) {
        size = nums.size();
        if (size==1) return 0;

        return binarySearch(nums, 0, nums.size()-1);
    }

    int binarySearch(vector<int>& nums, int l, int r){

        int mid = l + (r-l)/2;

        if ((mid > 0 && mid < size-1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            || (mid == 0 && nums[mid] > nums[mid+1])
            || (mid == size-1 && nums[mid > nums[mid-1]])){
                return mid;
            } else if (mid > 0 && nums[mid-1] > nums[mid]){
                return binarySearch(nums, l, mid-1);
            } else {
                return binarySearch(nums, mid+1, r);
            }


    }
};