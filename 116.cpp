/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root == nullptr)
        {
            return root;
        }    
        queue<Node*> assistant;
        //每一行的最后一个Node编号与层数有关，因为每层最后一个next为nullptr，
        //因此需要能判断Node是否为当前层数的最后一个节点
        int edge = 1;//第一层的边缘为1
        int floor = 1;
        int num = 0;//当前节点的编号（根节点为1号）
        assistant.push(root);
        //当队列非空时，执行while内程序
        while(!assistant.empty())
        {
            Node* curNode = assistant.front();
            assistant.pop();
            num++;
            if(curNode->left != nullptr)
            {
                assistant.push(curNode->left);
            }
            if(curNode->right != nullptr)
            {
                assistant.push(curNode->right);
            }            
            if(num == edge)
            {
                //说明即将进入下一层，更新层数与下一层的层数
                floor++;
                edge += pow(2, floor-1);
                //不更新next
            }
            else
            {
                //当前节点并不是当前层的最后一个节点
                curNode->next = assistant.front();
            }
        }
        return root;
    }
};