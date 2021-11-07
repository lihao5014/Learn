/*��C++11������˶���ԭʼ�ַ����������������巽ʽΪ��R ��xxx(ԭʼ�ַ���)xxx�� ���У������ߵ��ַ�������ʡ�ԡ�
 *ԭʼ������R����ֱ�ӱ�ʾ�ַ�����ʵ�ʺ��壬������Ҫ������ַ�����ת������ӵȲ�����
 */

/*��̹����У�ʹ�õ��ַ����г�����һЩ�����ַ���������Щ�ַ�����Ҫ��ר�ŵĴ���
 *ʹ����ԭʼ�������Ϳ������ɵĽ����������ˣ������ӡ·�������html��ǩ�����json�ļ��ȡ�
 */

/*��R��xxx(raw string)xxx���У�ԭʼ�ַ�������������()�����������ŵ�ǰ����Լ������ַ�����
 *���ӵ��ַ����ᱻ���ԣ����Ҽӵ��ַ�����������������ͬʱ���֡�
 */

#include <iostream>

#define _ERROR_
// #undef _ERROR_

using namespace std;

int main(int argc,char** argv)
{
	string str = "hello world \test";
	cout<<str<<endl;
	
	str = R"(hello world \test)";
	cout<<str<<endl;
	
	string path = "D:\hello\world\test.text";    //�ַ�����'\h'��'\w'ת��ʧ�ܣ���Ӧ���ַ���ԭ�������
	cout<<path<<endl;
	
	str = "D:\\hello\\world\\test.text";    //��Ϊ��\����ת���ַ���������Ҫʹ��ת���ַ�����ת�룬���ղ��ܵõ�һ��û�����⺬�����ͨ�ַ�\��
	cout<<path<<endl;
	
	path = R"(D:\hello\world\test.text)";    //ԭʼ������R()�е����ݾ�������·����ԭʼ�ַ������������κδ���
	cout<<path<<endl;
	
	string html = "<html>                           \
                     <head>                         \
                       <title>                      \
                         ������                     \
                       </title>                     \
                     </head>                        \
                     <body>                         \
                       <p>                          \
                         ����Ҫ��Ϊ������������!!!  \
                       </p>                         \
                     </body>                        \
                   </html>";
    cout<<html<<endl;
	
	/*��C++11֮ǰ���һ���ַ�����д���˲�ͬ������ߣ���Ҫ�����ӷ������ַ�ʽ�������������ƻ��˱��ʽ��ԭʼ���塣
	 *���ʹ��ԭʼ�������ͱ�ü򵥺ܶ࣬��ǿֱ�ۣ��ɶ���ǿ��
	 */
	html = R"(
<html>                         
  <head>                       
    <title>                    
      ������                   
    </title>                   
  </head>                      
  <body>                       
    <p>                        
      ����Ҫ��Ϊ������������!!!
    </p>                       
  </body>                      
</html>)";
	cout<<html<<endl;
	
	/*ʹ��ԭʼ������R��xxx(raw string)xxx��,()���ߵ��ַ����ڽ�����ʱ���ǻᱻ���Եģ����һ�㲻��ָ����
	 *�����()ǰ��ָ�����ַ�������ôǰ����ַ���������ͬ�����������﷨����
	 */
#ifdef _ERROR_
	path = R"foo(D:\hello\world\test.text)bar";
#else
	path = R"foo(D:\hello\world\test.text)foo";
#endif
	cout<<path<<endl;

	return 0;
}