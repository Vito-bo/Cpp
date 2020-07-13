//每日一题7-11
//1.有理数运算
#include <iostream>
#include <cmath>
//long long是两个关键字拼起来的，用起来很不方便，重命名一下
typedef long long _sint64;
//有理数类的声明
class RationalNumber{
	bool m_infinate; //处理除数为零
	bool m_negative; //处理负数
	_sint64 m_numerator; //分子，方便输出
	_sint64 m_denominator; //分母
	_sint64 m_integer; //整数部分
	_sint64 m_numeratorAll; //记录无整数分数的分子，方便进行运算
	_sint64 calcGCD(_sint64 a, _sint64 b); //求最大公约数的函数
public:
	RationalNumber(_sint64 numerator, _sint64 denominator); //构造函数
	RationalNumber operator+(RationalNumber const& o) const; //四则运算重载
	RationalNumber operator-(RationalNumber const& o) const;
	RationalNumber operator*(RationalNumber const& o) const;
	RationalNumber operator/(RationalNumber const& o) const;
	//输出流运算符重载
	friend std::ostream &operator<<(std::ostream &os, RationalNumber const& o);
};
//有理数类每个方法的实现
_sint64 RationalNumber::calcGCD(_sint64 a, _sint64 b)
{
	if (b == 0)
	{
		return a;
	}
	//辗转相除法
	return calcGCD(b, a % b);
}
RationalNumber::RationalNumber(_sint64 numerator, _sint64 denominator)
{
	m_negative = false;
	m_infinate = false;
	//处理分母为零的情况
	if (denominator == 0)
	{
		m_infinate = true;
		return;
	}
	//这里这样写，是因为在通过计算结果进行构造过程中，有可能出现分子分母均为负的情况。
	if (numerator < 0)
	{
		m_negative = !m_negative;
	}
	if (denominator < 0)
	{
		m_negative = !m_negative;
	}
	//计算整数、分子、分母。其中分母要参与下面的运算，所以不能是负的，用abs取绝对值，分子要保留原值
	m_integer = numerator / denominator;
	m_numerator = numerator - m_integer * denominator;
	m_denominator = abs(denominator);
	//约分，注意传给子函数的分子必须是正的，分母上面处理过了
	if (m_numerator)
	{
		_sint64 maxtmp = calcGCD(abs(m_numerator), m_denominator);
		if (maxtmp)
		{
			m_numerator /= maxtmp;
			m_denominator /= maxtmp;
		}
	}
	//计算约分后假分数版的分子，因为后续运算是不需要整数部分的，所以必须用假分数的分子算。
	m_numeratorAll = m_numerator + m_integer * m_denominator;
}
//以下为分数的加减乘除，统统使用m_numeratorAll（假分数的分子）进行运算。
RationalNumber RationalNumber::operator+(RationalNumber const& o) const
{
	_sint64 numerator = (m_numeratorAll * o.m_denominator) +
		(o.m_numeratorAll * m_denominator);
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
}
RationalNumber RationalNumber::operator-(RationalNumber const& o) const
{
	_sint64 numerator = (m_numeratorAll * o.m_denominator) -
		(o.m_numeratorAll * m_denominator);
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
}
RationalNumber RationalNumber::operator*(RationalNumber const& o) const
{
	_sint64 numerator = m_numeratorAll * o.m_numeratorAll;
	_sint64 denominator = m_denominator * o.m_denominator;
	return RationalNumber(numerator, denominator);
}
RationalNumber RationalNumber::operator/(RationalNumber const& o) const
{
	_sint64 numerator = m_numeratorAll * o.m_denominator;
	_sint64 denominator = m_denominator * o.m_numeratorAll;
	return RationalNumber(numerator, denominator);
}
std::ostream &operator<<(std::ostream &os, RationalNumber const& o)
{
	//分母为0的情况就不用继续了
	if (o.m_infinate)
	{
		os << "Inf";
		return os;
	}
	//整数和分子为0那干脆就是0了
	if (o.m_numerator == 0 && o.m_integer == 0)
	{
		os << "0";
		return os;
	}
	//负数打印括号和负号
	if (o.m_negative)
	{
		os << "(-";
	}
	//有整数就打整数
	if (o.m_integer)
	{
		os << abs(o.m_integer);
		if (o.m_numerator) //整数小数都有就打个空格隔开
		{
			os << " ";
		}
	}
	//有分数就打分数，分母已经abs过了，这里可以不用
	if (o.m_numerator)
	{
		os << abs(o.m_numerator) << '/' << o.m_denominator;
	}
	//负数的后半边括号
	if (o.m_negative)
	{
		os << ")";
	}
	return os;
}
int main()
{
	_sint64 n1, d1, n2, d2;
	scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);
	RationalNumber rn1(n1, d1), rn2(n2, d2);
	//轻松+愉快的使用函数时间
	std::cout << rn1 << " + " << rn2 << " = " << rn1 + rn2 << '\n';
	std::cout << rn1 << " - " << rn2 << " = " << rn1 - rn2 << '\n';
	std::cout << rn1 << " * " << rn2 << " = " << rn1 * rn2 << '\n';
	std::cout << rn1 << " / " << rn2 << " = " << rn1 / rn2 << '\n';
	return 0;
}
//2.前序和后序
#include <string>
#include <tuple>
#include <list>
#include <cstdio>
// 求n的阶乘
long long factorial(int n)
{
	long long r = 1;
	for (int i = 1; i <= n; i++)
	{
		r *= i;
	}
	return r;
}
// 求 n, m 的组合 C(n, m)
// 利用 C(n, m) == C(n, n - m) 的特点，计算容易的
long long combination(int n, int m)
{
	int max = m > (n - m) ? m : (n - m);
	long long numerator = 1;
	for (int i = max + 1; i <= n; i++)
	{
		numerator *= i;
	}
	return numerator / factorial(n - max);
}
// 重命名类型，类似于 typedef 作用
using PrePost = std::tuple<std::string, std::string>;
// 给出一棵树的前序+后序，利用最上面注释的原理
// 把每棵子树的前序+后序切分出来
std::list<PrePost> splitSubTrees(std::string const& pre, std::string const& post)
{
	std::list<PrePost> list{};
	size_t preIdx = 1;
	size_t lastPost = 0;
	while (preIdx < pre.size())
	{
		char rootValue = pre[preIdx];
		size_t postIdx = post.find(rootValue);
		int countOfNode = postIdx - lastPost + 1;
		list.emplace_back(std::make_tuple(
			pre.substr(preIdx, countOfNode),
			post.substr(lastPost, countOfNode)
			)
			);
		preIdx += countOfNode;
		lastPost += countOfNode;
	}
	return list;
}
// 递归的求解每一层的可能性，直到树中只剩一个或者零个结点
long long calculateNumOfPossibilities(int m,
	std::string const& pre,
	std::string const& post)
{
	if (pre.size() == 0 || pre.size() == 1) {
		return 1;
	}
	std::list<PrePost> subTrees = splitSubTrees(pre, post);
	long long result = combination(m, subTrees.size());
	for (PrePost const& prePost : subTrees)
	{
		result *= calculateNumOfPossibilities(m,
			std::get<0>(prePost),
			std::get<1>(prePost));
	}
	return result;
}

int main()
{
	int m;
	char pre[30];
	char post[30];
	while (scanf("%d %s %s", &m, pre, post) != EOF)
	{
		printf("%lld\n", calculateNumOfPossibilities(m, pre, post));
	}
	return 0;
}
