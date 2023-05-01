#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
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

void tree_to_array(TreeNode *root,vector<int> &res, int i){
    if(!root){
        return;
    }
    while((int)res.size()<i){
        res.push_back(-1);
    }
    res[i-1] = root->val;
    tree_to_array(root->left,res,2*i);
    tree_to_array(root->right,res,2*i+1);
}


void greaterST(TreeNode *root,int &sum){
    if(!root){
        return;
    }

    greaterST(root->right,sum);
    sum+=root->val;
    root->val = sum;
    greaterST(root->left,sum);
}

void in_order_traversal(TreeNode *root){
    if(!root){
        return;
    }
    
    in_order_traversal(root->left);
    cout<<root->val<<" ";
    in_order_traversal(root->right);
}
int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &x: a){
        cin>>x;
    }

    TreeNode *root = array_to_tree(a,1);

    // in_order_traversal(root);
    int sum;
    greaterST(root,sum);

    vector<int> res;
    tree_to_array(root,res,1);

    for(auto x:res){
        cout<<x<<" ";
    }
    cout<<endl;
}