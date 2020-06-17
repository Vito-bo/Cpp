#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Test_vector1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v3);

	v1 = v4;
}

void Test_vector2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	//3种遍历方式
	for (size_t i = 0; i < v1.size(); ++i)
	{
		v1[i] *= 2;
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it1 = v1.begin();
	while (it1 != v1.end())
	{
		*it1 *= 2;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	for (auto& e : v1)
	{
		e *= 2;
		cout << e << " ";
	}
	cout << endl;

}

void Print(const vector<int>& v)
{
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int>::const_reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
void test_vector3()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	vector<int>::reverse_iterator rit1 = v1.rbegin();
	while (rit1 != v1.rend())
	{
		*rit1 *= 2;
		cout << *rit1 << " ";
		++rit1;
	}
	cout << endl;

	Print(v1);

	cout << v1.max_size() << endl;
}

void Test_vector4()
{
	// PJ（VS）1.5倍增容的
	// SGI(Linux) 2倍增容的
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	foo.reserve(100);  // 知道需要多大空间，提前一次性把空间开好，避免增容
	//foo.resize(100); // 开出空间的同时，对这些空间进行初始化
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	// O(N)
	v.insert(v.begin(), 0);
	v.insert(v.begin() + 2, 20);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin()); // O(N)
	v.erase(v.begin() + 3); // O(N)
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//vector<int>::iterator pos1 = find(v.begin(), v.end(), 3);
	auto pos1 = find(v.begin(), v.end(), 3);
	if (pos1 != v.end())
	{
		v.insert(pos1, 30);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos2 = find(v.begin(), v.end(), 2);
	if (pos2 != v.end())
	{
		v.erase(pos2);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	sort(v.begin(), v.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.clear();
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	//Test_vector1();
	//Test_vector2();
	//test_vector3();
	//Test_vector4();
	//test_vector5();
	test_vector6();

	return 0;
}