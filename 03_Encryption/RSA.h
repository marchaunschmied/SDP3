#ifndef RSA_H
#define RSA_H

#include "Encryption.h"

class RSA : public Encryption{
private:
	size_t const mN = 187;
	size_t const mE = 7;
	size_t const mD = 23;

public:
	RSA() = default;
};

#endif