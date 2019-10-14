#include <string>
#include <iostream>


class ICommand {
    virtual void execute(std::string input) = 0;
};

class PrintOutput: public ICommand {
    void execute(std::string input) override {
        std::cout << input << std::endl;
    }
};
