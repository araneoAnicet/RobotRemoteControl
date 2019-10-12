#include <string>

class IEncryption {
protected:
    std::string result;
public:
    virtual void encrypt() = 0;
    virtual bool verify() = 0;
    virtual std::string getEncrypted() = 0;
};

class SHA256Encryptor: public IEncryption {
    // data
};