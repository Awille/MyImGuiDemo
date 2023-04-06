//#include <iostream>
//#include "imgui/imgui.h"
//#include "imgui/imgui_impl_glfw.h"
//#include "imgui/imgui_impl_opengl3.h"
//
//#include <Windows.h>
//
//
//int main() {
//    // 初始化 ImGui
//    ImGui::CreateContext();
//
//    ImGuiIO& io = ImGui::GetIO();
//    io.DisplaySize = ImVec2(800.0f, 600.0f);
//
//    // 创建字体纹理
//    unsigned char* fontPixels;
//    int fontWidth, fontHeight;
//    io.Fonts->GetTexDataAsRGBA32(&fontPixels, &fontWidth, &fontHeight);
//    // 这里可以将 fontPixels 中的图像数据上传到渲染器的纹理中
//
//    while (true) {
//        // 开始 ImGui 帧
//        ImGui::NewFrame();
//
//        // 在帧内部调用 ImGui 相关函数，例如：
//        //    - 创建窗口、添加控件等
//        //    - 处理用户输入，例如鼠标和键盘输入
//        //    - 更新 ImGui 输入状态，例如鼠标光标位置等
//
//        // 创建一个窗口
//        ImGui::Begin("Hello GUI");
//
//        // 在窗口上显示文本
//        ImGui::Text("Hello GUI");
//
//        // 结束窗口
//        ImGui::End();
//
//        // 渲染 ImGui 绘制命令到渲染器（这里省略了渲染器后端的函数调用）
//
//        // 将渲染结果显示到屏幕上（这里省略了显示的具体实现）
//
//        // 结束 ImGui 帧
//        ImGui::Render();
//    }
//
//    // 清理 ImGui 资源
//    ImGui::DestroyContext();
//
//    return 0;
//}

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

int main() {
    // 初始化 GLFW
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "ImGui Demo", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // 初始化 ImGui
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2(800.0f, 600.0f);

    // 创建字体纹理
    unsigned char* fontPixels;
    int fontWidth, fontHeight;
    io.Fonts->GetTexDataAsRGBA32(&fontPixels, &fontWidth, &fontHeight);
    // 这里可以将 fontPixels 中的图像数据上传到渲染器的纹理中

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // 开始 ImGui 帧
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 在帧内部调用 ImGui 相关函数，例如：
        //    - 创建窗口、添加控件等
        //    - 处理用户输入，例如鼠标和键盘输入
        //    - 更新 ImGui 输入状态，例如鼠标光标位置等

        // 创建一个窗口
        ImGui::Begin("Hello GUI");

        // 在窗口上显示文本
        ImGui::Text("Hello GUI");

        // 结束窗口
        ImGui::End();

        // 渲染 ImGui 绘制命令到渲染器
        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // 将渲染结果显示到屏幕上
        glfwSwapBuffers(window);
    }

    // 清理 ImGui 和 GLFW 资源
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();

    return 0;
}


