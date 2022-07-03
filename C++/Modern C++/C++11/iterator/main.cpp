/*STL��ʵ���˺ܶ��㷨��<algorithm>ͷ�ļ����������Ŀ�ǻ���STL��������ô�ܹ����ʹ�����д��룬
 *���������������Ч�ʡ���STL���������㷨֮��������ǵ������������ڶ�����Զ������͵�������
 *���������ǵ�������ʵ�֡�
 */

/*1.iterator��������
 *��1����������һ�ֳ������Ƹ����ʵ���������в�û��ֱ�Ӷ�Ӧ����������ʵ�
 *     �����ģʽ�е�����ģʽ��ָ���ṩһ�ַ�����ʹ֮�ܹ��������ĳ���ۺ��������
 *     �����ĸ���Ԫ�أ��������뱩¶�þۺ�����ڲ�������ʽ��
 *��2����������STL�Ĺؼ����ڣ��������������㷨�ֿ����˴˶�����ƣ��������������
 *     ������ϵ��һ������������ǵ�������
 *��3��std::iterator���ṩ�Լ򻯵�������Ҫ�����Ͷ���Ļ��ࡣ��C++17��׼��<iterator>
 *     ͷ�ļ��ѱ����á�
 *��4��STL������iterator������ģ�壬���������������Լ��ĵ��������а���Ҫ������ͱ�����
 *     iterator��һ���ṹ��ģ�壬��������5��������std::iterator_traitsģ������ͱ�����
 */

/*2.iterator������Դ�룺
 *	template <typename Category,                 // iterator::iterator_category
 *            typename T,                        // iterator::difference_type
 *            typename Distance = ptrdiff_t,     // iterator::value_type
 *			  typename Pointer = T*,             // iterator::pointer
 *            typename Reference = T&>           // iterator::reference
 *  struct iterator
 *  {
 *      typedef Category iterator_category;
 *      typedef T value_type;
 *      typedef Distance difference_type;
 *      typedef Pointer pointer;
 *      typedef Reference reference;
 *  };
 *
 *��1��������ģʽ��һ�־�������ģʽ����STL�ĵ�����ʵ���õ���ģ���һЩ���Ժͼ��ܣ�
 *     ��std::iterator��Դ���У�����ʹ��typedef�������ͱ�������Ϊ�˸�������㷨��̬
 *     ����ȡʱʹ�õġ����е�Category��Tģ�����û��Ĭ��ֵ����Ҫ�Լ��������ġ�
 *��2��value_type����ָ��������ͣ�ÿһ��������STL�㷨���������class����Ӧ�ö���
 *     �Լ���value_type��Ƕ���͡�
 *��3��difference_type��������ʾ2���������ľ��룬���������������ʾ���������������
 *     ͨ������STL�з����㷨�ṩ�ļ������ܡ�����STL�е�count()��distance()��
 *��4��reference����ʾ��������ָ֮��Ե�������ָ֮��������Ƿ�����ı䣬���Խ�������
 *     ��Ϊ2�࣬constant iterator��mutable iterator��
 *  �� constant iterator��������ı䡰��ָ����֮�����ߡ���Ϊconstant iterator��
 *  �� mutable iterator������ı䡰��ָ����֮�����ߡ���Ϊmutable iterator��
 *��5��pointer����ʾ��������ָ֮��ĵ�ַ��
 *��6��iterator_category����ʾ�����������ࡣ�����ƶ�������ʩ�в�������������Ϊ5�ࡣ
 *  �� Input Iterator�������������ָ�Ķ��󣬲��������ı䣬ֻ����
 *  �� Output Iterator�������������ָ�Ķ��󣬲���������ȡ��ֻд��
 *  �� Forward Iteratorǰ�������������д�����㷨�ڴ��ֵ��������γɵ������Ͻ��ж�д������
 *  �� Bidirectional Iterator˫�����������˫���ƶ���ĳЩ�㷨��Ҫ�����߷�ĳ�����䡣
 *  �� Random Access Iterator������ʵ�������֧��operator[]��+n��-n��+=n��-=n�����������
 *��7��ǰ4�ֵ�����ֻ�ṩһ����ָ������������ǰ3��֧��operator++����4��֧��operator--��
 *     ��5���򺭸�����ָ����������������operator[]��
 */
 
/*3.ģ��Ԫ����еı�ǩtag��
 *��ǩtagһ����һ�����࣬����������Ϊһ����һ�޶����������֣����ڱ��һЩ���������͵�������STL
 *�е��������������͵����֣�input_iterator_tag��output_iterator_tag��random_access_iterator_tag��
 *bidirectional_iterator_tag��forward_iterator_tag��ʵ����vector<int>::iterator::iterator_category
 *����random_access_iterator_tag������ʹ��type_traits������is_same���ж������Ƿ���ͬ�������������жϣ�
 *�����Ը����жϽ���������ӵ�Ԫ����߼�����һ���㷨�Ե�����Ϊ���������ݵ�������ǩ�����������Զ�ĳ��
 *���������⴦������ǩ�����������ֱ溯�����ء�
 */

/*4.STL��������5�ֱ�ǩtag��
 *��1��struct input_iterator_tag {};
 *��2��struct output_iterator_tag {};
 *��3��struct forward_iterator_tag : public input_iterator_tag {};
 *��4��struct bidirectional_iterator_tag : public forward_iterator_tag {};
 *��5��struct random_access_iterator_tag : public bidirectional_iterator_tag {};
 */

/*5.ʹ��tag��ǩ���ֵ����������ԭ��
 *��Ϊ����������㷨ʱ��Ӧ�����ĳ��ǿ���ĵ������ṩ��һ�ֶ��壬���������ṩ����Ч�ʡ�
 *�κ�һ����������������Ӧ������"�õ������������ĸ�����������ǿ�����Ǹ�"������int*����
 *RandomAccess Iterator������Bidirectional Iterator��ͬʱҲ��Forward Iterator������Ҳ��
 *Input Iterator����ô������Ӧ�ù���ΪRandomAccess iterator��
 */

#include <iostream>
#include <algorithm>
#include "array.hpp"
#include "algorithm.hpp"

#define UNUSED(x) (void)x;

using namespace	Study;

template <class T>
void print(const T& t)
{
	std::cout<<t<<" ,";
}

auto main(int argc,char* argv[]) -> int
{
	UNUSED(argc);
	UNUSED(argv);
	
	int seq[] = {0,1,2,5,5,5,5,7,8,9};
	
	/*��Ϊʹ����traits������Study::swap()����ģ�����ԭ��ָ����Զ����������֧��ʵ����ͳһ��
	 *���Ե���Study::swap()����ʱ�����ɴ�����ָͨ�룬Ҳ���Դ����������
	 */
	Study::swap(seq,seq + 5);
	
	Study::foreach(seq,seq + sizeof(seq)/sizeof(int),print<int>);
	std::cout<<std::endl;
	
	/*ֱ��ʹ����ָͨ��Ҳ���Ե���Study::count()��������ΪSTLͨ��ģ��ƫ�ػ�����ʹ�õ�����Ҳ֧��
	 *ԭ��ָ�롣�ѷ���������Ԫ�صĹ��ܶ������˵����������ǾͿ��Զ����е�������ͳһ�ķ�ʽ�����ˣ�
	 *�����ñ�¶ÿ��������ʵ��ϸ�ڡ�
	 */
	int ret = Study::count(seq,seq + sizeof(seq)/sizeof(seq[0]),5);
	std::cout<<"count 5 in seq: "<<ret<<std::endl;
	
	int* p = std::find(seq,seq + sizeof(seq)/sizeof(int),7);
	if(p != seq + sizeof(seq)/sizeof(int))
	{
		std::cout<<"find 7 in seq: "<<p - seq<<std::endl;
	}
	else
	{
		std::cout<<"can't find 7 in seq!"<<std::endl;
	}
	
	Array<int> arr1(3);
	::foreach(arr1.begin(),arr1.end(),print<int>);   //�����Զ����foreach()�㷨������
	std::cout<<std::endl;
	
	arr1.front() = 1;
	arr1[2] = 5;
	arr1.back() = 7;
	std::cout<<"arr1.at(1) ="<<arr1.at(1)<<" ,arr1.size() ="<<arr1.size()<<" ,arr1.empty() ="<<arr1.empty()<<std::endl;
	
	Array<int>::const_iterator citer = arr1.cbegin();
	for(;citer != arr1.cend();++citer)
	{
		std::cout<<*citer<<" ,";
	}
	std::cout<<std::endl;

#ifndef _CHANGE_WAY_
	int n = Study::count(arr1.cbegin(),arr1.cend(),3);
	Array<int>::iterator iter = ::find(arr1.begin(),arr1.end(),5);
#else
	int n = std::count(arr1.cbegin(),arr1.cend(),3);
	Array<int>::iterator iter = std::find(arr1.begin(),arr1.end(),5);
#endif
	std::cout<<"count 3 in arr1: "<<n<<std::endl;
	
	if(iter != arr1.end())
	{
		std::cout<<"find 5 in arr1: "<<iter - arr1.begin()<<std::endl;
	}
	else
	{
		std::cout<<"can't find 5 in arr1!"<<std::endl;
	}
	
	/*��1���Զ��������ArrayIterator�������ѭ����STL��׼���е�������ƹ���
	 *     ���Կ���ʹ��ArrayIterator����������<algorithm>ͷ�ļ���ͨ���㷨������
	 *��2���Զ�������Array�ͱ�׼��std::array���õ�����ȥ���ʣ���ͨ��������ʹ��
	 *     std::for_each()���������Կ����÷���ȫһ��.
	 */
	Array<double,5> arr2 = {3.14,2.718,1.414,0.618,1.732};
	std::for_each(arr2.cbegin(),arr2.cend(),print<typename Array<double,5>::data_type>);     //����STL��׼���е�for_each()�㷨������
	std::cout<<std::endl;
	
	::swap(arr2.begin(),2 + arr2.begin());
	for(auto val : arr2)        //�Զ��������ֻҪ�ṩ��begin()/end()��Ա������std::begin()/std::end()�������أ��Ϳ���֧�ַ�Χforѭ����
	{
		std::cout<<val<<" ,";
	}
	std::cout<<std::endl;
	
	return 0;
}