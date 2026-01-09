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
    int maxD = INT_MIN;
    unordered_map<int, int> mpp; // node -> its depth

    void populateDepth(TreeNode* root, int depth) {
        if (root == NULL) return;

        mpp[root->val] = depth;
        maxD = max(maxD, depth);

        populateDepth(root->left, depth+1);
        populateDepth(root->right, depth+1);
    }

    TreeNode* LCA(TreeNode* root) {
        if (root == NULL || mpp[root->val] == maxD) {
            return root;
        }

        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);

        if (l != NULL && r != NULL) {
            return root;
        }

        return (l != NULL) ? l : r;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return NULL;

        populateDepth(root, 0);

        return LCA(root);
    }
};