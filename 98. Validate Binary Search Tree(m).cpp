#include <iostream>

using namespace std;

// Time:O(n)
// Space:O(1)
bool dfs(TreeNode* node, long left, long right){

    //empty tree
    if (!node)
        return true;
    //cout<<node->val<<' '<<right<<' '<<left<<endl;
    if (!(node->val<right && node->val>left))
        return false;

    return dfs(node->left, left, node->val) and dfs(node->right, node->val, right);

}
bool isValidBST(TreeNode* root) {
    return dfs(root, LONG_MIN, LONG_MAX);
}
