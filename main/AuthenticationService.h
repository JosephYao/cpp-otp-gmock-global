#ifndef CPP_OTP_AUTHENTICATIONSERVICE_H
#define CPP_OTP_AUTHENTICATIONSERVICE_H

#include <string>
#include "RsaTokenDao.h"
#include <memory>

std::unique_ptr<RsaTokenDao> createRsaTokenDao();

class AuthenticationService {

public:
    bool isValid(const std::string userName, const std::string password);
};


#endif //CPP_OTP_AUTHENTICATIONSERVICE_H
