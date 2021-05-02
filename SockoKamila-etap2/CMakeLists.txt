cmake_minimum_required(VERSION 3.17)
project(SockoKamila-etap2)

set(CMAKE_CXX_STANDARD 14)

add_executable(SockoKamila-etap2 main.cpp Factory.cpp Factory.h Car.cpp Car.h Vehicle.cpp Vehicle.h Bike.cpp Bike.h MotorVehicle.cpp MotorVehicle.h MotorCycle.cpp MotorCycle.h Sprayer.cpp Sprayer.h usedVehicles.cpp usedVehicles.h Person.cpp Person.h)
