/*
Problem Description:
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
Note:

All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.
*/

class MyLinkedList {
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) {
		val = x;
		next = NULL;
	}
};
private:
	ListNode* head;
	ListNode* tail;
	int n;
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = nullptr;
		tail = nullptr;
		n = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index<0 || index >= n) return -1;
		ListNode* p = head;
		for (int i = 0; i<index && p; ++i) p = p->next;
		return p?p->val:-1;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		if (!head) {
			head = new ListNode(val);
			tail = head;
		}
		else {
			ListNode* node = new ListNode(val);
			node->next = head;
			head = node;
		}
		++n;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if (!head) {
			head = new ListNode(val);
			tail = head;
		}
		else {
			ListNode* node = new ListNode(val);
			tail->next = node;
			tail = node;
		}
		++n;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index<0 || index > n) return;
		if (index == 0) {
			addAtHead(val);
			return;
		}
		if (index == n) {
			addAtTail(val);
			return;
		}
		ListNode* p = head;
		for (int i = 0; i<index - 1; ++i) {
            p = p->next;
            if(!p) return;
        }
		ListNode* node = new ListNode(val);
		node->next = p->next;
		p->next = node;
		++n;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
        if(!head) return;
		if (index<0 || index >= n) return;
		if (index == 0) head = head->next;
		ListNode* p = head;
		for (int i = 0; i<index - 1; ++i){
            p = p->next;
            if(!p) return;
        } 
        if(!(p->next)) return;
		p->next = p->next->next;
        if (index == n - 1) tail = p;
		--n;
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */