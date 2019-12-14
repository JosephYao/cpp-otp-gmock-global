#include "AuthenticationService.h"

std::unique_ptr<RsaTokenDao> createRsaTokenDao() {
    return std::make_unique<RsaTokenDao>();
}
