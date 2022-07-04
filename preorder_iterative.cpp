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
vector<int>preorder(struct node*root)
{
    vector<int>pre;
    if(root==0) return pre;
    stack<struct node*>st;
    st.push(root);
    while(!st.empty())
    {
        root=st.top();
        st.pop();
        if(root->right!=0) st.push(root->right);  // first we have to push roots right part 
        if(root->left!=0) st.push(root->left);// then will push roots left part;
        pre.push_back(root->data);
    }
    return pre;
    
}

int main()
{
   struct node*root;
   root=new node(1);
   root->right=new node(2);
   root->left=new node(3);
   root->right->left=new node (4);
   root->left->right=new node(5);
  vector<int> ans= preorder(root);
  for(auto it:ans)
  {
      cout<<it<<" ";
  }

   
}