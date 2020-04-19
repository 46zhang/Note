#pragma once
#include<string>

template  <typename T>
class Message {
public:
	Message(){ }
	Message(T& a ) :data(a){  }
	T showMessage();
private :
	std::string data;
	//std::string name;
};
/*template<typename T>
typename T Message<T> ::showMessage() {
	return data;
}*/