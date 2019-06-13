//
// Created by qlu on 2019/2/14.
//

#ifndef PROJECT_SERVICE_H
#define PROJECT_SERVICE_H

#include "md_struct.h"
#include "oms_struct.h"
#include <string>
#include <vector>
#include "state.h"

namespace kungfu
{
    //接口层
    class Gateway
    {
    public:
        virtual const std::string& get_name() const = 0;
        virtual const std::string& get_source() const = 0;
        //enum
        virtual GatewayState get_state() const = 0;
        virtual void set_state(const GatewayState& state, const std::string& message = "") = 0;

        virtual void init() = 0;
        virtual void start() = 0;
        virtual void stop() = 0;

        virtual void on_login(const std::string& recipient, const std::string& client_id) = 0;
        virtual void on_started() = 0;
    };
    //行情网关 订阅、取消订阅
    class MdGateway: virtual public Gateway
    {
    public:
        virtual bool subscribe(const std::vector<Instrument>& instruments, bool is_level2) = 0;
        virtual bool unsubscribe(const std::vector<Instrument>& instruments) = 0;

        virtual void on_login(const std::string& recipient, const std::string& client_id) = 0;
        virtual void on_started() = 0;
    };
    //交易网关：下单撤单、查询持仓信息、账户信息
    class TdGateway: virtual public Gateway
    {
    public:
        virtual const std::string& get_account_id() const  = 0;
        virtual const AccountType get_account_type() const = 0;

        virtual bool insert_order(const OrderInput& input) = 0;
        virtual bool cancel_order(const OrderAction& action) = 0;

        virtual bool req_position_detail() = 0;
        virtual bool req_position() = 0;
        virtual bool req_account() = 0;

        virtual void on_login(const std::string& recipient, const std::string& client_id) = 0;
        virtual void on_started() = 0;

    };
}

#endif //PROJECT_SERVICE_H
