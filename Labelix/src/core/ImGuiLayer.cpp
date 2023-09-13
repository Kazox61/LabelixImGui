#include "core/ImGuiLayer.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

namespace LabelixNS {
	void ImGuiLayer::Init(const Window& window) {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		io.ConfigWindowsMoveFromTitleBarOnly = true;

		ImGui::StyleColorsDark();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		style.ScaleAllSizes(window.GetContentScale());

		style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;

		style.TabRounding = 0.0f;
		style.ScrollbarRounding = 0.0f;

		ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)window.m_WindowPtr, true);
		ImGui_ImplOpenGL3_Init("#version 330");

		ImGui::GetIO().IniFilename = "./imgui.ini";
	}

	void ImGuiLayer::BeginFrame() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
	}

	void ImGuiLayer::EndFrame() {
		if (ImGui::IsAnyItemFocused())
		{
			ImGui::CaptureKeyboardFromApp(false);
		}

		{
			ImGui::Render();
		}
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		GLFWwindow* context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(context);
	}

	void ImGuiLayer::Free() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
}