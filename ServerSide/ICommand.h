#include <string>

class ICommand {
    virtual void execute(std::string input) = 0;
};

