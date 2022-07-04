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

vector<int>postorder(struct node*root)
{
    vector<int>ans;
    struct node*curr=root;
    stack<struct node*>st;
    struct node*temp;
    while(curr!=0 || !st.empty())
    {
        if(curr!=0)
        {
            st.push(curr);
            curr=curr->left;
        }
        else{
               temp=st.top()->right;
               if(temp==0)
               {
                   temp=st.top();
                   ans.push_back(temp->data);
                   st.pop();
                   while(!st.empty() && temp==st.top()->right)
                   {
                      temp=st.top();
                      st.pop();
                      ans.push_back(temp->data);
                   }

               }
               else{
                curr=temp;
               }

        }
    }
    return ans;
}

int main()
{
   struct node*root;
   root=new node(1);
   root->right=new node(2);
   root->left=new node(3);
   root->right->left=new node (4);
   root->left->right=new node(5);
  vector<int> ans= postorder(root);
  for(auto it:ans)
  {
      cout<<it<<" ";
  }

   
}