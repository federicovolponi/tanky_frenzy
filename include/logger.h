#include <iostream>

enum PRIORITY {
    INFO,
    DEBUG,
    ERROR
};

class LOGGER {
    public:
        LOGGER(std::string name);
        static void info(const char *message);
        static void debug(const char *message);
        static void error(const char *message);
    private:
        static void log(const char *priority, const char *message);
        std::string _name;
};
