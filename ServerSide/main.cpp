#include "Server.cpp"

// g++ main.cpp -lcrypt -o main

int main() {
    Server* controlServer = new Server("13121978");
    IEncryption* encryptor = new DefaultEncryptor();
    encryptor->setSalt("4tyt3");
    controlServer->setEncryptor(encryptor);
    controlServer->setExecuter(new PrintOutput());
    controlServer->beginRecv();
    delete controlServer;
    return 0;
}