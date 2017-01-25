#ifndef EXPRESSION_H
#define EXPRESSION_H

template <class T>
class Expression
{
public:
	virtual T evaluate() = 0;
};

#endif