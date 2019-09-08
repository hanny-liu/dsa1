//
// Created by lhw on 8/9/19.
//
#include <vector>

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root);

bool isValidBST(TreeNode* root) {
    TreeNode* node = root;
    //travel the tree by inner-order 中序输出
    vector<TreeNode*> stack;

    vector<int> v;//中序输出保存至v中
    /* 5
      / \
     1   4
        / \
       3   6
   [5,1,4,null,null,3,6]
   */
    //node == nullptr 遍历完成
    while (stack.size()>0 || node!=NULL) {
        if (node!=NULL){
            stack.push_back(node);//5 1//进栈
            node = node->left;
        }else{
            node = stack.back();//NULL//vector容器中末尾元素的引用

            v.push_back(node->val);//NULL

            stack.pop_back();//删除最后结点NULL

            node = node->right;//NULL
        }
    }

    //check the vector wehther sorted or not
    for(int i=0; v.size()>0 && i<v.size()-1; i++){//空树也是二叉排序树
        if (v[i] >= v[i+1]) {
            return false;
        }
    }

    return true;
}

int main(){

    TreeNode* root = [5,1,4,null,null,3,6];
    isValidBST(TreeNode* root);
    return 0;
}

