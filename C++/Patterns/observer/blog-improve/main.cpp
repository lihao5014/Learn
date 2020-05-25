#include "blog_csdn.h"
#include "observer_blog.h"

int main()
{
	Blog *blog = new BlogCSDN("lihao CSDN");
	Observer *observer1 = new ObserverBlog("amy",blog);
	blog->attach(observer1);
	blog->setStatus(" 发表设计模式C++实现——观察者模式 ");
	blog->notify();
	delete observer1;
	delete blog;
	
	return 0;
}