#include<iostream>
using namespace std;

class Tree{
  public:

    int n;
    Tree* left;
    Tree* right;

    Tree(int n){

        this->n = n;
        left = right = NULL;

    }
    
};

    Tree* insertdata(int n){

      cout << "\nEnter the digits of binary tree: ";
      cin >> n;

        if(n == -1)
        return NULL;
        
      Tree* root = new Tree(n);
      root->left = insertdata(n);
      root->right = insertdata(n);

      return root;

    }

void display(Tree* root) {
    if (root == NULL) return;

    // check left child
    if (root->left != NULL) {
        cout << "This is the left of " << root->n << ": " << root->left->n << endl;
    }

    // check right child
    if (root->right != NULL) {
        cout << "This is the right of " << root->n << ": " << root->right->n << endl;
    }

    // recursively call for children
    display(root->left);
    display(root->right);
}

int main(){

  int n = 0;
  Tree* root;

    root = insertdata(n);

    cout << "\nInorder traversal: \n";
    display(root);

  return 0;
}