#include "Command.h"
#include <algorithm>

TurnOffAllLightsCommand::TurnOffAllLightsCommand(const std::vector<SmartDevice*>& devices) : devices(devices) {
    
}

void TurnOffAllLightsCommand::execute() {
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->getDeviceType() == "Light") {
            devices[i]->performAction();
        }
    }
}

LockAllDoorsCommand::LockAllDoorsCommand(const std::vector<SmartDevice*>& devices) : devices(devices) {}

void LockAllDoorsCommand::execute() {
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->getDeviceType() == "DoorLock") {
            devices[i]->performAction();
        }
    }
}

void MacroRoutine::addProcedure(Command* command) {
    commands.push_back(command);
}

void MacroRoutine::removeProcedure(Command* command) {
    commands.erase(std::remove(commands.begin(), commands.end(), command), commands.end());
}

void MacroRoutine::execute() {
    for (size_t i = 0; i < commands.size(); ++i) {
        commands[i]->execute();
    }
}