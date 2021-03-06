///////////////////////////////////////////////////////////////////////////
// Workfile :		Object.h
// Author :			Marc Haunschmied, Markus Riegler
// Date :			11-January-2020
// Description :	Base class for all objects
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
	virtual ~Object() = default;
protected:
	Object() = default;
};

#endif
