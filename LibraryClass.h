// LibraryClass.h

#ifndef _LIBRARYCLASS_h
#define _LIBRARYCLASS_h

#include "Config.h"
#include "Macros.h"

class LibraryClass
{
 protected:


 public:
	virtual ~LibraryClass()
	{
	}

	virtual void init() = 0;
	virtual void loop() = 0;
	virtual void on() = 0;
	virtual void off() = 0;
};

#endif

