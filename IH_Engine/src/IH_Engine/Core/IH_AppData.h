#pragma once

enum class AppRenderer
{
	Vulkan
};

struct OpticsData
{
	AppRenderer Renderer;
	int WindowWidth;
	int WindowHeight;
};

struct AppData
{
	char* AppName;
	OpticsData Optics;
};