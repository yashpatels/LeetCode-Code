class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxSpeed = *max_element(piles.begin(), piles.end());

        int minSpeed = 1;
        int mid = maxSpeed;
        int hMax = INT_MIN;

        int ans = INT_MAX;
        // long long ans1 = UINT_MAX;
        while (maxSpeed >= minSpeed){
            cout << "min speed " << minSpeed << " max speed " << maxSpeed << endl;
            mid = minSpeed + (maxSpeed-minSpeed)/2;

            long long hour = calculateHours(piles, mid);

            if (hour <= h && mid < ans){
                ans = mid; 
            }

            if (hour > h){
                minSpeed = mid + 1;
            } else {
                maxSpeed = mid - 1;
            } 
        }
        return ans;
    }

    long long calculateHours(vector<int>& piles, int speed){

        long long hours = 0;

        for (int i=0; i<piles.size(); i++){
            
            long long xh = piles[i]/speed;

            hours+=xh;
            if (piles[i]%speed != 0) hours++;
        }
        cout << "for speed: " << speed << " hours it takes " << hours << endl;
        return hours;
    }
};