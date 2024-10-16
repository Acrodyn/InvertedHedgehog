cmake_minimum_required (VERSION 3.1)

project (IH_Vulkan)

file(GLOB_RECURSE VULKAN_SOURCES "src/*.cpp" "src/*.h")

add_library(IH_Vulkan SHARED ${VULKAN_SOURCES})

find_package(Vulkan REQUIRED)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

find_program(GLSL_VALIDATOR glslangValidator HINTS /usr/bin /usr/local/bin $ENV{VULKAN_SDK}/Bin/ $ENV{VULKAN_SDK}/Bin32/)


file(GLOB_RECURSE GLSL_SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/shaders/*.frag"
    "${PROJECT_SOURCE_DIR}/shaders/*.vert"
    "${PROJECT_SOURCE_DIR}/shaders/*.comp"
    )

foreach(GLSL ${GLSL_SOURCE_FILES})
  message(STATUS "BUILDING SHADER")
  get_filename_component(FILE_NAME ${GLSL} NAME)
  set(SPIRV "${PROJECT_SOURCE_DIR}/shaders/${FILE_NAME}.spv")
  message(STATUS ${GLSL})
  add_custom_command(
    OUTPUT ${SPIRV}
    COMMAND ${GLSL_VALIDATOR} -V ${GLSL} -o ${SPIRV}
    DEPENDS ${GLSL})
  list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach(GLSL)

add_custom_target(
    Shaders 
    DEPENDS ${SPIRV_BINARY_FILES}
    )

add_subdirectory(third_party/vkbootstrap)
target_link_libraries(IH_Vulkan PRIVATE vk-bootstrap::vk-bootstrap)
set_target_properties(vk-bootstrap PROPERTIES FOLDER "ExternalLibs")

add_subdirectory(third_party/volk)
target_link_libraries(IH_Vulkan PRIVATE volk)
set_target_properties(volk PROPERTIES FOLDER "ExternalLibs")

add_subdirectory(third_party/vma)
target_link_libraries(IH_Vulkan PRIVATE GPUOpen::VulkanMemoryAllocator)
set_target_properties(VulkanMemoryAllocator PROPERTIES FOLDER "ExternalLibs")