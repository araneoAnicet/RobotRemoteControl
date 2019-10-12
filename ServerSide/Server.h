#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string>
#include "ICommand.h"
#include "IEncryption.h"


class Server {
private:
    int port = 9090;
    IEncryption* encrypter = nullptr;
    ICommand* executer = nullptr;
    int socketbf;
    char buffer[1024];
    std::string password;
    sockaddr_in server_addr;

    bool dataVerifier(std::string data);
    void passwrodEncryption(std::string password);
    
public:
    Server(std::string password);
    void setExecuter(ICommand* executer);
    void beginRecv();
};