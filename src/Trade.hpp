/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** Trade
*/

#ifndef TRADE_HPP_
#define TRADE_HPP_

#define SETTINGS 0
#define UPDATE 1
#define ACTION 2

#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

typedef struct candle_s {
    int date;
    float high;
    float low;
    float open;
    float close;
    float volume;
} candle_t;

typedef struct update_s {
    std::vector <candle_t> BTC_ETH;
    std::vector <candle_t> USDT_ETH;
    std::vector <candle_t> USDT_BTC;
    std::vector <float> buy;
    std::vector <float> sell;
    std::vector <std::string> buys;
    std::vector <std::string> sells;
    float BTC;
    float ETH;
    float USDT;
    float twenty_USDT_BTC;
    float twenty_USDT_ETH;
    float twenty_BTC_ETH;
    float fifty_USDT_BTC;
    float fifty_USDT_ETH;
    float fifty_BTC_ETH;
} update_t;

typedef struct settings_s {
    int timebank;
    int time_per_move;
    std::string player_names;
    std::string your_bot;
    int candle_interval;
    int candles_total;
    int candles_given;
    int initial_stack;
    float transaction_fee_percent;
    std::string candle_format;
} settings_t;

class Trade {
    public:
        Trade(void);
        ~Trade(void);
        void core(void);
        int commandToId(const char *);
        void settings(void);
        int settingsArgToId(const char *);
        void update(void);
        void wait(void);
        void average_twenty(void);
        void average_fifty(void);
        void twenty_USDT_BTC(void);
        void twenty_USDT_ETH(void);
        void twenty_BTC_ETH(void);
        void fifty_USDT_BTC(void);
        void fifty_USDT_ETH(void);
        void fifty_BTC_ETH(void);
        void compare_average(void);
        void buy(int);
        void sell(int);
        void sell_all(void);
        void print_all(void);
        void action(void);
        int typeToId(const char *);
        std::vector <int> candleOrder(char *);
        int settingsUptToId(const char *);
        int getPairPosition(std::vector<int>);
    protected:
    private:
        std::vector<std::string> _arguments;
        update_t _update;
        settings_t _settings;
};

#endif /* !TRADE_HPP_ */
