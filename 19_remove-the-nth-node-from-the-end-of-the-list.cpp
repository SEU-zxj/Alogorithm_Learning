/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* p1 = head;
        ListNode* p2 = head;
        //将p1平移n位，保持p1与p2之间的距离
        for(int i = 0 ; i < n ; i++)
        {
            p1 = p1->next;
        }
        //若p1 == nullptr，说明想要删除的是头节点
        if(p1 == nullptr)
        {
            return head->next;
        }
        //同时平移两个指针，直到p1的下一个为空指针
        while(p1->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        //此时p2指向的节点为删除节点的前一个节点
        //利用p2删除前面一个节点
        p2->next = p2->next->next;
        return head;
    }
};