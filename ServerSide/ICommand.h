#include <string>
#include <iostream>


class ICommand {
public:
    virtual void execute(std::string input) = 0;
};

class PrintOutput: public ICommand {
public:
    void execute(std::string input) override {
        std::cout << input << std::endl;
    }
};
