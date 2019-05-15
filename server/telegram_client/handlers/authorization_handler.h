#ifndef AUTHORIZATION_HANDLER_H
#define AUTHORIZATION_HANDLER_H

#include "td/telegram/Client.h"
#include "VolubleTelegramClientConfig.h"
#include "spdlog/spdlog.h"
#include <iostream>
#include <sstream>
#include <assert.h>

class AuthorizationHandler
{
public:
    AuthorizationHandler(std::shared_ptr<td::Client> client);
    virtual ~AuthorizationHandler();
    td::td_api::object_ptr<td::td_api::Function> handle_authorization_state(td::td_api::object_ptr<td::td_api::updateAuthorizationState> &updateAuthState);

private:
    std::shared_ptr<td::Client> _client;
    std::shared_ptr<spdlog::logger> _logger;
    td::td_api::object_ptr<td::td_api::Function> handle_tdlib_parameters();
    td::td_api::object_ptr<td::td_api::Function> handle_wait_encryption_key();
    td::td_api::object_ptr<td::td_api::Function> handle_wait_phone_number();
    td::td_api::object_ptr<td::td_api::Function> handle_wait_code();
};
#endif