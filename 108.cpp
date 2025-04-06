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
private:
    TreeNode* toBST(vector<int>& nums, int left, int right) {
        if (left == right) {
            TreeNode* temp = TreeNode(nums[left]);
            return temp;
        }
        
        int mid = (left + right) / 2;

        TreeNode* l = toBST(nums, left, mid);
        TreeNode* r = toBST(nums, mid + 1, right);
        cout << nums[mid] << " : " << l.val << ' ' << r.val << endl;
        return TreeNodee(nums[mid], l, r);
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size() - 1);
    }
};