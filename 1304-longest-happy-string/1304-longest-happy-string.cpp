class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a>0) pq.push({a, 'a'});
        if (b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});

        string ans;
        while (!pq.empty()) {

            pair<int, char> top = pq.top();
            pq.pop();

            int cnt = top.first;
            char character = top.second;

            if (ans.size() >= 2 && ans[ans.size()-1] == character && ans[ans.size()-2] == character) {

                if (pq.empty()) break;

                pair<int, char> secondTop = pq.top();
                pq.pop();

                ans+=secondTop.second;

                if (secondTop.first-1>0) pq.push({secondTop.first-1, secondTop.second});

            } else {
                cnt--;
                ans+=character;
            }

            if (cnt>0) pq.push({cnt, character});

        }
        return ans;
    }
};