class Solution {
public:
    int compress(vector<char>& chars) {

        int index = 0;
        char check = chars[0];
        int cnt=1;
        for (int i=1; i < chars.size(); i++){
            if (chars[i] == check){
                cnt++;
            } else {
                if (cnt == 1){
                    chars[index] = check;
                    index++;
                } else {
                    chars[index] = check;
                    index++;
                    std::string s = std::to_string(cnt);
                    // cout << cnt;
                    for (int j=0; j<s.size(); j++){
                        chars[index] = s[j];
                        index++;
                    }
                }
                cnt = 1;
                check = chars[i];
            }
        }
        if (cnt == 1){
            chars[index] = check;
            index++;
        }else {
                    chars[index] = check;
                    index++;
                    std::string s = std::to_string(cnt);
                    // cout << cnt;
                    for (int j=0; j<s.size(); j++){
                        chars[index] = s[j];
                        index++;
                    }
                }
        return index;
        
    }
};