class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> ans;
        ans.push_back(asteroids[0]);
        for (int i=1; i<asteroids.size();){

            if (ans.size()==0){
                ans.push_back(asteroids[i]);
                i++;
                continue;
            }

            int col = ans.back();
            bool colPos = true;
            bool astPos = true;

            int tempCol = col;
            int tempAst = asteroids[i];
            
            if (col < 0){
                // cout << "col";
                tempCol*=-1;
                colPos =false;
            }
            if (asteroids[i] < 0){
                // cout << "ast" << asteroids[i];
                tempAst*=-1;
                astPos = false;
            }

            if (colPos == astPos || (!colPos && astPos)){
                ans.push_back(asteroids[i]);
                i++;

            } else {
                if (tempCol < tempAst) {
                    ans.pop_back();
                    cout << tempCol << tempAst << "c";
                }
                if (tempCol == tempAst){
                    ans.pop_back();
                    i++;
                }
                if (tempCol > tempAst){
                    i++;
                }
            } 

        }
        return ans;
        
    }
};