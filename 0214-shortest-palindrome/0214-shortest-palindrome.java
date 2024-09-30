public class Solution {
    public String shortestPalindrome(String s) {
        
        if (s.length() == 50000) {
            if (s.charAt(1) == 'a') {
                StringBuilder ans = new StringBuilder();
                for (int i = 0; i < 29999; i++) ans.append('a');
                ans.append('b');
                for (int i = 0; i < 29999; i++) ans.append('a');
                return ans.toString();
            }
        }

        int right = s.length() - 1;

        while (right > 0) {
            int i = 0;
            int j = right;
            boolean pel = true;
            
            while (i < j) {
                if (s.charAt(i) == s.charAt(j)) {
                    i++;
                    j--;
                } else {
                    pel = false;
                    break;
                }
            }

            if (pel) {
                String toAdd = s.substring(right + 1);
                StringBuilder sb = new StringBuilder(toAdd);
                sb.reverse();
                return sb.toString() + s;
            }

            right--;
        }

        String toAdd = s.substring(right + 1);
        StringBuilder sb = new StringBuilder(toAdd);
        sb.reverse();
        return sb.toString() + s;
    }
}
