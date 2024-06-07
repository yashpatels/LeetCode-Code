class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string, int> m;

        for (string x: dictionary) {
            m[x]++;
        }
        string word;
        istringstream iss(sentence);
        string ans="";
        while (iss >> word) {

            string temp="";
            for (int i=0; i<word.size(); i++) {
                temp+=word[i];
                if (m.find(temp) != m.end()) {
                    break;
                } 
            }
            ans+=temp+" ";

        }
        ans.pop_back();
        return ans;

    } 
};