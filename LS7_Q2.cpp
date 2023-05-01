#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
}; 

TreeNode *buildTree(vector<int> &a, vector<int> &b, int p_index, int i_left, int i_right, map<int,int> index_in){
    if(i_left>i_right){
        return nullptr;
    }

    TreeNode *root = new TreeNode(a[p_index++]);
    int in_index = index_in[root->val];
    root->left = buildTree(a,b,p_index,i_left,in_index-1,index_in);
    root->right = buildTree(a,b,p_index,in_index+1,i_right,index_in);

    return root;
    
}

void tree_to_array(TreeNode *root, vector<int> &a, int i){
    if(!root){
        return;
    }

    while((int)a.size()<i){
        a.push_back(-1);
    }

    a[i-1] = root->val;
    tree_to_array(root->left,a, 2*i);
    tree_to_array(root->right,a, 2*i+1);

}

int main(){
    int n;
    cin>>n;

    vector<int> pre_order(n);
    vector<int> in_order(n);

    for(auto &x: pre_order){
        cin>>x;
    }

    for(auto &x: in_order){
        cin>>x;
    }

    map<int,int> index;

    for(int i = 0; i < n; i++){
        index[in_order[i]] = i;
    }

    TreeNode *root = buildTree(pre_order,in_order,0,0,n-1,index);

    vector<int> res;
    tree_to_array(root,res,1);

    for(auto x: res){
        cout<<x<<" ";
    }
    cout<<endl;
}