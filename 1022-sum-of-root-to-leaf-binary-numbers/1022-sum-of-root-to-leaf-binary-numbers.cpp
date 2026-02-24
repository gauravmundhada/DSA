class Solution {
public:
    int ans = 0;

    void solve(TreeNode* root, int cur) {
        if (!root) return;

        cur = cur * 2 + root->val;  

        if (!root->left && !root->right) {
            ans += cur;
            return;
        }

        solve(root->left, cur);
        solve(root->right, cur);
    }

    int sumRootToLeaf(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};