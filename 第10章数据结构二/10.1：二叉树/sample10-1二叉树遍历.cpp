/*
例题10.1	二叉树遍历（清华大学复试上机题）	
http://t.cn/AiKuUTlX
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct TreeNode{
    char data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(char c): data(c), lchild(nullptr), rchild(nullptr){}
};

TreeNode* BuildTree(string str, int& pos){
    char c = str[pos++];
    if(c == '#'){
        return nullptr;
    }
    TreeNode* root = new TreeNode(c);
    root->lchild = BuildTree(str, pos);
    root->rchild = BuildTree(str, pos);
    return root;
}

void InOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    InOrder(root->lchild);
    cout << root->data << " " ;
    InOrder(root->rchild);
    return;
}

int main(){
    string str;
    while(cin >> str){
        int pos = 0;
        TreeNode* root = BuildTree(str, pos);
        InOrder(root);
        cout << endl;
    }
    return 0;
}
