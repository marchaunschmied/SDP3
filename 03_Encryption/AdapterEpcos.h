#ifndef ADAPTER_EPCOS_H
#define ADAPTER_EPCOS_H

#include "IEpcos.h"
#include "Encryption.h"
#include "RSA.h"

class AdapterEpcos : public IEpcos {
public:
	RSA mRSA;
};
#endif	
