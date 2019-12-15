#include "gtest/gtest.h"
#include "../main/AuthenticationService.h"
#include "StubRsaTokenDao.h"
#include "gmock/gmock.h"
#include "gmock-global.h"

using namespace ::testing;

MOCK_GLOBAL_FUNC0(createRsaTokenDao, std::unique_ptr<RsaTokenDao>());

//std::unique_ptr<StubRsaTokenDao> stubRsaTokenDao = std::make_unique<StubRsaTokenDao>();;
//
//std::unique_ptr<RsaTokenDao> createRsaTokenDao(){
//    return std::move(stubRsaTokenDao);
//}

namespace {

    TEST(AuthenticationService, IsValid) {
        AuthenticationService target;
//        auto stubRsaTokenDao = std::make_unique<StubRsaTokenDao>();
        auto *stubRsaTokenDao = new StubRsaTokenDao();
//        auto stubRsaTokenDaoPtr = stubRsaTokenDao.get();
//        StubRsaTokenDao stubRsaTokenDao;

        ON_GLOBAL_CALL(createRsaTokenDao, createRsaTokenDao()).WillByDefault(Return(ByMove(std::unique_ptr<RsaTokenDao>(stubRsaTokenDao))));
        ON_CALL(*stubRsaTokenDao, getRandom(_)).WillByDefault(Return("000000"));

        bool actual = target.isValid("joey", "91000000");

        ASSERT_TRUE(actual);
    }

}