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
    if(i>(int)a.size() || a[i-1]==-1){
        return nullptr;
    }

    TreeNode *root = new TreeNode(a[i-1]);
    root->left = array_to_tree(a,2*i);
    root->right = array_to_tree(a,2*i+1);

    return root;
}

void in_order_traversal(TreeNode *root){
    if(!root){
        return;
    }

    in_order_traversal(root->left);
    cout<<root->val<<" ";
    in_order_traversal(root->right);
}

void kthLargest(TreeNode *root, int &k, int &ans)
{
    if (!root or ans != -1)
        return;
    kthLargest(root->right, k, ans);
    if (ans == -1) {
        if (k == 1) {
            ans = root->val;
        } else {
            k--;
            kthLargest(root->left, k, ans);
        }
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &x: a){
        cin>>x;
    }

    int k;
    cin>>k;

    TreeNode *root = array_to_tree(a,1);
    
    int res = -1;
    kthLargest(root,k,res);
    cout<<res<<endl;
}