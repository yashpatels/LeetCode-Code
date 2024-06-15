class Solution {
public:
    vector<vector<int>> ans;
    void help(vector<int>& nums, vector<int>& current, vector<bool>& visited) {
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (!visited[i]) {
                current.push_back(nums[i]);
                visited[i]=true;
                help(nums, current, visited);
                visited[i]=false;
                current.erase(current.begin()+current.size()-1);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        help(nums, temp, visited);
        return ans;
    }
};