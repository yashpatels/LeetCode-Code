class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long numZero1=0;
        
        long long sum2=0;
        long long numZero2=0;
        
        for (int i=0; i<nums1.size(); i++){
            if (nums1[i]==0) numZero1++;
            sum1+=nums1[i];
        }
        
         for (int i=0; i<nums2.size(); i++){
            if (nums2[i]==0) numZero2++;
            sum2+=nums2[i];
        }
        
        cout << "sum1: " << sum1 << " Nums zero: " << numZero1 << endl;
        cout << "sum2: " << sum2 << " Nums zero: " << numZero2 << endl;
        
        if (sum1==sum2){
            if (numZero2==numZero1) {
                return sum1+numZero1;
            } else if (numZero1 == 0 && numZero2 != 0) return -1;
            else if  (numZero2 == 0 && numZero1 != 0) return -1;
            else return sum1+max(numZero1, numZero2);
        }

        long long targetSum = sum1+numZero1;

        if (targetSum> sum2 && numZero2!=0 && targetSum >= numZero2+sum2) return targetSum;

        targetSum = sum2+numZero2;
        // cout << targetSum-sum1;
        if (targetSum > sum1 && numZero1!=0 && targetSum >= numZero1+sum1) return targetSum;

        return -1;
        
        // if (sum1 < sum2){
        //     //num of zero in 1 is more;
        //     int targetSum = sum2 + numZero2;
        //     cout << targetSum - sum1 << endl << numZero1;
        //     if (targetSum - sum1 < numZero1){
        //         int targetSum1 = sum1 + numZero1;
        //         if (targetSum1 - sum2 < numZero2){
        //             return -1;
        //         } else {
        //             if (numZero2==0) return -1;
        //             return targetSum1;
        //         }
        //         return -1;
        //     } else {
        //         if (numZero1==0) return -1;
        //         return targetSum;
        //     }
        // } else if (sum1 > sum2){
        //     int targetSum = sum1 + numZero1;
        //     if (targetSum - sum2 < numZero2){
        //         int targetSum1 = sum2 + numZero2;
        //         if (targetSum1 - sum1 < numZero1){
        //             return -1;
        //         } else {
        //             if (numZero1==0) return -1;
        //             return targetSum1;
        //         }
        //         return -1;
        //     } else {
        //         if (numZero2==0) return -1;
        //         return targetSum;
        //     }
        // } else {
            
        // }
        
    }
};