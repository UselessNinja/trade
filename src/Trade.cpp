/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** Trade
*/

#include "Trade.hpp"

Trade::Trade(void)
{
}

Trade::~Trade(void)
{
}

int Trade::getPairPosition(std::vector<int> cOrder)
{
    int i;
    for (i = 0; cOrder[i] != 0; ++i);
    return (i);
}

int Trade::settingsUptToId(const char *str)
{
    if (std::strcmp(str, "next_candles") == 0)
        return (0);
    if (std::strcmp(str, "stacks") == 0)
        return (1);
    return (-1);
}

int Trade::typeToId(const char *str)
{
    if (std::strcmp(str, "pair") == 0)
        return (0);
    if (std::strcmp(str, "date") == 0)
        return (1);
    if (std::strcmp(str, "high") == 0)
        return (2);
    if (std::strcmp(str, "low") == 0)
        return (3);
    if (std::strcmp(str, "open") == 0)
        return (4);
    if (std::strcmp(str, "close") == 0)
        return (5);
    if (std::strcmp(str, "volume") == 0)
        return (6);
    return (-1);
}

std::vector<int> Trade::candleOrder(char *cOrder)
{
    std::cout << cOrder << std::endl;
    std::vector <int> order;
    char *token = std::strtok(cOrder, ",");
    do {
        order.push_back(typeToId(token));
        token = std::strtok(NULL, ",");
    } while (token != NULL);
    return (order);
}

void Trade::update(void)
{
    std::vector <int> cOrder;
    std::vector <char *> cList;
    std::vector <char *> candle;
    char *token;
    char *tkn;
    char *tn;
    char *t;
    int pairPos = 0;
    if ("game" == this->_arguments[1]) {
        switch (int id = settingsUptToId(this->_arguments[2].c_str())) {
            case 0 :
                cOrder = candleOrder(const_cast<char *>(this->_settings.candle_format.c_str()));
                token = std::strtok(const_cast<char *>(this->_arguments.back().c_str()), ";");
                do {
                    cList.push_back(token);
                    token = std::strtok(NULL, ";");
                } while (token != NULL);
                pairPos = getPairPosition(cOrder);
                for (int i = 0; i < cList.size(); ++i) {
                    tkn = std::strtok(cList[i], ",");
                    do {
                        candle.push_back(tkn);
                        tkn = std::strtok(NULL, ",");
                    } while (tkn != NULL);
                    if (std::strcmp(candle[pairPos], "BTC_ETH") == 0) {
                        candle_t temp;
                        for (int j = 0; j < candle.size(); ++j) {
                            switch (cOrder[j]) {
                                case 1 :
                                    temp.date = std::atoi(candle[j]);
                                    break;
                                case 2 :
                                    temp.high = std::atof(candle[j]);
                                    break;
                                case 3 :
                                    temp.low = std::atof(candle[j]);
                                    break;
                                case 4 :
                                    temp.open = std::atof(candle[j]);
                                    break;
                                case 5 :
                                    temp.close = std::atof(candle[j]);
                                    break;
                                case 6 :
                                    temp.volume = std::atof(candle[j]);
                                    break;
                                default :
                                    break;
                            }
                        }
                        this->_update.BTC_ETH.push_back(temp);
                    } else if (std::strcmp(candle[pairPos], "USDT_ETH") == 0) {
                        candle_t temp;
                        for (int j = 0; j < candle.size(); ++j) {
                            switch (cOrder[j]) {
                                case 1 :
                                    temp.date = std::atoi(candle[j]);
                                    break;
                                case 2 :
                                    temp.high = std::atof(candle[j]);
                                    break;
                                case 3 :
                                    temp.low = std::atof(candle[j]);
                                    break;
                                case 4 :
                                    temp.open = std::atof(candle[j]);
                                    break;
                                case 5 :
                                    temp.close = std::atof(candle[j]);
                                    break;
                                case 6 :
                                    temp.volume = std::atof(candle[j]);
                                    break;
                                default :
                                    break;
                            }
                        }
                        this->_update.USDT_ETH.push_back(temp);
                    } else if (std::strcmp(candle[pairPos], "USDT_BTC") == 0) {
                        candle_t temp;
                        for (int j = 0; j < candle.size(); ++j) {
                            switch (cOrder[j]) {
                                case 1 :
                                    temp.date = std::atoi(candle[j]);
                                    break;
                                case 2 :
                                    temp.high = std::atof(candle[j]);
                                    break;
                                case 3 :
                                    temp.low = std::atof(candle[j]);
                                    break;
                                case 4 :
                                    temp.open = std::atof(candle[j]);
                                    break;
                                case 5 :
                                    temp.close = std::atof(candle[j]);
                                    break;
                                case 6 :
                                    temp.volume = std::atof(candle[j]);
                                    break;
                                default :
                                    break;
                            }
                        }
                        this->_update.USDT_BTC.push_back(temp);
                    }
                    candle.clear();
                }
                cOrder.clear();
                cList.clear();
                break;
            case 1 :
                tn = std::strtok(const_cast<char *>(this->_arguments.back().c_str()), ",");
                do {
                    cList.push_back(tn);
                    tn = std::strtok(NULL, ",");
                } while (tn != NULL);
                for (int h = 0; h < cList.size(); ++h) {
                    t = std::strtok(cList[h], ":");
                    do {
                        candle.push_back(t);
                        t = std::strtok(NULL, ":");
                    } while (t != NULL);
                    if (std::strcmp(candle[0], "ETH") == 0) {
                        this->_update.ETH = std::atof(candle[1]);
                    } else if (std::strcmp(candle[0], "BTC") == 0) {
                        this->_update.BTC = std::atof(candle[1]);
                    } else if (std::strcmp(candle[0], "USDT") == 0) {
                        this->_update.USDT = std::atof(candle[1]);
                    }
                    candle.clear();
                }
                cList.clear();
                break;
            default :
                break;

        }
    }
}

int Trade::settingsArgToId(const char *str)
{
    if (std::strcmp(str, "timebank") == 0)
        return (0);
    if (std::strcmp(str, "time_per_move") == 0)
        return (1);
    if (std::strcmp(str, "player_names") == 0)
        return (2);
    if (std::strcmp(str, "your_bot") == 0)
        return (3);
    if (std::strcmp(str, "candle_interval") == 0)
        return (4);
    if (std::strcmp(str, "candles_total") == 0)
        return (5);
    if (std::strcmp(str, "candles_given") == 0)
        return (6);
    if (std::strcmp(str, "initial_stack") == 0)
        return (7);
    if (std::strcmp(str, "transaction_fee_percent") == 0)
        return (8);
    if (std::strcmp(str, "candle_format") == 0)
        return (9);
    return (-1);
}

void Trade::settings(void)
{
    switch (int id = settingsArgToId(this->_arguments[1].c_str())) {
        case 0 :
            this->_settings.timebank = std::atoi(this->_arguments.back().c_str());
            break;
        case 1 :
            this->_settings.time_per_move = std::atoi(this->_arguments.back().c_str());
            break;
        case 2 :
            this->_settings.player_names = this->_arguments.back().c_str();
            break;
        case 3 :
            this->_settings.your_bot = this->_arguments.back().c_str();
            break;
        case 4 :
            this->_settings.candle_interval = std::atoi(this->_arguments.back().c_str());
            break;
        case 5 :
            this->_settings.candles_total = std::atoi(this->_arguments.back().c_str());
            break;
        case 6 :
            this->_settings.candles_given = std::atoi(this->_arguments.back().c_str());
            break;
        case 7 :
            this->_settings.initial_stack = std::atoi(this->_arguments.back().c_str());
            break;
        case 8 :
            this->_settings.transaction_fee_percent = std::atof(this->_arguments.back().c_str());
            break;
        case 9 :
            this->_settings.candle_format = this->_arguments.back().c_str();
            break;
        default :
            break;
    }
}

int Trade::commandToId(const char *str)
{
    if (!str)
        return (-1);
    if (std::strcmp(str, "settings") == 0)
        return (SETTINGS);
    if (std::strcmp(str, "update") == 0)
        return (UPDATE);
    if (std::strcmp(str, "action") == 0)
        return (ACTION);
    return (-1);
}

void Trade::wait(void)
{
    std::cout << "pass" << std::endl;
}

void Trade::twenty_USDT_BTC(void)
{
    float USDT_BTC = 0;

    for (int i = this->_update.USDT_BTC.size() - 20; i != this->_update.USDT_BTC.size() ; i++) {
        USDT_BTC += this->_update.USDT_BTC[i].close;
    }
    this->_update.twenty_USDT_BTC = USDT_BTC / 20;
}

void Trade::twenty_USDT_ETH(void)
{
    float USDT_BTC = 0;

    for (int i = this->_update.USDT_ETH.size() - 20; i != this->_update.USDT_ETH.size() ; i++) {
        USDT_BTC += this->_update.USDT_ETH[i].close;
    }
    this->_update.twenty_USDT_ETH = USDT_BTC / 20;
}

void Trade::twenty_BTC_ETH(void)
{
    float USDT_BTC = 0;

    for (int i = this->_update.BTC_ETH.size() - 20; i != this->_update.BTC_ETH.size() ; i++) {
        USDT_BTC += this->_update.BTC_ETH[i].close;
    }
    this->_update.twenty_BTC_ETH = USDT_BTC / 20;
}

void Trade::fifty_USDT_BTC(void)
{
    float USDT_BTC = 0;

    for (int i = this->_update.USDT_BTC.size() - 50; i != this->_update.USDT_BTC.size() ; i++) {
        USDT_BTC += this->_update.USDT_BTC[i].close;
    }
    this->_update.fifty_USDT_BTC = USDT_BTC / 50;
}

void Trade::fifty_USDT_ETH(void)
{
    float USDT_BTC = 0;

    for (int i = this->_update.USDT_ETH.size() - 50; i != this->_update.USDT_ETH.size() ; i++) {
        USDT_BTC += this->_update.USDT_ETH[i].close;
    }
    this->_update.fifty_USDT_ETH = USDT_BTC / 50;
}

void Trade::fifty_BTC_ETH(void)
{
    float USDT_BTC = 0;

    for (int i = this->_update.BTC_ETH.size() - 50; i != this->_update.BTC_ETH.size() ; i++) {
        USDT_BTC += this->_update.BTC_ETH[i].close;
    }
    this->_update.fifty_USDT_BTC = USDT_BTC / 50;
}

void Trade::average_twenty(void)
{
    twenty_USDT_BTC();
    twenty_USDT_ETH();
    twenty_BTC_ETH();
}

void Trade::average_fifty(void)
{
    fifty_USDT_BTC();
    fifty_USDT_ETH();
    fifty_BTC_ETH();
}

void Trade::buy(int i)
{
    if (i == 0) {
        if (this->_update.USDT > 0) {
            this->_update.BTC += (this->_update.USDT * 0.05 / this->_update.USDT_BTC.back().close) * 0.2 / 100;
            this->_update.buy.push_back(this->_update.BTC);
            this->_update.buys.push_back("USDT_BTC");
            this->_update.USDT = this->_update.USDT - this->_update.USDT * 0.05;
        }
    }
    if (i == 1) {
        if (this->_update.USDT > 0) {
            this->_update.ETH += (this->_update.USDT * 0.05 / this->_update.USDT_ETH.back().close) * 0.2 / 100;
            this->_update.buy.push_back(this->_update.ETH);
            this->_update.buys.push_back("USDT_ETH");
            this->_update.USDT = this->_update.USDT - this->_update.USDT * 0.05;
        }
    }
    if (i == 2) {
        if (this->_update.BTC > 0) {
            this->_update.ETH += (this->_update.BTC * 0.05 / this->_update.USDT_ETH.back().close) * 0.2 / 100;
            this->_update.buy.push_back(this->_update.ETH);
            this->_update.buys.push_back("BTC_ETH");
            this->_update.BTC = this->_update.BTC - this->_update.BTC * 0.05;
        }
    }
}

void Trade::sell(int i)
{
    if (i == 0) {
        if (this->_update.BTC > 0) {
            this->_update.USDT += (this->_update.BTC * this->_update.USDT_BTC.back().close) * 0.2 / 100;
            this->_update.sell.push_back(this->_update.BTC);
            this->_update.sells.push_back("USDT_BTC");
            this->_update.BTC = this->_update.BTC - this->_update.BTC;
        }
    }
    if (i == 1) {
        if (this->_update.ETH > 0) {
            this->_update.USDT += (this->_update.ETH * this->_update.USDT_ETH.back().close) * 0.2 / 100;
            this->_update.sell.push_back(this->_update.ETH);
            this->_update.sells.push_back("USDT_ETH");
            this->_update.ETH = this->_update.ETH - this->_update.ETH;
        }
    }
    if (i == 2) {
        if (this->_update.ETH > 0) {
            this->_update.BTC += (this->_update.ETH * this->_update.USDT_ETH.back().close) * 0.2 / 100;
            this->_update.sell.push_back(this->_update.ETH);
            this->_update.sells.push_back("BTC_ETH");
            this->_update.ETH = this->_update.ETH - this->_update.ETH;
        }
    }
}

void Trade::compare_average(void)
{
    int i = 0;
    
    if (this->_update.twenty_USDT_BTC > this->_update.fifty_USDT_BTC)
        buy(i);
    sell(i);
    i = 1;
    if (this->_update.twenty_USDT_ETH > this->_update.fifty_USDT_ETH)
        buy(i);
    sell(i);
    i = 2;
    if (this->_update.twenty_BTC_ETH > this->_update.fifty_BTC_ETH)
        buy(i);
    sell(i);
}

void Trade::print_all(void)
{
    int i = 0;
    int b = 0;


    for (int i = 0; i != this->_update.buys.size() && i != this->_update.buy.size() ; i++) {
        if (b > 0)
            std::cout << ";";
        std::cout << "buy " << this->_update.buys[i] << " " << this->_update.buy[i];
    }
    for (int i = 0; i != this->_update.sells.size() && i != this->_update.sell.size() ; i++) {
        if (b > 0)
            std::cout << ";";
        std::cout << "buy " << this->_update.sells[i] << " " << this->_update.sell[i];
    }
    std::cout << std::endl;
    this->_update.buys.clear();
    this->_update.buy.clear();
    this->_update.sells.clear();
    this->_update.sell.clear();
}

void Trade::sell_all(void)
{
    if (this->_update.BTC != 0) {
        this->_update.USDT += (this->_update.BTC * this->_update.USDT_BTC.back().close) * 0.2 / 100;
        this->_update.sell.push_back(this->_update.BTC);
        this->_update.sells.push_back("USDT_BTC");
        this->_update.BTC = this->_update.BTC - this->_update.BTC;
    }
    if (this->_update.ETH != 0) {
        this->_update.USDT += (this->_update.ETH * this->_update.USDT_ETH.back().close) * 0.2 / 100;
        this->_update.sell.push_back(this->_update.ETH);
        this->_update.sells.push_back("USDT_ETH");
        this->_update.ETH = this->_update.ETH - this->_update.ETH;
    }
}

void Trade::action(void)
{
    int i = 0;

    if (this->_update.BTC_ETH.size() < 50)
        wait();
    if (this->_update.BTC_ETH.size() >= 50) {
        if (this->_update.BTC_ETH.size() == this->_settings.candles_total - 1) {
            sell_all();
            print_all();
            i++;
        }
        average_twenty();
        average_fifty();
        compare_average();
        if (((this->_update.buy.size() != 0 && this->_update.sell.size() != 0) || 
            (this->_update.buy.size() != 0 && this->_update.sell.size() == 0) ||
            (this->_update.buy.size() == 0 && this->_update.sell.size() != 0)) && i == 0)
            print_all();
        else
            wait();
    }
}

void Trade::core(void)
{
    std::string stringInput;
    while (std::getline(std::cin, stringInput)) {
        if (stringInput.size() > 0) {
            char *cInput = const_cast<char *>(stringInput.c_str());
            char *token = std::strtok(cInput, " ");
            do {
                this->_arguments.push_back(token);
                token = std::strtok(NULL, " ");
            } while (token != NULL);
            switch (int id = this->commandToId(this->_arguments.front().c_str())) {
                case SETTINGS :
                    this->settings();
                    break;
                case UPDATE :
                    this->update();
                    break;
                case ACTION :
                    this->action();
                    break;
                default :
                    break;
            }
            this->_arguments.clear();
        }
    }
    exit(84);
}
