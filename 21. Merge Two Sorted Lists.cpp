/*
Problem Description:
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l=new ListNode(0),*head=l;
        while(l1 && l2)
        {
            l->next=new ListNode(0);
            if(l1->val<=l2->val)
            {
                l->next->val=l1->val;
                l1=l1->next;               
            }
            else
            {
                l->next->val=l2->val;
                l2=l2->next;   
            }
            l=l->next;
        }
        while(l1)
        {
            l->next=new ListNode(0);
            l->next->val=l1->val;
            l1=l1->next;
            l=l->next;
        }
        while(l2)
        {
            l->next=new ListNode(0);
            l->next->val=l2->val;
            l2=l2->next;
            l=l->next;
        }
        return head->next;
    }
};