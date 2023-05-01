#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr) , right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l) , right(r) {}
};

TreeNode *array_to_tree(vector<int> &arr,int i){
    if(arr[i-1]==-1 || i > (int)arr.size()){
        return nullptr;
    }

    TreeNode *root = new TreeNode(arr[i-1]);
    root->left = array_to_tree(arr,2*i);
    root->right = array_to_tree(arr,2*i+1);

    return root;
}

TreeNode *find_ancestor(TreeNode *root, int x, int y){
    if(!root){
        return nullptr;
    }
    if(root->val==x || root->val==y){
        return root;
    }
    TreeNode *left = find_ancestor(root->left,x,y);
    TreeNode *right = find_ancestor(root->right,x,y);

    if(left && right){
        return root;
    }

    if(left){
        return left;
    }

    return right;
}

int main(){
    int n, x, y;
    cin>>n>>x>>y;

    vector<int> arr(n);
    for(auto &x: arr){
        cin>>x;
    }

    TreeNode *root = array_to_tree(arr,1);

    TreeNode *res = find_ancestor(root,x,y);

    cout<<res->val;
}