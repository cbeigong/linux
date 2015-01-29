/*************************************************************************
	> File Name: cal.cpp
	> Author: chenlumin
	> Mail: 1025300632@qq.com
	> Created Time: 2015年01月26日 星期一 09时54分54秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
void printOneMonth(int year, int month);

bool  leapyear(int year)
{
	if(year % 4 == 0 && year % 100 != 0 && year % 400 == 0)
		return true;
	else
		return false;
}
void printCal(int year)
{
	int nextLine = 0;
	for(int month = 1; month <= 12; ++month)
	{
		printOneMonth(year, month);
		++nextLine;
		cout << "   ";
		if(nextLine == 2)
		{
			cout << endl;
		}

	}
}
int Maxmonth(int year, int month)
{
    int maxMonth;
//	cout << "plear input year and  month: " << endl;
//	cin >> year >> month;
	if(leapyear(year))
	{
		switch(month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				maxMonth = 31;
				break;
			case 2:
				maxMonth = 29;
				break;
			default:
				maxMonth = 30;
				break;
		}
	}
	else
	{
		switch(month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				maxMonth = 31;
				break;
			case 2:
				maxMonth = 28;
				break;
			default:
				maxMonth = 30;
				break;
		}
	}
	return maxMonth;
	//积木拉二审公式计算一号是周
}
void printTwo(int year,int month, int month1)
{
    //int month = 1;
    //int month1 = 2;
    int today, today1;
    int maxMon = Maxmonth(year, month);
//	cout << "plear input year and  month: " << endl;
//	cin >> year >> month;
	//积木拉二审公式计算一号是周几
	if(month == 1 || month == 2)
	{
		month = month + 12;
		year--;
	}
	today = (2 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

	if(month == 13)
	{
		cout << "      1月 " << "                ";
	}
	else if(month == 14)
	{
		cout << "     2月" << "                 ";
	}
	else
	{
		cout <<"      "<< month << "月" "                     ";
	}


	int maxMon1 = Maxmonth(year, month1);
	if(month1 == 1 || month1 == 2)
	{
		month1 = month1 + 12;
		year--;
	}
	today1 = (2 + 2 * month1 + 3 * (month1 + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

	if(month1 == 13)
	{
		cout <<"     "<< "1月" << endl;
	}
	else if(month1 == 14)
	{
		cout << "   2月" << endl;
	}
	else
	{
		cout << month1 << "月" << endl;
	}




	cout <<"日 一 二 三 四 五 六" << "   " <<"日 一 二 三 四 五 六" << endl;
	cout <<"====================" << "   " <<"====================" <<endl;
	//填补空白
	for(int ix = 0; ix < today; ++ix)
	{
		cout << "   ";
	}
	int ix = 1;
	for(int j = 0; j < 7 - today; ++j)
	{
		cout << ix << "  ";
		++ix;
	}
	//第一月份打印玩之后要打印两个空白;
	cout << "  ";
	for(int ix = 0; ix < today1; ++ix)
	{
	    cout << "   ";
	}
	int day = 1;
	//cout << "today 1: " << today1 << endl;
	for(int ix = 0; ix < 7 - today1; ++ix)
	{
	    cout << day << "  ";
	    ++day;
	}
	cout << endl;
	int jx = 0;
	for(; ix <= maxMon; ++ix)
	{
		if(ix < 10)
		{
			cout << ix << "  ";
		}
		else
		{
			cout << ix << " ";
		}
		++jx;
		if(jx % 7 == 0)
		{
			cout << "  ";
			for(; day <= maxMon1; )
			{
			    if(day < 10)
                {
                    cout << day++ << "  ";
                }
                else
                {
                    cout << day++ << " ";
                }
                ++jx;
                if(jx % 7 == 0)
                {
                    cout << endl;
                    break;
                }
			}

		}

	}
	while(jx % 7 != 0)
	{
	    cout << "   ";
	    ++jx;
	}
	cout << "  ";
	for(; day <= maxMon1; ++day)
	{
	    cout << day << " ";
	}


	cout << endl;


}
void printOneMonth(int year , int month)
{

	static int  maxMonth,today;
//	cout << "plear input year and  month: " << endl;
//	cin >> year >> month;
	if(leapyear(year))
	{
		switch(month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				maxMonth = 31;
				break;
			case 2:
				maxMonth = 29;
				break;
			default:
				maxMonth = 30;
				break;
		}
	}
	else
	{
		switch(month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				maxMonth = 31;
				break;
			case 2:
				maxMonth = 28;
				break;
			default:
				maxMonth = 30;
				break;
		}
	}
	//积木拉二审公式计算一号是周几
	if(month == 1 || month == 2)
	{
		month = month + 12;
		year--;
	}
	today = (2 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
	/*if(today == 0)
	{
		today = 7;
	}
	*/
	if(month == 13)
	{
		cout << "1 " << endl;
	}
	else if(month == 14)
	{
		cout << "2" << endl;
	}
	else
	{
		cout << month << endl;
	}
	cout <<"日 一 二 三 四 五 六" << endl;
	cout <<"====================" << endl;
	//填补空白
	for(int ix = 0; ix < today; ++ix)
	{
		cout << "   ";
	}
	int ix = 1;
	for(int j = 0; j < 7 - today; ++j)
	{
		cout << ix << "  ";
		++ix;
	}
	cout << endl;
	int jx = 0;
	for(; ix <= maxMonth; ++ix)
	{
		if(ix < 10)
		{
			cout << ix << "  ";
		}
		else
		{
			cout << ix << " ";
		}
		++jx;
		if(jx % 7 == 0)
		{
			cout << endl;
		}

	}
	cout << endl;
}

int main()
{
    int year;
    cout <<"chose the year you want to print the calendar: " ;
    cin >> year;
    cout << endl;
    for(int ix = 1; ix <= 12; ix += 2)
    {
        printTwo(year,ix, ix+1);
    }

}

