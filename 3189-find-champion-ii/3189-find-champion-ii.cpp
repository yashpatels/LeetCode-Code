class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> temp(n, -1);

        for (int i=0; i<edges.size(); i++) {
            temp[edges[i][1]]=1;
        }

        int ans;
        int cnt=0;
        int i=0;
        for (auto x: temp){
            if (x==-1) {
                ans=i;
                cnt++;
            }
            i++;
        }
        if (cnt==1) return ans;
        return -1;
    }
};