class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        vector<int> f;
        f = flowerbed;

        f.insert(f.begin(), 0);
        f.insert(f.end(), 0);
        
        int cnt = 0;
        for (int i=1; i<f.size()-1; i++){
            if (f[i] == 0 && f[i-1] == 0 && f[i+1] == 0){
                f[i]=1;
                n--;
            }
        }
        if (n<=0){
            return true;
        }
        return false;
    }
};