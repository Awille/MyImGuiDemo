cmake_minimum_required(VERSION 3.10)
project(MyImGuiDemo)


include_directories(E:/GLFW/glfw-3.3.8.bin.WIN32/include)
# 添加 imgui 目录下的所有源码文件
file(GLOB IMGUI_SOURCES ${PROJECT_SOURCE_DIR}/imgui/*.cpp)
file(GLOB IMGUI_HEADERS ${PROJECT_SOURCE_DIR}/imgui/*.h)

# 编译 imgui 为一个库
add_library(imgui ${IMGUI_SOURCES} ${IMGUI_HEADERS})

# 设置 imgui 库的包含目录
target_include_directories(imgui PUBLIC ${PROJECT_SOURCE_DIR}/imgui)

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# 添加可执行文件，并链接 imgui 库
add_executable(MyImGuiDemo main.cpp)
target_link_libraries(MyImGuiDemo PRIVATE imgui)
