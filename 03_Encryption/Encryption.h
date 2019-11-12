#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

class Encryption {
private:
	std::string mText;
	std::string const mEnding;

	std::string ReadFile(std::string const& fileName, std::string& text);
	void WriteFile(std::string const& fileName, std::string& text);
protected:
	virtual void DoCipher() = 0;
	virtual void DoEncrypt() = 0;
	Encryption(std::string const& fileName);
public:
	void Encrypt(std::string const& fileName);
	void Decrypt(std::string const& fileName);
};

#endif