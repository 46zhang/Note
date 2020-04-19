#include <iostream>

struct ListNode {
	int data;
	ListNode * next;
};

void deleteDuplication(ListNode ** head) {
	ListNode *p = *head;
	if (head == NULL)
		return;
	while (p) {
		if (p->next&&p->data == p->next->data)
		{
			ListNode *q = p->next;
			p->next = p->next->next;
			delete q;
		}
		p = p->next;
	}
}

ListNode *createListII(int n)
{
	ListNode *head, *p, *q;
	head = p = new ListNode();
	int i = 0;
	while (i++<n)
	{
		if (i == 2)
			p->data = 1;
		else
			p->data = i;
		p->next = new ListNode();
		p = p->next;
	}
	p->data = i-1;
	p->next = NULL;
	return head;
}
void printListII( ListNode * head)
{
	ListNode *p = head;
	while (p) {
		std::cout << p->data << "  ";
		p = p->next;
	}
	std::cout << std::endl;
}
//删除链表中的重复节点
void deleteDuplicationTest() {
	ListNode *head = createListII(10);
	printListII(head);
	deleteDuplication(&head);
	printListII(head);
}
