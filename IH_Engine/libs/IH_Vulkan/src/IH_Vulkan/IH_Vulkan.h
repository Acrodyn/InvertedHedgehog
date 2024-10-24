#pragma once

#include "IH_VkTypes.h"
#include "IH_Engine/Optics/IH_RendererInterface.h"

class IH_Window;

class IH_Vulkan : public IH_RendererInterface
{
public:
	void Init(IH_Window* Window) override;
	int64_t GetWindowFlags() override;

private:
	void InitVulkan();
	void InitSwapchain();
	void InitCommands();
	void InitSyncStructures();
	
private:
	VkInstance _instance;						// Vulkan library handle
	VkDebugUtilsMessengerEXT _debug_messenger;	// Vulkan debug output handle
	VkPhysicalDevice _chosenGPU;				// GPU chosen as the default device
	VkDevice _device;							// Vulkan device for commands
	VkSurfaceKHR _surface;						// Vulkan window surface

	IH_Window* _window;
};