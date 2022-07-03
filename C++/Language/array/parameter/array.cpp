#include <iostream>

#define SIZE 5

using namespace std;

static int sum(const int* arr,int length);
static int* copy(const int* arr,int length);
static void display(const int arr[],int length);

int main()
{
    int arr[] = {1,3,5,7,9};
	
    int len = sizeof(arr)/sizeof(arr[0]);
    int	ret = sum(arr,5/*len*/);
	std::cout<<"ret ="<<ret<<std::endl;
	
	int *copyArray = copy(arr,len);
	display(copyArray,len);
	
	{
		int length = 0;
		cout<<"�������length��ֵ"<<endl;
		cin>>length;
		
#if 0	
		static int a[length];              //��̬���鲻��ʹ�ñ������峤��
#else
		int a[length];
#endif

		for(int i=0;i<length;i++){
			a[i] = i;
		}
		
		for(int i=0;i<length;i++){
			cout<<"a["<<i<<"] ="<<a[i]<<" ";
		}
	}
}

int sum(const int* arr,int length)
{
	if(arr == nullptr)
	{
		std::cout<<"arr = nullptr"<<std::endl;
	}
	
	int ret = 0;
    for (int i=0;i<length;i++)
	{
        ret += arr[i];
    }
    return ret;
}

int* copy(const int* arr,int length)
{
	if(arr == nullptr)
	{
		std::cout<<"arr = nullptr"<<std::endl;
	}
#if 0	
	static int ret[length];        //��������ʱ�������С������Ϊ����
#else
	static int ret[SIZE];
#endif
	for (int i =0;i<length;i++)
	{
        ret[i] = arr[i];
    }
	return ret;
}

void display(const int arr[],int length)
{
	if(arr == nullptr)
	{
		std::cout<<"arr = nullptr"<<std::endl;
	}
	
	for(int i=0;i<length;++i)
	{
		std::cout<<"arr["<<i<<"] ="<<arr[i]<<std::endl;
	}
}