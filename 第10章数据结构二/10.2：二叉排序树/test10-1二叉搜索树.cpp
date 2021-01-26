/*
习题10.1	二叉搜索树（浙江大学复试上机题）	
http://t.cn/Ai9PUJtK
*/

// 方法一：
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(int x):data(x), lchild(nullptr), rchild(nullptr){}
};

TreeNode* Insert(TreeNode* root, int x){
    if(root == nullptr){
        root = new TreeNode(x);
    }
    else if(root->data > x){
        root->lchild = Insert(root->lchild, x);
    }
    else if (root->data < x){
        root->rchild = Insert(root->rchild, x);
    }
    return root;
}

bool Same(TreeNode* original, TreeNode* root){
    if(original == nullptr && root == nullptr){
        return true;
    }
    if(original != nullptr && root != nullptr && original->data == root->data){
        return Same(original->lchild, root->lchild) && Same(original->rchild, root->rchild);
    }
    return false;
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        string str;
        cin >> str;
        TreeNode* original = nullptr;
        for(int i = 0; i < str.size(); i++){
            original = Insert(original, str[i] - '0');
        }
        for(int i = 0; i < n; i++){
            cin >> str;
            TreeNode* root = nullptr;
            for(int j = 0; j < str.size(); j++){
                root = Insert(root, str[j] - '0');
            }
            if(Same(original, root)){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}



//  方法二：
// 思路：判断两颗二叉树是否相同的方法可以是：判断先序遍历与中序遍历是否相同。
//        而对于二叉排序树（二叉搜索树）来说，其中序遍历的结果必定是递增序列。
//        判断依据：1.比较中序遍历的结果（利用sort排序后比较即可)。 2.比较先序遍历的结果

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode{
    char data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int x): data(x), leftChild(nullptr), rightChild(nullptr){}
};

TreeNode* Insert(TreeNode* root, int x){
    if(root == nullptr){
        root = new TreeNode(x);
    }
    else if(root->data > x){
        root->leftChild = Insert(root->leftChild, x);
    }
    else{
        root->rightChild = Insert(root->rightChild, x);
    }
    return root;
}

void PreOrder(TreeNode* root, string& str){
    if(root == nullptr){
        return;
    }
    else{
        str = str + root->data;
        PreOrder(root->leftChild, str);
        PreOrder(root->rightChild, str);
        return;
    }
}

void InOrder(TreeNode* root, string& str){
    if(root == nullptr){
        return;
    }
    else{
        PreOrder(root->leftChild, str);
        str = str + root->data;
        PreOrder(root->rightChild, str);
        return;
    }
}


int main()
{
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        string str;
        cin >> str;
        TreeNode* tree = nullptr;
        for(int i = 0; i < str.size(); i++){
            tree = Insert(tree, str[i]);
        }
        string preStr = "";
        PreOrder(tree, preStr);
        string inStr = "";  // 用于判断中序遍历
        InOrder(tree,inStr);
        while(n--){
            string tempStr;
            cin >> tempStr;
            TreeNode* tempTree = nullptr;
            for(int i = 0; i < tempStr.size(); i++){
                tempTree = Insert(tempTree, tempStr[i]);
            }
            string tempInStr = "";
            InOrder(tempTree, tempInStr);
            if(inStr == tempInStr){
                string tempPreStr = "";
                PreOrder(tempTree, tempPreStr);
                if(preStr == tempPreStr){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
