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
        ListNode* cur = nullptr;
        ListNode* preResult = nullptr;
        //先处理第一个节点
        preResult = new ListNode(-1);
        cur = preResult;

        while(p1 != nullptr && p2 != nullptr)
        {
            if(p1->val <= p2->val)
            {
                cur->next = p1;
                cur = p1;
                p1 = p1->next;
            }
            else
            {
                cur->next = p2;
                cur = p2;
                p2 = p2->next;
            }
        }

        cur->next = (p1 == nullptr)? p2 : p1;
        return preResult->next;
    }
};