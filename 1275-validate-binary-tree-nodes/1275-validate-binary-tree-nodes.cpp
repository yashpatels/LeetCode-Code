class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
            //find root
            //do bfs from there

            unordered_map<int, int> set;
            int root = -1;
            for (int i=0; i<n; i++){
                set[i]=0;
            }

            for (int i=0; i<n; i++){
                // set[i]=0;
                if (leftChild[i] != -1){
                    if (leftChild[leftChild[i]] == i){
                        return false;
                    }
                    ++set[leftChild[i]];
                }

                if (rightChild[i] != -1){
                    if (rightChild[rightChild[i]] == i){
                        return false;
                    }
                    ++set[rightChild[i]];
                }
            }

            for (int i=0; i<set.size(); i++){
                cout << set[i] << " ";
                if (set[i] > 1){
                    // cout << "here";
                    return false;
                }
                if (set[i] == 0 && root!=-1){
                    // cout << "here 1";
                    return false;
                }
                if (set[i] == 0 && root==-1){
                    root = i;
                }
            }
            if (root == -1){
                return false;
            }
            cout << "root is : " << root;
            deque<int> q1;
            int cnt=0;

            q1.push_back(root);

            while(!q1.empty()){
                cnt++;
                int x = q1.front();
                if (leftChild[x]!=-1){
                    if (find(q1.begin(), q1.end(), leftChild[x])!=q1.end()){
                        return false;
                    } else{
                        q1.push_back(leftChild[x]);
                    }
                }
                if (rightChild[x]!=-1){
                    if (find(q1.begin(), q1.end(), rightChild[x])!=q1.end()){
                        return false;
                    } else{
                        q1.push_back(rightChild[x]);
                    }
                }
                q1.pop_front();
            }
            if (cnt!=n){
                return false;
            }

            return true;
    }
};






