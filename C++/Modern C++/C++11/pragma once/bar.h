/*1.��C/C++����ʹ��Ԥ����ָ��#include��ʱ��Ϊ�˷�ֹ�ظ�������ɶ����ԣ�ͨ�������ַ�ʽ��
 *��1����һ����#ifndefָ���ֹ������ظ����á�
 *��2���ڶ��־�������Ҫ�������ļ���ͷд��#pragma onceָ�
 */

/*2.#pragma once��#ifndefָ�����ȱ�㣺
 *��1��#ifndef��ʽ��C/C++���Եı�׼֧�֣�Ҳ�ǱȽϳ��õķ�ʽ��#ifndef�ķ�ʽ�������Զ���ĺ������ܳ�ͻ��
 *     ��������Ա�֤ͬһ���ļ����ᱻ�������Σ�Ҳ�ܹ���֤��ͬ�ļ�����ȫ��ͬ�����ݲ��ᱻ�������Ρ�
 *     ������Զ���ĺ겻С�ġ��������ˣ����ݲ�ͬ���ļ�ʹ��ͬһ�������#ifndef���ᵼ�±������Ҳ��������������
 *     ���������ж�Ϊ�ض���������ˡ�
 *��2�����ڱ�����ÿ�ζ���Ҫ��ͷ�ļ������ж��Ƿ����ظ����壬�����ڱ��������Ŀʱ��#ifndef��ʹ�ñ���ʱ����Խϳ���
 *     ���һЩ�������𽥿�ʼ֧��#pragma once�ķ�ʽ��Visual Studio 2017�½�ͷ�ļ����Դ�#pragma onceָ�
 *��3��#pragma onceһ���ɱ������ṩ��֤��ͬһ���ļ����ᱻ������Ρ�������˵�ġ�ͬһ���ļ�����ָ�����ϵ�һ���ļ���
 *     ������ָ������ͬ�������ļ����޷���һ��ͷ�ļ��е�һ�δ�����#pragma once��������ֻ����������ļ���
 *     �˷�ʽ������ֺ�����ײ������������⣬������Ŀ�ı����ٶ�Ҳ����ṩ��һЩ��ȱ�������ĳ��ͷ�ļ��ж�ݿ�����
 *     �÷������ܱ�֤���ǲ����ظ���������C/C++��#pragma once��һ���Ǳ�׼���Ǳ��㷺֧�ֵķ�ʽ��
 *��4�� #pragma once��ʽ������#ifndef֮��#ifndef��ʽ��C/C++���Ա�׼��֧�֣����ܱ��������κ����ƣ�
 *     ��#pragma once��ʽ��Щ���ϱ�������֧�֣������Բ����á�#ifndef�������һ���ļ��еĲ��ִ��룬
 *     #pragma onceֻ����������ļ�����Զ���#ifndef�����������Ժã�#pragma once�����򵥣�Ч�ʸߡ�
 */

#ifndef _BAR_H
#define _BAR_H

#include "foo.h"

#pragma message("include bar.h once")

extern void bar(const char* str);

#endif //_BAR_H