#include<iostream>

/*
算法名称：		俩个链表的第一个公共节点
算法来源：		剑指Offer 面试题52
算法思想：		

算法注意：		1.边界检查
				
算法效率分析:	
算法实现时间:	花了大概30min实现，链表比较熟悉，但是一开始没有想到好的解法，看书上才知道可以这么解

*/


struct ListNode {
	int m_nvalue;
	ListNode * m_pNext;
};
static ListNode *createList(int n)
{
	ListNode *head, *p, *q = nullptr;
	head = p = new ListNode();
	int i = 0;
	while (i++ < n - 1)
	{

		p->m_nvalue = i;
		q = p;
		p->m_pNext = new ListNode();
		p = p->m_pNext;
		

	}
	p->m_nvalue = i;
	p->m_pNext = NULL;
	return head;
}
static void printList(ListNode * head)
{
	ListNode *p = head;
	while (p) {
		
		std::cout <<  p->m_nvalue << "  " ;
		p = p->m_pNext;
	}
	std::cout << std::endl;
}

int getListLen(ListNode *p) {
	int len = 0;
	while (p) {
		p = p->m_pNext;
		++len;
	}
	return len;
}

ListNode* findFirstCommonNode(ListNode *pFirst,ListNode *pSecond) {
	if (pFirst == nullptr || pSecond == nullptr)
		return nullptr;
	int firstLen = getListLen(pFirst), secondLen= getListLen(pSecond);
	if (firstLen > secondLen) {
		while (firstLen - secondLen > 0) {
			--firstLen;
			pFirst = pFirst->m_pNext;
		}
	}
	else {
		while ( secondLen - firstLen > 0) {
			--secondLen;
			pSecond = pSecond->m_pNext;
		}
	}
	while (pFirst) {
		if (pFirst == pSecond)
			break;
		pFirst = pFirst->m_pNext;
		pSecond = pSecond->m_pNext;
	}
	return pFirst;

}

void findFirstCommonNodeTest() {
	ListNode *p = createList(10), *q = createList(3),*result;
	//printList(q);
	//q->m_pNext->m_pNext->m_pNext = p->m_pNext->m_pNext->m_pNext->m_pNext->m_pNext;
	q->m_pNext->m_pNext->m_pNext = p->m_pNext->m_pNext->m_pNext;
	printList(p);
	printList(q);
	result = findFirstCommonNode(q,p);
	std::cout << result->m_nvalue << std::endl;
}