#include<iostream>
#include<string>
#include<vector>
using namespace std;

int findString(const vector<string>& aim,const string target) {
	int left = 0, right = aim.size() - 1,mid;
	int res(-1);
	if (target.empty())
		return res;
	while (left <= right) {
		mid = (left + right) / 2;
		while (mid > left && aim[mid].empty())
			--mid;
		//全部为NULL
		if (aim[mid].empty())
			left = mid + 1;
		else if (aim[mid] == target) {
			res = mid;
			//找到最左的target
			while (--mid >= left)
				if (aim[mid] == target)
					res = mid;
				else if(!aim[mid].empty())
					break;
			return res;
		}
		else if (aim[mid] > target)
			right = mid - 1;
		else if (aim[mid] < target)
			left = mid + 1;
	}
	return res;
}

/*int main() {
	vector<string> str1{ "","a","","","a","b","b","c" };
	cout << findString(str1,"a") << endl;
	cout << findString(str1, "b") << endl;
	cout << findString(str1, "c") << endl;

	vector<string> str2{ "","a","","","a","","b","","b","","","b","","","c","","","","c" };
	cout << findString(str2, "a") << endl;
	cout << findString(str2, "b") << endl;
	cout << findString(str2, "c") << endl;

	vector<string> str3{ "","a","","","b","","","" };
	cout << findString(str3, "a") << endl;
	cout << findString(str3, "b") << endl;
	cout << findString(str3, "c") << endl;

	vector<string> str4{ "","","","","","","","b" };
	cout << findString(str4, "a") << endl;
	cout << findString(str4, "b") << endl;
	cout << findString(str4, "c") << endl;
	getchar();
	return 0;
}*/