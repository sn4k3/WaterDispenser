// LibraryClass.h

#ifndef _LIBRARYCLASS_h
#define _LIBRARYCLASS_h

class LibraryClass
{
 protected:


 public:
	virtual ~LibraryClass()
	{
	}

	virtual void init() = 0;
	virtual void loop() = 0;
};

#endif

