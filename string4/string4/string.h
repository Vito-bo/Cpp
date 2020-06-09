#include <assert.h>
//namespace Vitobo
//{
//	class string
//	{
//	public:
//		string()
//			:_str(nullptr)
//		{}
//		string(char* str)
//			:_str(str)
//		{}
//
//		size_t size()
//		{
//			return strlen(_str);
//		}
//
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//
//	private:
//		char* _str;
//	};
//	void Teststring1()
//	{
//		string s1("hello");
//		string s2;
//
//		for (size_t i = 0; i < s1.size(); ++i)
//		{
//			//"hello"是存放在代码段(常量区)的，是不能被修改的。多以报错
//			//s1[i] += 1;
//			//其它问题，一会再想插入字符，空间不够怎么办？
//			//在堆上开一个空间，拷贝过去，修改再拷贝回来
//			cout << s1[i] << " ";
//		}
//		cout << endl;
//	}
//}

//namespace Vitobo
//{
//	//实现一个简单的string -->深浅拷贝问题
//	class string
//	{
//	public:
//		/*string()
//			:_str(new char[1])
//		{
//			_str[0] = '\0';
//		}
//		
//		string(char* str)
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}*/
//		//构造函数(全缺省)
//		string(char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//
//		//拷贝构造
//		//string s2(s1)-->深拷贝
//		string(const string& s)
//			: _str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		//析构函数
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		//s1=s3
//		//s1=s1
//		string& operator=(const string& s)
//		{
//			//为了防止自己给自己赋值
//			if (this != &s)
//			{
//				char* tmp = new char[strlen(s._str) + 1];
//				strcpy(tmp, s._str);
//				delete[] _str;
//				_str = tmp;
//			}
//			return *this;
//		}
//
//		const char* c_str()
//		{
//			return _str;
//		}
//		 
//
//		size_t size()
//		{
//			return strlen(_str);
//		}
//
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//
//	private:
//		char* _str;
//	};
//
//	void Teststring1()
//	{
//		string s1("hello");
//		string s2;
//
//		for (size_t i = 0; i < s1.size(); ++i)
//		{
//			s1[i] += 1;
//			cout << s1[i] << " ";
//		}
//		cout << endl;
//
//		for (size_t i = 0; i < s2.size(); ++i)
//		{
//			s2[i] += 1;
//			cout << s2[i] << " ";
//		}
//		cout << endl;
//	}
//
//	void Teststring2()
//	{
//		string s1("hello");
//		string s2(s1);
//
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//
//		string s3("world");
//		//不写的话，调用系统的operator=会导致浅拷贝内存释放两次
//		s1 = s3;
//		cout << s1.c_str() << endl;
//		cout << s3.c_str() << endl;
//
//	}
//}

// 增删查改的string类模拟实现
namespace Vitobo
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		// s1(s2)
		string(const string& s)
		{
			// +1是开空间时永远保持给\0多开一个
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._size;

			/*_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;*/
		}

		// s1 = s2
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[s._size + 1];
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._size;
			}

			return *this;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* newstr = new char[n + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;

				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size) // 删除数据
			{
				_size = n;
				_str[_size] = '\0';
			}
			else // 插入数据
			{
				// 空间不够先增容
				if (n > _capacity)
					reserve(n);

				for (size_t i = _size; i < n; ++i)
					_str[i] = ch;
				_size = n;
				_str[_size] = '\0';
			}
		}

		// s1.push_back('x');
		void push_back(char ch)
		{
			// 增容
			if (_size == _capacity)
			{
				if (_capacity == 0)
				{
					reserve(2);
				}
				else
				{
					reserve(_capacity * 2);
				}
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		// s1.append("xxxxxxxxxx");
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_size + len);

			strcpy(_str + _size, str);
			_size += len;
		}

		// s1 += 'x'
		string& operator+=(char ch)
		{
			this->push_back(ch);
			return *this;
		}

		// s1 += "xxxxx"
		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}

			size_t end = _size;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}

			_str[pos] = ch;
			++_size;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size;
			while (end >= pos)
			{
				_str[end + len] = _str[end];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (_size - pos <= len)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
					return i;
			}

			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			const char* p = strstr(_str + pos, str);
			if (p == nullptr)
				return npos;
			else
				return p - _str;
		}

		// s1 < s2
		// 实现这两个，其他的比较复用实现
		bool operator<(const string& s)
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator==(const string& s)
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s)
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s)
		{
			return !(*this < s);
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

		size_t string::npos = -1;

		ostream& operator<<(ostream& out, const string& s)
		{
			for (size_t i = 0; i < s.size(); ++i)
			{
				out << s[i];
			}

			return out;
		}

		istream& operator>>(istream& in, string& s)
		{
			while (1)
			{
				char ch = in.get();
				if (ch == ' ' || ch == '\n')
					break;
				else
					s += ch;
			}
			return in;
		}

		void Teststring2()
		{
			string s1("hello");
			s1.insert(2, 'e');
			cout << s1 << endl;

			s1.insert(2, "world");
			cout << s1 << endl;

			string s2("hello world wrold");
			cout << s2 << endl;
			s2.erase(5, 6);
			cout << s2 << endl;

			//s2.erase(5);
			s2.erase(5, 10);
			cout << s2 << endl;

			string s;
			cin >> s;
			cout << s << endl;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};
}
