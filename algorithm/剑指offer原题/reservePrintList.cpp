#include <vector>
#include <iostream>
struct ListNode
{
	int m_nKey;
	ListNode * m_pnext;
};

bool createList(ListNode **head,int n)
{
	ListNode *p, *q;
	p = q = new ListNode();
	int i;
	for (i = 0; i < n-1; i++)
	{
		q->m_nKey = i;
		q->m_pnext = new ListNode();
		q = q->m_pnext;
	}
	q->m_nKey = i;
	q->m_pnext = NULL;
	*head = p;
	return true;
}
void printListByOrder(ListNode *head)
{
	ListNode * p = head;
	while (p)
	{
		std::cout << p->m_nKey << "  ";
		p = p->m_pnext;
	}
	
}
bool reversePrintList(ListNode *head)
{
	ListNode *p=head;
	if (p == NULL)
		return false;
	else
		reversePrintList(p->m_pnext);
	std::cout << p->m_nKey << "  ";
	return true;
	
}
//从尾到头打印链表
void reversePrintListTest()
{
	ListNode **head =(ListNode**) malloc(sizeof(ListNode*));
	if (true == createList(head, 0))
		printListByOrder(*head);
	std::cout << std::endl;
	reversePrintList(*head);

}