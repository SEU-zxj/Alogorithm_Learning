#include <iostream>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
    public:
    //返回整个list的长度
    //只有返回指针的引用才能真正改变list的值，否则形参无法改变
    int ReverseList(ListNode*& list)
    {
        //反转链表
        //记录链表长度
        int length = 0;
        //反转所需要的三个指针
        ListNode* left = nullptr;
        ListNode* medium = nullptr;
        ListNode* right = list;
        while(right != nullptr)
        {
            length++;
            left = medium;
            medium = right;
            right = right->next;
            medium->next = left;
        }
        //原来的list应该是链表头，反转之后应该也指向链表头
        list = medium;
        return length;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        //将要返回的链表
        ListNode* result = nullptr;
        //类似归并排序
        //对每一位做加法时，有低位进位，也有向高位的进位
        int carry_in = 0;
        int carry_out = 0;
        //当前位两个数相加的结果
        int value = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        //当前位两数相加得到的数形成的节点
        ListNode* curNode = result;
        //前一位两数相加得到的数形成的节点
        ListNode* lastNode = nullptr;
        while(p1 != nullptr && p2 != nullptr)
        {
            value = p1->val + p2->val + carry_in;
            carry_out = (value > 9)? 1 : 0;
            value = value % 10;
            curNode = new ListNode(value, lastNode);
            p1 = p1->next;
            p2 = p2->next;
            //上一位的“向高位进位”变成下一位的“低位向高位的进位”
            carry_in = carry_out;
            //刚才的当前位也变成了上一位
            lastNode = curNode;
        }
        while(p1 != nullptr)
        {
            value = p1->val + carry_in;
            carry_out = (value > 9)? 1 : 0;
            value = value % 10;
            curNode = new ListNode(value, lastNode);
            p1 = p1->next;
            //上一位的“向高位进位”变成下一位的“低位向高位的进位”
            carry_in = carry_out;
            //刚才的当前位也变成了上一位
            lastNode = curNode;
        }
        while(p2 != nullptr)
        {
            value = p2->val + carry_in;
            carry_out = (value > 9)? 1 : 0;
            value = value % 10;
            curNode = new ListNode(value, lastNode);
            p2 = p2->next;
            //上一位的“向高位进位”变成下一位的“低位向高位的进位”
            carry_in = carry_out;
            //刚才的当前位也变成了上一位
            lastNode = curNode;
        }
        //若两个数都加完了，但carry_in依然等于1，结果还要加一位
        if(carry_in == 1)
        {
            curNode = new ListNode(carry_in, lastNode);
        }
        //此时整个链表排序是按照逆序来的，不用逆转了
        result = curNode;
        ReverseList(result);
        return result;
    }
};