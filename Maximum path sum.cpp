
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node*left;
    struct node*right;
    node(int value)
    {
       data=value;
       left=0;
       right=0;
    }
};
int maxpathsum(struct node*root,int&min)
{
    if(root==0) return 0;
    int hl= max(0,maxpathsum(root->left,min));
    int hr= max(0,maxpathsum(root->right,min));
    min= max(min,(hl+hr+root->data));
    return root->data+max(hl,hr);

}
int main()
{
    struct node *root;
    root = new node(-4);
    root->right = new node(3);
    root->left = new node(-2);
    root->right->left = new node(1);
    root->left->right = new node(1);
    int mini=-1e9;
    maxpathsum(root,mini);
    cout<<mini;
}