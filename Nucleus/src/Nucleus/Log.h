#pragma once


#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Nucleus {
	
	class NCL_API Log {

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { 
			return s_CoreLogger; 
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}


	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};	
}

//core logger
#define NCL_CORE_ERROR(...)  ::Nucleus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NCL_CORE_WARN(...)   ::Nucleus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NCL_CORE_INFO(...)   ::Nucleus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NCL_CORE_TRACE(...)  ::Nucleus::Log::GetCoreLogger()->trace(__VA_ARGS__)


//client logger
#define NCL_ERROR(...)  ::Nucleus::Log::GetClientLogger()->error(__VA_ARGS__)
#define NCL_WARN(...)   ::Nucleus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NCL_INFO(...)   ::Nucleus::Log::GetClientLogger()->info(__VA_ARGS__)
#define NCL_TRACE(...)  ::Nucleus::Log::GetClientLogger()->trace(__VA_ARGS__)


