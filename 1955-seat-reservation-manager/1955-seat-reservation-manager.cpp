class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int> > g;
    SeatManager(int n) {
        for (int i=1; i<=n; i++) g.push(i);
    }
    
    int reserve() {
        int x = g.top();
        g.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        g.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */