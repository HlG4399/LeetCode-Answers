/*
Problem Description:
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p=head,*pre=nullptr;
        while(p)
        {
            if(p->val==val)
            {
                if(p==head)
                {
                    head=p->next;
                }
                else
                {
                    pre->next=p->next;
                }               
            }
            else
            {
                pre=p;
            }
            p=p->next;
        }
        return head;
    }
};