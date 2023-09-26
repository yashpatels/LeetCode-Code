class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int temp = arr[0];
        int cnt = 1;
        std::unordered_map<int, int> x;
        for (int i=1; i<arr.size(); i++){
            if (temp == arr[i]){
                cnt++;
            } else {
                cout << arr[i] << i;
                if (x.find(cnt) != x.end()){
                    cout << "\n"<< cnt << arr[i];
                    return false;
                }
                x[cnt] = 1;
                cnt = 1;
                temp = arr[i];
            }

        }
        if (x.find(cnt) != x.end()){
            return false;
        }

        return true;
        
    }
};