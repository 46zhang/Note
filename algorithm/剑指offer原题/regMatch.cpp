#include <iostream>
/*
�㷨���ƣ�������ʽƥ��
�㷨��Դ����ָOffer ������19
�㷨˼�룺		���ж�ģʽ�ַ����ڶ����Ƿ���* ���ǵĻ�����Ҫ������һЩ���⴦��
					��2��ѡ��
					(1).ģʽ�ַ�����һ��=�ַ���||ģʽ�ַ�����һ��Ϊ��.����Ŀ���ַ�����Ϊ��
							������3��ѡ�� 
								a.ģʽ�ַ���,Ŀ���ַ���+1,�����ݹ���ȥ���൱��*ƥ����n���ַ�
								b.ģʽ�ַ���+2��Ŀ���ַ���,�൱�� * ƥ��0���ַ�
								c.ģʽ�ַ���+2,Ŀ���ַ���+1,�൱��*ƥ��1���ַ�
					(2). ģʽ�ַ�����һ����=Ŀ���ַ�����һ��&&ģʽ�ַ�����һ����Ϊ��.������Ŀ���ַ���Ϊ��
						ģʽ�ַ���+2��Ŀ���ַ���,�൱�� * ƥ��0���ַ�

�㷨ע�⣺		1.�ݹ����������
				2.���ж�ģʽ�ַ����Ƿ�Ϊ"."ʱҪע���ʱ��Ŀ���ַ����Ƿ�λ��
�㷨Ч�ʷ���:	1.nlog(n)
�㷨ʵ��ʱ��:	�㷨1 ���˰��Сʱʵ���㷨������1��Сʱdebug��̫���ˣ�һֵûȥע��ü�
					��ģʽ�ַ����Ƿ�Ϊ"."ʱҪע���ʱ��Ŀ���ַ����Ƿ�λ��

*/
bool match(char *str,char *mode) {
	std::cout << str << "  " << mode<<std::endl;
	if (*str == '\0' && *mode == '\0')
	{
		std::cout << "��ΪNull��" << std::endl;
		return true;
	}
	else if (*str == '\0' || *mode == '\0') {
		std::cout << "sdsdf" << std::endl;
		return false;
	}
		
	int len = strlen(mode);
	bool s = false;
	if (len > 1 && mode[1] == '*') {
		if (str[0] == mode[0] ||( mode[0] == '.'&&*str!='\0')) {
			std::cout << "2131" << std::endl;
			return match(str, mode + 2) || match(str + 1, mode) || match(str + 1, mode + 2);
		}
		else
			return match(str, mode + 2);
	}
	else {
		if (mode[0] == str[0] || (mode[0] == '.'&& *str != '\0'))
			return  match(str + 1, mode + 1);
		
	}
	return false;
		
}
bool matchAll(char *str, char *mode)
{
	if (str == nullptr || mode == nullptr)
		return false;
	return match(str, mode);
}
void reMatch() {
	//char str[20] = "bcbbabab";
	//char mode1[20] = ".*a*a",mode2[20]="ab*ac*afdb";
	char str[20] = "a";
	char mode1[20] = ".*",mode2[20]="ab*ac*afdb";
	bool s1 = matchAll(str, mode1);
	bool s2 = matchAll(str, mode2);
	if (s1)
		std::cout << "��ģʽ1ƥ��" << std::endl;
	else
		std::cout << "��ģʽ1��ƥ��" << std::endl;
	if (s2)
		std::cout << "��ģʽ2ƥ��" << std::endl;
	else
		std::cout << "��ģʽ2��ƥ��" << std::endl;
}