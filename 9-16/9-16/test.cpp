
#include <iostream>
using namespace std;

////没有返回值,没有参数
////在C语言中：一下代码可以通过编译
////在C++语言中：以下代码不能通过编译
////C++编译器比C语言编译器语法检查更加严格
//void Test()
//{}
//int main()
//{
//	Test();
//	Test(10);
//	Test(10,20);
//	Test(10,20,30);
//	return 0;
//}

////在C语言中：以下函数可以通过编译，因为没有显示写返回值类型时，C语言编译器默认函数返回整形
////在C++中：以下函数不能通过编译
//TestFunc(void)
//{}
//int main()
//{
//	int ret = TestFunc();
//	printf("%d\n", ret);
//	return 0;
//}

////缺省参数：在定义函数时，可以给函数的参数指定一个默认值
//void Test3(int a=10, int b=20)
//{
//	printf("%d %d\n", a, b);
//}
//int main()
//{
//	Test3(10, 20);
//	Test3(10, 20);
//	Test3(10, 20);
//	Test3(10, 20);
//	Test3(10, 20);
//	Test3(10, 20);
//	Test3(10, 20);
//	Test3(10, 20);
//	//上述调用中，每次调用传递的都是同一组实参
//	//不想传递，但是让该函数执行起来后，还可以拿到实参10,20
//	//C++允许给函数实参设置默认值，调用起来可以不用传参
//	Test3();
//	Test3(30,40);
//	Test3(300,400);
//	return 0;
//}

////缺省参数分类：
////1.全缺省参数：每个参数都带有默认值
//void Test4(int a=1, int b=2, int c=3)
//{
//	cout << "a=" << a;
//	cout << "b=" << b;
//	cout << "c=" << c;
//	cout << endl;
//}
//int main()
//{
//	Test4();        //1,2,3
//	Test4(10);      //10,2,3
//	Test4(10,20);   //10,20,3
//	Test4(10,20,30);//10,20,30
//	return 0;
//}

//2.半缺省参数：部分参数带有默认值
void Test4(int a, int b = 2, int c = 3)
{
	cout << "a=" << a;
	cout << "b=" << b;
	cout << "c=" << c;
	cout << endl;
}
int main()
{
	Test4();        //1,2,3
	Test4(10);      //10,2,3
	Test4(10, 20);   //10,20,3
	Test4(10, 20, 30);//10,20,30
	return 0;
}
