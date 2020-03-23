#include <iostream>

#include "Maker.h"
#include "WindowsUtilities.h"

int main()
{

	Maker maker;
	maker.fillRAMInfo();
	maker.fillCPUInfo();
	maker.fillGPUInfo();
	
	while (1) {
		printf("Available RAM: %.2fGB\n", maker.getAvailableMemory() / 1024e6);
		printf("Number of processors: %lu\n", maker.getNumberOfCores());
		printf("Processor architecture: %d\n", maker.getProcessorArchitecture());
		printf("Processor type: %lubits\n", maker.getProcessorType() == 8664 ? 64 : 32);
		std::cout << "GPU name: " << maker.getGPUName();
		
		Sleep(1000);
		maker.update();
		WindowsUtilities::clearConsoleText();
	}
}