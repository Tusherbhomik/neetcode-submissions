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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root == p  || root==q) return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        if(left) return left;
        if(right) return right;
        return NULL;
    }
};
/*
1. root == NULL
   → return NULL

2. root == p বা root == q
   → return root

3. Left subtree-তে search
   → left

4. Right subtree-তে search
   → right

5. left এবং right দুটোই non-NULL
   → current root-ই LCA
   → return root

6. শুধু left non-NULL
   → return left

7. শুধু right non-NULL
   → return right

8. দুটোই NULL
   → return NULL
*/
