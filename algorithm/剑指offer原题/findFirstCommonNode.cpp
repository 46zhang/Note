#include<iostream>

/*
�㷨���ƣ�		��������ĵ�һ�������ڵ�
�㷨��Դ��		��ָOffer ������52
�㷨˼�룺		

�㷨ע�⣺		1.�߽���
				
�㷨Ч�ʷ���:	
�㷨ʵ��ʱ��:	���˴��30minʵ�֣�����Ƚ���Ϥ������һ��ʼû���뵽�õĽⷨ�������ϲ�֪��������ô��

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