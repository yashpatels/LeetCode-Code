class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int currentWin=max(arr[0], arr[1]);
        int cnt=1;
        if (cnt == k) return currentWin;
        if (k > arr.size()) {
            return *max_element(arr.begin(), arr.end());
        }

        int i=2;
        while (1) {
            if (arr[i] > currentWin) {
                cnt=1;
                currentWin = arr[i];
                cout << currentWin << endl;
            } else {
                cnt++;
            }
            i++;
            if (i==arr.size()) i=0;
            if (cnt == k) break;
        }
        return currentWin;
    }
};