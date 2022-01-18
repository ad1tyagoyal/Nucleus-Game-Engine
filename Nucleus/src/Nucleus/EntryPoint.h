#pragma once


#ifdef NCL_PLATFORM_WINDOWS

extern Nucleus::Application* Nucleus::CreateApplication();


int main(int argc, char** argv) {

	Nucleus::Log::Init();
	NCL_CORE_INFO("Welcome to Nucleus Engine!");

	auto application = Nucleus::CreateApplication();
	application->Run();
	delete application;

}
	
#endif // NCL_PLATFORM_WINDOWS

