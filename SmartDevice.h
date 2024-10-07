#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>

class SmartDevice;

class SmartDevice {
public:
    virtual ~SmartDevice() = default;
    virtual std::string getStatus() const = 0;
    virtual void performAction() = 0;
    virtual std::string getDeviceType() const = 0;
};

class DeviceState {
public:
    virtual ~DeviceState() = default;
    virtual std::string getStatus() const = 0;
    virtual void toggle(SmartDevice* device) = 0;
};

class Light : public SmartDevice {
private:
    DeviceState* state;

public:
    Light();
    ~Light();

    std::string getStatus() const override;
    void performAction() override;
    std::string getDeviceType() const override;

    void setState(DeviceState* newState);
};

class LightOnState : public DeviceState {
public:
    std::string getStatus() const override;
    void toggle(SmartDevice* device) override;
};

class LightOffState : public DeviceState {
public:
    std::string getStatus() const override;
    void toggle(SmartDevice* device) override;
};

// Thermostat class inheriting from SmartDevice
class Thermostat : public SmartDevice {
private:
    int temperature;

public:
    Thermostat();
    ~Thermostat() = default;

    std::string getStatus() const override;
    void performAction() override;
    std::string getDeviceType() const override;

    void setTemperature(int temp);
    int getTemperature() const;
};

class DoorLock : public SmartDevice {
private:
    bool locked;

public:
    DoorLock();
    ~DoorLock() = default;

    std::string getStatus() const override;
    void performAction() override;
    std::string getDeviceType() const override;

    void lock();
    void unlock();
    bool isLocked() const;
};
#endif  