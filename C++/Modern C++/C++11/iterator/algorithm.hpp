#ifndef _ALGORITHM_HPP_
#define _ALGORITHM_HPP_

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#include <iterator>

namespace Study {

/*foreach()�㷨���õ��˵������еĿ������졢��++��!=�����ڡ�*���������㡣
 *������Ҫͨ������������foreach()����������ĵ���������֧������4�����㡣
 *�����������������������4������Ҫ�����ͼ��������������foreach()����
 *֧�������������ǰ���������˫���������������ʵ��������Ͳ�����
 */
template <typename InputIterator,class Function>
void foreach(InputIterator first,InputIterator last,Function fun)
{
	while(first != last)
	{
		fun(*first);
		first++;
	}
}

/*ʹ�õ��������ǲ���Ҫ���������ľ������ͣ�Ҳ����Ҫ����T�ľ���ʵ�֣�
 *���ܹ��Բ�ͬ���������в��Ҳ�����
 */
template <typename InputIterator,typename T>
InputIterator find(InputIterator first,InputIterator last,const T& value)   //���ҷ�Χ[first,last)
{
	for(;first != last;++first)
	{
		if(*first == value)
		{
			return first;
		}
	}
	
	return last;
}

//�������е�difference_type���ͣ�ͨ������STL�з����㷨�ṩ�ļ������ܡ�
template <typename InputIterator,typename T>
auto count(InputIterator first,InputIterator last,const T& value) -> typename std::iterator_traits<InputIterator>::difference_type    //ͳ��[first,last)��Χ�У���ֵvalue���ֵĴ�����
{
	typename std::iterator_traits<InputIterator>::difference_type n = 0;
	for(;first != last;++first)
	{
		if(*first == value)
		{
			n++;
		}
	}
	
	return n;
}

#ifdef _ERROR_
/*swap()����ģ���ʵ������������������ָ����������󡣾ֲ�����tempӦ����ʲô����
 *����û��֪������ʹ֪��������ָ����������ȴ�޼ƿ�ʩ����Ϊֱ����ģ������ʵ��ʱ��
 *����ȷ����������͡��ڲ�֪�����������ʱ������ʹ��auto�������������һЩ����£�
 *����Ҳ��֪�����������͵�ֵ�����Ͳ��
 */
template <typename ForwardIteraor>
void swap(ForwardIteraor first,ForwardIteraor last)    //��������Ϊ�����Ľ���������ģ�����Ͳ���ָ���˵��������͡�
{
	temp = *first;      //error��variable temp undeclared
	*first = *last;
	*last = temp;
}
#else   //_ERROR_
#ifndef _CHANGE_WAY_
/*����auto��decltype���������Զ��Ƶ��⣬����Щ�����Ļ��ƿ���ȷ��һ����������ָ��ֵ�����͡�
 *����һ���Ǽ��Ҫ��ÿ��ʹ��swap()�����ĵ���������Ӧ�ð���һ��������������ͱ���value_type��
 *�����Ϳ���ʹ���ڵ������ж����value_type���ͱ�������ָ��swap()��temp���������͡�
 */
template <typename ForwardIteraor>
void swap(ForwardIteraor first,ForwardIteraor last)
{
	typename ForwardIteraor::value_type temp = *first;
	*first = *last;
	*last = temp;
}
#else  //_CHANGE_WAY_
/*��Ϊvalue_type���������ڵ��������У����Կ���ͨ��typename ForwardIteraor::value_type�ķ�ʽ��������
 *����������value_type�����ĵ������࣬������swap()����������ʹ�á�Ȼ��STL���㷨��֧��ָ�����Ͳ�����
 *Ҳ֧�ֵ����������ForwardIteraor����ͨ���͵�ָ�룬����swap()�������ܾ��޷�ʹ���ˡ���Ϊָ�벻���࣬
 *���ܰ�������ı��������Բ���д��int*::value_type��STL����traits������ȡ���������ŵؽ����������⡣
 */
template <typename ForwardIteraor>
void swap(ForwardIteraor first,ForwardIteraor last)
{
	typename std::iterator_traits<ForwardIteraor>::value_type temp = *first;
	*first = *last;
	*last = temp;
}
#endif  //_CHANGE_WAY_
#endif  //_ERROR_

}  //namespace Study

#endif  //_ALGORITHM_HPP_
