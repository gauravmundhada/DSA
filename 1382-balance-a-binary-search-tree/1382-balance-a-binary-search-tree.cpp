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
    TreeNode* balanceBST(TreeNode* root) {
        // null check 
        if (!root) return root;
        
        // vector to store the nodes
        vector<TreeNode*> nodes;

        // populate the vector by inorder traversal(L-Root-R)
        inorderTraversal(root, nodes);

        // construct the tree (recursively)
        return constructTree(nodes, 0, nodes.size()-1); // (nodes, l, r)
    }

    void inorderTraversal(TreeNode* root, vector<TreeNode*>& nodes) {
        // base case
        if (!root) return;

        // traverse to the left
        inorderTraversal(root->left, nodes);

        // push the node in the list
        nodes.push_back(root);

        // traverse to the right
        inorderTraversal(root->right, nodes);
    }

    TreeNode* constructTree(vector<TreeNode*>& nodes, int l, int r) {
        if (l > r) return nullptr;

        int m = l + (r - l) / 2;
        TreeNode* root = nodes[m];

        // left subtree
        root->left = constructTree(nodes, l, m-1);

        // right subtree
        root->right = constructTree(nodes, m+1, r);

        return root;
    }
};