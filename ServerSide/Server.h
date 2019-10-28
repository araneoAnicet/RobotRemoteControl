#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "ICommand.h"
#include "IEncryption.h"


class Server {
private:
    int port = 9090;
    IEncryption* encryptor = nullptr;
    ICommand* executer = nullptr;
    int socketbf;
    char buffer[1024];
    char* password;
    sockaddr_in server_addr;

    bool dataVerifier(char* data);
    
public:
    Server();
    ~Server();
    void setEncryptor(IEncryption* encryptor);
    void setPassword(char* password);
    void setExecuter(ICommand* executer);
    void beginRecv();
};