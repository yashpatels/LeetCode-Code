class Solution {
public:
    string reverseVowels(string s) {

        vector<char> vowels{'a','e','i','o','u','A', 'E', 'I', 'O', 'U'};
        string ans = s;

        int left = 0;
        int right = s.length()-1;
        int i1=-1;
        int i2=-1;

        while (left < right){

            if (std::find(vowels.begin(), vowels.end(), s[left]) != vowels.end()){
                i1 = left;
            } else {
                left++;
            }
            if (std::find(vowels.begin(), vowels.end(), s[right]) != vowels.end()){
                i2=right;
            } else{
                right--;
            }

            if (i1!=-1 && i2!=-1){
                //swap characters
                char temp = ans[i1];
                ans[i1] = ans[i2];
                ans[i2] = temp;
                i1=-1;
                i2=-1;
                left++;
                right--;
            }
        }
        return ans;
        
    }
};