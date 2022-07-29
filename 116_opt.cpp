//从这道题学到的：用已知解决未知（上一层的next可以用来求下一层的next）
class Solution {
public:
    Node* connect(Node* root) 
    {
        if (root == nullptr) 
        {
            return root;
        }
        //从第一层开始

        Node* leftmost = root;
        //👇本层              👇下一层
        //第1层next完毕，开始第二层
        //只有下一层存在时，才能为下一层添加next
        while(leftmost->left != nullptr)
        {
            Node* head = leftmost;
            //因为本层next指针已经初始化完毕，可以像链表一样遍历本层

            while(head != nullptr)
            {
                //第一种link
                head->left->next = head->right;
                //第二种link
                if(head->next != nullptr)
                {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            //到下一层继续更新
            leftmost = leftmost->left;
        }
        return root;
    }
};