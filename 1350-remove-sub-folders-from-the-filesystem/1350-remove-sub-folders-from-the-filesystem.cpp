class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        string prev = folder[0];
        vector<string> ans;
        ans.push_back(prev);
        for (int i=1; i<folder.size(); i++) {
            string current = folder[i];

            if (current.size()>prev.size() && current.substr(0, prev.size()) == prev && current[prev.size()]=='/') {
                continue;
            } else {
                ans.push_back(current);
                prev=current;
            }
        }
        return ans;
    }
};