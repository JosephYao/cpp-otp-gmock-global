//
// Created by Joseph Yao on 2018/7/31.
//

#include <string>
#include "AuthenticationService.h"
#include "ProfileDao.h"
#include "RsaTokenDao.h"

bool AuthenticationService::isValid(const std::string userName, const std::string password) {
    // 根據 account 取得自訂密碼
    ProfileDao profileDao;
    auto passwordFromDao = profileDao.getPassword(userName);

    // 根據 account 取得 RSA token 目前的亂數
    auto randomCode = AuthenticationServiceFactory::createRsaTokenDao()->getRandom(userName);

    // 驗證傳入的 password 是否等於自訂密碼 + RSA token亂數
    auto validPassword = passwordFromDao + randomCode;
    auto isValid = password == validPassword;

    if (isValid) {
        return true;
    } else {
        return false;
    }
}

static std::unique_ptr<RsaTokenDao> rsaTokenDao_;

std::unique_ptr<RsaTokenDao> AuthenticationServiceFactory::createRsaTokenDao() {
    if (rsaTokenDao_) {
        return std::move(rsaTokenDao_);
    }
    return std::make_unique<RsaTokenDao>();
}

void AuthenticationServiceFactory::setRsaTokenDao(std::unique_ptr<RsaTokenDao> rsaTokenDao) {
    rsaTokenDao_ = std::move(rsaTokenDao);
}
