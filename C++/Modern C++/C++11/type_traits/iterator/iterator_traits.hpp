/*1.iterator_traits������������ȡ����
 *��1��iterator_traitsģ�����Ͷ�����ͷ�ļ�<iterator>�С����ģ��Ϊ���������������Զ�����
 *     һ�ױ�׼�����ͱ��������㷨�ȿ����õ�������Ҳ������һ���ָ�롣
 *��2��struct��class�ڱ���������ͬ�ģ����˽ṹ��ĳ�ԱĬ����public��iterator_traits�ṹ��
 *     ģ����û�г�Ա�����ͳ�Ա��������������ֻ�������ͱ����Ķ��塣��Щ������Iterator��Ϊ
 *     ���Ͳ�����ģ�塣����ģ������ͱ���difference_type��value_type��pointer�ȣ��Լ�����
 *     ���ɵ�����ģ��ʵ�������ͣ����ӦIterator�����Ͳ���֮�䶨����ӳ�䡣����԰�������Ч
 *     �ؽ���˲�֪��ģ�嶨����������ʲô�����⡣
 *��3�����Ե�����Ϊ�������庯��ģ��ʱ��������ģ����ʹ��std::iterator_traits�ﶨ��ı�׼���ͱ�����
 *     MyIterator�����������ָ���������ǿ�����Ϊstd::iterator_traits<MyIterator>::pointer���ã�
 *     ��Ϊ����ͬ��MyIterator::pointer������Ҫָ��һ��MyIterator��������ָ��ֵ������ʱ������д��
 *     std::iterator_traits<MyIterator>::value_type���⽫�ᱻӳ��ΪMylterator::value_type��
 *��4��ģ�岻�Ǵ��룬���Ǳ������������ɴ�����䷽��iterator_traitsģ��ֻ�������ͱ�������˲������
 *     ��ִ�д��롣������������C++����Ĺ����л��õ�����������Ĵ����н�������iterator_traitsģ����ټ���
 *     ����Ψһ����֮����������C++����Ĺ����С�
 *��5��
 */

/*2.iterator_traits������������ȡ���ж����5�����ͱ�����
 *��1��difference_type����ʾ����������֮����ֵ�����͡�
 *��2��value_type����ʾ��������ָ��ֵ�����͡�
 *��3��pointer����ʾ��������ָ��ֵ�ĵ�ַ���͡�
 *��4��reference����ʾ��������ָ��ֵ���������͡�
 *��5��iterator_category���������ı�ǩ���ͣ�������input_iterator_tag��output_iterator_tag��
 *     forward_iterator_tag��bidirectional_iterator_tag��random_access_iterator_tag��5�֡�
 *��6��һ������STLҪ����Զ�������������ȫ��������Щ���������������������������iterator_category��
 *     ���еı��������Զ���Ϊ void��������Ϊ���������ָ������Ŀ�ĵ�ַ�����Ƕ������׵������ṩ��
 *     ��������֪���Ĺ��ڵ�������һ�С�
 */

/*3.iterator_traitsģ�����ָͨ����������
 *��1��Ϊ����STL�㷨����ܵ�����һ��������ָͨ�롣iterator_traitsģ���ػ�������T*��const T*�Ķ��塣
 *��2����iterator_traitsģ�����Ͳ�����ָ������ʱ���������汾�����˶�Ӧ�ڱ��������͡�T*���͵�ָ��
 *     value_type�ı�������ΪT��
 *��3��������ʵ����������Ҫ���ȫ���������������õ�ָ���ϡ���˶���ָ�룬iterator_categor�ı���
 *     ���ǵ�ͬ��std::random_access_iterator_tag���͡����iterators_traits�ܷ���������ȡ����ģ��
 *     ���Ͳ�����ָ�뻹�ǵ����������͡���ģ�����Ͳ�����ָ��ʱ����ѡ��ʹ��iterators_traits���ָ��
 *     ��������ģ�壻����ѡ���׼��ģ�嶨�塣
 */

#ifndef _ITERATOR_TRAITS_HPP_
#define _ITERATOR_TRAITS_HPP_

namespace Learn {

struct input_iterator_tag {};
struct output_iterator_tag{};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <typename Iterator>
struct iterator_traits
{
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
};

template <typename T>
struct iterator_traits<T*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
};

template <typename T>
struct iterator_traits<const T*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef const T* pointer;
	typedef const T& reference;
};

}  // namespace Learn

#endif  //_ITERATOR_TRAITS_HPP_