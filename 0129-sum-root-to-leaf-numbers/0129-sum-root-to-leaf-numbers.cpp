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
    void solve(TreeNode* root, vector<int>& nums, int curNum) {
        if (!root) return;

        curNum = curNum * 10 + root->val;
        
        if (!root->left && !root->right) {
            nums.push_back(curNum);
            return;
        }

        solve(root->left, nums, curNum);
        solve(root->right, nums, curNum);
    }

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;

        vector<int> nums;

        solve(root, nums, 0);

        int ans = 0;
        for (int num : nums) {
            ans += num;
        }
        return ans;
    }
};