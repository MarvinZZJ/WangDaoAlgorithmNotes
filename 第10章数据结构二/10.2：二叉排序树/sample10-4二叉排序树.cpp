/*
例题10.4	二叉排序树（华中科技大学复试上机题）	
http://t.cn/AiKD0L5V
*/

#include <iostream>
#include <cstdio>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *lchild, *rchild;
    TreeNode(int x): data(x), lchild(nullptr), rchild(nullptr){}
};

TreeNode* Insert(TreeNode* root, int x){
    if(root == nullptr){  // 创建新结点
        root = new TreeNode(x);
    }
    else if(root->data == x){  // 存在x值，不插入
        // 不操作
    }
    else if(root->data > x){  // 插入左子树
        root->lchild = Insert(root->lchild, x);
    }
    else{                     // 插入右子树
        root->rchild = Insert(root->rchild, x);
    }
    return root;
}

void PreOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    cout << root->data << " " ;
    PreOrder(root->lchild);
    PreOrder(root->rchild);
    return;
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

void PostOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    cout << root->data << " " ;
    return;
}

int main(){
    int n;
    while(cin >> n){
        TreeNode* root =nullptr;
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            root = Insert(root, x);
        }
        PreOrder(root);
        cout << endl;
        InOrder(root);
        cout << endl;
        PostOrder(root);
        cout << endl;
    }
    return 0;
}
