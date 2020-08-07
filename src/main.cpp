#include "crow_all.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "<div><p>Hi, Crow</p></div>";
    });

    char *szport = getenv("PORT");
    uint16_t  shPort = (uint16_t)(szport==nullptr?8080:stoi(szport));
    std::cout <<"application running on port ["<< shPort<<"]\n";
    app.port(shPort).multithreaded().run();
}