#include "logger.h"

using std::string;
using std::cout, std::endl;

LOGGER::LOGGER(string name) {
    _name = name;
}

void LOGGER::log(const char *priority, const char *message) {
    cout << priority << message << endl;
}

void LOGGER::info(const char *message) {
    log("[info] - ", message);
}

void LOGGER::debug(const char *message) {
    log("[debug] - ", message);
}

void LOGGER::error(const char *message) {
    log("[error] - ", message);
}
