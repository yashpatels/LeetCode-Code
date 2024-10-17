class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;
        int temp=num;

        while (temp!=0) {
            nums.push_back(temp%10);
            temp=temp/10;
        }

        int left=0;
        int right=nums.size()-1;

        while(left<right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

        for (auto x: nums) cout << x << " ";
        cout << endl;

        vector<int> sortNums=nums;
        sort(sortNums.rbegin(), sortNums.rend());
        
        for (auto x: sortNums) cout << x << " ";
        cout << endl;


        int i=0;
        while (i<=nums.size()-1) {
            if (nums[i] != sortNums[i]) break;
            i++;
        }

        if (i==nums.size()) return num;

        int toSwap=nums.size()-1;

        while (toSwap>=0) {
            if (nums[toSwap] == sortNums[i]) break;
            toSwap--;
        }
        swap(nums[i], nums[toSwap]);
        for (auto x: nums) cout << x << " ";
        cout << endl;
        int ans=0;

        for (int itr=0; itr<nums.size(); itr++) {
            ans*=10;
            ans+=nums[itr];
        }
        return ans;


        
    }
};