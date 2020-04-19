#include <iostream>

/*
算法名称：		数组中的逆序对
算法来源：		剑指Offer 面试题51
算法思想：		利用类似归并排序的思想，将其进行分解然后计算其逆序对的个数，相加然后合并

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	算法时间复杂度O(nlogn)，空间复杂度O(n)
				
算法实现时间:	算法实现时间挺长的，顺带复习了一下归并排序

*/


/*

int mergePair(int *pNum,int *pLeft, int leftLen, int *pRight, int rightLen,int &time) {
	int i=leftLen-1,j=rightLen-1;
	for (; i >=0&&j >= 0;) {
		//说明存在逆序对
		if (pLeft[i] > pRight[j]) {
			pNum[i + j+1] = pLeft[i];
			time += j+1;
			--i;
		}
		else {
			pNum[i + j+1] = pRight[j];
			--j;
		}
	}
	std::cout << "i: " << i << "j: " << j << std::endl;
	while (i >= 0)
		pNum[i+j+1] = pLeft[i--];
	while (j >= 0)
		pNum[j+i+1] = pRight[j--];
	for (int k = 0; k < leftLen + rightLen ; k++) {
		std::cout << " " << pNum[k] << "  ";
	}
	std::cout << std::endl;
	return time;

}

int inversrPair(int *pNum,int len,int &time) {
	if (pNum==nullptr||len <= 1)
		return 0;
	int mid = len / 2;
	int *pLeftNum = new int[mid];
	int *pRightNum = new int[len - mid];
	//给左右数组赋值
	for (int i = 0; i < mid; ++i) 
		pLeftNum[i] = pNum[i];
	for (int i = 0; i < len - mid; ++i)
		pRightNum[i] = pNum[mid + i];
	std::cout << mid << "  " << len - mid << std::endl;
	inversrPair(pLeftNum, mid,time);
	inversrPair(pRightNum, len-mid,time);
	mergePair(pNum,pLeftNum, mid, pRightNum, len-mid,time);

	delete[] pLeftNum;
	delete[] pRightNum;
	return time;
}
*/

int inversrPair(int *pNum,int *pCopy,int start,int end,int& time) {
	if (start == end) {
		pCopy[start] = pNum[start];
		return 0;
	}
	int mid = (end + start) / 2;
	
	inversrPair(pCopy, pNum, start, mid, time);
	inversrPair(pCopy, pNum, mid+1, end, time);
	
	std::cout << " srart: " << start << " mid: " << mid << " end: " << end << std::endl;
	int i = mid , j = end,k=end;
	while (i >= start && j >= mid+1) {
		if (pCopy[i] > pCopy[j]){
			pNum[k-- ] = pCopy[i];
			time += j-mid;
			--i;
		}
		else {
			pNum[k--] = pCopy[j];
			--j;
		}
	}
	while (i >= start)
		pNum[k--] = pCopy[i--];
	while (j >= mid+1)
		pNum[k--] = pCopy[j--];
	for (int k = start; k <= end; ++k) {
		std::cout << pNum[k]<<"  ";
	}
	std::cout << std::endl;
	return time;
}
void inversePairTest() {
	//int num[4] = { 7,5,6,4 }, copy[4]= { 7,5,6,4 }, n=4;
	int num[8] = { 1, 2, 3, 4, 5, 6, 7, 0 }, copy[8] = { 1, 2, 3, 4, 5, 6, 7, 0 }, n = 8;
	int time = 0;
	int a=inversrPair(num, copy,0,n-1,time);
	std::cout << "逆序对个数为： " << a << std::endl;
}