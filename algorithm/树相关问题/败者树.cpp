#include<iostream>
#include<vector>
using namespace std;
const int K = 5;//表示5路归并
const int loser = INT_MIN;
const int len = 4;
class LoserTree {
public:
	LoserTree(int value, vector<int>& data) :k(value) {
		for (int i = 0; i < k; ++i) {
			lt.push_back(k);
		}
	
		
	}
	void adjust(int index, vector<int>& data) {
		int t = (index + k) / 2;
		while (t > 0) {
			/*cout << " t: " << t << " index: " << index << " data[index]: " << data[index] <<
				" lt[index] " << lt[index] << "  data[lt[index]] " << data[lt[index]] << endl;*/
			if (data[index] > data[lt[t]])
				swap(index, lt[t]);
			
			t /= 2;
		}
		lt[0] = index;
	}
	vector<int> lt;
private:
	int k;
	
};

class SortArray {
public:
	SortArray(int p, int l, vector<int>& a) :pos(p), len(l),data(a){
		
	}
	vector<int > data;
	int pos = 0;
private:
	int len;
	
};


void kMerge(LoserTree & lt,vector<int>& extral, vector<SortArray *>& files) {
	for (int i = K - 1; i >= 0; i--)
		lt.adjust(i, extral); //加入一个基点，要进行调整
	for (auto a : lt.lt)
		cout << a << " ";
	cout << endl;
	for (int i = 0; i < K*len; ++i) {
		int key = lt.lt[0];
		cout << files[key]->data[files[key]->pos-1]<<" ";
		extral[key]= files[key]->data[files[key]->pos++];
		lt.adjust(key, extral);
	}
	
}

/*int main() {
	vector<vector<int>> data{ { 1,2,3,5 } ,{ 7,8,11,15 } ,{ 0,2,3,15 } ,{ 6,12,13,25 } , { -3,12,63,75 } };
	vector<SortArray *> files(K);
	for (int i = 0; i < K; ++i)
	{
		files[i] = new SortArray(0, len, data[i]);
	}
	vector<int > extral(K+1);
	LoserTree lt(K, extral);
	for (int j = 0; j < K; ++j) {
		
		extral[j] = files[j]->data[0];
		files[j]->pos++;
	}
	extral[K] = INT_MIN;
	kMerge(lt, extral, files);
	for (int i = 0; i < K; ++i)
		delete files[i];
	getchar();
	return 0;
}*/