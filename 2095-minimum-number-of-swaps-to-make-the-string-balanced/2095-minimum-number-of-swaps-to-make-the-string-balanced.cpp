class Solution {
public:
    int minSwaps(string s) {
        int closings=0;
        int openings=0;

        int right=s.size()-1;

        int ans=0;

        for (int i=0; i<s.size(); i++) {

            if (s[i] == '[') {
                openings++;
            } else {
                closings++;
            }

            if (closings > openings) {
                
                while (s[right] != '[') {
                    right--;
                }
                // cout << "for " << i << " swapping with " << right << endl;
                closings--;
                openings++;
                swap(s[i], s[right]);
                ans++;
            }

        }
        return ans;
    }
};