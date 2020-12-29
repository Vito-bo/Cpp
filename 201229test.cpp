
/*
// 蓝桥杯训练
#include <iostream>
using namespace std;
#define N 1000001
#define M 10007

int n, i, arr[N];
int main()
{
	cin >> n;
	arr[1] = 1;
	arr[2] = 1;
	for (i = 3; i<=n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2])%M;
	cout << arr[n] << endl;
	return 0;
}

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int r;
	cin >> r;
	double s;
	double PI = atan(1.0) * 4;
	s = PI*r*r;
	printf("%.7lf\n", s); //输出双精度浮点型数据
	return 0;
}

#include <iostream>
using namespace std;
#define N 1000000001

int main()
{
	int n;
	cin >> n;
	long long ret;
	ret = n*(n + 1) / 2;
	printf("%I64d\n", ret);
	return 0;
}
*/

//剑指offer35-复杂链表复制
class Node
{
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val)
	{
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head) return head;
		copyNodes(head); // 拷贝 value 和 next
		copyRandom(head); // 拷贝 random
		return getCopy(head); // 提取出新的链表
	}
	void copyNodes(Node* head)
	{
		// 将 a -> b -> c 的链表变成 a -> a' -> b -> b' -> c -> c'
		if (!head) return;
		Node* pos = head;
		while (pos)
		{
			Node* copy = new Node(pos->val);
			Node* nextPtr = pos->next;
			pos->next = copy;
			copy->next = nextPtr;
			pos = copy->next;
		}
	}
	void copyRandom(Node* head)
	{
		if (!head) return;
		Node* pos = head;
		while (pos)
		{
			// 例：a -> a' -> b -> b' -> c -> c'
			// 假如 a -> random存在，则 a' -> random 一定等于 a -> random -> next
			// 假如 a -> random不存在，则 a' -> random == nullptr
			Node* copy = pos->next;
			Node* oldRandom = pos->random;
			if (oldRandom) copy->random = oldRandom->next;
			else copy->random = nullptr;
			pos = copy->next;
		}
	}
	Node* getCopy(Node* head)
	{
		if (!head) return head;
		Node* pos = head;
		Node* copy = pos->next;
		Node* newHead = copy;
		while (pos)
		{
			// 将原链表与复制出的链表提取成两条单独的链表，并返回复制出的链表
			pos->next = copy->next;
			pos = pos->next;
			if (pos) copy->next = pos->next;
			copy = copy->next;
		}
		return newHead;
	}
};

//剑指offer147对链表进行插入排序
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;     //设置一个呀节点在head节点之前。
		ListNode* lastSorted = head; //设置链表已排序部分的最后一个节点
		ListNode* cur = head->next;  //维护cur为待插入的节点

		while (cur != nullptr)
		{
			if (lastSorted->val <= cur->val)
			{
				lastSorted = lastSorted->next;
			}
			else
			{
				ListNode* prev = dummyHead;
				while (prev->next->val <= cur->val)
				{
					prev = prev->next;
				}
				lastSorted->next = cur->next;
				cur->next = prev->next;
				prev->next = cur;
			}
			cur = lastSorted->next;
		}
		return dummyHead->next;

	}
};