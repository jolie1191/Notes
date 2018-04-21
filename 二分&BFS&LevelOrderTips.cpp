#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;


//总结：set, map 和unordered_set, unordered_map 和multiset, unordered_mutlimap..区别
//1. unordered_map, unordered_set 属于 hashTable一类， O(1)， 不能有duplicate key
//2. set, map 是平衡二叉树：RB-tree一种， O(logn)， key会“自动排序”， key不能有duplicate
//要duplicate， 全用multiset， unordered_mutlimap等， 关键字multi-

//Binary Search in Recursion
int BinarySearch(const int anArray[], int first, int last, int target)
{
    int index;
    if(first > last)
        index = -1;
    else
    {
        int mid = first + (last -first)/2;
        if(target == anArray[mid])
            index = mid;
        else if(target < anArray[mid])
            index = BinarySearch(anArray, first, mid - 1, target);
        else
            index = BinarySearch(anArray, mid + 1, last, target);
    }

    return index;
}


//Binary Search with NO-Recursion 模板
//二分法--XXOO: 找到一个条件使得满足 OOXX 模型
int BinarySearch(vector<int>& nums, int x)
{
    if(nums.size() == 0)
        return -1;

    int start= 0, end = nums.size() - 1;
    //@相邻就退出循环： start = 2, end = 3就退出
    //所以最后需要加double check
    while(start + 1 < end)
    {
        //@avoid exceeding the limit of int 2^31
        int mid = first + (last -first)/2;
        if(target = nums[mid])
        {
            //@<要改>根据问题具体分析： return Any/First/Second position of anArray
            //1. 如果是返回the first index
            end = mid;
            //2. 如果是返回the last index
            //start = mid
            //3. Any index
            //return mid;
        }
        else if(nums[mid] < target)
            start = mid;
        else
            end = mid;
    }

    //@<要改>double check, 因为while时相邻即退出
    //1. return first index: 先看start再看end
    //2. return last index: 先看end 再看start
    if（nums[start] == traget)
        return start;

    if(nums[end] == target)
        return end;

    return -1;

}

//二叉树通用时间复杂度公式： T(n)= O(二叉树节点个数N * 每个节点处理时间O(k))
//因为每个节点直走一次！！！遍历和分治都是O(n*每个节点处理时间）

//分治法就是后序postOrder的递归版： 按“左右根”。 分治变非递归版， 类似PostOrder
//======================================
//树的preoder traversal 非递归版本
void preOrderNoRecursion(TreeNode* root){
    if(root == NULL)
    return;
    //step 1: 把根节点放到栈stack中
    stack<TreeNode*> stack;

    //Step 2： 当stack不为空， 就从栈顶pop一个节点， 然后风别将它的右孩子，左孩子push到栈stack
    //里。 如果子节点为空， 则什么也不做
    while(!stack.empty())
    {
        TreeNode* node = stack.top();
        cout << node->val; //也可以用一个vector去保存
        stack.pop();

        //preoder: 根-左-右， 根据stack后进先出原则
        if(node->right != NULL)
        {
            stack.push(node->right);
        }

        if(node->left != NULL)
        {
            stack.push(node->left);
        }
    }

    //Step 3: 重复第2步， 直到栈stack为空

}
//背诵
void InOrderNORecursion(TreeNode* root){
    stack<TreeNode*> stack;

   //只要 根节点不为空 或 栈不为空， 循环继续
    while(root != NULL || !stack.empty())
    {
        //只要root不为空， 一直向下走到最左节点
        while(root != NULL)
        {
            stack.push(root);
            root = root->left;
        }
        //最左节点为空， pop, + 打印此节点， + root= root->right
        root = stack.top();
        stack.pop();
        cout << root-val;
        //!!!!把root->右子树
        root = root->right;
    }
}

//背诵
void PostOrderNoRecursion(TreeNode* root){

}


//================BFS 宽度优先搜索 +++++++++++++++++++++//
//BFS 类似 Level Order
//return list of list, 每个小list中存的是每层的元素
//1. 用Queue， 先放一个元素root进去
//2. while(!queue.isEmpty())
//3 Mark： 多加一个for loop进行分层， 不加就不会分层
vector<vector<int>> LevelOrder(TreeNode* root)
{
    if(root == NULL)
        return results;

    vector<vector<int>> results;
    queue<TreeNode*> queue;//queue中每次"do"...while, "do"中存的是一层的所有节点，
    //while中先pop 当前Queue中节点， 再放的是下一层节点
    queue.push(root);

    while(!queue.empty())
    {
        //不分层写法
        /*
            3
           / \
          9  20
            /  \
           15   7

           return [3, 9, 20, 15, 7]
        //+++++++++++++++++模板++++++++++++++++++++
        *///在此嵌套for loop分层，《背诵！》以下166~173都在读层，后序处理层
        TreeNode* node = queue.front();
        queue.pop(); //-->node = queue.pop()

        //把node的子节点放到Queue中， 以便下次while遍历
        if(node->left != NULL)
            queue.push(node->left);

        if(node->right != NULL)
            queue.push(node->right);
    //++++++++++++++++++++++++++++++++++++++++++++++++++++
    }

   /*
           3
           / \
          9  20
            /  \
           15   7
        return:
                [
                  [3],
                  [9,20],
                  [15,7]
                ]
   *///多加一个for loop结果“分层”
    while(!queue.empty())
    {
        vector<int> level;
        int size = queue.size();//1. !!!Important!!! 先缓存下，queue的size在之后随时在变化
        //把这一层每个结点的neighbor加进Queue
        for(int i = 0; i< size; i++)
        {   //+++++++模板++++++++++//
            TreeNode* node = queue.front();
            queue.pop();//node = queue.pop();
            level.push_back(node->val);//2. 《变动》!!!把当前node分层level！！
            if(node->left != NULL)
                queue.push(node->left);

            if(node->right != NULL)
                queue.push(node->right);
            //++++++++++++++++++++++//
        }
        result.push_back(level);//3. <新加>把当前level加入大result
    }
    return result;
}



//Reverse a Linked List
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){}
};

ListNode* reverseLinkedList(ListNode* head)
{
    ListNode* pre, *cur, *nextNode;
    cur = head;
    pre = NULL;
    nextNode = NULL;

    while(cur != NULL)
    {
        nextNode = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nextNode;
    }
    head = pre;

    return head;

}


int main()
{
    int array[10] = {6, 7, 2, 3, 1, 5, 4, 7, 2, 0};
    int find = BinarySearch(array, 0, 10, 5);
    cout << find << endl;

return 0;
}
