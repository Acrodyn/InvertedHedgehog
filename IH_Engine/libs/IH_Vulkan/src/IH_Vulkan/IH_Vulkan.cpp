#include "IH_Vulkan.h"

#include "IH_Engine/Optics/IH_Window.h"

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

int64_t IH_Vulkan::GetWindowFlags()
{
	return SDL_WINDOW_VULKAN;
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


	//use vkbootstrap to select a gpu. 
	//We want a gpu that can write to the SDL surface and supports vulkan 1.3 with the correct features
	vkb::PhysicalDeviceSelector selector{ vkb_inst };
	vkb::PhysicalDevice physicalDevice = selector
		.set_minimum_version(1, 3)
		.set_required_features_13(features)
		.set_required_features_12(features12)
		.set_surface(_surface)
		.select()
		.value();


	//create the final vulkan device
	vkb::DeviceBuilder deviceBuilder{ physicalDevice };

	vkb::Device vkbDevice = deviceBuilder.build().value();

	// Get the VkDevice handle used in the rest of a vulkan application
	_device = vkbDevice.device;
	_chosenGPU = physicalDevice.physical_device;
}

void IH_Vulkan::InitSwapchain()
{
}

void IH_Vulkan::InitCommands()
{
}

void IH_Vulkan::InitSyncStructures()
{
}
