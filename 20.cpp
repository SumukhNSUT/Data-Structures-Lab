#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform preorder traversal
void preorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to perform inorder traversal
void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Function to perform postorder traversal
void postorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main()
{
    // Constructing the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    // Deallocating memory to prevent memory leaks
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
