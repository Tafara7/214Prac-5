//u22565991 - Mr. Tafara Hwata
//u05169098 - Mr. Devan de Wet 
#include "SmartDevice.h"
#include "LegacyThermostat.h"
#include "Command.h"
#include "Sensor.h"
#include <iostream>
#include <vector>

int main() {
    // ** SmartDevice Testing **
    SmartDevice* livingRoomLight = new Light();
    SmartDevice* frontDoorLock = new DoorLock();  

    // Test initial states
    std::cout << "Initial Light status: " << livingRoomLight->getStatus() << std::endl;
    std::cout << "Initial Door status: " << frontDoorLock->getStatus() << std::endl;

    // Test Light toggle action
    livingRoomLight->performAction();  // Turn On light
    std::cout << "Light is now: " << livingRoomLight->getStatus() << std::endl;
    
    livingRoomLight->performAction();  // Turn Off light
    std::cout << "Light is now: " << livingRoomLight->getStatus() << std::endl;

    // Test DoorLock toggle action
    frontDoorLock->performAction();  // Lock the door
    std::cout << "Door is now: " << frontDoorLock->getStatus() << std::endl;

    frontDoorLock->performAction();  // Unlock the door
    std::cout << "Door is now: " << frontDoorLock->getStatus() << std::endl;

    // ** LegacyThermostat Integration Testing **
    std::cout << "\nTesting LegacyThermostat Integration" << std::endl;
    LegacyThermostat* oldThermostat = new LegacyThermostat();
    SmartDevice* adaptedThermostat = new SmartThermostatIntegrator(oldThermostat);

    std::cout << "Initial Thermostat Status: " << adaptedThermostat->getStatus() << std::endl;
    adaptedThermostat->performAction();  // Adjust the temperature
    std::cout << "Thermostat Status after adjustment: " << adaptedThermostat->getStatus() << std::endl;

    // ** MacroRoutine Testing (Automation) **
    std::vector<SmartDevice*> devices;
    devices.push_back(livingRoomLight);
    devices.push_back(frontDoorLock);

    MacroRoutine* goodnightRoutine = new MacroRoutine();
    
    // Test adding commands to the routine
    goodnightRoutine->addProcedure(new TurnOffAllLightsCommand(devices));
    goodnightRoutine->addProcedure(new LockAllDoorsCommand(devices));

    // Execute "Goodnight" routine (turn off all lights and lock all doors)
    std::cout << "\nExecuting Goodnight Routine..." << std::endl;
    goodnightRoutine->execute();

    std::cout << "Light status after Goodnight routine: " << livingRoomLight->getStatus() << std::endl;
    std::cout << "Door status after Goodnight routine: " << frontDoorLock->getStatus() << std::endl;

    // Edge case: Test an empty MacroRoutine
    MacroRoutine* emptyRoutine = new MacroRoutine();
    std::cout << "\nExecuting Empty Routine..." << std::endl;
    emptyRoutine->execute();  // Should handle gracefully without performing any actions

    // ** Sensor Notifications (Observer pattern) **
    Sensor motionSensor;
    MotionSensor livingRoomLightObserver(livingRoomLight);

    // Add the light as an observer to the motion sensor
    motionSensor.addDevice(&livingRoomLightObserver);
    std::cout << "\nSensor detecting motion..." << std::endl;
    motionSensor.notifyDevices();  // Notify devices

    // ** Cleanup **
    delete livingRoomLight;
    delete frontDoorLock;
    delete adaptedThermostat;
    delete goodnightRoutine;
    delete emptyRoutine;
    delete oldThermostat;

    return 0;
}
