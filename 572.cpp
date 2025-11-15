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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }

        if (sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);    
    }

private:
    bool sameTree(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2)
            return root1 == nullptr && root2 == nullptr;

        bool l = sameTree(root1->left, root2->left);
        bool r = sameTree(root1->right, root2->right);
        if (root1->val == root2->val)
            return l && r;
        return false;
    }
};