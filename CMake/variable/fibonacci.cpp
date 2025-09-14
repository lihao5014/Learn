/**
 *1.HJ37 统计每个月兔子的总数：
 *（1）问题描述：有一种兔子，从出生后第三个月起，每个月都会生一只兔子，生出来的兔子同理。假设兔子都不死，求解第 nn 个月时的兔子总数。
 *（2）输入描述：在一行上输入一个整数n(1≦n≦31)代表查询的月份。
 *（3）输出描述：在一行上输出一个整数，代表第 nn 个月的兔子总数。
 *
 *（4）示例1：
 * <1> 输入：3
 * <2> 输出：2
 * <3> 说明：第一个月时，只有初始兔子（记为r0）此时兔子总数为1。
 *           第二个月时，依旧只有r0。
 *           第三个月时，r0开始生兔子（记生出来的兔子为r1），此时兔子总数为2。
 *           第四个月时，r0再生一只兔子，此时兔子总数为3。
 *           第五个月时，r0再生一只兔子，与此同时r1也开始生兔子，此时兔子总数为5。
 *
 *（5）示例2：
 * <1> 输入：5
 * <2> 输出：5
 */

#include <time.h>
#include <assert.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

//斐波那契数列
static int fibonacii(int n)
{
	assert(n > 0);
	
	if(n == 1 || n == 2)
	{
		return 1;
	}
	
	return fibonacii(n - 1) + fibonacii(n - 2);
}


//带动态规划的斐波那契数列
class Fibonacii
{
public:
	static int item(int n)
	{
		map<int,int>::iterator iter = m_resultMap.find(n);
		if(iter != m_resultMap.end())
		{
			return m_resultMap[n];
		}
		
		m_resultMap[n] = item(n - 1) + item(n - 2);
		return m_resultMap[n];
	}
	
private:
	static map<int,int> m_resultMap;    //key - 月份，value - 斐波那契数列值
};

map<int,int> Fibonacii::m_resultMap = {{1,1},{2,1}};


//统计耗时
class ElapsedTime
{
public:
	ElapsedTime(const string& strText)
		:m_startTime(clock())
		,m_strText(strText)
	{
		
	}
	
	~ElapsedTime()
	{
		clock_t endTime = clock();
		double duration = (double)(endTime - m_startTime) / CLOCKS_PER_SEC;
		cout<<m_strText<<": "<<duration<<"s"<<endl;
	}

private:
	clock_t m_startTime;
	string m_strText;
};

int main(int argc,char* argv[])
{
	cout<<"fibonacii(5) ="<<fibonacii(5)<<endl;
	cout<<"fibonacii(6) ="<<fibonacii(6)<<endl;
	
	
	cout<<"Fibonacii::item(5) ="<<Fibonacii::item(5)<<endl;
	cout<<"Fibonacii::item(6) ="<<Fibonacii::item(6)<<endl;
	
	{
		ElapsedTime elapsed("caculate fibonacii(45) elapsed time");
		cout<<"fibonacii(45) ="<<fibonacii(45)<<endl;
	}
	
	{
		ElapsedTime elapsed("caculate Fibonacii::item(45) elapsed time");
		cout<<"Fibonacii::item(45) ="<<Fibonacii::item(45)<<endl;
	}
	return 0;
}