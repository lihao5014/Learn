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

#include <limits.h>
#include <iostream>
#include <chrono>

#define _CHANGE_WAY_ 1<<2   //1<<0 = 0b001, 1<<1 = 0b010, 1<<2 = 0b100

#define INFINITY INT_MIN

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

/*����һ��ģ�庯��sumArray()����ѭ��չ����Ȼ��Ƚϴ�ͳѭ���ۼӺ�ѭ��չ�����ۼӵ�ʱ�䡣
 *��չ��ѭ����ʱ��ѭ��չ����ʱ���١��ɼ������չ�����岻���ر�󡣶��ҵ����ȱ��֮��
 *�����������ˣ�չ����ֱ�ӱ��������
 */
int totalArray(int* parr,int size)
{
	if(parr == nullptr || size < 0)
	{
		cout<<"totalArray() error: parr is null or size<0"<<endl;
		return INFINITY;
	}
	
	int ret = 0;
	while(size-->0)
	{
		ret += parr[size];
	}
	
	return ret;
}

template <int N>
int sumArray(int arr[])
{
	if(arr == nullptr)
	{
		cout<<"sumArray() error: arr is null"<<endl;
		return INFINITY;
	}
	
	return arr[0] + sumArray<N - 1>(arr + 1);
}

template <>
int sumArray<1>(int arr[])
{
	return arr[0];
}

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

/*��������Ҫ�󼫸߲�����ʹ�õ�˵�Ӧ�ó���Ҳ�����ٽ�ʡһ�㿪��������ܼ���ѭ���ļ�����������Ҳ��
 *�ȽϿɹ۵���������������Ӧ��չ����ֱ�Ӽ��㣺result=a[0]*b[0]+a[1]*b[1]+a[2]*b[2]+a[3]*b[3]���ʽ��
 *��������ϣ������������ʽ���Ա�Ӧ���ڲ�ͬά�����������㣬����ģ��Ԫ������ÿ��Է��ӳ�������ʱ����
 *�����ɴ����������
 */
int dotProduct(int dim,int vec1[],int vec2[])
{
	if(dim < 0)
	{
		cout<<"dotProduct() warn: dimension is less than zero"<<endl;
		return INFINITY;
	}
	
	int result = 0;
	for(int i=0;i<dim;++i)     //���ֱ�ӽ�ѭ��չ��Ϊa[0]*b[0]+a[1]*b[1]+a[2]*b[2]���ʽ���м������ܸ��á�
	{
		result += vec1[i] * vec2[i];
	}
	
	return result;
}

/*ʹ��ģ��Ԫ��̽���������˵ķ����Ƕ���һ����ģ��DotProduct��ΪԪ������ͨ���ݹ����
 *����չ�����ʽ����������һ���ֲ��ػ��İ汾��ʹ����ά���ݼ���1ʱ�ܹ��ս�ݹ顣
 */
template <int DIM>
struct DotProduct
{
	static int result(int* pvec1,int* pvec2)
	{
		return pvec1[0] * pvec2[0] + DotProduct<DIM - 1>::result(pvec1 + 1,pvec2 + 1);
	}
};

template <>
struct DotProduct<1>    //��Ϊ�ݹ���������ľֲ��ػ�
{
	static int result(int* pvec1,int* pvec2)
	{
		return pvec1[0] * pvec2[0];
	}
};

/*dot_product()��װ�����Ľӿ������dotProduct()�Ѿ��ı䣬����ԭ��ģ����������ڱ���ʱȷ����
 *����DIM������һ����������������һ������������ģ��Ԫ��̼�������ֵ���㷽���һ���ش����ơ�
 *��Ȼ���ڵ�˼�����ԣ�������ά��һ�㶼���ڱ���ʱȷ����
 */
template <int DIM>
int dot_product(int* pvec1,int* pvec2)
{
	if(pvec1 == nullptr || pvec2 == nullptr)
	{
		cout<<"dot_product() warn: pvec1 or pvec2 is null"<<endl;
		return INFINITY;
	}
	
	return DotProduct<DIM>::result(pvec1,pvec2);
}

int main(void)
{
	int ret = sum(50000);
	cout<<"sum 1~50000 = "<<ret<<endl;
	
	Loop<10>::run(print);
	cout<<endl;
	
	Loop<6>::run(show);
	cout<<endl;
	
	int seq[] = {8,5,0,9,3,1,2,6,4,7};
	{
		Timer timer;
		ret = totalArray(seq,sizeof(seq)/sizeof(int));
	}
	cout<<"totalArray(): "<<ret<<endl;
	
	{
		Timer timer;
		ret = sumArray<sizeof(seq)/sizeof(seq[0])>(seq);
	}
	cout<<"sumArray(): "<<ret<<endl;
	
	int arr[] = {1,2,3};
	int vec[] = {3,4,5};
	{
		Timer timer;
		ret = dotProduct(sizeof(arr)/sizeof(int),arr,vec);
	}
	cout<<"dotProduct(): "<<ret<<endl;
	
	{
		Timer timer;
		ret = dot_product<sizeof(arr)/sizeof(arr[0])>(arr,vec);
	}
	cout<<"dot_Product(): "<<ret<<endl;
	
	return 0;
}