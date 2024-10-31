#pragma once

#include "IH_VkTypes.h"
#include "IH_Engine/Optics/IH_RendererInterface.h"

class IH_Window;

constexpr uint16_t FRAME_COUNT = 2;

struct FrameData 
{
	VkCommandPool CommandPool;
	VkCommandBuffer MainCommandBuffer;
};

constexpr unsigned int FRAME_OVERLAP = 2;

class IH_Vulkan : public IH_RendererInterface
{
public:
	void Init(IH_Window* Window) override;
	void Clear() override;
	uint64_t GetWindowFlags() override;
	FrameData& GetCurrentFrame();

private:
	void InitVulkan();

	void CreateSwapchain(uint32_t Width, uint32_t Height);
	void InitSwapchain();
	void DestroySwapchain();

	void InitCommands();
	void DestroyCommands();

	void InitSyncStructures();


public:
	FrameData _frames[FRAME_COUNT];
	
private:
	VkInstance _instance;						// Vulkan library handle
	VkDebugUtilsMessengerEXT _debug_messenger;	// Vulkan debug output handle
	VkPhysicalDevice _chosenGPU;				// GPU chosen as the default device
	VkDevice _device;							// Vulkan device for commands
	VkSurfaceKHR _surface;						// Vulkan window surface

	VkSwapchainKHR _swapchain;
	VkFormat _swapchainImageFormat;
	std::vector<VkImage> _swapchainImages;
	std::vector<VkImageView> _swapchainImageViews;
	VkExtent2D _swapchainExtent;

	VkQueue _graphicsQueue;

	IH_Window* _window;

	uint16_t _currentFrame = 0;
	uint32_t _graphicsQueueFamily = 0;
};