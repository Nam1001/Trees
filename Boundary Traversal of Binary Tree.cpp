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
// void f1(struct node *root,vector<int>&s,set<int>&st)
// {
//     if(root==0) return;
//     if(root->left==0 && root->right==0)
//     {
//         st.insert(root->data);
//         s.push_back(root->data);
//         return;

//     }
    
//     f1(root->left,s,st);
//     f1(root->right,s,st);

    
// }
// void f(struct node*root, vector<int>&s,set<int>&st)
// {
//     if(root==0) return;
//     st.insert(root->data);
//     s.push_back(root->data);
//     f(root->left,s,st);
//     f1(root->right,s,st);

// }
// void f2(struct node*root,vector<int>&s,set<int>&st)
// {
//       if(root==0) return;
//       if(st.find(root->data)==st.end()) 
//       {
//         s.push_back(root->data);
//       }
      
//       f2(root->right,s,st);
      

// }

void right(struct node *root,vector<int>&ans,set<int>&st)
{
    if(root==0)
    {
        return;
    }
    if(st.find(root->data)==st.end()) 
    {
        ans.push_back(root->data);
        st.insert(root->data);
    }
    right(root->right,ans,st);
    
}

void leaf(struct node *root,vector<int>&ans,set<int>&st)
{
    if(root==0) return ;
    if(root->left==0 && root->right==0)
    {
        if(st.find(root->data)==st.end())
        {
          ans.push_back(root->data);
          st.insert(root->data);
        }
    }
    leaf(root->left,ans,st);
    leaf(root->right,ans,st);

}
void left(struct node *root,vector<int>&ans,set<int>&st)
{
       if(root==0)
       {
        return;
       }
       st.insert(root->data);
       ans.push_back(root->data);
       left(root->left,ans,st);

}


int main()
{
    struct node *root;
    root = new node(10);
    root->right = new node(20);
    root->left = new node(5);
    root->right->left = new node(18);
    root->right->right = new node(25);
    root->left->left=new node(3);
    root->left->right=new node(8);
    root->left->right->left=new node(7);
    root->left->right->left->left=new node(11);
    vector<int> ans;
    set<int>s;
    struct node*t=root;
    struct node*t1=root;
    struct node*t2=root;
    left(t,ans,s);
    leaf(t1,ans,s);
    right(t2,ans,s);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
 }