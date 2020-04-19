#include <iostream>
#include <windows.h>

/*int main()
{
	typedef int(*_pAdd)(int a, int b);
	typedef int(*_pSub)(int a, int b);
	HINSTANCE hDll = LoadLibrary("JenseDLL.dll");
	int nParam1 = 9;
	int nParam2 = 3;
	_pAdd pAdd = (_pAdd)GetProcAddress(hDll, "add");
	_pSub pSub = (_pSub)GetProcAddress(hDll, "sub");
	int nAdd = pAdd(nParam1, nParam2);
	int nSub = pSub(nParam1, nParam2);
	std::cout << nAdd << ":" << nSub << std::endl;
	FreeLibrary(hDll);
	system("pause");
	return 0;
}*/