#include "gtest/gtest.h"
#include "../main/AuthenticationService.h"
#include "StubRsaTokenDao.h"
#include "gmock/gmock.h"

using namespace ::testing;

std::unique_ptr<StubRsaTokenDao> stubRsaTokenDao = std::make_unique<StubRsaTokenDao>();;

std::unique_ptr<RsaTokenDao> createRsaTokenDao(){
    return std::move(stubRsaTokenDao);
}

namespace {

    TEST(AuthenticationService, IsValid) {
        AuthenticationService target;
        auto stubRsaTokenDaoPtr = stubRsaTokenDao.get();

        ON_CALL(*stubRsaTokenDaoPtr, getRandom(_)).WillByDefault(Return("000000"));

        bool actual = target.isValid("joey", "91000000");

        ASSERT_TRUE(actual);
    }

}