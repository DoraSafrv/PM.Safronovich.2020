#pragma once
#include "Carrier.h"
#include <string>
class Plane :
    public Carrier {
    std::string type;
    int id;
    double priceFactor;
public:
    void setType(std::string type1) {
        type = type1;
    }
    std::string getType() {
        return type;
    }
    void setId(int id1) {
        id = id1;
    }
    void setPriceFactor(double priceFactor1) {
        priceFactor = priceFactor1;
    }
    int getId() {
        return id;
    }
    double getPriceFactor() {
        return priceFactor;
    }
    Plane(int id11, std::string type1) {
        id = id11;
        type = type1;
        setPriceFactor(1.5);
    }
    int calcPrice(double distance);
    virtual void Show();
    virtual void Sound();
};

