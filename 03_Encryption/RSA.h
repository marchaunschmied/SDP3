#ifndef RSA_H
#define RSA_H

#include "Encryption.h"

class RSA : public Encryption{
private:
	size_t const mN = 187;
	size_t const mE = 7;
	size_t const mD = 23;

	
protected:
	virtual void DoCipher(std::string& text) override;
	virtual void DoDecipher(std::string& text) override;

public:
	RSA();

};

#endif