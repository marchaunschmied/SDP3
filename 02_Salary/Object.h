///////////////////////////////////////////////////////////////////////////
// Workfile :		Object.h
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef Object_H
#define Object_H

class Object {
public:
	//pure virtual
	virtual ~Object() = 0;

};

//is needed???
inline Object::~Object(){}

#endif
