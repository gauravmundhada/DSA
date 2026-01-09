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
    typedef pair<int, TreeNode*> P;

    P solve(TreeNode* root) {
        if (!root) return {0, NULL};

        P l = solve(root->left);
        P r = solve(root->right);

        if (l.first == r.first) { // same depth
            return {l.first + 1, root};
        }

        return (l.first > r.first) ? make_pair(l.first + 1, l.second) : make_pair(r.first + 1, r.second);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};