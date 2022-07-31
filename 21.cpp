#include <iostream>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == nullptr)
        {
            return list2;
        }    
        if(list2 == nullptr)
        {
            return list1;
        }

        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* last = nullptr;
        ListNode* cur = nullptr;
        ListNode* result = nullptr;
        //先处理第一个节点
        if(p1->val <= p2->val)
        {
            cur = new ListNode(p1->val);
            p1 = p1->next;
            result = cur;
        }
        else
        {
            cur = new ListNode(p2->val);
            p2 = p2->next;
            result = cur;
        }

        while(p1 != nullptr && p2 != nullptr)
        {
            last = cur;
            if(p1->val <= p2->val)
            {
                cur = new ListNode(p1->val);
                p1 = p1->next;
            }
            else
            {
                cur = new ListNode(p2->val);
                p2 = p2->next;
            }
            last->next = cur;
        }

        while(p1 != nullptr)
        {
            last = cur;
            cur = new ListNode(p1->val);
            last->next = cur;
            p1 = p1->next;
        }

        while(p2 != nullptr)
        {
            last = cur;
            cur = new ListNode(p2->val);
            last->next = cur;
            p2 = p2->next;
        }
        return result;
    }
};