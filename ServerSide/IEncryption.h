#include <unistd.h>
#include <string.h>

class IEncryption {
protected:
    char* result;
    char* salt;
public:
    virtual void encrypt(char* message) = 0;
    virtual char* decrypt(char* message) = 0;
    virtual bool verify(char* inputMessage) = 0;
    virtual void setSalt(char* salt) = 0;
    virtual char* getEncrypted() = 0;
};

class DefaultEncryptor: public IEncryption {
private:
    
    char commands[4][9] = {"forward", "left", "right", "backward"};
public:

    void setSalt(char* salt) override {
        this->salt = salt;
    }

    void encrypt(char* message) override {
        this->result = crypt(message, this->salt);
    }

    bool verify(char* inputMessage) override {
        
        for (int i = 0; i < 4; i++) {
            if (strcmp(crypt(this->commands[i], this->salt), inputMessage) == 0) {
                return true;
            }
        }
        return false;
    }

    char* decrypt(char* message) override {
        for (int i = 0; i < 4; i++) {
            if (strcmp(crypt(this->commands[i], this->salt), message) == 0) {
                return this->commands[i];
            }
        }
        return nullptr;
    }

    char* getEncrypted() override {
        return this->result;
    }
};