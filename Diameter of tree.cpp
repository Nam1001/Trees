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

int height(struct node*root,int &dia)
{
    if (root==0) return 0;
    int left=height(root->left,dia);
    int right=height(root->right,dia);
    dia= max(dia,right+left);
    return 1+max(right,left);

}
int diameter(struct node*root)
{
    int dia=0;
    height(root,dia);
    return dia;

}

int main()
{
   struct node*root;
   root=new node(1);
   root->right=new node(3);
   root->left=new node(2);
   root->right->left=new node (4);
   root->right->left->left=new node (5);
   root->right->left->left->left=new node (9);
   root->right->right=new node (6);
   root->right->right->right=new node (7);
   root->right->right->right->right=new node (8);
   cout<< diameter(root);

}


                    //     1
                    //  3     2
                    //    5  4  6
                            //    7  8