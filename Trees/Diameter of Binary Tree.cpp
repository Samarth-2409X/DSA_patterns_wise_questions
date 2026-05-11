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
    int solve(TreeNode* root, int& result){
        if(root == NULL){
            return 0;
        }
        int l = solve(root -> left, result);
        int r = solve(root -> right, result);

        result = max(result, l + r);

        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       

        int result = INT_MIN;

        solve(root, result);

        return result;
    }
};