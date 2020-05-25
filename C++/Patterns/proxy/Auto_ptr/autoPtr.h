template<class T>
class Auto_ptr {
private:
    T *ptr;        //真正的指针值
    mutable bool owns;    //是否拥有该指针
public:
    //不可以隐式转化的构造函数
    explicit Auto_ptr(T *p = 0):ptr(p),owns((bool)p){}    //不能隐式转化，例如Auto_ptr<int> Ap = new int(1024) //error
    //复制构造函数
    //Auto_ptr(const Auto_ptr& a):ptr(a.ptr),owns(a.owns){ a.owns = 0;}
    //泛化版的复制构造函数
    template <class U>
    Auto_ptr(const Auto_ptr<U>& a):ptr(a.ptr),owns(a.owns){ a.owns = 0;}

    //重载赋值操作符
    Auto_ptr& operator=(const Auto_ptr& a)
    {
        if(&a != this)    //防止自身赋值
        {
            if(owns)
                delete ptr;
            owns = a.owns;
            ptr  = a.ptr;
            a.owns = 0;
        }
		return *this;
    }
    //泛化版的重载赋值操作符
    template<class U>
    Auto_ptr& operator=(Auto_ptr<U>& a)
    {
        if (&a != this)
        {
            if(owns)
                delete ptr;
            owns = a.owns;
            ptr  = a.ptr;
            a.owns = false;
        }
        return *this;
    }
    T& operator  *() const {return *ptr;} 
    T* operator ->() const {return ptr;}
    T* get() const { return ptr;}
    void reset(T *p = 0)
    {
        if(owns)
        {
            if(ptr != p)    //如果p 和 ptr的值不同    
            {
                delete ptr;    //删除原来指向的对象
            }                //else付过相同肯定不能删除啊
        }
        ptr = p;            //这里赋值时安全的，机试ptr和p原来相等
    }
    T* release() const{ owns = false;return ptr;}
    ~Auto_ptr(){if(owns) {cout << "析构！"<< endl;delete ptr;}}
};