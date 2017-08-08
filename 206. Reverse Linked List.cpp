/*
Problem Description:
Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
        ListNode *reverse_p=NULL,*p=head;
        while(p)
        {
            ListNode* temp=reverse_p;
            reverse_p=p;
            p=p->next;
            reverse_p->next=temp;
        }
        return reverse_p;
    }
};