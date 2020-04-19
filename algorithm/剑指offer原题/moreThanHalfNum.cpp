#include<iostream>

//8.30pm begin
/*
算法名称：		查找超过数组长度一半的数字
算法来源：		剑指Offer 面试题39
算法思想：		解法1.：先排序，再查找，如果存在重复数字超过数组一半的数字，那么当它排好序时，num[n/2]肯定就是我们要找的数字
					排序算法的时间复杂度O(nlogn),可以改进快速排序，将时间复杂度降为O(n)，当返回的下标是n/2则返回该数，
					当返回的下标大于或者小于n/2，则缩小范围，重新查找
					1. 检查是否为合法输入
					2. 以num[0]为节点开始排序，如果结束下标j为n/2，返回num[j]
					3. 否则开始分治
				解法2：这是我一开始首先想到的，用哈希表存每个数字的个数，然后返回出现次数超过n/2的
				解法3：剑指Offer里面提到的算法，是算法2的改进，如果数字超过n/2，说明其出现次数最多
					1.设置一个time值，初始化为0，当time=0时，遇到的数字保存到result
					2.如果遇到的数字与result大小相等，time+=1,否则time-=1,当time为0,跳转到1
					3. 返回最终的result

算法注意：		1.输入检查
				2.结尾NULL指针的设置
算法效率分析:	算法1时间复杂度O(n)，空间复杂度O(1)
				算法2时间复杂度O(n)，空间复杂度O(n)
				算法3时间复杂度O(n)，空间复杂度O(1)
算法实现时间:	花了25min小时实现算法，花了15mindebug,快拍还是比较熟悉的

*/

int partition(int *pNum,int begin,int end,int len) {
	if (pNum == NULL ||begin >=end)
		return 0;
	int temp, change = pNum[begin],i=begin,j=end;
	int time = 0;
	while (i < j) {
		while (i<end&&pNum[++i] <= change);
		while (j>begin&pNum[--j] > change);
		if (i >= j  )
			break;
		temp = pNum[i];
		pNum[i] = pNum[j];
		pNum[j] = temp;
		++time;
	}
	temp = pNum[j];
	pNum[j] = pNum[begin];
	pNum[begin] = pNum[j];
	std::cout << "j:  "<<j<<" num[j]: "<<pNum[j] << "    "<<pNum[begin]<< "  "<<time <<std::endl;
	if (len / 2 == j)
		return pNum[j];
	else if (j < len / 2)
		return partition(pNum, j+1, end, len);
	else
		return partition(pNum, begin, j, len);
}

int moreThanHalfNum(int *pNum,int len) {
	if (pNum == nullptr || len <= 0)
		return 0;
	else if (len == 1)
		return pNum[0];
	return partition(pNum, 0, len, len);
}

void moreThanHalfNumTest() {
	//int num[9] = { 1,2,3,2,2,2,5,4,2 }, n = 9;
	int num[11] = { 1,2,3,2,2,2,5,4,2,7,2 }, n = 11;
	int a = moreThanHalfNum(num, n);
	std::cout << a << std::endl;
}