class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int cnt=0;
        int max=0;
        int temp = k;

        while (j<nums.size()){
            if (nums[j] == 1){
                cnt++;
                j++;
            } else {
                if (temp > 0){
                    cnt++;
                    if (max < cnt){
                        max = cnt;
                    }
                    temp--;
                    j++;
                } else {
                    if (nums[i]==1){
                        if (max < cnt){
                            max = cnt;
                        }
                        cnt--;
                        i++; 
                    } else {
                        cout << i << " " << j << "\n";
                        cnt--;
                        temp++;
                        i++;
                    }
                }

            }
        }  
        if (max < cnt) {
            max = cnt;
        }
        return max;     
    }
};