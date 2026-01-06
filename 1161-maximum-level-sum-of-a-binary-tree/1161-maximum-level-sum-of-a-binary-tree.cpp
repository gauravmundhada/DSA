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
    int maxLevelSum(TreeNode* root) {
        // level sum hai to BFS
        if (!root) return 0;

        long long maxSum = LONG_MIN;
        int maxSumLvl = 1;
        int lvl = 1;

        queue<TreeNode*> q;
        q.push(root);

        // Start BFS
        while (!q.empty()) {
            int nodes_count = q.size();
            long long currSum = 0;

            for (int i = 0; i < nodes_count; i++) {
                TreeNode* curNode = q.front();
                q.pop();
                currSum += curNode->val;

                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                maxSumLvl = lvl;
            }
            lvl++;
        }
        return maxSumLvl;
    }
};