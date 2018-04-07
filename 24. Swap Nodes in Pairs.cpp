/*
Problem Description:
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p=head->next,*pre=new ListNode(0),*p1=head,*p2=p;  
        pre->next=head;
        while(p1 && p2)
        {
            p1->next=p2->next;
            p2->next=p1;
            pre->next=p2;
            pre=p1;
            p2=(p1->next?p1->next->next:NULL);
            p1=p1->next;
        }
        return p;
    }
};