class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        // if (str1 + str2 != str2 + str1){
        //     return "";
        // }
        // return str1.substr(0, gcd(str1.size(), str2.size()));

        int n1 = str1.size();
        int n2 = str2.size();

        string ans;

        while(n1 != n2){
            if (n1 > n2){
                n1-=n2;
            } else{
                n2-=n1;
            }
        }

        vector<int> div;
        for (int i=n1; i>0; i--){
            if (n1%i == 0){
                div.push_back(i);
            }
        }

        for (int i=0; i<div.size(); i++){

            bool still = true;

            string check = str1.substr(0, div[i]);

            for (int j=0; j<str1.size();){

                string tempCheck = str1.substr(j, div[i]);
                // cout << tempCheck << " " << check << "\n";
                if (tempCheck.compare(check)!=0){
                    still = false;
                    break;
                }
                j=j+div[i];
            }

            for (int j=0; j<str2.size();){

                string tempCheck = str2.substr(j, div[i]);
                if (tempCheck.compare(check)!=0){
                    still = false;
                    // cout << tempCheck << " " << check << "\n";
                    break;
                }
                j=j+div[i];
            }

            if (still){
                return check;
            }
        }
        return "";
    }
};