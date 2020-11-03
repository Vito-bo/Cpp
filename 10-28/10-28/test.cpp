
#include<iostream>
using namespace std;
#include<assert.h>

#if 0
//模板
笔试题：写一个通用类型的加法函数？
写与类型无关的代码，最好的方法就是使用模板
模板：铸造物体所使用的模具。
	 模板不是真正的函数。
模板：可以实现一些与类型无关的代码
泛型编程：与类型无关，与数据结构无关
模板是泛型编程的基础。

注意：函数模型并不是真正的函数
而是用户告诉编译器生成代码的规则

函数模板原理：
1.隐式实例化：没有明确指明模板参数列表T的实际类型
	在编译阶段，编译器需要对传递的实参类型进行推演
	推演的结果来确定模板参数列表中T的实际类型。
	如果T的类型可以确定，则处理生成具体类型的函数。
	如果T的类型无法确定，则报错
2.显式实例化：明确指明了模板参数列表中T的实际类型
	编译器直接根据用户所提供的T的类型来生成处理具体类型的函数
	将函数生成之后，如果发现类型不匹配，则会进行隐式类型转换
	如果转化成功，则编译通过
	如果转化失败，则报错
#endif 

#if 0
//模板函数
template<class T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	//隐式实例化:让编译器根据实参推演参数的实际类型
	Add(1, 2);        //Add<int>
	Add(1.0, 2.0);    //Add<double>
	Add('1', '2');     //Add<char>
	Add(1, (int)2.0); //Add<int>

	//显式实例化：在函数名后的<>中指定模板参数的实际类型
	Add<int>(1, 2.0);
	//Add(1, 2.0);//编译失败

	return 0;
}

//对于非模板函数和同名函数模板，如果其它条件都相同，在调用时优先匹配非模板函数
//模板函数不允许自动类型转换，但普通函数可以进行自动类型转换
//非模板类函数
int Add(int left, int right)
{
	return left + right;
}
//模板类函数
template<class T1,class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}
int main()
{
	Add(1, 2); //与非模板类函数匹配，编译器不需要特化
	Add(1, 2.5);//调用编译器特化的Add版本
	return 0;
}
#endif 

//类模板--并不是真正的类，而实例化的结果才是真正得类。
//顺序表
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

	SeqList(const SeqList<T>&);
	SeqList<T>& operator=(const SeqList<T>&);

	//使用析构函数演示：在类中声明，在类外定义
	~SeqList();

	size_t size() const
	{
		return _size;
	}

	size_t capacity() const
	{
		return _capacity;
	}
	bool empty() const
	{
		return 0 == _size;
	}
	void push_back(const T& data)
	{
		//空间足够
		_array[_size++] = data;
	}

	void pop_back()
	{
		--_size;
	}

	// 临时标量具有常性，不能改变
	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}
	const T& operator[](size_t index) const
	{
		assert(index < _size);
		return _array[index];
	}

private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

//注意：类模板在类外进行定义时，需要加模板参数列表
template<class T>
SeqList<T>::~SeqList()
{
	if (_array)
	{
		delete[] _array;
		_capacity = 0;
		_size = 0;

	}
}

int main()
{
	SeqList<int> s;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);

	cout << s.size() << endl;
	cout << s.capacity() << endl;

	cout << s[0] << endl;
	s[0] = 20;

	cout << s[0] << endl;

	const SeqList<int> s2;
	//s2[0];    //const类型的对象，是不能调用普通成员函数的
	return 0;
}
 