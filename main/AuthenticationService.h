#ifndef CPP_OTP_AUTHENTICATIONSERVICE_H
#define CPP_OTP_AUTHENTICATIONSERVICE_H

#include <string>
#include "RsaTokenDao.h"
#include <memory>


class AuthenticationService {

public:
    bool isValid(const std::string userName, const std::string password);
};

class AuthenticationServiceFactory {

public:
    static std::unique_ptr<RsaTokenDao> createRsaTokenDao();

    static void setRsaTokenDao(std::unique_ptr<RsaTokenDao> rsaTokenDao);

};


#endif //CPP_OTP_AUTHENTICATIONSERVICE_H
