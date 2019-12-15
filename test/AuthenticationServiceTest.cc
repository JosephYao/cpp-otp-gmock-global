#include "gtest/gtest.h"
#include "../main/AuthenticationService.h"
#include "StubRsaTokenDao.h"
#include "gmock/gmock.h"
#include "gmock-global.h"

using namespace ::testing;

MOCK_GLOBAL_FUNC0(createRsaTokenDao, std::unique_ptr<RsaTokenDao>());

namespace {

    TEST(AuthenticationService, IsValid) {
        AuthenticationService target;
        auto *stubRsaTokenDao = new StubRsaTokenDao();

        ON_GLOBAL_CALL(createRsaTokenDao, createRsaTokenDao()).WillByDefault(Return(ByMove(std::unique_ptr<RsaTokenDao>(stubRsaTokenDao))));
        ON_CALL(*stubRsaTokenDao, getRandom(_)).WillByDefault(Return("000000"));

        bool actual = target.isValid("joey", "91000000");

        ASSERT_TRUE(actual);
    }

}