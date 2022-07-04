#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *right;
    struct node *left;
    node(int value)
    {
        data = value;
        right = 0;
        left = 0;
    }
};

int main()
{
    struct node *root;
    root = new node(1);
    root->right = new node(2);
    root->left = new node(3);
    root->right->left = new node(4);
    root->left->right = new node(5);
    stack<pair<struct node *, int>> st;
    vector<int> pre;
    vector<int> post;
    vector<int> in;
    st.push({root, 1});
    // if(root==0) return 0;
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1) 
        {

            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != 0)
                st.push({it.first->left, 1});
        }
      else  if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            
            st.push(it);
            if (it.first->right != 0)
                st.push({it.first->right, 1});
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    for (auto it : pre)
    {
        cout << it << " ";
    }
    cout<<endl;
    for (auto it : in)
    {
        cout << it << " ";
    }
    cout<<endl;
    for (auto it : post)
    {
        cout << it << " ";
    }
}