//
// Created by Home on 15.12.2020.
//

#include "Vehicle.h"

Vehicle::Vehicle(std::string& brand, std::string& owner, std::string& color) : _brand(brand), _owner(owner),_color(color){

}
void Vehicle::changeOwner(std::string &owner) {
    this->_owner = owner;
}

Vehicle::~Vehicle() = default;
