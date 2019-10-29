#include "Server.h"
#include <iostream>

Server::Server(const char* password) {
    this->password = password;
}

void Server::setEncryptor(IEncryption* encryptor) {
    if (this->encryptor != nullptr) {
        delete this->encryptor;
    }
    this->encryptor = encryptor;
}

void Server::setExecuter(ICommand* executer) {
    if (this->executer != nullptr) {
        delete this->executer;
    }
    this->executer = executer;
}

void Server::setPassword(char* password) {
    this->password = password;
}

Server::~Server() {
    delete this->encryptor;
    delete this->executer;
}

void Server::beginRecv() {
    std::cout << "Creating socket..." << std::endl;
    if ((this->socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    memset(&this->serverAddr, 0, sizeof(this->serverAddr));
    memset(&this->clientAddr, 0, sizeof(this->clientAddr));

    this->serverAddr.sin_family = AF_INET;
    this->serverAddr.sin_addr.s_addr = INADDR_ANY;
    this->serverAddr.sin_port = htons(this->port);

    std::cout << "Binding socket..." << std::endl;

    if (bind(this->socketfd, (const sockaddr*)&this->serverAddr, sizeof(this->serverAddr)) < 0) {
        std::cout << "Bind failed" << std::endl;
        return;
    }

    int index;
    socklen_t length;
    index = recvfrom(
        this->socketfd, 
        (char*) (this->buffer), 
        this->bufferSize, 
        MSG_WAITALL, 
        (sockaddr*) &(this->clientAddr), 
        &length
        );

    this->buffer[index] = '\0';

    this->executer->execute(buffer);
    
}