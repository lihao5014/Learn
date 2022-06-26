/*C++��һ�ŵײ����ԣ��޷���java��C#һ�������ڶ�̬�ж϶������͵���Ϣ��ͨ��C++��ģ����ȡ����
 *����ʵ����һ��������ͨ�������ģ��ʵ�л����������Ϊ����������Ч�ʸ��ߣ�������Ӽ�ࡣ
 */

/*1.traits����������ԭ��
 *��1��C++��ģ������Ϊ���ͱ���ṩ��֧�֡�ʹ���ǾͿ��Ա�д����ͨ�õĴ��룬�����ع���ȥ
 *     ���Ĳ��������͡�Ȼ����ʵȴ�����͵Ĳ�ͬ���ܶ�ʱ��ȴӰ�쵽���㷨�е�ĳ��СС��ʵ�֡�
 *     ����Ϊ�˽�����������⣬C++�е�traits���ɱ����������ˡ�
 *��2���������������һЩ��װ��ͨ���㷨�е�ĳЩ���֣�����Ϊ�������Ͳ�ͬ�����´�����߼�
 *     ��ͬʱ��traits����һ�ֺܺõĽ��������
 *��3��traits�����򵥵�˵���ǣ�����һ�����ԣ���ȡһ��������ԡ�
 */

/*2.����������ȡ������
 *��1��traits�ֱ�����������ȡ������˵�ü򵥵������ȡ���������Ķ��󡱶�Ӧ�ķ������ͣ�
 *     ��ͬһ���ӿ�ʵ�ֶ�Ӧ�Ĺ��ܡ���ΪSTL���㷨�������Ƿ���ģ�����ͨ�����������ӡ�
 *     �㷨��ʵ�ֲ���֪���Լ���������ʲô����ȡ���൱���ڽӿں�ʵ��֮���һ���װ��
 *     ������һЩϸ�ڲ�Э�����ú��ʵķ���������Ҫƫ�ػ��ȼ��ɡ�
 *��2��traits������STL���бȽϳ�����һ��C++���Լ��ɱ�﷽ʽ֮һ��ͨ��C++ģ���������
 *     ������������ȡ��������ͬһ���ӿ�ʵ�ֶ�Ӧ�Ĺ��ܡ��ر������㷨�������п��Խ���
 *     ������Ķ������ͣ�ʹ������ͨ��������ʵ�����ӡ�
 *��3��type_traits��C++11�ṩ��ģ��Ԫ��̻����⣬ͨ��type_traits����ʵ���ڱ����ڼ��㡢
 *     ��ѯ���жϡ�ת����ѡ���ṩ��ģ��Ԫ�����Ҫ��һЩ����Ԫ������
 *��4��traits�����Ĺؼ�����ʹ�õ�����traitsģ���࣬����ģ���ػ��Ĺ��ܣ�ʵ�ֶ��Զ���
 *     �������ͺͱ����������������͵�ͳһ��tratis���������ڱ�׼���ʵ���У������ճ�
 *     �����н��ʹ�������Ҳ�кܺõĽ�����塣
 */

/*3.traits������ʵ�֣���ģ���ȫ�ػ���ƫ�ػ���traitsʹ�õĹؼ�������
 *���ǽ���Ϊģ���βΣ����������βΡ��������βΣ���ͬ�����µĲ�ͬ����ȡ���µ�ģ����ȥ��
 *Ȼ��ͨ��ģ����ػ���ȫ�ػ���ƫ�ػ����ɣ����ֱ�ʵ���䲻ͬ����һ���ģ�嶼����������
 *����traits��ʾ��������Ҳ���������һ�෽����ΪC++��traits������traits����չ�ֳ�
 *��һ�ֱ�̵�˼�룬Ҳ������ͬ��������ã�����ͬ�Ĳ���ͨ���ӿ���ʵ�֡���ģ���β�����
 *��ͬ��ʵ�ְ���һ����ʵ�����ģʽ�еĲ���ģʽ�����ƣ������ֳ�����ͬ�ı��˼�롣
 *ֻ����ǰ���Ǳ���ʱȷ���ģ�������������ʱȷ���ġ�
 */

#include <iostream>
#include <iterator>

#define UNUSED(x) (void)x;

using namespace std;

class Polygon
{
public:
	void paint()
	{
		cout<<"Polygon::paint()"<<endl;
	}
};

class Circle
{
public:
	void draw()
	{
		cout<<"Circle::draw()"<<endl;
	}
};

template <typename Shape>
struct Painter
{
	typedef Shape shape_type;    //Ϊ�㷨��ȡ�����á�
	
	static void onDraw(shape_type shape)
	{
		cout<<"onDraw(): other shape"<<endl;
	}
};

template <>
struct Painter<Polygon>
{
	typedef Polygon shape_type;   //Ϊ�㷨��ȡ�����á�
	
	static void onDraw(shape_type shape)
	{
		shape.paint();
	}
};

template <>
struct Painter<Circle>
{
	typedef Circle shape_type;
	
	static void onDraw(shape_type shape)
	{
		shape.draw();
	}
};

/*���е�ͼ������û��ʹ�ü̳кͶ�̬��Ҳû����Ϊ��ͬ����״��������if-else��switch�жϡ�
 *���������ִ�л���ͼ�Σ��Զ������˸���ͼ���Լ��Ļ��ƺ�����������Ǳ����ھ;������ˡ�
 *�����C++ traits��ȡ����������ĿҪ���Ч�������¾����Ƿǳ��õ�ѡ��
 */
template <typename Shape>
void drawByObject(Shape s)
{
	Painter<Shape>::onDraw(s);
}

/*drawByType()�����ܻ���ϵͳ�����е�ͼ�Σ���Circle��Polygon��Rectangle�ȣ���ͬʱ�滭�����п���
 *Ҫ��������ͼ�ε���ʱ���󣨾���Ҫ��̬��ȡ�����ͼ�����ͣ�������ĳ�־���ͼ�ε��㷨�Ͽ϶��в��죬
 *����ʹ��drawByType()��ʹ������˵����������Щ��ҲӦ�ò�ȥ������Щ��ֻ��Ҫ����drawByType()������
 *�����Լ���ͼ�ξͿ����ˡ�
 */
template <typename Shape>
void drawByType()
{
	typedef typename Painter<Shape>::shape_type shape_type;   //�㷨����ȡ�Ķ�Ӧ���͡�
	
	shape_type temp_shape;                //ʹ��traits������ȡ��������������ʱ����
	Painter<Shape>::onDraw(temp_shape);
}

auto main(int argc,char* argv[]) -> int
{
	UNUSED(argc);
	UNUSED(argv);
	
	Polygon polyon;
	Circle circle;
	
	drawByObject(polyon);
	drawByObject(circle);
	
	drawByType<Polygon>();
	drawByType<Circle>();
	
	return 0;
}

