class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        map<int, int> m;

        for (int i=0; i<times.size(); i++) {
            m[times[i][0]]=i;
        }

        sort(times.begin(), times.end());

        priority_queue<int, vector<int>, greater<int>> freeSeats;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> usedSeats;

        int cnt=0;

        for (int i=0; i<times.size(); i++) {
            
            int arrTime=times[i][0];
            int depTime=times[i][1];
            int seatToAssign;

            // cout << "for " << arrTime << endl;

            while(!usedSeats.empty() && usedSeats.top().first<=arrTime) {
                // cout << "popped " << usedSeats.top().second << endl;
                freeSeats.push(usedSeats.top().second);
                usedSeats.pop();

            }


            if(freeSeats.empty()) {
                //there are no seats so assign with counter;
                seatToAssign=cnt;
                cnt++;
            } else {
                seatToAssign=freeSeats.top();
                freeSeats.pop();
            }

            if(m[arrTime] == targetFriend) return seatToAssign;

            usedSeats.push(make_pair(depTime, seatToAssign));

        }

        
        return 1;
    }
};