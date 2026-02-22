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
    void solve(TreeNode* root, int curNum, int& ans) {
        if (!root) return;

        curNum = curNum * 10 + root->val;
        
        if (!root->left && !root->right) {
            ans += curNum;
            return;
        }

        solve(root->left, curNum, ans);
        solve(root->right, curNum, ans);
    }

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;

        int ans = 0;
        solve(root, 0, ans);

        return ans;
    }
};