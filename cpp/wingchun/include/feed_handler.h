//
// Created by qlu on 2019/1/10.
//

#ifndef KUNGFU_FEEDHANDLER_H
#define KUNGFU_FEEDHANDLER_H

#include "md_struct.h"
#include "oms_struct.h"

namespace kungfu
{
    //行情数据处理句柄
    class MarketDataFeedHandler
    {
    public:
    //行情
        virtual void on_quote(const Quote* quote) {};
        //逐笔委托
        virtual void on_entrust(const Entrust* entrust) {};
        //逐笔成交
        virtual void on_transaction(const Transaction* transaction) {}
    };
    //交易数据处理句柄
    class TraderDataFeedHandler
    {
    public:
        //委托录入
        virtual void on_order_input(const OrderInput* input) {}
        //委托操作：撤单
        virtual void on_order_action(const OrderAction* action) {}
        //委托状态更新
        virtual void on_order(const Order* order) {}
        //成交单
        virtual void on_trade(const Trade* trade) {}
        virtual void on_position(const Position* pos) {}
        virtual void on_position_detail(const Position* pos) {}
        virtual void on_account(const AccountInfo* account) {}
    };
}
#endif //KUNGFU_FEEDHANDLER_H
