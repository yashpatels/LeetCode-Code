class Solution {
public:
    char findKthBit(int n, int k) {
        if (n==1) return '0';
        string current = "0";
        int i=2;
        while (i!=n+1) {
            int left=0;
            int right=current.size()-1;
            string temp = current;
            while (left<right) {
                swap(temp[left], temp[right]);
                left++;
                right--;
            }

            for (int i=0; i<temp.size(); i++) {
                if (temp[i]=='1') temp[i]='0';
                else temp[i]='1';
            }
            string nextString = current+'1'+temp;
            current=nextString;
            // cout << i << " " << current << endl;
           i++; 
        }
        return current[k-1];
    }
};