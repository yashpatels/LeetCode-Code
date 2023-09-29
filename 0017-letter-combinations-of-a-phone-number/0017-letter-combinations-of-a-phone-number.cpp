class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> mapper{"abc", "def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;

        for (int i=0; i<digits.size(); i++){

            vector<string> temp;
            int x = digits[i] - '0';
            cout << x;
            x-=2;
            string mappedChars = mapper[x];

            if (i == 0){
                for(int j=0; j<mappedChars.size(); j++){
                    string s(1,mappedChars[j]);
                    temp.push_back(s);
                }
            } else {
                for (int j=0; j<mappedChars.size(); j++){
                    for (int k=0; k<ans.size(); k++){
                        temp.push_back(ans[k] + mappedChars[j]);
                    }
                }

            }
            ans = temp;

        }
        return ans;

    }
};