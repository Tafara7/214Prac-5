#ifndef LEGACYTHERMOSTAT_H
#define LEGACYTHERMOSTAT_H

#include "SmartDevice.h"

class LegacyThermostat {
public:
    int currentTemperature;
    
    LegacyThermostat();
    int getLegacyTemperature();
    void setLegacyTemperature(int temp);
};

class SmartThermostatIntegrator : public SmartDevice {
private:
    LegacyThermostat* legacyThermostat;

public:
    SmartThermostatIntegrator(LegacyThermostat* legacyThermostat);
    std::string getStatus() const override;
    void performAction() override;
    std::string getDeviceType() const override;

    void setTemperature(int temp);
    int getTemperature();
};

#endif  