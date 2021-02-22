/*
例题10.2	二叉树遍历（华中科技大学复试上机题）	
http://t.cn/AiKgDfLU
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct TreeNode{
    char data;
    TreeNode *lchild, *rchild;
    TreeNode(char c):data(c), lchild(nullptr), rchild(nullptr){}
};

TreeNode* BuildTree(string preOrder, string inOrder){
    if(preOrder.size() == 0){
        return nullptr;
    }
    char c = preOrder[0];
    TreeNode* root = new TreeNode(c);
    int pos = inOrder.find(c);
    root->lchild = BuildTree(preOrder.substr(1, pos), inOrder.substr(0, pos));
    root->rchild = BuildTree(preOrder.substr(pos + 1), inOrder.substr(pos + 1));
    return root;
}

void PostOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    cout << root->data;
    return;
}

int main(){
    string preOrder, inOrder;
    while(cin >> preOrder >> inOrder){
        TreeNode* root = BuildTree(preOrder, inOrder);
        PostOrder(root);
        cout << endl;
    }
    return 0;
}
