#include "keyboard-overlay.h"
#include <imgui.h>
#include <GLFW/glfw3.h>

void renderKeyboardOverlay(GLFWwindow* window)
{
    ImGui::SetNextWindowPos(ImVec2(10, 175), ImGuiCond_FirstUseEver);
    ImGui::Begin("Controls", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);

    ImGui::Text("Movement Controls:");
    ImGui::Spacing();

    // Helper function to draw a key button
    auto drawKey = [&](const char* label, int glfwKey, float width = 40.0f) {
        bool isPressed = glfwGetKey(window, glfwKey) == GLFW_PRESS;

        if (isPressed)
        {
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.2f, 0.2f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.2f, 0.2f, 0.2f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.2f, 0.2f, 0.2f, 1.0f));
        }
        else
        {
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.4f, 0.4f, 0.4f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.5f, 0.5f, 0.5f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.3f, 0.3f, 0.3f, 1.0f));
        }

        ImGui::Button(label, ImVec2(width, 40.0f));
        ImGui::PopStyleColor(3);
    };

    // WASD Layout
    ImGui::Indent(48.0f);
    drawKey("W", GLFW_KEY_W);
    ImGui::Unindent(48.0f);

    drawKey("A", GLFW_KEY_A);
    ImGui::SameLine();
    drawKey("S", GLFW_KEY_S);
    ImGui::SameLine();
    drawKey("D", GLFW_KEY_D);

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    // SPACE and CTRL
    drawKey("SPACE", GLFW_KEY_SPACE, 140.0f);
    drawKey("CTRL", GLFW_KEY_LEFT_CONTROL, 140.0f);

    ImGui::End();
}
