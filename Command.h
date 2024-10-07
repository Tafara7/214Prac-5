#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include "SmartDevice.h"

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

class TurnOffAllLightsCommand : public Command {
private:
    std::vector<SmartDevice*> devices;

public:
    TurnOffAllLightsCommand(const std::vector<SmartDevice*>& devices);
    void execute() override;
};

class LockAllDoorsCommand : public Command {
private:
    std::vector<SmartDevice*> devices;

public:
    LockAllDoorsCommand(const std::vector<SmartDevice*>& devices);
    void execute() override;
};

class MacroRoutine : public Command {
private:
    std::vector<Command*> commands;

public:
    void addProcedure(Command* command);
    void removeProcedure(Command* command);
    void execute() override;
};

#endif 