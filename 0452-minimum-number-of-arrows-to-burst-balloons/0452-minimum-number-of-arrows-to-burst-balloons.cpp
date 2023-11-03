class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1;

        std::sort(points.begin(), points.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {
  return a[1] < b[1];
});

        for (int i=0; i<points.size(); i++) {
            cout << points[i][0] << " " << points[i][1] << endl;
        }

        int arr=points[0][1];

        for(int i=1; i<points.size(); i++){

            if (points[i][0] > arr){
                ans++;
                arr = points[i][1];
            }

        }
        return ans;
    }
};