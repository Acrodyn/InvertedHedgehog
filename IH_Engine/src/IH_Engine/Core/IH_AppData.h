#pragma once

enum class AppRenderer
{
	Vulkan
};

struct AppData
{
	char* AppName;
	AppRenderer Renderer;
};