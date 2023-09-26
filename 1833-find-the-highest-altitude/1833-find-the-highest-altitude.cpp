class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int curAlt = 0;
        int maxAlt = 0;

        for (int i=0; i<gain.size(); i++){

            curAlt += gain[i];
            if (curAlt > maxAlt){
                maxAlt = curAlt;
            }

        }

        return maxAlt;
        
    }
};