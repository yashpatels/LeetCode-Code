class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       map<char, int> m;

       for (char x: s1) {
        m[x]++;
       } 

       int left=0;
       int right=0;
        map<char, int> m1;
       for (int right=0; right<s2.size(); right++) {
            if (m.find(s2[right]) != m.end()) {
                //add to map;
                m1[s2[right]]++;

               while (right - left + 1 > s1.size()) {
                    if (m1[s2[left]] == 1) {
                        m1.erase(s2[left]);
                    } else {
                        m1[s2[left]]--;
                    }
                    left++;
                }
                //check map are equals;
                if (m1 == m) {
                    return true;
                }
            } else {
                left=right+1;
                m1.clear();
            }
       }
       if (m1==m) return true;
       return false;
    }
};