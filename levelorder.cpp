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
vector<vector<int>> levelorder(struct node*root)
{
    vector<vector<int>>ans;
    if(root==0) return ans;
    queue<struct node*>q;
    q.push(root);
    while(!q.empty())
    {
        vector<int>level;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            
            struct node*root=q.front();
            q.pop();
            if(root->left!=0) q.push(root->left);
            if(root->right!=0) q.push(root->right);
            level.push_back(root->data);
        }
        ans.push_back(level);



    }
}

int main()
{
   struct node*root;
   root=new node(1);
   root->right=new node(2);
   root->left=new node(3);
   root->right->left=new node (4);
   root->left->right=new node(5);
  vector<vector<int>> ans= levelorder(root);
  for(auto it:ans)
  {
    for(auto i:it)
    {
        cout<<i<<" ";
    }
    cout<<endl;
  }

   
}