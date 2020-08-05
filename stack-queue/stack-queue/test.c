//stack的模拟实现
//从栈的接口中可以看出，栈实际是一种特殊的vector，因此使用vector完全可以模拟实现stack；
#include <iostream>
#include <vector>
using namespace std;

namespace Mystack
{
	template<class T>
	class stack
	{
	public:
		stack() {}

		void push(const T& x){
			_c.push_back(x);
		}

		void pop(){
			_c.pop_back();
		}

		T& top()const{
			return _c.back();
		}

		const T& top() const{
			return _c.back();
		}

		size_t size() const{
			return _c.size();
		}

		bool empty()const{
			return _c.empty();
		}

	private:
		vector<T> _c;
	};
}

//queue的模拟实现
//因为queue接口中存在头删和尾插，借助list模拟实现queue
#include <list>
namespace Myqueue
{
	template<class T>
	class queue
	{
	public:
		queue(){}

		void push(const T& x){
			_c.push_back(x);
		}

		void pop(){
			_c.pop_front();
		}

		T& back(){
			return _c.front();
		}

		const T& back()const{
			return _c..front();
		}

		T& front(){
			return _c.front();
		}

		size_t size()const{
			return _c.size;
		}

		bool empty()const{
			return _c.empty();
		}
	private:
		list<T> _c;
	};
}