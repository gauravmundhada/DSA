/*
-1 → Not Covered
This node is not monitored by any camera.

0 → Has Camera
A camera is installed on this node.

1 → Covered (No Camera)
This node does not have a camera, but it is covered by a camera placed on one of its children.
*/

class Solution {
public:
    int camera = 0;

    int solve(TreeNode* root) {
        if (!root) return 1;   // null nodes are considered covered

        int lc = solve(root->left);
        int rc = solve(root->right);

        if (lc == -1 || rc == -1) {
            camera++;
            return 0; // place camera here
        }

        if (lc == 0 || rc == 0) {
            return 1; // covered by child camera
        }

        return -1; // not covered
    }

    int minCameraCover(TreeNode* root) {
        if (solve(root) == -1) camera++;
        return camera;
    }
};