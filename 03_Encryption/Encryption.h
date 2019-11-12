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
	virtual void DoCipher(std::string& text) = 0;
	virtual void DoDecipher(std::string& text) = 0;
	Encryption(std::string const& ending);
public:
	void Encrypt(std::string const& fileName);
	void Decrypt(std::string const& fileName);
};

#endif