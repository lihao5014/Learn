#include "simplify.h"
#include <stdio.h>

#define THRESHOLD 5

void use_else(data_t value)
{
	if(value == THRESHOLD)
	{
		fputs("value is equal threshold\n",stdout);
	}
	else
	{
		fputs("value is't equal threshold\n",stdout);
	}
	
	puts("use_case end");            //对于if else后面还有操作的情况，且else里面的语句不能提到if判断以前，不能优化
}

#ifndef _CHANGE_WAY_
void use_return(data_t value)
{
	if(value > THRESHOLD)
	{
		puts("use_return: value is larger than threshold");
	}
	else if(value < THRESHOLD)
	{
		puts("use_return: value is less than threshold");
	}
	else
	{
		puts("use_return: value is equal threshold");
	}
}
#else
void use_return(data_t value)         //提前return
{
	if(value > THRESHOLD)
	{
		puts("use_return: value is larger than 5");
		return ;
	}
	else if(value < THRESHOLD)
	{
		puts("use_return: value is less than threshold");
		return ;
	}
	puts("use_return: value is equal or lesser than 5");
}	
#endif

#ifndef _CHANGE_WAY_
void use_break(data_t value)
{
	while(value --> 0)
	{
		if(value <= THRESHOLD)
		{
			if(value == THRESHOLD)
			{
				fputs("use_break: value equal threshold\n",stdout);
			}
			else
			{
				printf("use_break: value =%d\n",value);
			}
		}
	}
	
	puts("use_break end");
}
#else
void use_break(data_t value)
{
	while(value --> 0)
	{
		if(value > THRESHOLD)
		{
			break;
		}
		
		if(value == THRESHOLD)
		{
			fputs("use_break: value equal threshold\n",stdout);
			continue;
		}
		printf("use_break: value =%d\n",value);
	}
	puts("use_break end");
}	
#endif

#ifndef _CHANGE_WAY_
void use_continue(data_t value)
{
	if(value >= THRESHOLD)
	{
		while(value --> 0)
		{
			if(value == THRESHOLD)
			{
				fputs("use_continue: value equal threshold\n",stdout);
			}
			else
			{
				printf("use_continue: value =%d\n",value);
			}
		}
	}
	else
	{
		fputs("value is less than threshold\n",stdout);
	}
}
#else
void use_continue(data_t value)
{
	if(value < THRESHOLD)
	{
		fputs("value is less than threshold\n",stdout);
		return ;
	}
	
	while(value --> 0)
	{
		if(value == THRESHOLD)              //提前continue
		{
			fputs("use_continue: value equal threshold\n",stdout);
			continue;
		}
		printf("use_continue: value =%d\n",value);
	}	
}	
#endif

#ifndef _CHANGE_WAY_
data_t use_switch(data_t x,data_t y, Option opt)
{
	data_t ret = 0;
	if(opt == '+')
	{
		ret = add(x,y);
	}
	else if(opt == '-')
	{
		ret = sub(x,y);
	}
	else if(opt == '*' || opt == 'x')
	{
		ret = mult(x,y);
	}
	else if(opt == '/')
	{
		ret = divi(x,y);
	}
	else
	{
		fprintf(stdout,"use_switch: opt is illegal\n");
	}
	
	return ret;
}
#else
data_t use_switch(data_t x,data_t y, Option opt)
{
	switch(opt)
	{
	case ADD:
		return add(x,y);
	case SUB:
		return sub(x,y);
	case 'x':
	case MULT:
		return mult(x,y);
	case DIVI:
		return divi(x,y);
	default:
		printf("use_switch: opt is illegal\n");
	}
	
	return 0;
}	
#endif

#ifndef _CHANGE_WAY_
data_t use_operator(data_t value)
{
#if TRUE
	if(value >= THRESHOLD)
	{
		printf("use_operator: return %d\n",value);
		return value;
	}
	else             //这个else完全没有必要，因为else前面的if语句中都要return
	{
		printf("use_operator: return %d\n",THRESHOLD);
		return THRESHOLD;
	}
#else
	if(value > = THRESHOLD)
	{
		printf("use_operator: return %d\n",value);
		return value;
	}
	printf("use_operator: return %d\n",THRESHOLD);
	return THRESHOLD;
#endif
}
#else
data_t use_operator(data_t value)
{
	value = value >= THRESHOLD ? value : THRESHOLD;
	printf("use_operator: return %d\n",value);
	return value;
}
#endif

#ifndef _CHANGE_WAY_
void front(data_t value,data_t *num)
{
	if(value > THRESHOLD)
	{
		*num = THRESHOLD * 2;
	}
	else
	{
		*num = THRESHOLD;
	}
	
	printf("value =%d, num =%d\n",value,*num);
}
#else
void front(data_t value,data_t *num)
{
	*num = THRESHOLD;                     //将else语句块中的语句前置，以去掉else
	if(value > THRESHOLD)
	{
		*num = THRESHOLD * 2;
	}
	
	printf("value =%d, num =%d\n",value,*num);
}	
#endif

#ifndef _CHANGE_WAY_     
void merge(data_t value,data_t num)
{
	if(value >= THRESHOLD)
	{
		if(num >= THRESHOLD)
		{
			puts("merge: threshold is smallest");
		}
	}
	
	if(value/2 < THRESHOLD)
	{
		fputs("merge: threshold is larger than half\n",stdout);
		return ;
	}
	
	if(num/2 < THRESHOLD)
	{
		fputs("merge: threshold is larger than half\n",stdout);
	}
}
#else
void merge(data_t value,data_t num)
{
	if(value >= THRESHOLD && num >= THRESHOLD)
	{
		puts("merge: threshold is smallest");
	}
	
	if(value/2 < THRESHOLD || num/2 < THRESHOLD)
	{
		fputs("merge: threshold is larger than half\n",stdout);
	}
}	
#endif

#if _CHANGE_WAY_
void tableDriven(data_t x,data_t y, Option opt)
{
	switch(opt)
	{
	case '+':
		add(x,y);
		break;
	case '-':
		sub(x,y);
		break;
	case 'x':
	case '*':
		mult(x,y);
		break;
	case '/':
		divi(x,y);
		break;
	case '>':
		max(x,y);
		break;
	case '<':
		min(x,y);
		break;
	default:
		printf("tableDriven: opt is illegal\n");
	}
}
#else
void tableDriven(data_t x,data_t y, Option opt)
{
	for(int i=0;i<messageMap_size;++i)
	{
		if(messageMap[i].opt == opt)
		{
			messageMap[i].pfun(x,y);
			return ;
		}
	}
	
	printf("tableDriven: opt is illegal\n");
}
#endif

void stateMachine(data_t value); 

#ifndef _CHANGE_WAY_
void strategyPattern(data_t x,data_t y,Option opt)
{
	if(opt == ADD)
	{
		add(x,y);
		return ;
	}
	else if(opt == SUB)
	{
		sub(x,y);
		return ;
	}
	else if(opt == MULT || opt == 'x')
	{
		mult(x,y);
		return ;
	}
	else if(opt == DIVI)
	{
		divi(x,y);
		return ;
	}

	fprintf(stdout,"strategyPattern: opt is illegal\n");
}
#else
void strategyPattern(data_t x,data_t y, pFun pfun)
{
	if(pfun == NULL)
	{
		fprintf(stdout,"strategyPattern: opt is illegal\n");
		return ;
	}
	
	pfun(x,y);
}	
#endif