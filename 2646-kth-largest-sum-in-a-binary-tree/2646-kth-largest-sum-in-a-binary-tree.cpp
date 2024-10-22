/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long ans = 0;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {

            int size = q.size();
            long long cur=0;
            while (size--) {

                TreeNode* temp = q.front();
                q.pop();
                cur+=(long long)temp->val;

                if (temp->left!=nullptr) q.push(temp->left);
                if (temp->right!=nullptr) q.push(temp->right);
            }

            if (pq.size() < k) pq.push(cur);
            else {
                if (pq.top() < cur) {
                    pq.pop();
                    pq.push(cur);
                }
            }
        }

        if (pq.size()==k) return pq.top();
        return -1;

    }
};