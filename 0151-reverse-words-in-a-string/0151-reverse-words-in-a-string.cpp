class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;
        string temp;

        for (int i=0; i<s.size(); i++){
            if (s[i]!=' '){
                temp+=s[i];
            } 
            
            if (temp.size()!=0 && s[i]==' ') {
                words.insert(words.begin(), temp);
                temp="";
            }
        }
        if (temp.size()!=0) {
                words.insert(words.begin(), temp);
                temp="";
            }

        string ans="";
        for (int i=0; i<words.size(); i++){
            ans +=words[i];
            if (i!=words.size()-1){
            ans+=' ';}
        }
        return ans;
        
    }
};