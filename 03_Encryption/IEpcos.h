#ifndef I_EPCOS_H
#define I_EPCOS_H
#include <string>
class IEpcos {
public:
	virtual void EncryptRSA(std::string const& fileName) = 0;
	virtual void DecryptRSA(std::string const& fileName) = 0;

};

#endif