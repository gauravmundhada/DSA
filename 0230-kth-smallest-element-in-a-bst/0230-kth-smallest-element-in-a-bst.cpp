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
    void traverse(TreeNode* root, priority_queue<int>& pq, int k) {
        if (!root) return;

        if (pq.size() < k) {
            pq.push(root->val);
        } else if (pq.top() > root->val) {
            pq.pop();
            pq.push(root->val);
        }

        traverse(root->left, pq, k);
        traverse(root->right, pq, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        priority_queue<int> pq;

        traverse(root, pq, k);

        return pq.top();
    }
};