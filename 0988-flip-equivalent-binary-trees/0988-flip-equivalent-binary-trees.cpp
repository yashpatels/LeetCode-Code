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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        if (root1==nullptr && root2!=nullptr) return false;
        if (root2==nullptr && root1!=nullptr) return false;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        map<int, set<int>> m1;map<int, set<int>> m2;

        if (root1!=nullptr) q1.push(root1);
        if (root2!=nullptr) q2.push(root2);

        while (!q1.empty()) {
            int size = q1.size();
            while (size--) {
                TreeNode* current = q1.front();
                q1.pop();

                if (current->left!=nullptr) {
                    q1.push(current->left);
                    m1[current->val].insert(current->left->val);
                }

                if (current->right!=nullptr) {
                    q1.push(current->right);
                    m1[current->val].insert(current->right->val);
                } 
            }
        }

        while (!q2.empty()) {
            int size = q2.size();

            while (size--) {
                TreeNode* current = q2.front();
                q2.pop();

                if (current->left!=nullptr) {
                    q2.push(current->left);
                    m2[current->val].insert(current->left->val);
                    if (m1[current->val].find(current->left->val) == m1[current->val].end()) return false;
                }

                if (current->right!=nullptr) {
                    q2.push(current->right);
                    m2[current->val].insert(current->right->val);
                    if (m1[current->val].find(current->right->val) == m1[current->val].end()) return false;
                }

            }
        }

        if (root1!=nullptr) q1.push(root1);
        while (!q1.empty()) {
            int size = q1.size();
            while (size--) {
                TreeNode* current = q1.front();
                q1.pop();

                if (current->left!=nullptr) {
                    q1.push(current->left);
                    if (m2[current->val].find(current->left->val) == m2[current->val].end()) return false;
                }

                if (current->right!=nullptr) {
                    q1.push(current->right);
                    if (m2[current->val].find(current->right->val) == m2[current->val].end()) return false;
                } 
            }
        }
        return true;
    }
};