class Solution {
    public String reverseWords(String s) {
        Stack<Character> stack = new Stack<Character>();

        String ans = "";

        for (int i=0; i<s.length(); i++){
            if (s.charAt(i) == ' '){
                while (!stack.empty()){
                    ans+=stack.pop();
                }
                 ans+=' ';
            } else {
                stack.push(s.charAt(i));
            }
        }
        while (!stack.empty()){
            ans+=stack.pop();
        }
        return ans;
    }
}