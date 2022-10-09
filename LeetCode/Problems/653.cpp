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
    bool find(TreeNode* root, int f) {
        if (root == NULL) return false;
        if (root->val > f) return find(root->left, f);
        else if (root->val < f) return find(root->right, f);
        else return true;
    }

    bool handle(TreeNode* root, TreeNode* node, int k) {
        if (node == NULL) return false;
        int temp = k - node->val;
        if (temp < node->val && find(root, temp)) return true;

        return handle(root, node->left, k) || handle(root, node->right, k);
    }


    bool findTarget(TreeNode* root, int k) {
        return handle(root, root, k);
    }
};