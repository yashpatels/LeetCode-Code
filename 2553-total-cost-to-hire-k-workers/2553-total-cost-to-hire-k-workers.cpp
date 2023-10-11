class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        

        priority_queue <int, vector<int>, greater<int> > left;
        priority_queue <int, vector<int>, greater<int> > right;

        int j=costs.size()-1;
        if (2*candidates < costs.size()){
            for (int i=0; i<candidates; i++){
                left.push(costs[i]);
                right.push(costs[j]);
                j--;
            }
        } else {
            for (int i=0; i<costs.size(); i++){
                left.push(costs[i]);
            }
            int cost=0;
            for (int i=0; i<k; i++){
                cost+=left.top();
                left.pop();
            }
            return cost;
        }
        

        int leftIndex = candidates-1;
        int rightIndex = costs.size()-candidates;

        long cost=0;

        for (int i=0; i<k; i++){
            if (!left.empty() && !right.empty()){
                if (left.top() <= right.top()){
                    cout << "left : " << left.top() << endl;
                    cost+=left.top();
                    left.pop();
                    leftIndex++;
                    if (leftIndex<rightIndex){
                        cout << "left pushed: " << costs[leftIndex] << endl;
                        left.push(costs[leftIndex]);
                    }
                } else {
                    cout << "right : " << right.top() << endl;
                    cost+=right.top();
                    right.pop();
                    rightIndex--;
                    if (leftIndex<rightIndex){
                        cout << "right pushed: " << costs[rightIndex] << endl;
                        right.push(costs[rightIndex]);
                    }
                }
            } else {
                if (left.empty()){
                    cost+=right.top();
                    right.pop();
                } else {
                    cost+=left.top();
                    left.pop();
                }
            }
        } 
        return cost;

    }
};