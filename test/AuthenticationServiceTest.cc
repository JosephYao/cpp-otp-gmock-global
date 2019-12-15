#include "gtest/gtest.h"
#include "../main/AuthenticationService.h"
#include "StubRsaTokenDao.h"
#include "gmock/gmock.h"

using namespace ::testing;

namespace {

    TEST(AuthenticationService, IsValid) {
        AuthenticationService target;
        auto stubRsaTokenDao = std::make_unique<StubRsaTokenDao>();;
        auto stubRsaTokenDaoPtr = stubRsaTokenDao.get();
        AuthenticationServiceFactory::setRsaTokenDao(std::move(stubRsaTokenDao));

        ON_CALL(*stubRsaTokenDaoPtr, getRandom(_)).WillByDefault(Return("000000"));

        bool actual = target.isValid("joey", "91000000");

        ASSERT_TRUE(actual);
    }

}