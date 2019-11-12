#ifndef CAESAR_H
#define CAESAR_H

#include "Encryption.h"

class Caesar : public Encryption {
private:
	size_t const mKey = 13;


public:
	Caesar() = default;
};

#endif