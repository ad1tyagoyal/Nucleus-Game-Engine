#include "NclPch.h"
#include "WindowsInput.h"
#include "Nucleus/Application.h"

#include <GLFW/glfw3.h>

namespace Nucleus {

    Input* Input::s_Instance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(int keyCode){
        GLFWwindow* window = static_cast<GLFWwindow*> (Application::Get().GetWindow().GetNativeWindow());
        int state = glfwGetKey(window, keyCode);
        return (state == GLFW_PRESS || state == GLFW_REPEAT);
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button) {
        GLFWwindow* window = static_cast<GLFWwindow*> (Application::Get().GetWindow().GetNativeWindow());
        int state = glfwGetMouseButton(window, button);
        return (state == GLFW_PRESS);
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl() {
        GLFWwindow* window = static_cast<GLFWwindow*> (Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);
        return { (float)xPos, (float)yPos };
    }

    float WindowsInput::GetMouseXImpl() {
        auto [x, y] = GetMousePosition();
        return x;
    }

    float WindowsInput::GetMouseYImpl() {
        auto [x, y] = GetMousePosition();
        return y;
    }


}

