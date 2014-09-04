#include <iostream>
#include <process.h>
#include <windows.h>
#include <time.h>

//内核对象(线程、进程、事件、互斥体、信号、管道、完成端口等等)
//任何内核对象都有激发和非激发两种状态
//线程:在运行的时候是非激发状态,线程执行完毕就进入激发状态

unsigned int __stdcall f(void* p)
{
	srand((unsigned int)time(0));
	int t = rand() % 10000;
	Sleep(t);
	std::cout<<1;
	return 1u;
}

void main()
{
	//_beginthreadex就是线程句柄
	HANDLE h = (HANDLE)_beginthreadex(0, 0, f, 0, 0, 0);

	//等待一个内核对象从非激发状态转换到激发状态
	WaitForSingleObject(h, INFINITE);

	std::cout<<2;

	system("pause");
}
