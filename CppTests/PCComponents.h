#pragma once

#include <windows.h>
#include <d3d9.h>
#include <string>

struct GPU {
	std::string name;
};

struct PROCESSOR {
	unsigned long numberOfCores;
	unsigned long processorType;
	unsigned short processorArchitecture;
};

struct RAM {
	unsigned __int64 availableMemory;
};