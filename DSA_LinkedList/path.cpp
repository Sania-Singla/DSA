#include <iostream>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void spotPandQ(TreeNode *root, TreeNode *p, TreeNode *q, string temp,
               string &pathP, string &pathQ)
{
    if (!root)
    {
        return;
    }
    else if (root == p)
    {
        pathP = temp;
    }
    else if (root == q)
    {
        pathQ = temp;
    }

    // left
    temp += 'L';
    spotPandQ(root->left, p, q, temp, pathP, pathQ);
    temp.pop_back();

    // right
    temp += 'R';
    spotPandQ(root->right, p, q, temp, pathP, pathQ);
    temp.pop_back();
}

void traverse(TreeNode *root, string pathP, string pathQ,
              TreeNode *&ancestor)
{

    int i = 0, m = pathP.length(), n = pathQ.length();

    while (i < m && i < n)
    {
        if (pathP[i] == pathQ[i])
        {
            if (pathP[i] == 'L')
            {
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
            i++;
        }
        else
        {
            break;
        }
    }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (p->left == q || p->right == q)
        return p;
    if (q->left == p || q->right == p)
        return q;

    string pathP = "", pathQ = "", temp = "";

    spotPandQ(root, p, q, temp, pathP, pathQ);
    cout << "Path P: " << pathP << endl;
    cout << "Path Q: " << pathQ << endl;

    TreeNode *ancestor = root;
    traverse(root, pathP, pathQ, ancestor);

    return ancestor;
}

int main()
{
    // use the class
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    // Example usage

    TreeNode *ancestor = lowestCommonAncestor(root, root->left->right->left, root->left->right -> right);
    cout << ancestor->val << endl;
}
