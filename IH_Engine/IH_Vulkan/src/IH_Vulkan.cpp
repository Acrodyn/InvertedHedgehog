////> includes
//#include "IH_Vulkan.h"
//
////#include "SDL.h"
////#include <SDL_vulkan.h>
//
//#include "vk_initializers.h"
//#include "vk_types.h"
//
//#include <chrono>
//#include <thread>
//
//IH_Vulkan* VulkanInstance = nullptr;
//
//IH_Vulkan& IH_Vulkan::Get() { return *VulkanInstance; }
//void IH_Vulkan::init()
//{
//    // only one engine initialization is allowed with the application.
//    //assert(VulkanInstance == nullptr);
//    //VulkanInstance = this;
//
//    //// We initialize SDL and create a window with it.
//    //SDL_Init(SDL_INIT_VIDEO);
//
//    //SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);
//
//    //_window = SDL_CreateWindow(
//    //    "Vulkan Engine",
//    //    SDL_WINDOWPOS_UNDEFINED,
//    //    SDL_WINDOWPOS_UNDEFINED,
//    //    _windowExtent.width,
//    //    _windowExtent.height,
//    //    window_flags);
//
//    //// everything went fine
//    //_isInitialized = true;
//}
//
//void IH_Vulkan::cleanup()
//{
//    if (_isInitialized) {
//
//        //SDL_DestroyWindow(_window);
//    }
//
//    // clear engine pointer
//    VulkanInstance = nullptr;
//}
//
//void IH_Vulkan::draw()
//{
//    // nothing yet
//}
//
//void IH_Vulkan::run()
////{
////    SDL_Event e;
////    bool bQuit = false;
////
////    // main loop
////    while (!bQuit) {
////        // Handle events on queue
////        while (SDL_PollEvent(&e) != 0) {
////            // close the window when user alt-f4s or clicks the X button
////            if (e.type == SDL_QUIT)
////                bQuit = true;
////
////            if (e.type == SDL_WINDOWEVENT) {
////                if (e.window.event == SDL_WINDOWEVENT_MINIMIZED) {
////                    stop_rendering = true;
////                }
////                if (e.window.event == SDL_WINDOWEVENT_RESTORED) {
////                    stop_rendering = false;
////                }
////            }
////        }
////
////        // do not draw if we are minimized
////        if (stop_rendering) {
////            // throttle the speed to avoid the endless spinning
////            std::this_thread::sleep_for(std::chrono::milliseconds(100));
////            continue;
////        }
////
////        draw();
////    }
//}