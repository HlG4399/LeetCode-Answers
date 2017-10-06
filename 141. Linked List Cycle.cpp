/*
Problem Description:
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //v_p=2,v_q=1
        ListNode *p=head,*q=head;
        while(p && q && p->next)
        {
            p=p->next->next;
            q=q->next;
            if(p==q)
            {
                return true;
            }
        }
        return false;
    }
};