///////////////////////////////////////////////////////////////////////////
// Workfile :		IEpcos.h
// Author :			Marc Haunschmied
// Date :			November 2019
// Description :	Interface for Epcos
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef I_EPCOS_H
#define I_EPCOS_H
#include <string>

class IEpcos {
public:
	virtual void EncryptRSA(std::string const& fileName) = 0;
	virtual void DecryptRSA(std::string const& fileName) = 0;
	virtual ~IEpcos() = default;
};

#endif