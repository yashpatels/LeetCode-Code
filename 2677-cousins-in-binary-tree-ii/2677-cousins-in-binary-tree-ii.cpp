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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> stored;

        queue<TreeNode*> q;

        q.push(root);
        stored.push_back(root->val);

        while (!q.empty()) {
            int size = q.size();
            // vector<int> temp;
            int cur=0;
            while (size--) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left!=nullptr) {
                    q.push(current->left);
                    cur+=current->left->val;
                } 

                if (current->right!=nullptr) {
                    q.push(current->right);
                    cur+=current->right->val;
                }
            }

            if (cur!=0) stored.push_back(cur);
        }

        for (auto x: stored) {
            cout << x << " ";
        }

        queue<TreeNode*> q2;
        TreeNode* newNode = new TreeNode();
        stored.push_back(0);
        q2.push(newNode);

        q.push(root);
        int i=1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* current = q.front();
                TreeNode* toJoin = q2.front();
                q2.pop();
                q.pop();
                int cur=stored[i];

                if (current->left!=nullptr) {
                    q.push(current->left);
                    cur-=current->left->val;
                } 

                if (current->right!=nullptr) {
                    q.push(current->right);
                    cur-=current->right->val;
                }

                if (current->left!=nullptr) {
                    TreeNode* tempLeft = new TreeNode(cur);
                    toJoin->left = tempLeft;
                    q2.push(tempLeft);
                } 

                if (current->right!=nullptr) {
                    TreeNode* tempRight = new TreeNode(cur);
                    toJoin->right = tempRight;
                    q2.push(tempRight);
                }

                
            }
            i++;
        }

        return newNode;
    }
};