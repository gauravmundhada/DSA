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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<int> temp;
        int sum = 0;

        solve(root, targetSum, temp, result, sum);
        
        return result;
    }

    void solve(TreeNode* root, int& targetSum, vector<int> temp, vector<vector<int>>& result, int sum) {
        if (!root)
            return;

        sum += root->val; //include current node's value
        temp.push_back(root->val);

        
        if (root->left == NULL && root->right == NULL) { // check if it is LEAF node
            if (sum == targetSum) { // if leaf node then check if the target is obtained or not
                result.push_back(temp);
                return;
            }
        }

        solve(root->left, targetSum, temp, result, sum); //traverse to the left subtree
        solve(root->right, targetSum, temp, result, sum); //traverse to the right subtree
        temp.pop_back(); // backtrack

    }
};