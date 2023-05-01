#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r){}
};

TreeNode *array_to_tree(vector<int> &a, int i){
    if(i>(int)a.size() || a[i-1]==-1){
        return nullptr;
    }
    TreeNode *root = new TreeNode(a[i-1]);
    root->left = array_to_tree(a,2*i);
    root->right = array_to_tree(a,2*i+1);

    return root;
}


int freedom_nodes(TreeNode *root, int x){
    if(!root){
        return 0;
    }
    x-=root->val;
    if(x<0){
        return 0;
    }
    if(!x and !root->left and !root->right){
        return 1;
    }
    return freedom_nodes(root->left,x)+freedom_nodes(root->right,x);
}

int main(){
    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    for(auto &i : a){
        cin>>i;
    }

    TreeNode *root = array_to_tree(a,1);

    int res = freedom_nodes(root,x);

    cout<<res;

}