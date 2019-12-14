#ifndef CPP_OTP_STUBRSATOKENDAO_H
#define CPP_OTP_STUBRSATOKENDAO_H

#include "../main/RsaTokenDao.h"
#include "gmock/gmock.h"

class StubRsaTokenDao : public RsaTokenDao {

public:
    MOCK_METHOD1(getRandom, std::string(std::string));
};

#endif //CPP_OTP_STUBRSATOKENDAO_H
