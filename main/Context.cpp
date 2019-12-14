#include "Context.h"
#include <map>

std::map<std::string, std::string> Context::profiles;

std::string Context::getPassword(const std::string userName) {
    profiles = {
            {"joey", "91"},
            {"mei",  "99"}
    };
    return profiles[userName];
}
