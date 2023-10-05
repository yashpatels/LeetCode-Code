/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        
        int left = 1;
        int right = n;

        if (guess(n)==0) return n;
        // return ehehehe(left, right);

        while (left <= right){
            int mid = left+(right-left)/2;
            int reply = guess(mid);
            if (reply ==1){
                left = mid;
                // guessNumber(mid, right);
            } else if (reply == -1){
                right = mid;
                // guessNumber(left, mid);
            } else {
                return mid;
            }
        }
        return 0;
        // long reply = guess(n);
        // // System.out.println(reply);

        // if (reply==1){
        //     return guessNumber(n+1);
        // } else if (reply==-1){
        //     return guessNumber(n-1);
        // } else {
        //     return n;
        // }
    }

    // public int ehehehe(int left, int right){

    // }
}