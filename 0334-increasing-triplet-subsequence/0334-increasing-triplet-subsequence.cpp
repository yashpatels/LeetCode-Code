class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int min = nums[0];
        int mid = INT_MAX;
        int max = INT_MAX;
        bool mdC = false;
        bool mxC = false;


        for (int i=0; i<nums.size(); i++){

            if (nums[i] <= min && i < nums.size()-2){
                min = nums[i];
            } else if (nums[i] <= mid && nums[i] > min && i < nums.size()-1){
                mid = nums[i];
                mdC = true;
            } else if (nums[i] <= max && nums[i] > mid){
                max = nums[i];
                mxC = true;
            }
            if ( min < mid && mid < max && mxC && mdC){
                return true;
            }
        }

        return false;



        // int left = 0;
        // int right = nums.size()-1;
        // // cout << left << right;

        // while (left<right){
        //     // cout<<"int";
        //     if (nums[left] > nums[right]){
        //         // cout << "yo";
        //         left++;
        //     } else {
        //         // cout << "here";
        //         for (int i=left+1; i<right; i++){
        //             // cout << "x";
        //             if (nums[i] > nums[left] && nums[i] < nums[right]){
        //                 return true;
        //             }
        //         }
        //         right--;
        //     }
        // }
        // return false;
    }
};