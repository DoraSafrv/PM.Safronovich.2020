#include "Car.h"
#include <iostream>

int Car::calcPrice(double distance) {
    return distance * getPriceFactor();
}

void Car::Show() {
    std::cout << "car";
}

void Car::Sound() {
    std::cout << "uuuu";
}
