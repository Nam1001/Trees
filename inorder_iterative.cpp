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
vector<int>inorder(struct node*root)
{
    vector<int>in;
    if(root==0) return in;
    stack<struct node*>st;
    while(true)
    {
        if(root!=0)
        {
            st.push(root);
            root=root->left;
        }
        else{
            if(st.size()==0) break;
            root=st.top();
            st.pop();
            in.push_back(root->data);
            root=root->right;

        }

    }
    return in;
 
    
}

int main()
{
   struct node*root;
   root=new node(1);
   root->right=new node(2);
   root->left=new node(3);
   root->right->left=new node (4);
   root->left->right=new node(5);
  vector<int> ans= inorder(root);
  for(auto it:ans)
  {
      cout<<it<<" ";
  }

   
}