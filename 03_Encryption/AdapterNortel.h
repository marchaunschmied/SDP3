#ifndef ADAPTER_NORTEL_H
#define ADAPTER_NORTEL_H

#include "INortel.h"
#include "Encryption.h"
#include "RSA.h"
#include "Caesar.h"

class AdapterEpcos : public INortel {
public:
	RSA mRSA;
	Caesar mCaesar;
};
#endif	
