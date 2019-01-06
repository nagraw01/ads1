#ifndef IMARKOV_H
#define IMARKOV_H



template<class T>
class IMarkov
{
public:
	IMarkov() {}
	virtual void add(T,T) = 0;
	virtual void generate(int) = 0;

	virtual ~IMarkov() {}


};

#endif

