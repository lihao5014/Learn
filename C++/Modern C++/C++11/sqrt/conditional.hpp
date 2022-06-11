#ifndef _CONDITIONAL_HPP_
#define _CONDITIONAL_HPP_

template <bool B,typename Then,typename Else>
struct Conditional
{
	
};

template <typename Then,typename Else>
struct Conditional<true,Then,Else>
{
	typedef Then type;
};

template <typename Then,typename Else>
struct Conditional<false,Then,Else>
{
	typedef Else type;
};

#endif  //_CONDITIONAL_HPP_