#include <iostream>
#include <vector>
/*
算法名称：		和为S的数字
算法来源：		剑指Offer 面试题57
算法思想：		俩道算法题
				1: 和为s的俩个数字
					数组是递增序列，所以可以通过俩个指针俩完成，一个头指针一个尾指针。俩个之和大于s，则递减尾指针
					俩个之和小于S则递增头指针
				2: 和为s的连续正数序列：
					相加之和必须是连续的，可以观察到有俩个特点
						(1). 相加的数字是连续的
						(2). 连续相加的数字不会超过(num+1)/2也就是说 7最多相加到数字4就可以判断是否存在了
					与1解法类似，用俩个指针法去做，一开始一前一后，累加和，当和相等时，如果下标没超过 (num+1)/2
						则继续让尾指针递增，此时和大于s，递增头指针，直到头尾指针相交或者是存在某个指针下标越过(num+1)/2
					第二题一开始想用动态规划或者递归来做，但是发现其要求是连续的，所以很难，比如说  9=f(5)+f(4)
						然后继续求f(5)的组合序列，这种做法不可取，因为不一定是2，3这种连续，而且就算是2，3也无法保证跟4连续
						例如f(15)=f(7)+f(8),你就很难去判断f(7)递归的得到的组合跟f(8)得到的是连续的

算法注意：		1.抓住连续、递增这俩个关键词
				2.边界检测
算法效率分析:	算法1时间复杂度O(n)，空间复杂度O(1)
				算法2时间复杂度O(n)，空间复杂度O(n)
算法实现时间:	花了1个小时实现算法1、2

*/

bool twoNumSum(std::vector<int> data,int &num1,int &num2,int s) {
	if (data.size() <= 0)
		return false;
	for (int i = 0, j = data.size() - 1; i < j; ) {
		if (data[i] + data[j] == s) {
			num1 = data[i];
			num2 = data[j];
			return true;
		}
		else if (data[i] + data[j] > s)
			--j;
		else
			++i;
	}
	return false;
}

void twoNumSumisSTest() {
	std::vector<int> num{ 1,2,4,7,11,15 };
	int num1, num2,s=30;
	if (twoNumSum(num, num1, num2, s)) {
		std::cout << "第一个数：" << num1 << "第二个数: " << num2 << std::endl;
	}
	else
		std::cout << "找不到这样的俩个数" << std::endl;
}

void continueNumSumIsSTest(int s) {
	if (s < 3 )
		return;
	int *num = new int[(s+1)/2+1];
	for (int i = 0; i < (s + 1) / 2 + 1; ++i)
		num[i] = i;
	int tempSum = num[1];
	for (int i = 1, j = 2; i < (s + 1) / 2 + 1&& i < (s + 1) / 2 + 1;) {
		if (tempSum + num[j] < s) {
			tempSum += num[j];
			j++;
		}
		else if (tempSum + num[j] == s) {
			tempSum += num[j];
			std::cout << i << " ~ " << j << std::endl;
			++j;
		}
		else {
			if (i < j) {
				tempSum -= num[i];
				++i;
			}
			else
				break;
		}
	}
}

void sumIsSTest() {
	//twoNumSumisSTest();
	continueNumSumIsSTest(4);
}