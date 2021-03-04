/*1.�������캯�����ƶ����캯���ĵ���˳��
 *��1�������빹�캯���Ĳ�����һ����ֵ/����/����ʱ����ô������ƥ����ֵ���ð汾�Ŀ������캯����
 *     ������в�������ֵ���ð汾�Ŀ������캯������ô�����ƥ�䳣����ֵ���ð汾�Ŀ������캯����
 *     ���������ֵ���ð汾�Ŀ������캯��Ҳ������ʱ����ô��������ֱ�ӱ��﷨���󣬶����ܱ����졣
 *     ���������ƥ�䵽��ֵ���ð汾���ƶ����캯�������ǿ���ͨ��std::move������һ����ֵת��Ϊ��ֵ��
 *     �Ӷ����õ��ƶ����캯����
 *��2�������빹�캯���Ĳ�����һ��������ֵ/��������/const����ʱ����ô������ƥ�䳣����ֵ���ð汾�Ŀ������캯����
 *     ������в����ڳ�����ֵ�汾�Ŀ������캯������ô�Ͳ���������ƥ����ֵ���û���ֵ���ð汾�Ŀ������캯���ˡ�
 *     �������ᱨ�﷨���󣬿������캯������ʧ�ܣ������첻�ɹ���
 *��3�������빹�캯���Ĳ�����һ����ֵ/��ʱ����ʱ����ô������ƥ����ֵ���ð汾���ƶ����캯����
 *     ������в�������ֵ���ð汾���ƶ����캯������ô�����ƥ�䳣����ֵ���ð汾�Ŀ������캯����
 *     ���������ֵ���ð汾�Ŀ������캯��Ҳ������ʱ����ô��������ֱ�ӱ��﷨���󣬶����ܱ����졣
 *     ʼ�ղ���ƥ�䵽��ֵ���ð汾�Ŀ������캯����C++�п���ͨ��std::move��һ����ֱֵ��ת��Ϊ��ֵ��
 *     ����ȴû�н���ֱֵ��ת��Ϊ��ֵ�ķ�����
 */

/*2.�������캯�����ƶ����캯���Աȣ�
 *��1����ֵ���ð汾�Ĺ��캯���������޸Ĵ���Ĳ�����������Ĳ�����������ֵ������ʵ��Ϊ�����ǳ�������ƶ����캯����
 *     ��C++11��ǰ��û���ƶ������֧�֣�auto_ptr����ָ�����ͨ����ֵ����ʵ�ֵ��ƶ����캯����
 *��2��������ֵ�汾�Ĺ��캯�����������޸Ĵ���Ĳ�����������Ĳ����������������ͣ�������Ĳ�����������ֵ��������ֵ����ֵ��
 *     ֻ��ʵ��Ϊ������캯����
 *��3����ֵ���ð汾�Ĺ��캯���������޸Ĵ���Ĳ�����������Ĳ�����������ֵ������ʵ��Ϊ�����ǳ�������ƶ����캯����
 *     ����ֵ���ð汾�Ĺ��캯��ʵ��Ϊ�������ǳ�������캯������ô��ʧȥ��ת����ֵ/��ʱ�����ڴ���Դ����Ȩ�����塣
 */
 
 /*3.��ֵ���ú���ֵ����ʵ�ֵ��ƶ����캯���ıȽϣ�
  *��1����ֵ���ð汾�ƶ����캯����ֻ�ܽ�����ֵ/����/�������Ͳ����������ܽ�����ֵ/��ʱ�������Ͳ�������������Դת�ƹ��̱Ƚ����ޣ�
  *     �û������ײ��������û���С�ļ���ʹ����ԭ���ڴ���Դ����Ȩ��ת���˵ı��������п��ܿ�ָ����ʵ����⡣
  *��2����ֵ���ð汾�ƶ����캯�������Խ�����ֵ/��ʱ�������Ͳ�����Ҳ����ͨ��std::move����������ֵ/����/�������Ͳ�����
  *     ������ֵ/����/�������͵Ĳ�������Դ����Ȩ��ת�ƶ�Ҫʹ��std::move�������൱����ʾ�����û��������ƶ����캯����
  *     ԭ�������е��ڴ���Դ����Ȩ�Ѿ�������ת�ƣ��ñ����Ѿ�ʧЧ���ٽ������Ĵ����в����ټ���ʹ���ˡ�
  */
 
/*һ������ֻ��Ҫʵ�ֳ�����ֵ���ð汾��������캯������ֵ���ð汾���ƶ����캯�����С�
 *��Ϊ��ֵ���ð汾�Ĺ��캯�������ʵ��Ϊǳ��������ô���������ʱͬһƬ�ڴ�ռ䱻����������⣬
 *ǳ������ʽ���ڹ��е����ȱ�ݣ�ͨ���඼��ʹ��ǳ�������캯�������ʵ��Ϊ������ƶ����캯����
 *��ô������ֵ����ʵ�ֵ�������캯������ֵ����ʵ�ֵ��ƶ����캯����������ֵ����ʵ�ֵúá�
 *��������һ�㲻��Ҫ��ֵ���ð汾�Ĺ��캯����
 */
 
//��ֵ������Ҫ����ʵ���ƶ����������ת����

#ifndef _SAMPLE_H
#define _SAMPLE_H

typedef int data_t;

class Sample
{
public:
	Sample();
	Sample(const data_t data);
	Sample(const char* name,const data_t data);
	
	//��ֵ����&ʵ�ֹ��캯��ʱ��Ϊ�˱���ǳ������ɵ�ͬһ�ڴ�ռ�������ʱ���ͷ��������⡣Ҳ���Խ���ʵ��Ϊ
	//����ת�ƶ��ڴ���Դ����Ȩ���ܵ��ƶ����캯������ͨ����ֵ����Ҳ����ʵ���ƶ����캯��/�ƶ����塣
	Sample(Sample& other);          //��ֵ����&ʵ�ֵ�ǳ�������캯��/�ƶ����캯��������һ�㲻��Ҫ������ֵ���ð汾���캯��
	Sample(const Sample& other);    //������ֵ����const &ʵ�ֵ�������캯����
	Sample(Sample&& other);         //��ֵ����&&ʵ�ֵ��ƶ����캯����
	virtual ~Sample();

	Sample& operator =(Sample& other);   //��ֵ����Sample&ʵ�ֵ�ǳ������ֵ������һ�㲻��Ҫ������ֵ���ð汾��ֵ����
	Sample& operator =(const Sample& other);  //������ֵ����const Sample&ʵ�ֵ������ֵ��
	Sample& operator =(Sample&& other);   //��ֵ����Sample&&ʵ�ֵ��ƶ���ֵ��
	
	void setName(const char* name);
	const char* getName()const;
	
	void setData(const data_t data);
	data_t getData()const;
	
	void show()const;
private:
	char *name;
	data_t data;
};

#endif //_SAMPLE_H