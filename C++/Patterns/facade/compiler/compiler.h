#ifndef _COMPILCER
#define _COMPILCER

#include <iostream>

class Scanner
{
public:
	void scan()
	{
		std::cout<<"´Ê·¨·ÖÎö"<<std::endl;
	}
};

class Parser
{
public:
	void parse()
	{
		std::cout<<"Óï·¨·ÖÎö"<<std::endl;
	}
};

class Compile
{
public:
	void compile()
	{
		std::cout<<"±àÒë"<<std::endl;
	}
};

class Assembly
{
public:
	void assemble()
	{
		std::cout<<"»ã±à"<<std::endl;
	}
};

class Linker
{
public:
	void link()
	{
		std::cout<<"ÏÎ½Ó"<<std::endl;
	}
};

class Compiler
{
public:
	void compile()
	{
		scanner.scan();
		parser.parse();
		compiling.compile();
		assembly.assemble();
		linker.link();
	}
private:
	Scanner scanner;
	Parser parser;
	Compile compiling;
	Assembly assembly;
	Linker linker;
};

#endif //_COMPILCER