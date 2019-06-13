//
// Created by qlu on 2019/1/21.
//

#ifndef PROJECT_MD_STRUCT_H
#define PROJECT_MD_STRUCT_H

#include "constant.h"

namespace kungfu
{
    //合约信息
    struct Instrument
    {
        char instrument_id[INSTRUMENT_ID_LEN];     //合约ID
        char exchange_id[EXCHANGE_ID_LEN];         //交易所ID
        InstrumentType instrument_type;            //合约类型
    };

    typedef Instrument StockInstrument;

    //期货合约信息
    struct FutureInstrument: Instrument
    {
        char product_id[PRODUCT_ID_LEN];           //产品ID

        int contract_multiplier;                   //合约乘数
        double price_tick;                         //最小变动价位

        char open_date[DATE_LEN];                  //上市日
        char create_date[DATE_LEN];                //创建日
        char expire_date[DATE_LEN];                //到期日

        int delivery_year;                         //交割年份
        int delivery_month;                        //交割月

        bool is_trading;                           //当前是否交易

        double long_margin_ratio;                  //多头保证金率
        double short_margin_ratio;                 //空头保证金率
    };

    //行情
    struct Quote
    {
        //16个字符
        char source_id[SOURCE_ID_LEN];              //柜台ID
        //9个字符
        char trading_day[DATE_LEN];                 //交易日
        //时间戳
        int64_t rcv_time;                           //数据接收时间
        int64_t data_time;                          //数据生成时间
        //32个字符
        char instrument_id[INSTRUMENT_ID_LEN];      //合约ID
        //16
        char exchange_id[EXCHANGE_ID_LEN];          //交易所ID
        //char 类型 by constant
        InstrumentType instrument_type;             //合约类型

        double pre_close_price;                     //昨收价
        double pre_settlement_price;                //昨结价

        double last_price;                          //最新价
        int64_t volume;                             //数量
        double turnover;                            //成交金额

        double pre_open_interest;                   //昨持仓量
        double open_interest;                       //持仓量

        double open_price;                          //今开盘
        double high_price;                          //最高价
        double low_price;                           //最低价

        double upper_limit_price;                   //涨停板价
        double lower_limit_price;                   //跌停板价

        double close_price;                         //收盘价
        double settlement_price;                    //结算价

        double bid_price[10];                       //申买价
        double ask_price[10];                       //申卖价
        int64_t	bid_volume[10];                     //申买量
        int64_t	ask_volume[10];                     //申卖量

    };

    //逐笔委托
    struct Entrust
    {
        char source_id[SOURCE_ID_LEN];              //柜台ID
        char trading_day[DATE_LEN];                 //交易日

        int64_t rcv_time;                           //数据接收时间
        int64_t data_time;                          //数据生成时间

        char instrument_id[INSTRUMENT_ID_LEN];      //合约ID
        char exchange_id[EXCHANGE_ID_LEN];          //交易所代码
//char 类型 by constant
        InstrumentType instrument_type;             //合约类型

        double price;                               //委托价格
        int64_t volume;                             //委托量
        //char 类型 by constant
        Side side;                                  //委托方向
        //char 类型 by constant
        PriceType price_type;                       //订单价格类型（市价、限价、本方最优）

        int64_t main_seq;                           //主序号
        int64_t seq;                                //子序号

    };

    //逐笔成交
    struct Transaction
    {
        char source_id[SOURCE_ID_LEN];              //柜台ID
        char trading_day[DATE_LEN];                 //交易日

        int64_t rcv_time;                           //数据接收时间
        int64_t data_time;                          //数据生成时间

        char instrument_id[INSTRUMENT_ID_LEN];      //合约ID
        char exchange_id[EXCHANGE_ID_LEN];          //交易所代码

        InstrumentType instrument_type;             //合约类型

        double price;                               //成交价
        int64_t volume;                             //成交量

        int64_t bid_no;                             //买方订单号
        int64_t ask_no;                             //卖方订单号

        ExecType exec_type;                         //SZ: 成交标识
        BsFlag  bs_flag;                            //SH: 内外盘标识

        int64_t main_seq;                               //主序号
        int64_t seq;                                    //子序号

    };

}
#endif //PROJECT_MD_STRUCT_H
