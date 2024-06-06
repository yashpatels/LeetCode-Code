class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize != 0) return false;
        
        int groups = hand.size()/groupSize;

        sort(hand.begin(), hand.end());

        map<int, int> m;
        for (auto x: hand) {
            m[x]++;
        }

        vector<int> unique;
        for (auto x: m) {
            unique.push_back(x.first);
        }

        sort(unique.begin(), unique.end());
        if (unique.size() == 1 && groupSize>1) return false;
        if (unique.size() == 1 && groupSize==1) return true;
        for (int i=0; i<=unique.size()-groupSize;i++) {
            int temp = groupSize-1; 
            int cnt = i+1;
            int current = unique[i];
            if (m[current] > 0) {
                m[current]--;
                while (temp--) {
                    if (unique[cnt] == current+1 && m[unique[cnt]] > 0) {
                        m[unique[cnt]]--;
                    } else {
                        return false;
                    }
                    current=unique[cnt];
                    cnt++;
                }
            }
            if (m[unique[i]] >0)i--;

        }

        for (auto x: m) {
            if (x.second>0) return false;
        }
        return true;
    }
};