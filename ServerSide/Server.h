#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "ICommand.h"
#include "IEncryption.h"


class Server {
private:
    static const int port = 9090;
    IEncryption* encryptor = nullptr;
    ICommand* executer = nullptr;
    int socketfd;
    static const int bufferSize = 1024;
    char buffer[bufferSize];
    char* password;
    sockaddr_in serverAddr, clientAddr;

    bool dataVerifier(char* data) {
        return this->encryptor->verify(data);
    }

public:
    Server(char* password);
    ~Server();
    void setEncryptor(IEncryption* encryptor);
    void setPassword(char* password);
    void setExecuter(ICommand* executer);
    void beginRecv();
};