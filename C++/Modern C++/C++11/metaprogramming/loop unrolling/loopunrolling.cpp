/*1.ѭ��չ����
 *��һ����������ĳߴ����ӿ�����ִ���ٶȵ��Ż������������ɳ���Ա��ɣ�Ҳ���ɱ������Զ��Ż���ɡ�
 *ѭ��չ�����������ѭ��������Ϊ���ж�����ܵ�Ԫ�Ĵ������ṩָ����С�Ҳ������ָ����ˮ�ߵĵ��ȡ�
 */

/*2.ѭ��չ���Ľ��������ܵ�2���棺
 *��1�������˲�ֱ�������ڳ������Ĳ���������������ѭ����������ͷ�֧������
 *��2���ṩ��һЩ���������Խ�һ���仯���룬�������������йؼ�·���ϵĲ���������
 */

/*3.ѭ��չ������ȱ�㣺
 *ѭ��չ���Գ����������ź���Ҫ��Ӱ�죬���Լ��ٷ�֧Ԥ��������������ȡ��������ؽ�һ�����ò���ִ��
 *����ٶȵĻ��ᡣ���ǲ��������ҽ����ֶ���ѭ��չ�����ڴ����н���ѭ��չ���ᵼ�³���Ŀɶ����½���
 *�������͡�Ϊ��ֱ�۸���ѭ��չ�������ܵ�Ӱ�죬���Դ������н�������ڲ����������Ż�������½��еĲ��ԣ�
 *��ʵ�����ǿ����˱������Ż���ʱ�򣬱��������Զ������ǵ�ѭ���������ѭ��չ���������ǿ����ڱ����˴���
 *�ɶ��Ե�ͬʱ���������ܵ�ѭ��չ�������ǳ������ܵ���ߡ�
 */

#include <iostream>
#include <chrono>

#define _CHANGE_WAY_ 1<<2   //1<<0 = 0b001, 1<<1 = 0b010, 1<<2 = 0b100

using namespace std;

typedef void (*pFun)(int);

class Timer
{
public:
	Timer():m_startTimePoint(chrono::steady_clock::now()){}
	
	~Timer()
	{
		auto endTimePoint = chrono::steady_clock::now();
		auto duration = chrono::duration<double,std::micro>(endTimePoint - m_startTimePoint);
		
		cout<<"spend time: "<<duration.count()<<"ms"<<endl;
	}
private:
	chrono::steady_clock::time_point m_startTimePoint;
};

#if (_CHANGE_WAY_ & 0b001)
//δ����ѭ��չ���Ż��Ĵ���
int sum(int num)
{
	Timer timer;
	
	int ret = 0;
	for(int i=1;i<=num;++i)
	{
		ret += i;
	}
	
	return ret;
}
#elif (_CHANGE_WAY_ & 0b010)
/*��1��ѭ��չ��һ�Σ���ÿ��ѭ����i��i+1һ���ۼӵ�ret�����ϣ��������԰�ѭ��������num�ν���
 *     ��num/2�Σ�����CPU�ĸ߶���ˮ�߻������������ӷ�ָ�����Ӻ�ʱ�ܵͣ����Դ˰汾�������
 *     һ���̶�����߳��������ٶȡ�
 *��2����Ȼ���ǿ��Լ�������ѭ��չ�������Խ�һ����߳��������ٶȣ������������ѭ��չ������
 *     Ҳ�����޶ȵģ����ﵽ��CPU�����������֮�󣬼�������ѭ��չ��������û������ġ�
 */
int sum(int num)
{
	Timer timer;
	
	int ret = 0;
	for(int i=1;i <= num;i += 2)    //ѭ��չ��
	{
		ret += i;
		ret += i + 1;
	}
	
	return ret;
}
#elif (_CHANGE_WAY_ & 0b100)
/*��1������ѭ��չ��һ�κ�Ĵ�����Ȼ�н�һ���Ż��Ŀռ䣬�Ǿ�����������ָ�������ԣ��Դﵽָ����У�
 *     ���ǿ��Կ���ѭ��չ����Ĵ��룬ѭ��������������䣺ret += i��ret += i+1���ڶ������sum += i+1
 *     �����ڵ�һ������ret += i��ִ�н�����������������ֻ������ִ�У�������CPU��һ��������ܵĿ��ܡ�
 *��2�������½�����������ret1��ret2���ڴ洢ѭ��չ��ʱ�������ۼ������ۼӽ���������ѭ�����⽫������
 *     �����ӵõ����ս�����ô����������ۼ����֮���ǻ�����صģ�����CPU���Բ���ִ��������ָ�
 *     �Դﵽ���ܵĽ�һ����ߡ�
 */
int sum(int num)
{
	Timer timer;
	
	int ret1 = 0;
	int ret2 = 0;
	for(int i=1;i <= num;i += 2)   //��ѭ��չ���ֶ�·����
	{
		ret1 += i;
		ret2 += i + 1;
	}
	
	return ret1 + ret2;
}
#endif

void print(int n)
{
	cout<<n<<" ";
}

void show(int n)
{
	cout<<n * n<<" ";
}

/*ʹ��ģ��Ԫ��̽���ѭ��չ������Ϊ�ڱ����Ĵ�������û�еݹ��ѭ���ġ�
 *�е�ֻ�Ǻܶ��ػ���Loop<10>��Loop<9>...Loop<0>��ִ����run()������
 */
template <int N>
struct Loop
{
	static int run(pFun pfun)
	{
		int num = Loop<N - 1>::run(pfun);
		
		pfun(num + 1);
		return num + 1;
	}
};

template <>
struct Loop<0>
{
	static int run(pFun pfun)
	{
		pfun(0);
		return 0;
	}
};

int main(void)
{
	int ret = sum(50000);
	cout<<"sum 1~50000 = "<<ret<<endl;
	
	Loop<10>::run(print);
	cout<<endl;
	
	Loop<6>::run(show);
	cout<<endl;
	
	return 0;
}