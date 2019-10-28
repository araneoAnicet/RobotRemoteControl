#pragma once
#include <unistd.h>
#include <string.h>

class IEncryption {
protected:
    char* result;
    const char* salt;
public:
    virtual void encrypt(const char* message) = 0;
    virtual char* decrypt(const char* message) = 0;
    virtual bool verify(const char* inputMessage) = 0;
    virtual void setSalt(const char* salt) = 0;
    virtual char* getEncrypted() = 0;
};

class DefaultEncryptor: public IEncryption {
private:
    
    char commands[4][9] = {"forward", "left", "right", "backward"};
public:

    void setSalt(const char* salt) override {
        this->salt = salt;
    }

    void encrypt(const char* message) override {
        this->result = crypt(message, this->salt);
    }

    bool verify(const char* inputMessage) override {
        
        for (int i = 0; i < 4; i++) {
            if (strcmp(crypt(this->commands[i], this->salt), inputMessage) == 0) {
                return true;
            }
        }
        return false;
    }

    char* decrypt(const char* message) override {
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