class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = fx - sx;
        int y = fy - sy;

        if (x == y && x==0){
            if (t==1) return false;
            return true;
        }

        if (x<0) x=x*-1;
        if (y<0) y=y*-1;

        int minDist = min(x,y) + abs(x-y);
        if (minDist <=  t) return true;
        return false;
    }
};