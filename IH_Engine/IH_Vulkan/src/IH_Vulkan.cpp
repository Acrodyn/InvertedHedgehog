#include "IH_Vulkan.h"

void IH_Vulkan::Init()
{
	VulkanEngine engine;

	engine.init();

	engine.run();

	engine.cleanup();

	return 0;
}
