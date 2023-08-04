#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

TreeNode *array_to_tree(vector<int> &a, int i){
    if(i>(int) a.size() || a[i-1]==-1){
        return nullptr;
    }
    
    TreeNode *root = new TreeNode(a[i-1]);
    root->left = array_to_tree(a,2*i);
    root->right = array_to_tree(a,2*i+1);
    return root;
}

TreeNode *make_beautiful(TreeNode *root, int l, int r){
    if(!root){
        return root;
    }

    if(root->val<l){
        return make_beautiful(root->right,l,r);
    }

    if(root->val>r){
        return make_beautiful(root->left,l,r);
    }

    root->left = make_beautiful(root->left, l, r);
    root->right = make_beautiful(root->right, l, r);

    return root;
}

void post_order_traversal(TreeNode *root){
    if(!root){
        return;
    }
    
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    cout<<root->val<<" ";
}

int main(){
    int n, l, r;
    cin>>n>>l>>r;

    vector<int> a(n);
    for(auto &x : a){
        cin>>x;
    }
    TreeNode *root = array_to_tree(a,1);
    root = make_beautiful(root,l,r);
    post_order_traversal(root);
}