///////////////////////////////////////////////////////////////////////////
// Workfile :		Object.h
// Author :			Marc Haunschmied, Markus Riegler
// Date :			03-December-2019
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