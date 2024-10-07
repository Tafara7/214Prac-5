#include "SmartDevice.h"
#include <iostream>
#include <sstream>

Light::Light() {
    state = new LightOffState();
}

Light::~Light() {
    delete state;
}

std::string Light::getStatus() const {
    return state->getStatus();
}

void Light::performAction() {
    state->toggle(this);
}

std::string Light::getDeviceType() const {
    return "Light";
}

void Light::setState(DeviceState* newState) {
    if (state) delete state;
    state = newState;
}

std::string LightOnState::getStatus() const {
    return "on";
}

void LightOnState::toggle(SmartDevice* device) {
    std::cout << "Turning the light off." << std::endl;
    static_cast<Light*>(device)->setState(new LightOffState());
}

std::string LightOffState::getStatus() const {
    return "off";
}

void LightOffState::toggle(SmartDevice* device) {
    std::cout << "Turning the light on." << std::endl;
    static_cast<Light*>(device)->setState(new LightOnState());
}

Thermostat::Thermostat() : temperature(22) {}  

std::string Thermostat::getStatus() const {
    std::ostringstream oss;
    oss << "Temperature: " << temperature << "°C";
    return oss.str();
}

void Thermostat::performAction() {
    std::cout << "Adjusting thermostat..." << std::endl;
    setTemperature(22);  
}

std::string Thermostat::getDeviceType() const {
    return "Thermostat";
}

void Thermostat::setTemperature(int temp) {
    temperature = temp;
}

int Thermostat::getTemperature() const {
    return temperature;
}

DoorLock::DoorLock() : locked(false) {
    
}

std::string DoorLock::getStatus() const {
    return locked ? "locked" : "unlocked";
}

void DoorLock::performAction() {
    if (locked) {
        unlock();
    } else {
        lock();
    }
}

std::string DoorLock::getDeviceType() const {
    return "DoorLock";
}

void DoorLock::lock() {
    locked = true;
    std::cout << "Door is now locked." << std::endl;
}

void DoorLock::unlock() {
    locked = false;
    std::cout << "Door is now unlocked." << std::endl;
}

bool DoorLock::isLocked() const {
    return locked;
}