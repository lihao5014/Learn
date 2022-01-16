/*1.�ж�C++��׼�汾:
 *��1��clang��gcc���������ж�__cplusplus���ֵ��
 *��2��msvc���������ж�_MSVC_LANG���ֵ��
 */

/*2.��ͬC++��׼�汾�У�__cplusplus��_MSVC_LANG����Ӧ��ֵ��
 *  C++17	    201703L
 *  C++14	    201402L
 *  C++11	    201103L
 *  C++03����	199711L
 */

/*3.�ж�C++ʹ�õı�������
 *��1��msvc��������_MSC_VER
 *��2��clang��������__clang__
 *��2��gcc��������__GNUC__
 */

/*4.�������л�֧�ֵ�C++��׼ѡ�
 *��1��gcc��������-std=c++98��-std=c++11��-std=c++14��-std=c++17��
 *��2��msvc��������/std:c++14��/std:c++17��/std:c++latest��ע��VC++��������/stdѡ���Ǵ�vs2015 Update3��ʼ֧�ֵġ�
 */

/*5. msvc��������C++��׼�汾��֧�֣�
 *��1��Ĭ������£�Visual Studioʼ��Ϊ__cplusplusԤ�������귵��ֵ��199711L����__cplusplusԤ��������ͨ�����ڱ��档
 *     ��Ϊ�ܶ����д�����Ҫ�˺��ֵ�롰199711L��ƥ�䣬���Ա�����������Ĵ˺��ֵ������ͨ��ʹ��/Zc:__cplusplus
 *     ������ѡ�������ʽѡ�� 
 *��2����Visual Studio 2017�汾15.7��ʼ�����ṩ/Zc:__cplusplusѡ���ѡ����Ĭ������´��ڽ���״̬��
 *��3��/Zc:__cplusplus������ѡ������__cplusplusԤ����������������µ�C++���Ա�׼֧�ֱ�����µ�ֵ��
 *��4����������/Zc:__cplusplusѡ�������£�__cplusplus�����ֵȡ����/std�汾�л����á�
 *��5��_MSVC_LANGԤ��������׼�汾����/Zc:__cplusplus�����û��ǽ���״̬���������/Zc:__cplusplus��
 *     ��__cplusplus == _MSVC_LANG��
 */

/*6._MSVC_LANG�꣺
 *����Ϊָ�������������C++���Ա�׼�������ı��� �˺���ڱ���ΪC++�Ĵ��������á� Ĭ������£�
 *���ߵ�ָ����/std:c++14������ѡ��ʱ���˺�Ϊ�����ı�ֵ201402L�����ָ����/std:c++17������ѡ�
 *��˺�����Ϊ201703L�����ָ����/std:c++20������ѡ���˺�����Ϊ202002L����ָ����/std:c++latestѡ��ʱ��
 *������Ϊ���ߵ�δָ��ֵ������������򲻻ᶨ��˺ꡣ��vs2015 Update3��ʼ���ṩ_MSVC_LANG���/std������ѡ�
 */

#ifndef CPP_STANDARD_H
#define CPP_STANDARD_H

#if defined(__clang__) || defined(__GNUC__)
	#define CPP_STANDARD __cplusplus
#elif defined(_MSC_VER)
	#define CPP_STANDARD _MSVC_LANG
#endif
 
#if CPP_STANDARD >= 199711L
	#define HAS_CPP_03 1
#endif
#if CPP_STANDARD >= 201103L
	#define HAS_CPP_11 1
#endif
#if CPP_STANDARD >= 201402L
	#define HAS_CPP_14 1
#endif
#if CPP_STANDARD >= 201703L
	#define HAS_CPP_17 1
#endif

#endif   //CPP_STANDARD_H