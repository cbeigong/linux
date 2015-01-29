/*************************************************************************
	> File Name: friendnum.cpp
	> Author: chenlumin
	> Mail: 1025300632@qq.com 
	> Created Time: 2015年01月27日 星期二 08时16分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
	int a, b,cnt_b;
	for(int a = 1; a < 3000; ++a)
	{
		b = 0;
		for(int j = 1; j < a/2; ++j )
		{
			if(!(a % j))
			{
				b += j;//保证a的全部因子之和一定等于b
			}
		}
		cnt_b = 0;
		for(int k = 1; k < b/2; ++k)
		{
			if(!(b % k))
			{
				cnt_b += k;
			}
		}
		if(cnt_b == a)//b的全部因子之和等于a的话
		{
			cout << "a: " << a << "b: " << b << endl;
		}
	}
}
