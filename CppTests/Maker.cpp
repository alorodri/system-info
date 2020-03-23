#include "Maker.h"

Maker::Maker() {

}
Maker::~Maker() {};

void Maker::fillCPUInfo() {
	SYSTEM_INFO* systemInfoBuffer = new SYSTEM_INFO;
	GetSystemInfo(systemInfoBuffer);
	processor.numberOfCores = systemInfoBuffer->dwNumberOfProcessors;
	processor.processorArchitecture = systemInfoBuffer->wProcessorArchitecture;
	processor.processorType = systemInfoBuffer->dwProcessorType;
}

void Maker::fillGPUInfo() {
	LPDIRECT3D9 gpuObj = nullptr;
	gpuObj = Direct3DCreate9(D3D_SDK_VERSION);
	D3DADAPTER_IDENTIFIER9 adapterIdentifier9;
	gpuObj->GetAdapterIdentifier(0, 0, &adapterIdentifier9);
	gpuObj->GetAdapterCount();
	gpu.name = adapterIdentifier9.Description;
}

void Maker::fillRAMInfo() {
	memoryStatusBuffer.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memoryStatusBuffer);
	ram.availableMemory = memoryStatusBuffer.ullAvailPhys;
}

void Maker::update() {
	GlobalMemoryStatusEx(&memoryStatusBuffer);
	ram.availableMemory = memoryStatusBuffer.ullAvailPhys;
}

unsigned long Maker::getNumberOfCores() {
	return processor.numberOfCores;
}

unsigned long Maker::getProcessorType() {
	return processor.processorType;
}

unsigned short Maker::getProcessorArchitecture() {
	return processor.processorArchitecture;
}

unsigned __int64 Maker::getAvailableMemory() {
	return ram.availableMemory;
}

std::string Maker::getGPUName() {
	return gpu.name;
}