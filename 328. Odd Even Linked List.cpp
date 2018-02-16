/*
Problem Description:
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        ListNode *p1=head,*p2=head->next,*even_head=head->next;
        int i=1;
        while(p2)
        {
            p1->next=p2->next;
            if(p2->next)
            {   
                p1=p1->next;
                swap(p1,p2);
                i++;          
            }
            else
            {
                break;
            }
        }
        if(i%2==1)
        {
            p1->next=even_head;            
        }
        else
        {
            p2->next=even_head;
        }
        return head;
    }
};