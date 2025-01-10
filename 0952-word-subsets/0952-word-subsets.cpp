class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char, int> m;

        for (string x: words2) {
            map<char, int> temp;
            for (char itr: x) {
                temp[itr]++;
            }

            for (auto itr: temp) {

                if (m.find(itr.first) == m.end()) {
                    m[itr.first]=itr.second;
                } else {
                    m[itr.first]=max(m[itr.first], itr.second);
                }
            }
        }
        vector<string> ans;
        for (string x: words1) {

            map<char, int> temp;

            for (char itr: x) temp[itr]++;

            bool found = true;
            for (auto itr: m) {
                if (temp.find(itr.first) == temp.end()) {
                    found=false;
                    break;
                } else if (temp[itr.first]<itr.second) {
                    found=false;
                    break;
                }
            }
            if (found) {
                ans.push_back(x);
            }

        }

        // for (auto x: m) {
        //     cout << x.first << " " << x.second << endl;
        // }
        
        return ans;
    }
};