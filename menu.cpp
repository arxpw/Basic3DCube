#include <imgui.h>
#include "menu.h"

void renderMenu(float& cubeScale, float fps, int& currentFpsIndex, const char** fpsOptions, int* fpsLimits, double& targetFrameTime)
{
    ImGui::SetNextWindowPos(ImVec2(10, 5), ImGuiCond_None);
    ImGui::SetNextWindowSize(ImVec2(240, 110), ImGuiCond_None);
    ImGui::Begin("Cube Controls");
    ImGui::Text("FPS: %.1f", fps);

    ImGui::Separator();
    ImGui::SliderFloat("Size", &cubeScale, 0.1f, 3.0f);

    if (ImGui::Combo("FPS Limit", &currentFpsIndex, fpsOptions, 5))
    {
        targetFrameTime = 1.0 / fpsLimits[currentFpsIndex];
    }

    ImGui::End();
}
