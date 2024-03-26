// 21 Construct a binary search tree
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
// Function to insert a value into the BST
TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }
    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}
// Function to perform inorder traversal (to verify BST)
void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main()
{
    // Creating an empty BST
    TreeNode *root = nullptr;
    // Inserting elements into the BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    // Verifying the BST by performing inorder traversal
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;
    // Deallocating memory to prevent memory leaks
    // You may want to implement a separate function to deallocate memory
    // for
    //  the entire tree
    //  For simplicity, memory deallocation is omitted here
    return 0;
}