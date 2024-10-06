class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1 == sentence2) return true;
        vector<string> s1;
        vector<string> s2;

        string temp="";

        for (char x : sentence1) {
            if (x==' ') {
                s1.push_back(temp);
                temp="";
            } else {
                temp+=x;
            }
        }
        s1.push_back(temp);
        temp="";

        for (char x : sentence2) {
            if (x==' ') {
                s2.push_back(temp);
                temp="";
            } else {
                temp+=x;
            }
        }
        s2.push_back(temp);

        int l=0;
        int r1=s1.size()-1;
        int r2=s2.size()-1;

        while (l<min(r1, r2)+1) {
            if (s1[l] != s2[l]) {
                break;
            }
            l++;
        }
        // l--;
        if (l==min(r1, r2)+1) return true;

        while (r1>=0 && r2>=0) {
            cout << s1[r1] << " " << s2[r2] << endl;
            if (s1[r1] != s2[r2]) {
                break;
            }
            r1--;
            r2--;
        }
        r1++;
        r2++;

        // cout << l << " " << r1 << " " << r2 << endl;

        if (r1==l || r2==l || r1<l || r2<l) return true;
        return false;
    }
};