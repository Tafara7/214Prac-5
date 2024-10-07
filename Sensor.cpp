//u22565991 - Mr. Tafara Hwata
//u05169098 - Mr. Devan de Wet 
#include "Sensor.h"
#include <iostream>
#include <algorithm>

void Sensor::addDevice(DeviceObserver* device) {
    devices.push_back(device);
}

void Sensor::removeDevice(DeviceObserver* device) {
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}

void Sensor::notifyDevices() {
    for (size_t i = 0; i < devices.size(); ++i) {
        devices[i]->update();
    }
}

MotionSensor::MotionSensor(SmartDevice* device) : device(device) {}

void MotionSensor::update() {
    std::cout << "Motion detected! Notifying device..." << std::endl;
    device->performAction();
}