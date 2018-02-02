/*
Problem Description:
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        stack<int> s1,s2;
        while(l1)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);    
            l2=l2->next;
        }
        int carry=0,num1=0,num2=0;
        ListNode *p=NULL,*q=NULL;
        while(!s1.empty() || !s2.empty())
        {
            num1=s1.empty()?0:s1.top();
            num2=s2.empty()?0:s2.top();
            q=p;
            p=new ListNode((num1+num2+carry)%10);
            p->next=q;
            carry=(num1+num2+carry)/10;
            if(!s1.empty())
            {
                s1.pop();
            }
            if(!s2.empty())
            {
                s2.pop();
            }
        }
        if(carry>0)
        {
            q=p;
            p=new ListNode(carry%10);
            p->next=q;            
        }
        return p;
    }
};