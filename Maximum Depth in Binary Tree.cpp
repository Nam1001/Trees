#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node*right;
    struct node*left;
    node(int value)
    {
        data=value;
        right=0;
        left=0;
    }

};

int depth(struct node*root)
{
    if (root==0) return 0;
    int left=depth(root->left);
    int right=depth(root->right);
    return max(left,right)+1;

}
int main()
{
    struct node *root;
    root = new node(1);
    root->right = new node(2);
    root->left = new node(3);
    root->right->left = new node(4);
    root->left->right = new node(5);
    root->left->left=new node(6);
    root->left->left->left=new node(7);
    root->left->left->left->left=new node(8);
    root->left->left->left->left->left=new node(9);
    root->left->left->left->left->left->left=new node(10);

    cout<<depth(root);
}