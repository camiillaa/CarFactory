//
// Created by Home on 08.01.2021.
//

#ifndef SOCKOKAMILA_ETAP3_HELPERFORFAIL_H
#define SOCKOKAMILA_ETAP3_HELPERFORFAIL_H

#include <string>


struct Except : public std::exception {
    std::string message;
    explicit Except(std::string message) : message(std::move(message)) {}
};

struct vehicleFail : public Except {
    explicit vehicleFail(std::string message) : Except(std::move(message)) {}
};
struct factoryFail : public Except {
    explicit factoryFail(std::string message) : Except(std::move(message)) {}
};
struct usedVehiclesFail : public Except {
    explicit usedVehiclesFail(std::string message) : Except(std::move(message)) {}
};
struct ownerVehicleFail : public Except {
    explicit ownerVehicleFail(std::string message) : Except(std::move(message)) {}
};
struct incorrectPosition: public Except {
    explicit incorrectPosition(std::string message) : Except(std::move(message)) {}
};
#endif //SOCKOKAMILA_ETAP3_HELPERFORFAIL_H
