#include "NclPch.h"

#include <Nucleus/Log.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Nucleus {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() {
		spdlog::set_pattern("%^ [%T] %n : %v %$");

		s_CoreLogger = spdlog::stderr_color_mt("Nucleus Engine");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stderr_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
	

}
