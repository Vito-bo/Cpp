//list的模拟实现
namespace myList
{
	// List的结点类
	template<class T>
	class ListNode
	{
	public:
		ListNode(const T& val = T())
			: _data(val)
			, _next(nullptr)
			, _prev(nullptr)
		{}
		T _data;
		ListNode<T>* _next;
		ListNode<T>* _prev;
	};

	// List的迭代器
	template<class T, class Ref, class Ptr>	
	class ListIterator
	{
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
		PNode _node;

		ListIterator(PNode node)
			:_node(node)
		{}

		// T& *iterator()
		Ref operator*()
		{
			return _node->_data;
		}

		// T* operator->()
		Ptr operator->()
		{
			return &(_node->_data);
		}

		// ++iterator _node->_next
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	// List的反向迭代器
	// 传参的时候根据模板推演参数类型
	template<class T, class Ref, class Ptr, class Iterator>	
	class ListReverseIterator
	{
		typedef ListReverseIterator<T, Ref, Ptr, Iterator> Self;
	public:
		ListReverseIterator(const Iterator& it)
			:_it(it)
		{}

		ListReverseIterator(const Self& s)
			:_it(s._it)
		{}

		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);	//正向迭代器和反向迭代器是前后的。反向迭代器当前位置的下一个位置是正向迭代器的当前位置。
		}

		Ptr operator->()
		{
			return &operator*();
		}

		//前置++，反向迭代器的++就是正向迭代器的--
		Self& operator++()	//前置返回引用
		{
			--_it;
			return *this;
		}

		Self operator++(int)
		{
			Iterator temp(_it);		//调用正向迭代器的构造方法
			--_it;
			return temp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self operator--(int)
		{
			Iterator temp(_it);
			++_it;
			return temp;
		}

		bool operator==(const Self& s)
		{
			return _it == s._it;
		}

		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}

	private:
		Iterator _it;		//封装正向迭代器，底层调用的是const和非const的正向迭代器
	};

	template<class T>
	class List
	{
	public:
		typedef ListNode<T> Node;
		typedef Node* PNode;
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
		typedef ListReverseIterator<T, const T&, const T*, iterator> reverse_iterator;
		typedef ListReverseIterator<T, const T&, const T*, const_iterator> const_reverse_iterator;
		///////////////////////////////////////////////////////////////////////////////////////////
		// list的构造
		List()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		List(int n, const T& value = T())
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			for (int i = 0; i < n; ++i){
				PushBack(value);
			}
		}

		template<class Iterator>
		List(Iterator first, Iterator last)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			while (first != last){
				PushBack(*first);
				++first;
			}
		}

		List(const List<T>& l)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			List<T> temp(l.cbegin(), l.cend());
			swap(_head, temp._head);
		}

		List<T>& operator=(List<T> l)	//现代版写法，传值会调用构造，创建出临时变量，交换this的指针指向，
			//临时变量出作用域会销毁
		{
			swap(_head, l._head);
			return *this;
		}

		~List()
		{
			if (_head)
			{
				PNode cur = _head->_next;
				while (cur != _head)
				{
					PNode next = cur->_next;
					delete cur;
					cur = next;
				}
				delete _head;
				_head = nullptr;
			}
		}

		////////////////////////////////////////////////////////////////////
		//迭代器
		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator cbegin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator cend() const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());	//end()传入相当传入iterator(_head)然后调用反向迭代器的构造函数
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator crbegin() const
		{
			return const_reverse_iterator(cend());
		}

		const_reverse_iterator crend() const
		{
			return const_reverse_iterator(cbegin());
		}

		///////////////////////////////////////////////////////////////////////
		// List element Access
		T& Front()
		{
			return _head->_next->_data;
		}

		const T& Front() const
		{
			return _head->_next->_data;
		}

		T& Back()
		{
			return _head->_prev->_data;
		}

		const T& Back() const
		{
			return _head->_prev->_data;
		}

		/////////////////////////////////////////////////////////////////////////////
		// List Modifiers
		// 在list首元素前插入值为val的元素
		void PushFront(const T& val)
		{
			PNode newnode = new Node(val);
			newnode->_prev = _head;
			newnode->_next = _head->_next;
			_head->_next->_prev = newnode;
			_head->_next = newnode;
		}

		// 删除list中第一个元素
		void PopFront()
		{
			PNode cur = _head->_next;
			if (cur != _head){
				_head->_next = cur->_next;
				cur->_next->_prev = _head;
				delete cur;
			}
		}

		// 在list尾部插入值为val的元素
		void PushBack(const T& val)
		{
			PNode newNode = new Node(val);
			PNode prev = _head->_prev;
			prev->_next = newNode;
			newNode->_prev = prev;
			newNode->_next = _head;
			_head->_prev = newNode;
		}

		// 删除list中最后一个元素
		void PopBack()
		{
			//找到要删除的结点，也就是头结点的前一个就是最后一个结点
			PNode del = _head->_prev;
			//只有一个头结点不能删除
			if (del != _head){
				_head->_prev = del->_prev;
				del->_prev->_next = _head;
				delete del;
			}
		}
		
		// 在pos位置前插入值为val的元素
		iterator Insert(iterator pos, const T& val)
		{
			PNode newnode = new Node(val);
			//pos是迭代器，要取到pos位置的结点
			PNode cur = pos._node;
			newnode->_next = cur;
			newnode->_prev = cur->_prev;
			newnode->_prev->_next = newnode;
			cur->_prev = newnode;

			return iterator(newnode);
		}


		// 删除pos位置的结点，返回该结点的下一个位置
		iterator Erase(iterator pos)
		{
			//保存pos位置的结点以及pos位置结点的前一个结点和后一个结点
			PNode del = pos._node;
			PNode prev = del->_prev;
			PNode next = del->_next;
			//注意不能删除头结点
			if (del != _head){
				prev->_next = next;
				next->_prev = prev;

				delete del;
				del = nullptr;

				//更新迭代器
				pos = iterator(next);
			}
			return pos;
		}

		// 清空list中的有效元素
		void Clear()
		{
			PNode cur = _head->_next;
			while (cur != _head){
				PNode next = cur->_next;
				delete cur;
				cur = next;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}

		//////////////////////////////////////////////////////////////
		// List Capacity
		// 返回list中有效节点的个数
		size_t Size() const
		{
			size_t count = 0;
			PNode cur = _head->_next;
			while (cur != _head){
				++count;
				cur = cur->_next;
			}
			return count;
		}

		// 检测list是否为空，是返回true,否则返回false
		bool Empty() const
		{
			return _head->_next == _head;
		}

		void ReSize(size_t newSize, const T& val = T())
		{
			size_t oldSize = Size();
			if (oldSize <= newSize){
				for (size_t i = oldSize; i < newSize; ++i){
					PushBack(val);
				}
			}
			else{
				for (size_t i = newSize; i < oldSize; ++i){
					PopBack();
				}
			}
		}
	private:
		PNode _head;
	};
}