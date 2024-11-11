class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxVal=INT_MIN;

        for (int x: nums) {
            maxVal=max(maxVal, x);
        }

        vector<int> primes = {2, 3, 5, 7, 521, 11, 523, 13, 17, 19, 23, 29, 541, 31, 547, 37, 41, 43, 557, 47, 563, 53, 569, 59, 571, 61, 577, 67, 71, 73, 587, 79, 593, 83, 599, 89, 601, 607, 97, 101, 613, 103, 617, 107, 619, 109, 113, 631, 127, 641, 131, 643, 647, 137, 139, 653, 659, 149, 661, 151, 157, 673, 163, 677, 167, 683, 173, 179, 691, 181, 701, 191, 193, 197, 709, 199, 719, 211, 727, 733, 223, 227, 739, 229, 743, 233, 239, 751, 241, 757, 761, 251, 257, 769, 773, 263, 269, 271, 787, 277, 281, 283, 797, 293, 809, 811, 307, 821, 311, 823, 313, 827, 317, 829, 839, 331, 337, 853, 857, 347, 859, 349, 863, 353, 359, 877, 367, 881, 883, 373, 887, 379, 383, 389, 907, 397, 911, 401, 919, 409, 929, 419, 421, 937, 941, 431, 433, 947, 439, 953, 443, 449, 967, 457, 971, 461, 463, 977, 467, 983, 479, 991, 997, 487, 491, 499, 503, 509};

        sort(primes.begin(), primes.end());

        // for (int i=2; i<=maxVal; i++) {
        //     int cnt=0;
        //     for (int j=1; j<=i; j++) {
        //         if (i%j==0) cnt++;
        //     }
        //     if (cnt==2) primes.push_back(i);
        // }

        

        for (int i=nums.size()-2; i>=0; i--) {
            
            if (nums[i] >= nums[i+1]) {
                int diff = nums[i]-nums[i+1];
                int toDelete=INT_MIN;
                for (auto x: primes) {
                    if (x>diff) {
                        toDelete=x;
                        break;
                    }
                }
                if (toDelete==INT_MIN) return false;
                nums[i]=nums[i]-toDelete;
                if (nums[i]<=0) return false;
            }
        }
        return true;
    }
};