class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> m;

        for (auto s: strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto x: m) {
            ans.push_back(x.second);
        }
        return ans;
        
        // vector<vector<string>> ans;

        // vector<string> temp;

        // vector<unordered_map<char, int>> mapVector;

        // temp.push_back(strs[0]);
        // ans.push_back(temp);
        // unordered_map<char, int> m1;
        // for (int j=0; j<strs[0].size(); j++) {
        //     m1[strs[0][j]]++;
        // }
        // mapVector.push_back(m1);


        // for (int i=1; i<strs.size(); i++) {

        //     unordered_map<char, int> m;

        //     for (int j=0; j<strs[i].size(); j++) {
        //         m[strs[i][j]]++;
        //     }

        //     bool found = false;
        //     for (int j=0; j<ans.size(); j++) {
        //         if (mapVector[j] == m) {
        //             ans[j].push_back(strs[i]);
        //             found=true;
        //             break;
        //         }
        //     }
        //     if (!found) {
        //         vector<string> temp1;
        //         temp1.push_back(strs[i]);
        //         ans.push_back(temp1);
        //         mapVector.push_back(m);
        //     }

        // }
        // return ans;

    }
};