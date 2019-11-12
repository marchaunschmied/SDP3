#ifndef I_NORTEL_H
#define I_NORTEL_H
#include <string>

enum TEncoding {
	T_RSA, T_Caesar
};

class INortel {
public:
	virtual void Encipher(std::string const& fileName, TEncoding enc) = 0;
	virtual void Decipher(std::string const& fileName, TEncoding enc) = 0;

};

#endif