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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* p1 = nullptr;
        ListNode* p2 = nullptr;
        if(head == nullptr)
        {
            return head;
        }
        p1 = head;
        p2 = head;
        if(p2->next != nullptr)
        {
            p2 = p2->next;
        }
        else
        {
            return head;
        }
        while(true)
        {
            if(p2->next != nullptr && p2->next->next != nullptr)
            {
                p2 = p2->next->next;
                p1 = p1->next;
            }
            else//至少有一个是空指针
            {
                return p1->next;
            }
        }
    }
};