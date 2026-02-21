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
    void solve(TreeNode* root, int& ans, int maxTillNow) {
        if (root == NULL) 
            return;

        if (root->val >= maxTillNow) {
            ans++;
            maxTillNow = root->val;
        }

        solve(root->left, ans, maxTillNow);
        solve(root->right, ans, maxTillNow);
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        solve(root, ans, root->val);
        return ans;
    }
};