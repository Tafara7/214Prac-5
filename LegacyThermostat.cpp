#include "LegacyThermostat.h"
#include <iostream>
#include <sstream>

LegacyThermostat::LegacyThermostat() : currentTemperature(22) {
    
} 

int LegacyThermostat::getLegacyTemperature() {
    return currentTemperature;
}

void LegacyThermostat::setLegacyTemperature(int temp) {
    currentTemperature = temp;
}

SmartThermostatIntegrator::SmartThermostatIntegrator(LegacyThermostat* legacyThermostat) {
    this->legacyThermostat = legacyThermostat;
}

std::string SmartThermostatIntegrator::getStatus() const {
    std::ostringstream oss;
    oss << "Temperature: " << legacyThermostat->getLegacyTemperature() << "°C";
    return oss.str();
}

void SmartThermostatIntegrator::performAction() {
    std::cout << "Adjusting legacy thermostat..." << std::endl;
    legacyThermostat->setLegacyTemperature(22);  
}

std::string SmartThermostatIntegrator::getDeviceType() const {
    return "Thermostat (Legacy)";
}

void SmartThermostatIntegrator::setTemperature(int temp) {
    legacyThermostat->setLegacyTemperature(temp);
}

int SmartThermostatIntegrator::getTemperature() {
    return legacyThermostat->getLegacyTemperature();
}