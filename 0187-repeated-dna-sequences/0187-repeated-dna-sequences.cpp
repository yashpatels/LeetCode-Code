class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        int i=0;
        int j=9;

        vector<string> ans;
        map<string, int> dupCheck;

        string check = s.substr(i,10);
        cout << check;
        ++dupCheck[check];
        i++;
        j++;
        while (j<s.size()){
            check = s.substr(i,10);

            if(dupCheck.find(check) != dupCheck.end()){
                if (dupCheck[check]==1){
                    ans.push_back(check);
                }
                ++dupCheck[check];
            } else {
                ++dupCheck[check];
            }
            i++;
            j++;

        }

        return ans;
    }
};