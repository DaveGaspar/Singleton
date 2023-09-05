#include <iostream>

class Singleton{
private:
	int data;
public:
	static Singleton* objectPtr;
	
	void set_data(int i){
		data = i;
	}
	int get_data(){
		return data;
	}

	static Singleton* createObject(){
		if (objectPtr == nullptr){
			objectPtr = new Singleton();
			return objectPtr;
		}
		return objectPtr;
	}

	static void destroyObject(){
		if (objectPtr != nullptr){
			delete objectPtr;
			objectPtr = nullptr;
		}
	}

private:
	Singleton(){
	}
public:
	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;
};

Singleton* Singleton::objectPtr = nullptr;

int main(){

	Singleton* obj1 = Singleton::createObject();
	obj1->set_data(5);

	std::cout << obj1->get_data() << std::endl;

	Singleton* obj2 = Singleton::createObject();
	std::cout << obj2->get_data() << std::endl;
	
	obj2->set_data(7);

	std::cout << obj1->get_data() << std::endl;
	std::cout << obj2->get_data() << std::endl;

	obj1->destroyObject();
	obj2->destroyObject();

	return 0;
}