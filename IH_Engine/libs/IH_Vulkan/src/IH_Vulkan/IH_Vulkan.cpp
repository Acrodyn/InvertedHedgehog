#include "IH_Vulkan.h"

#include "IH_Engine/Core/IH_Engine.h"
#include "IH_Engine/Optics/IH_Window.h"
#include "IH_Engine/Core/IH_AppData.h"

#include "IH_VKInitializers.h"
#include "VkBootstrap.h"
#include "SDL3/SDL_vulkan.h"

constexpr bool UseValidationLayers = true;

void IH_Vulkan::Init(IH_Window* Window)
{
	_window = Window;

	InitVulkan();
	InitSwapchain();
	InitCommands();
	InitSyncStructures();
}

void IH_Vulkan::Clear()
{
	DestroyCommands();
	DestroySwapchain();

	vkDestroySurfaceKHR(_instance, _surface, nullptr);
	vkDestroyDevice(_device, nullptr);

	vkb::destroy_debug_utils_messenger(_instance, _debug_messenger);
	vkDestroyInstance(_instance, nullptr);
}

uint64_t IH_Vulkan::GetWindowFlags()
{
	return SDL_WINDOW_VULKAN;
}

FrameData& IH_Vulkan::GetCurrentFrame()
{
	return _frames[_currentFrame];
}

void IH_Vulkan::InitVulkan()
{
	vkb::InstanceBuilder builder;

	//make the vulkan instance, with basic debug features
	auto inst_ret = builder.set_app_name("Example Vulkan Application")
		.request_validation_layers(UseValidationLayers)
		.use_default_debug_messenger()
		.require_api_version(1, 3, 0)
		.build();

	vkb::Instance vkb_inst = inst_ret.value();

	//grab the instance 
	_instance = vkb_inst.instance;
	_debug_messenger = vkb_inst.debug_messenger;

	SDL_Vulkan_CreateSurface(_window->GetWindowObject(), _instance, nullptr, &_surface);

	//vulkan 1.3 features
	VkPhysicalDeviceVulkan13Features features{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES };
	features.dynamicRendering = true;
	features.synchronization2 = true;

	//vulkan 1.2 features
	VkPhysicalDeviceVulkan12Features features12{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES };
	features12.bufferDeviceAddress = true;
	features12.descriptorIndexing = true;

	vkb::PhysicalDeviceSelector selector{ vkb_inst };
	vkb::PhysicalDevice physicalDevice = selector
		.set_minimum_version(1, 3)
		.set_required_features_13(features)
		.set_required_features_12(features12)
		.set_surface(_surface)
		.select()
		.value();


	vkb::DeviceBuilder deviceBuilder{ physicalDevice };
	vkb::Device vkbDevice = deviceBuilder.build().value();

	_device = vkbDevice.device;
	_chosenGPU = physicalDevice.physical_device;

	_graphicsQueue = vkbDevice.get_queue(vkb::QueueType::graphics).value();
	_graphicsQueueFamily = vkbDevice.get_queue_index(vkb::QueueType::graphics).value();
}

void IH_Vulkan::InitSwapchain()
{
	const OpticsData& opticsData = IHE_PTR->GetAppData()->Optics;

	CreateSwapchain(opticsData.WindowWidth, opticsData.WindowHeight);
}

void IH_Vulkan::InitCommands()
{
	VkCommandPoolCreateInfo commandPoolInfo = VK_Init::CommandPoolCreateInfo(_graphicsQueueFamily, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);

	for (int i = 0; i < FRAME_COUNT; ++i) 
	{
		VK_CHECK(vkCreateCommandPool(_device, &commandPoolInfo, nullptr, &_frames[i].CommandPool));

		VkCommandBufferAllocateInfo cmdAllocInfo = VK_Init::CommandBufferAllocateInfo(_frames[i].CommandPool, 1);

		VK_CHECK(vkAllocateCommandBuffers(_device, &cmdAllocInfo, &_frames[i].MainCommandBuffer));
	}
}

void IH_Vulkan::DestroyCommands()
{
	vkDeviceWaitIdle(_device);

	for (int i = 0; i < FRAME_OVERLAP; ++i) 
	{
		vkDestroyCommandPool(_device, _frames[i].CommandPool, nullptr);
	}
}

void IH_Vulkan::InitSyncStructures()
{

}

void IH_Vulkan::CreateSwapchain(uint32_t Width, uint32_t Height)
{
	vkb::SwapchainBuilder swapchainBuilder{ _chosenGPU,_device,_surface };

	_swapchainImageFormat = VK_FORMAT_B8G8R8A8_UNORM;

	vkb::Swapchain vkbSwapchain = swapchainBuilder
		.set_desired_format(VkSurfaceFormatKHR{ _swapchainImageFormat, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR })
		.set_desired_present_mode(VK_PRESENT_MODE_FIFO_KHR)
		.set_desired_extent(Width, Height)
		.add_image_usage_flags(VK_IMAGE_USAGE_TRANSFER_DST_BIT)
		.build()
		.value();

	_swapchainExtent = vkbSwapchain.extent;
	_swapchain = vkbSwapchain.swapchain;
	_swapchainImages = vkbSwapchain.get_images().value();
	_swapchainImageViews = vkbSwapchain.get_image_views().value();
}

void IH_Vulkan::DestroySwapchain()
{
	vkDestroySwapchainKHR(_device, _swapchain, nullptr);

	for (int i = 0; i < _swapchainImageViews.size(); i++)
	{
		vkDestroyImageView(_device, _swapchainImageViews[i], nullptr);
	}
}
