#include<iostream>
#include<string>
#include<vector>
using namespace  std;

class Message {
public:
	Message() {
		cout << "message ����" << endl;
	};
	virtual ~Message() { };
	virtual string getType()=0;
	virtual void showMessage()=0;
};
class Type {
public:
	Type() {
		cout << "type" << endl;
	}
	virtual void addType() { cout << "addType" << endl; };
	virtual void deleteType() { cout << "deleteType" << endl; };
};
class QueryMessage:public Message,private Type {
public:
	QueryMessage() {
		cout << "Qeymessage ����" << endl;
	};
	QueryMessage(string t) :type(t) { 
		cout << "QueryMessage ����" << endl;
	};
	void showMessage()override {
		cout << type << endl;
	}
	string getType() {
		return type;
	}
private:
	string type;
};
class AnswerMessage :public Message,Type {
public:
	AnswerMessage() {
		cout << "Ansmessage ����" << endl;
	};
	AnswerMessage(string t) :type(t) {
		cout << "AnswerMessage ����" << endl;
	};
	void showMessage()override {
		cout << type << endl;
	}
	virtual string getType() {
		return type;
	}
	virtual void changType(const string& a) {
		cout << "aa" << endl;
	};
	virtual void ShowType(const string& a) {
		cout << type << endl;
	};
	
private:
	string type;
};
class DriverClass :public AnswerMessage {

};
/*QueryMessage a("Jense");
AnswerMessage b("Lucy");
DriverClass d;
int main() {
	cout << " message size : " << sizeof(Message) << " QueryMessage Size: " << sizeof(QueryMessage) << " AnswerMessage: " << sizeof(AnswerMessage) << endl;
	//QueryMessage a("Jense");
	a.showMessage();
	//AnswerMessage b("Lucy");
	cout << b.getType() << endl;
	int *dAddress = (int*)&d;

	// 1. ��ȡ������ڴ沼����Ϣ 
	// ����ַ
	int *vtptr = (int*)*(dAddress + 0);
	// 2. ���������ڴ沼����Ϣ
	int *pFunc1 = (int *)*(vtptr + 0);
	int *pFunc2 = (int *)*(vtptr + 1);
	int *pFunc3 = (int *)*(vtptr + 2);
	int *pdFunc1 = (int *)*(vtptr + 3);

	

	printf("\t vfunc1addr: 0x%08x \n"
		"\t vfunc2addr: 0x%08x \n"
		"\t vfunc3addr: 0x%08x \n"
		"\t vdfunc1addr: 0x%08x \n\n",
		pFunc1,
		pFunc2,
		pFunc3,
		pdFunc1
	);
	cout << "hello world" << endl;
	getchar();
	return 0;
}*/