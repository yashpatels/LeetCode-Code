class Solution {
public:
    vector<int> ans;
    int tart = 0;
    int cnt = 0;
    vector<int> searchRange(vector<int>& nums, int target) {
        // vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);

        if (nums.size() == 0) return ans;
        // if (nums.size() == 1 && )

        int l=0;
        int r=nums.size()-1;
        tart = target;
        // bfs(nums, l, r);
        // return ans;

        bool lf=false;
        bool rf= false;

        while (l <= r) {
            if (nums[l] == target){
                ans[0]=l;
                lf=true;
            } else {
                l++;
            }

            if (nums[r] == target){
                ans[1]=r;
                rf=true;
            } else {
                r--;
            }

            if (lf && rf){
                break;
            }
        }
        return ans;
    }

    void bfs(vector<int>& nums,int l,int r){
        int mid = l + (r-l)/2;
        cout <<"mid is " <<mid << " left: " << l << " right: " << r << "\n\n";

        if (mid == l){
            if (nums[l] != nums[r]){
                if (nums[l]==tart){
                    ans[cnt] = l;
                    cnt++;
                }
                if (nums[r]==tart){
                   ans[cnt] = r;
                   cnt++;
                }
            }
            return;
        }

        if (nums[mid] > tart){
            cout << "left\n";
            cout << "mid to left with l: " << l << " r: " << mid << endl;
            bfs(nums, l, mid);
        } else if (nums[mid] < tart){
            cout << "right\n";
            cout << "mid to right with l: " << mid << " r: " << r << endl;
            bfs (nums, mid, r);
        } else {
            cout << "equal\n";
            cout << "mid to left with l: " << l << " r: " << mid << endl;
            bfs(nums, l, mid);
            cout << "mid to right with l: " << mid << " r: " << r << endl;
            bfs(nums, mid, r);
        }
    }
};