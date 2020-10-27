#ifndef _CALCULATOR_H
#define _CALCULATOR_H

//控制器用于获取视图界面的输入值和响应视图的输入事件，并将视图输入值传递给模型处理。
//当模型将输入值处理完以后，模型再通过控制器将处理结果交给视图去显示，即通过控制器更新界面。
typedef enum Event
{
	INIT,      //清除半径和面积label，恢复界面初始化事件
	INPUT,     //输入半径值事件
	CLICK,     //点击计算事件
	QUIT       //退出程序事件
}Event_t;

class CalculatorUi;     //视图必须提供获取用户输入值，获取用户输入事件和更新界面显示值的三个接口
class CalculatorModel;    //模型必须提供获取输入数据，处理输入数据和返回处理结果的三个接口

class Calculator   //控制器必须提供将视图输入值传递给模型处理，并将模型处理结果返回给视图渲染的功能接口
{
public:
	Calculator();
	virtual ~Calculator();
	
	void run();
private:
	Calculator(const Calculator& other);
	Calculator& operator =(const Calculator& other);
	
	void onInitUi();           //使用函数来封装对view和model的操作，即封装control类的变化点，以实现类之间的高内聚、低耦合。
	void onInputRadius();
	void onCalculate();
	void processEvent();
	
	int event;              //界面处理事件，用于实现界面更新状态机
	CalculatorUi *pview;
	CalculatorModel *pmodel;
};

#endif //_CALCULATOR_H