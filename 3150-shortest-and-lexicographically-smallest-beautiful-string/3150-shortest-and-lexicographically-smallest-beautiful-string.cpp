class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0;
        int j=0;
        
        int cnt=0;
        string finalAns;;
        string ans;
        bool first = false;
        while(i<s.size() && s[i]!='1' ){
            i++;
        }
        while (j<s.size() && cnt != k){
            if (s[j] == '1') cnt++;
            j++;
        }
        if (cnt==k){
          ans = string(s.begin() + i, s.begin() + j);  
        }
        cout << "first " << ans << endl;
        // j++;
        while (j < s.size()){
            // cout << s[j] << endl;
            if (s[j] == '1'){
                i++;
                if (s[i]=='1'){
                    string second = string(s.begin() + i, s.begin() + j + 1);
                    cout << second << endl;
                    if (second.size() == ans.size()){
                        for (int in=0; in<second.size(); in++){
                            cout << in<< " " <<second.size() << " " << second[in] << ans[in] << endl ;
                            if (second[in] == '0' && ans[in] != '0'){
                                cout << "here";
                                ans = second;
                                break;
                            } else if (ans[in] == '0' && second[in] != '0'){
                                break;
                            }
                        }
                    }
                    if (second.size() < ans.size()) {
                        ans = second;
                    }
                    j++;
                } 
            } else {
                    j++;
                }
        }
        return ans;
    }
};