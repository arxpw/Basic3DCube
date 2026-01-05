cmake_minimum_required(VERSION 3.20)
project(Basic3DCube)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(Basic3DCube WIN32
    main.cpp
    imgui/imgui_impl_glfw.cpp
    imgui/imgui_impl_opengl3.cpp
)

target_include_directories(Basic3DCube PRIVATE imgui)

target_compile_definitions(Basic3DCube PRIVATE IMGUI_IMPL_OPENGL_LOADER_GLAD)

target_link_libraries(Basic3DCube
    glfw
    glad::glad
    imgui::imgui
    glm::glm
)
