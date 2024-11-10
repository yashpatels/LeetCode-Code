class Solution {
public:

    void printVec(vector<int>& nums) {
        for (int i=0; i<32; i++) cout << nums[i] << " ";
        cout << endl;
    }

    int addValue(vector<int>& nums, int x) {
        int i=0;
        while (x!=0) {
            nums[i]+=(x%2);
            x=x/2;
            i++;
        }

        int val=0;
        i=0;

        while (i<32) {
            if (nums[i]>0) {
                val+=pow(2, i);
            }
            i++;
        }
        // cout << val << endl;
        return val;

    }

    int removeValue(vector<int>& nums, int x) {
        int i=0;
        while (x!=0) {
            nums[i]-=(x%2);
            x=x/2;
            i++;
        }

        int val=0;
        i=0;

        while (i<32) {
            if (nums[i]>0) {
                val+=pow(2, i);
            }
            i++;
        }
        // cout << val << endl;
        return val;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> cur(32, 0);

        int left=0;
        int current=0;
        int ans=INT_MAX;

        for (int right=0; right<nums.size(); right++) {
            current=addValue(cur, nums[right]);
            // printVec(cur);
            // cout << current << endl;
            if (current >= k) {
                ans=min(ans, right-left+1);
                while (current!=0 && current>=k) {
                    ans=min(ans, right-left+1);
                    current=removeValue(cur, nums[left]);
                    // cout << "removing left " << nums[left] << endl;
                    // printVec(cur);
                    left++;
                }
                // ans=min(ans, right-left+1);
            }
        }
        while (current!=0 && current>=k) {
                    ans=min(ans, static_cast<int>(nums.size())-left+1);
                    current=removeValue(cur, nums[left]);
                    // cout << "removing left " << nums[left] << endl;
                    // printVec(cur);
                    left++;
                }
        // if (current>=k) ans=min(ans, static_cast<int>(nums.size()));
        if (ans == INT_MAX) return -1;
        return ans;
    }
};