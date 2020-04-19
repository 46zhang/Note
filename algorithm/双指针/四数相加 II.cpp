#include<iostream>
#include<map>
#include<vector>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	map<int, int>sum;
	if (A.size() <= 0 || B.size() <= 0 || C.size() <= 0 || D.size() <= 0)
		return 0;
	for (auto a: A) {
		for (auto b : B)
			sum[a + b]++;
	}

	for (auto iter = sum.begin(); iter != sum.end(); ++iter) 
		std::cout << iter->first << "  " << iter->second<<std::endl;
	
	int time = 0;
	for (auto c : C) {
		for (auto d : D)
			time += sum[-(c + d)];
	}
	return time;
}


void fourSumCountTest() {
	vector<int >A{ 1, 2 };
	vector<int >B{ -2, -1 };
	vector<int >C{ -1, 2 };
	vector<int >D{ 0, 2 };
	int a = fourSumCount(A, B, C, D);
	std::cout << a << std::endl;
}