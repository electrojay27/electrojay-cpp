#include <bits/stdc++.h>

// class Stack
// {
// private:
// 	std::vector<T> s;
// public:
// 	void push(T x){};
// 	T pop(){};
// 	int Find(T x){
// 		for(int i = 1;i <= size;i ++){
// 			if(s[i] == x)return i;
// 		}
// 		return -1;//不存在
// 	}
// }
template <typename T>
class TypeToID
{
public:
	static int const ID = 0;
};
template <typename T>
class TypeToID<T*>
{
public:
	static int const ID = 12345;
};


// template <>
// class TypeToID<int>
// {
// public:
// 	static int const ID = 1;
// };
// template <>
// class TypeToID<float>
// {
// public:
// 	static int const ID = 0xF1047;
// };
// template <>
// class TypeToID<void*>
// {
// public:
// 	static int const ID = 0x401d;
// };
void PrintID(){
	std::cout << "INTID: " << TypeToID<int>::ID << std::endl;
	std::cout << "FLOATID: " << TypeToID<float>::ID << std::endl; 
	std::cout << "VOID*ID: " << TypeToID<double>::ID << std::endl;
}

int main()
{
	PrintID();
}
