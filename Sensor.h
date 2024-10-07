#ifndef SENSOR_H
#define SENSOR_H

#include "SmartDevice.h"
#include <vector>

class DeviceObserver {

public:
    virtual ~DeviceObserver() = default;
    virtual void update() = 0;
};

class Sensor {

private:
    std::vector<DeviceObserver*> devices;

public:
    void addDevice(DeviceObserver* device);
    void removeDevice(DeviceObserver* device);
    void notifyDevices();
};

class MotionSensor : public DeviceObserver {
    
private:
    SmartDevice* device;

public:
    MotionSensor(SmartDevice* device);
    void update() override;
};

#endif  