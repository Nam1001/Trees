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
int balance(struct node *root)
{
    if(root==0) return 0;
    int hl=balance(root->left);
    int hr=balance (root->right);
    if(hl==-1 || hr==-1) return -1;
    if (abs(hl-hr)>1) 
    {
          return -1;
          
    }
    return 1+max(hr,hl);

    
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
    cout<<balance(root);
 }

// // *
//       1
//     2   3
//   4  5 6  7
//             8
//                9

// // 