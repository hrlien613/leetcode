#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ret) {
    if (root==NULL) return 0;

    int left = dfs(root->left, p, q, ret);
    int right = dfs(root->right, p, q, ret);
    int self = (root==p || root==q);
    int sum = left + right + self;



    //ret=NULL make sure the node is the first Common Ancestor
    if(sum==2 && ret==NULL){
        ret = root;
    }
    return sum;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* ret = NULL;
    int a = dfs(root, p, q, ret);
    return ret;
}