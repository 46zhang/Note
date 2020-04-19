#include<iostream>
#include<vector>
#include<string>
#include <time.h>
using namespace std;

template <typename T>
static void quickSort(vector<T>& nums, int begin, int end) {
	if (begin >= end)
		return;
	int i = begin, j = end, target = nums[i];
	while (i < j) {
		while (i < end-1 && nums[++i] < target);
		while (j > begin && nums[--j] > target);
		//cout << i << "  " << j << endl;
		if (i < j)
			swap(nums[i], nums[j]);
	}
	nums[begin] = nums[j];
	nums[j] = target;
	quickSort(nums, begin, j);
	quickSort(nums, j + 1, end);
}

template <typename T>
static void mergeSort(vector<T>& nums, vector<T>& helper, int begin, int end) {
	if (begin == end)
	{
		helper[begin] = nums[begin];
		return;
	}
	int mid = (begin + end) / 2;

	//注意这一步进行 辅助空间与原数组的交换
	//相当于让数据归并到辅助数组上，然后辅助数组再合并到nums上
	mergeSort(helper, nums, begin, mid);
	mergeSort(helper, nums, mid+1, end);

	int i = begin, j = mid+1;
	int k = begin;

	//二路归并，将helper的数据归并到nums上
	while (i <= mid && j <= end  ) {
		if (helper[i] < helper[j])
			nums[k++] = helper[i++];
		else
			nums[k++] = helper[j++];
	}
	while (i <= mid)
		nums[k++] = helper[i++];
	while (j <= end)
		nums[k++] = helper[j++];


}

//快排
static void qsort(vector<int>& nums) {
	quickSort(nums, 0, nums.size());
}

//归并排序
template<typename T>
static void mergeSort(vector<T> &nums) {
	vector<int> helper(nums);
	mergeSort(nums, helper, 0, nums.size()-1);
}

int fatherIndex(int index) {
	return (index - 1) / 2;
}

pair<int, int> childrenIndex(int index) {
	return { index * 2 + 1,index * 2 + 2 };
}

static void heapity(vector<int>&nums,int father,int end) {
	auto a = childrenIndex(father);
	int left = a.first, right = a.second;
	while (father >= 0) {
		int temp = father;
		if (left < end && nums[temp] < nums[left])
			temp = left;
		if (right < end&&nums[temp] < nums[right])
			temp = right;
		if (father != temp)
			swap(nums[father], nums[temp]);
		if (!father)
			break;
		father = (father-1)/2;
	}
}
static void makeHeap(vector<int>& nums,int end) {
	for (int i = (end-1) / 2; i >= 0;--i) {
		heapity(nums, i, end);
	}
}

//堆排序
static void heapSort(vector<int>& nums) {
	for (int i = nums.size(); i > 0; --i) {
		makeHeap(nums, i);
		swap(nums[i - 1], nums[0]);
	}
}

//产生随机数组
vector<int> makeRandNumArray(int n) {
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
		nums[i] = rand();
	return nums;
}

void testQuickSort(vector<int> nums ) {
	// 使用clock()构造clock_t对象(实际上是long类型的变量)
	clock_t t1 = clock();

	// 一段计算
	qsort(nums);

	// 计算clock差，除以clock数/每秒，即可求出秒数
	// 将秒数乘以1000得到毫秒数
	cout << "快速排序 " << nums.size() << "个数字所花费时间: " << (clock() - t1) * 1.0 / CLOCKS_PER_SEC*1000 << " ms " << endl;
	
}
void testHeapSort(vector<int> nums) {
	// 使用clock()构造clock_t对象(实际上是long类型的变量)
	clock_t t1 = clock();

	// 一段计算
	heapSort(nums);

	// 计算clock差，除以clock数/每秒，即可求出秒数
	// 将秒数乘以1000得到毫秒数
	cout << "堆排序 " << nums.size() << "个数字所花费时间: " << (clock() - t1) * 1.0 / CLOCKS_PER_SEC*1000 <<" ms " << endl;
}

void testMergeSort(vector<int> nums) {
	// 使用clock()构造clock_t对象(实际上是long类型的变量)
	clock_t t1 = clock();

	// 一段计算
	mergeSort(nums);

	// 计算clock差，除以clock数/每秒，即可求出秒数
	// 将秒数乘以1000得到毫秒数
	cout << "归并排序 "<<nums.size()<<"个数字所花费时间: "<<(clock() - t1) * 1.0 / CLOCKS_PER_SEC*1000 << " ms " << endl;
}

/*int main()
{
	
	for (int i = 10; i < 1000000; i*=10) {
		vector<int> nums = makeRandNumArray(i);
		testQuickSort(nums);
		testHeapSort(nums);
		testMergeSort(nums);
		
	}
	getchar();
	return 0;
}*/