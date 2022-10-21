#include "GPU_Wars.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

/*
The function changeLocation() is printing a message to the player but it is getting swallowed up by the display
function when it skips 100 blank lines.
Need to pass the string to the display function
*/



// using namespace std;

Wallet::Wallet() {
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
}

Wallet::~Wallet(){
}

int Wallet::get3070Qty() {
    return RTX_3070_qty;
}
int Wallet::get3080Qty() {
    int card = RTX_3080_qty;
    return card;
}
int Wallet::get3090Qty() {
    int card = RTX_3090_qty;
    return card;
}
int Wallet::get6700Qty() {
    int card = RX_6700_XT_qty;
    return card;
}
int Wallet::get6800Qty() {
    int card = RX_6800_XT_qty;
    return card;
}
int Wallet::get6900Qty() {
    int card = RX_6800_XT_qty;
    return card;
}
int Wallet::getCash() {
    return cash;
}
std::string Wallet::getLocation() {
    return location;
}
int Wallet::getDay() {
    return day;
}
int Wallet::getDebt() {
    return debt;
}
void Wallet::set3070Qty(int val) {
    RTX_3070_qty += val;
}
void Wallet::set3080Qty(int val) {
    RTX_3080_qty += val;
}
void Wallet::set3090Qty(int val) {
    RTX_3090_qty += val;
}
void Wallet::set6700Qty(int val) {
    RX_6700_XT_qty += val;
}
void Wallet::set6800Qty(int val) {
    RX_6800_XT_qty += val;
}
void Wallet::set6900Qty(int val) {
    RX_6900_XT_qty += val;
}
void Wallet::setDebt(int val) {
    debt += val;
}
void Wallet::setDay(int val) {
    day = val;
}
void Wallet::setLocation(std::string loc) {
    location = loc;
}
void Wallet::setCash(int val) {
    cash += val;
}
void Wallet::initWallet() {
    cash = 10000;
    debt = 10000;
    day = 1;
    location = "Newegg";
    RTX_3070_qty = 0;
    RTX_3080_qty = 0;
    RTX_3090_qty = 0;
    RX_6700_XT_qty = 0;
    RX_6800_XT_qty = 0;
    RX_6900_XT_qty = 0;
}


void Wallet::setPrices() {
    prices["RTX 3070"] = 499;
    prices["RTX 3080"] = 699;
    prices["RTX 3090"] = 999;
    prices["RX 6700 XT"] = 449;
    prices["RX 6800 XT"] = 649;
    prices["RX 6900 XT"] = 949;
}

void Wallet::calculatePrices() {
    float min = 1.0;
    float max = 1.4;
    float delta = max - min;
    srand(time(NULL));                                                                                  // seed pseudorandom number generator
    prices["RTX 3070"] = (int)499 * ((((float) rand() / (float) RAND_MAX) / max) + min);
    prices["RTX 3080"] = (int)699 * ((((float) rand() / (float) RAND_MAX) / max) + min);
    prices["RTX 3090"] = (int)999 * ((((float) rand() / (float) RAND_MAX) / max) + min);
    prices["RX 6700 XT"] = (int)449 * ((((float) rand() / (float) RAND_MAX) / max) + min);
    prices["RX 6800 XT"] = (int)649 * ((((float) rand() / (float) RAND_MAX) / max) + min);
    prices["RX 6900 XT"] = (int)949 * ((((float) rand() / (float) RAND_MAX) / max) + min);    
}
void Wallet::calculatePrices(float multiplier) {
    float min = 1.0;
    float max = 1.4;
    float delta = max - min;
    srand(time(NULL));
    prices["RTX 3070"] = (int)499 * (((((float) rand() / (float) RAND_MAX) / max) + min) * multiplier);
    prices["RTX 3080"] = (int)699 * (((((float) rand() / (float) RAND_MAX) / max) + min) * multiplier);
    prices["RTX 3090"] = (int)999 * (((((float) rand() / (float) RAND_MAX) / max) + min) * multiplier);
    prices["RX 6700 XT"] = (int)449 * (((((float) rand() / (float) RAND_MAX) / max) + min) * multiplier);
    prices["RX 6800 XT"] = (int)649 * (((((float) rand() / (float) RAND_MAX) / max) + min) * multiplier);
    prices["RX 6900 XT"] = (int)949 * (((((float) rand() / (float) RAND_MAX) / max) + min) * multiplier);    
}
int Wallet::randomEvent() {
    // float min = 0;
    // float max = 100;
    srand(time(NULL));
    float event = rand() % 100;
    return event;
}

void randomEvent() {
    
}

std::map<std::string, int> Wallet::getPrices() {
    return prices;
}
void Wallet::incrementDay() {
    day += 1;
}
void Wallet::changeLocation() {
    for (int i = 0; i < 100; i++) {
        std::cout << "\n";
    } 
    std::cout << "WHERE DO YOU WANT TO GO?\n";
    std::cout << std::setw(20) << "1. NEWEGG";
    std::cout << std::setw(20) << "2. MICRO CENTER\n";
    std::cout << std::setw(20) << "3. FRY'S";
    std::cout << std::setw(20) << "4. TIGER DIRECT\n";
    std::cout << std::setw(20) << "5. ANOTHER OPTION";
    std::cout << std::setw(20) << "6. BEST BUY\n"; 
    std::cout << std::setw(20) << "7. BANK\n"; 

    int selection;
    std::cin >> selection;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::string item;
        std::cin >> item;
        selection = -1;
    }

    int event = randomEvent();
    std::cout << "Random number: " << event << "\n";

    switch (selection) {
        case 1:
            location = "NEWEGG";
            if (event > 80) {
                std::cout << "PRICES ARE THROUGH THE ROOF! CASH IN, IF YOU CAN\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(2);
            }
            else if (event < 20) {
                std::cout << "THE CRYPTO MARKET HAS TANKED AND MINERS A DUMPING CARDS\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(0.5);
            }
            else {
                calculatePrices();
            }
            break;
        case 2:
            location = "MICRO CENTER";
            if (event > 80) {
                std::cout << "PRICES ARE THROUGH THE ROOF! CASH IN, IF YOU CAN\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(2);
            }
            else if (event < 20) {
                std::cout << "THE CRYPTO MARKET HAS TANKED AND MINERS A DUMPING CARDS\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(0.5);
            }
            else {
                calculatePrices();
            }
            break;
        case 3:
            location = "FRY'S";
            if (event > 80) {
                std::cout << "PRICES ARE THROUGH THE ROOF! CASH IN, IF YOU CAN\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(2);
            }
            else if (event < 20) {
                std::cout << "THE CRYPTO MARKET HAS TANKED AND MINERS A DUMPING CARDS\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(0.5);
            }
            else {
                calculatePrices();
            }
            break;
        case 4: 
            location = "TIGER DIRECT";
            if (event > 80) {
                std::cout << "PRICES ARE THROUGH THE ROOF! CASH IN, IF YOU CAN\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(2);
            }
            else if (event < 20) {
                std::cout << "THE CRYPTO MARKET HAS TANKED AND MINERS A DUMPING CARDS\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(0.5);
            }
            else {
                calculatePrices();
            }
            break;
        case 5: 
            location = "ANOTHER";
            if (event > 80) {
                std::cout << "PRICES ARE THROUGH THE ROOF! CASH IN, IF YOU CAN\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(2);
            }
            else if (event < 20) {
                std::cout << "THE CRYPTO MARKET HAS TANKED AND MINERS A DUMPING CARDS\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(0.5);
            }
            else {
                calculatePrices();
            }
            break;
        case 6: 
            location = "BEST BUY";
            if (event > 80) {
                std::cout << "PRICES ARE THROUGH THE ROOF! CASH IN, IF YOU CAN\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(2);
            }
            else if (event < 20) {
                std::cout << "THE CRYPTO MARKET HAS TANKED AND MINERS A DUMPING CARDS\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
                calculatePrices(0.5);
            }
            else {
                calculatePrices();
            }
            break;
        case 7:
            payDebt();
            break;
    }
}

void Wallet::buy() {
    std::map<std::string, int> prices = getPrices();

    std::cout << "WHAT DO YOU WANT TO BUY?\n";
    int selection;
    std::cin >> selection;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::string item;
        std::cin >> item;
        selection = -1;
    }

    std::cout << "HOW MANY DO YOU WANT?\n";
    int qty;
    std::cin >> qty;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::string item;
        std::cin >> item;
        selection = -1;
    }

    switch (selection) {
        case 1:
            if (qty * prices["RTX 3070"] > cash) {
                std::cout << "YOU DON'T HAVE ENOUGH CASH FOR THAT\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set3070Qty(qty);
                cash += -(qty * prices["RTX 3070"]);
            }
            break;
        case 2:
            if (qty * prices["RTX 3080"] > cash) {
                std::cout << "YOU DON'T HAVE ENOUGH CASH FOR THAT\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set3080Qty(qty);
                cash += -(qty * prices["RTX 3080"]);
            }
            break;
        case 3:
            if (qty * prices["RTX 3090"] > cash) {
                std::cout << "YOU DON'T HAVE ENOUGH CASH FOR THAT\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set3090Qty(qty);
                cash += -(qty * prices["RTX 3090"]);
            }
            break;
        case 4:
            if (qty * prices["RX 6700 XT"] > cash) {
                std::cout << "YOU DON'T HAVE ENOUGH CASH FOR THAT\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set6700Qty(qty);
                cash += -(qty * prices["RX 6700 XT"]);
            }
            break;
        case 5:
            if (qty * prices["RX 6800 XT"] > cash) {
                std::cout << "YOU DON'T HAVE ENOUGH CASH FOR THAT\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set6800Qty(qty);
                cash += -(qty * prices["RX 6800 XT"]);
            }
            break;
        case 6:
            if (qty * prices["RX 6900 XT"] > cash) {
                std::cout << "YOU DON'T HAVE ENOUGH CASH FOR THAT\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set6900Qty(qty);
                cash += -(qty * prices["RX 6900 XT"]);
            }
            break;
    }
}

void Wallet::sell() {
    std::map<std::string, int> prices = getPrices();

    std::cout << "WHAT DO YOU WANT TO SELL?\n";
    int selection;
    std::cin >> selection;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::string item;
        std::cin >> item;
        selection = -1;
    }

    std::cout << "HOW MANY DO YOU WANT TO SELL?\n";
    int qty;
    std::cin >> qty;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::string item;
        std::cin >> item;
        selection = -1;
    }

    switch (selection) {
        case 1:
            if (qty > get3070Qty()) {
                std::cout << "YOU DON'T HAVE THAT MANY TO SELL\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set3070Qty(-qty);
                cash += (qty * prices["RTX 3070"]);
            }
            break;
        case 2:
            if (qty > get3080Qty()) {
                std::cout << "YOU DON'T HAVE THAT MANY TO SELL\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set3080Qty(-qty);
                cash += (qty * prices["RTX 3080"]);
            }
            break;
        case 3:
            if (qty > get3090Qty()) {
                std::cout << "YOU DON'T HAVE THAT MANY TO SELL\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";            // desperately need to refactor this away
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set3090Qty(-qty);
                cash += (qty * prices["RTX 3090"]);
            }
            break;
        case 4:
            if (qty > get6700Qty()) {
                std::cout << "YOU DON'T HAVE THAT MANY TO SELL\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set6700Qty(-qty);
                cash += (qty * prices["RX 6700 XT"]);
            }
            break;
        case 5:
            if (qty > get6800Qty()) {
                std::cout << "YOU DON'T HAVE THAT MANY TO SELL\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set6800Qty(-qty);
                cash += (qty * prices["RX 6800 XT"]);
            }
            break;
        case 6:
            if (qty > get6900Qty()) {
                std::cout << "YOU DON'T HAVE THAT MANY TO SELL\n";
                std::cout << "PRESS ENTER TO CONTINUE\n";
                std::cin.ignore();
                std::cin.get();
            }
            else {
                set6900Qty(-qty);
                cash += (qty * prices["RX 6900 XT"]);
            }
            break;
    }
}

void Wallet::endOfGame() {
    if (debt > 0) {
        std::cout << "YOU FAILED TO PAY OFF YOUR DEBT. BETTER LUCK NEXT TIME\n";
    }
    else {
        std::cout << "CONGRATULATIONS! YOU ENDED THE GAME WITH " << cash << " CASH.";
        std::cout << "\nCAN YOU DO BETTER???";
    }
}

void Wallet::payDebt() {
    for (int i = 0; i < 100; i++) {
        std::cout << "\n";
    }
    std::cout << "HOW MUCH DEBT DO YOU WANT TO REPAY?\n";
    int debtRepayment;
    std::cin >> debtRepayment;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::string item;
        std::cin >> item;
        debtRepayment = -1;
    }
    if (debtRepayment > cash) {
        std::cout << "YOU DONT HAVE ENOUGH CASH FOR THAT\n";
        std::cout << "\n\nPress ENTER to continue.\n";
        std::cin.get();
    }
    else {
        setCash(-debtRepayment);
        setDebt(-debtRepayment);
    }

}
void display(Wallet &wallet);
void printTitle();


/**
  Displays menu options and gets user input.
  @param none
  @return the choice
 */
int menu() {
    int selection;

    do
    {
        std::cout << "Choose an option:\n";
        std::cout << "1. Buy" << std::setw(12) << "2. Sell" << std::setw(20) << "3. Change Location\n";

        std::cin >> selection;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::string item;
            std::cin >> item;
            selection = -1;
        }
    } 
    while (selection < 1 || selection > 3);
    
    return selection;
}

int main()
{
    printTitle();
    Wallet wallet;      
    wallet.initWallet();
    wallet.calculatePrices();

    while (wallet.getDay() < 31) {
        display(wallet);
        int menuChoice = menu();
        switch (menuChoice) {
            case 1: 
                wallet.buy();
                break;
            case 2:
                wallet.sell();
                break;
            case 3:
                wallet.changeLocation();
                wallet.incrementDay();
                break;
        }
    }
    wallet.endOfGame();
    return 0;
}

/**
 * @brief Handles the main stats display
 * @param wallet
 */
void display(Wallet &wallet) {
    for (int i = 0; i < 100; i++) {
        std::cout << "\n";
    }
    // create local instance for printing --- this may be a bad idea
    std::map<std::string, int> prices = wallet.getPrices();

    std::cout << "************************************************************************************************\n";
    std::cout << "*" << std::setw(30) << "Location: " << wallet.getLocation() << std::setw(20) << "Day: " << wallet.getDay() << std::setw(40) << "*\n";
    std::cout << "*************************************************************************************************\n";
    std::cout << "*" << std::setw(97) << "*\n";
    std::cout << "*" << std::setw(12) << "RTX 3070" << std::setw(12) << wallet.get3070Qty() << std::setw(73) << "*\n";
    std::cout << "*" << std::setw(12) << "RTX 3080" << std::setw(12) << wallet.get3080Qty() << std::setw(73) << "*\n";
    std::cout << "*" << std::setw(12) << "RTX 3090" << std::setw(12) << wallet.get3090Qty() << std::setw(73) << "*\n";
    std::cout << "*" << std::setw(14) << "RX 6700 XT" << std::setw(10) << wallet.get6700Qty() << std::setw(73) << "*\n";
    std::cout << "*" << std::setw(14) << "RX 6800 XT" << std::setw(10) << wallet.get6800Qty() << std::setw(73) << "*\n";
    std::cout << "*" << std::setw(14) << "RX 6900 XT" << std::setw(10) << wallet.get6900Qty() << std::setw(73) << "*\n";
    std::cout << "*" << std::setw(97) << "*\n";
    std::cout << "*" << std::setw(8) << "Cash" << std::setw(16) << wallet.getCash() << std::setw(73) << "*\n";
    std::cout << "*" << std::setw(8) << "Debt" << std::setw(16) << wallet.getDebt() << std::setw(73) << "*\n";
    std::cout << "*************************************************************************************************\n";
    std::cout << "HEY GAMER, THE PRICES HERE ARE:\n\n";
    std::cout << std::setw(20) << "1. RTX 3070" << std::setw(5) << "$" << prices["RTX 3070"];
    std::cout << std::setw(20) << "4. RX 6700 XT" << std::setw(5) << "$" << prices["RX 6700 XT"] << "\n";
    std::cout << std::setw(20) << "2. RTX 3080" << std::setw(5) << "$" << prices["RTX 3080"];
    std::cout << std::setw(20) << "5. RX 6800 XT" << std::setw(5) << "$" << prices["RX 6800 XT"] << "\n";
    std::cout << std::setw(20) << "3. RTX 3090" << std::setw(5) << "$" << prices["RTX 3090"];
    std::cout << std::setw(20) << "6. RX 6900 XT" << std::setw(5) << "$" << prices["RX 6900 XT"] << "\n";
}

void printTitle() {
    for (int i = 0; i < 100; i++) {
        std::cout << "\n";
    }
    std::ifstream title_file;
    std::string line;
    title_file.open("../text/title_1.txt"); // MacOS
    // title_file.open(R"(D:\Code\GPU Wars\title_1.txt)"); // Windows


    while (getline(title_file, line)) {
        std::cout << line << "\n";
    }

    title_file.close();

    std::cout << "\n\nPress ENTER to continue.\n";
    std::cin.get();
    return;
}

