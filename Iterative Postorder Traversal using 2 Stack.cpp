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

vector<int> postorder(struct node *root)
{
    vector<int> ans;
    if (root == 0)
        return ans;
    stack<struct node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left != 0)
            st1.push(root->left);
        if (root->right != 0)
            st1.push(root->right);
    }
    while(!st2.empty())
    {

        root=st2.top();
        ans.push_back(root->data);
        st2.pop();
    }
    return ans;
}
int main()
{
    struct node *root;
    root = new node(1);
    root->right = new node(2);
    root->left = new node(3);
    root->right->left = new node(4);
    root->left->right = new node(5);
    vector<int> ans = postorder(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
