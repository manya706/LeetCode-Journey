// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
#include <bits/stdc++.h>
using namespace std;
 
// A Tree node
struct Node {
  int key, head;
  struct Node *left, *right;
};
 
// Utility function to create a new node
Node* newNode(int key)
{
  Node* temp = new Node;
  temp->key = key;
  temp->left = temp->right = NULL;
  return (temp);
}

int print_tree(Node* root){
    // preorder printing 
    if(root==NULL) return 0;
    cout<<root->key<<" ";
    print_tree(root->left);
    print_tree(root->right);
}
bool check_symmetry(Node* root1 , Node* root2){
    if(root1 ==NULL && root2==NULL) return true;
    if(root1==root2 && root1->key == root2->key){
        return check_symmetry(root1->left, root2->right) && check_symmetry(root1->right,root2->right);
    }
    return false;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]] = i;
        }
        Node* root = buildtree(preorder,0,preorder.size()-1,inorder, 0 ,inorder.size()-1, inmap);
        return root;
    }
Node* buildtree(vector<int>& preorder,int prestart, int preend, vector<int>& inorder,int instart, int inend, map<int,int>& inmap){
    if(prestart>preend || instart>inend) return NULL;
    Node* root = newNode(preorder[prestart]);
    int inroot = inmap[root->key];
    int numsleft = inroot - instart;
    root->left = buildtree(preorder,prestart+1,prestart+numsleft,inorder, instart ,inroot-1, inmap);
    root->right = buildtree(preorder,prestart+numsleft+1,preend,inorder, inroot+1 ,inend, inmap);
    return root;
}
int main(){
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    cout<<"Original tree:"<<endl;
    print_tree(root);
    cout<<endl;
    cout<<"Check symmetry of the tree: ";
    cout<<check_symmetry(root,root);
    vector<int> preorder[3,9,20,15,7];
    vector<int> inorder[9,3,15,20,7];    
}