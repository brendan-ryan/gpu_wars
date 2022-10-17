#ifndef GPU_Wars_H__
#define GPU_Wars_H__

#include <string>
#include <map>
#include <vector>

// using namespace std;

class Wallet {
    public:
    Wallet();
    ~Wallet();

    int get3070Qty();
    int get3080Qty();
    int get3090Qty();
    int get6700Qty();
    int get6800Qty();
    int get6900Qty();
    void set3070Qty(int val);
    void set3080Qty(int val);
    void set3090Qty(int val);
    void set6700Qty(int val);
    void set6800Qty(int val);
    void set6900Qty(int val);

    void initWallet();

    int getCash();
    int getDay();
    int getDebt();
    void setDebt(int val);
    void setCash(int val);
    void setDay(int val);
    void setLocation(std::string loc);
    std::string getLocation();

    int randomEvent();
    

    void calculatePrices();
    void calculatePrices(float multiplier);
    void setPrices(); // probably don't need this function
    std::map<std::string, int> getPrices();
    
    void incrementDay();
    void changeLocation();

    void buy();
    void sell(); // generalize buy/sell into one function
    void payDebt();

    void endOfGame();

    private:
    int cash;
    int RTX_3090_qty;
    int RTX_3080_qty;
    int RTX_3070_qty;
    int RX_6900_XT_qty;
    int RX_6800_XT_qty;
    int RX_6700_XT_qty;
    int debt;
    int day;
    std::string location;
    std::map<std::string, int> prices;
};

#endif // GPU_Wars_H__