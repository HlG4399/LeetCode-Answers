/*
Problem Description:
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return true;
        }
        ListNode *p1,*p2;
        p1=head;
        int n=1;
        while(head->next!=NULL)
        {
            head=head->next;
            n++;
        }
        head=p1;
        int length=n;
        n=1;
        p1=NULL,p2=head;
        while(head->next!=NULL)
        {
            if(n<=std::ceil(length/2.0))
            {
                head=head->next;
                p2->next=p1;
                p1=p2;
                p2=head;
            }
            else
            {
                break;
            }
            n++;
        }
        if(length%2==1)
        {
            p1=p1->next;
        }
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val!=p2->val)
            {
                return false;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }
};