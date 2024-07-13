class Solution {
public:
    string intToRoman(int num) {
        int x=10;
        string ans="";
        while (num>0){
            int rem = num%x;
            ans.insert (0,     smallRoman(rem));
            x=x*10;
            num = num - rem;
        }
        return ans;
        
    }

    string smallRoman(int x){
        if (x == 1){
            return "I";
        } else if (x == 2) {
            return "II";
        } else if (x == 3) {
            return "III";
        }else if (x == 4) {
            return "IV";
        }else if (x == 5) {
            return "V";
        }else if (x == 6) {
            return "VI";
        }else if (x == 7) {
            return "VII";
        }else if (x == 8) {
            return "VIII";
        }else if (x == 9) {
            return "IX";
        }else if (x == 10) {
            return "X";
        }else if (x == 20) {
            return "XX";
        }else if (x == 30) {
            return "XXX";
        }else if (x == 40) {
            return "XL";
        }else if (x == 50) {
            return "L";
        }else if (x == 60) {
            return "LX";
        }else if (x == 70) {
            return "LXX";
        }else if (x == 80) {
            return "LXXX";
        }else if (x == 90) {
            return "XC";
        }else if (x == 100) {
            return "C";
        }else if (x == 200) {
            return "CC";
        }else if (x == 300) {
            return "CCC";
        }else if (x == 400) {
            return "CD";
        } else if (x == 500) {
            return "D";
        }else if (x == 600) {
            return "DC";
        }else if (x == 700) {
            return "DCC";
        }else if (x == 800) {
            return "DCCC";
        }else if (x == 900) {
            return "CM";
        }else if (x == 1000) {
            return "M";
        }else if (x == 2000) {
            return "MM";
        }else if (x == 3000) {
            return "MMM";
        }
        return "";
    }
};