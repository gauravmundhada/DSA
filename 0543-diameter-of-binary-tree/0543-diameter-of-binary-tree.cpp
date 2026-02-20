class Solution {
public:
    int solve(TreeNode* root, int& result) {
        if (!root)
            return 0;

        int l = solve(root->left, result);
        int r = solve(root->right, result);

        result = max(result, l + r);   // diameter candidate

        return 1 + max(l, r);          // return height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        solve(root, result);
        return result;
    }
};
