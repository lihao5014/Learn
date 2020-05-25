#include<iostream>

using namespace::std;

class OutClass{
public:
    OutClass(){
       cout<<"OutClass constructor"<<endl;
    }

    ~OutClass(){
      cout <<"OutClass destructor"<<endl;
    }
    //如果内部类定义在public中,则可以通过外部类::内部类来进行生成内部类对象
    class InnerClassOne{
    public:
        InnerClassOne(){
          cout<<"InnerClassOne constructor"<< endl;
        }
        ~InnerClassOne(){
          cout <<"InnerClassOne destructor"<<endl;
        }
        void setInnerClassOneMember(int innerClassOneMember){
            innerClassOneMember = innerClassOneMember;
        }
        //内部类可以直接去访问外部类的静态成员,枚举变量,而不需要去使用外部类对象名,静态成员属于类,不属于对象
        void showOutClassMember(){
          cout<<"static member:"<< static_member << endl;
          //注意:内部类不能够直接访问外部类的非静态成员,因为这是需要外部类对象的
          //cout << "member:" <<member<endl;
        }
    private:
        int innerClassOneMember;
    };

    //内部类可以在外部类中先去声明,然后去外部实现
    class InnerClassFour;
	
private:
    int member;
    static int static_member;

    //如果定义在private中,那么这个内部类只能在外部类本类中进行使用,在外部不能够定义内部类的对象
    class InnerClassTwo{
    public:
		InnerClassTwo(){
          cout <<"InnerClassTwo constructor" <<endl;
        }
        ~InnerClassTwo(){
          cout<<"InnerClassTwo destructor"<<endl;
        }
    };

protected:
    //定义在proteced中的内部类,也是不可以在外部定义的
    class InnerClassThree{
      public:
        InnerClassThree(){
          cout<<"InnerClassThree constructor" << endl;
        }
        ~InnerClassThree(){
          cout<<"InnerClassThree destructor" << endl;
        }
    };
};

int OutClass::static_member = 0;

//声明的内部类的实现
class OutClass::InnerClassFour{
  public:
     void showStaticMember(){
       cout <<"static_member:"<< static_member << endl;
     }
};

int main(){
  //创建一个外部类
  OutClass outclass;
  //创建一个内部类InnerClassOne
  OutClass::InnerClassOne innerclassOne;
  innerclassOne.setInnerClassOneMember(5);
  innerclassOne.showOutClassMember();

  //创建内部类InnerClassFour
  OutClass::InnerClassFour innerclassFour;
  innerclassFour.showStaticMember();

  //创建内部类InnerClassThree
  //OutClass::InnerClassThree innerclassthree;

  //输出OutClass的大小
  cout<<"sizeof OutClass:"<<sizeof(OutClass)<<endl;
  //输出InnerClass的大小
  cout<<"sizeof InnerClassOne:"<<sizeof(OutClass::InnerClassOne)<<endl;


  return 0;
}