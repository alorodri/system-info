#pragma once

#include "PCComponents.h"

class Maker
{
public:
	Maker();
	~Maker();
	void fillCPUInfo();
	void fillGPUInfo();
	void fillRAMInfo();
	void update();

	unsigned long getNumberOfCores();
	unsigned long getProcessorType();
	unsigned short getProcessorArchitecture();
	unsigned __int64 getAvailableMemory();
	std::string getGPUName();
private:
	RAM ram;
	PROCESSOR processor;
	GPU gpu;

	MEMORYSTATUSEX memoryStatusBuffer;
};