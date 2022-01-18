#pragma once

#ifdef  NCL_PLATFORM_WINDOWS
#if NCL_DYNAMIC_LINK
	#ifdef NCL_BUILD_DLL
		#define NCL_API __declspec(dllexport)
	#else 
		#define NCL_API __declspec(dllimport)
	#endif // 
#else
	#define NCL_API 
#endif
#else 
	#error Nuclues only support windows!
#endif //  NCL_PLATFORM_WINDOWS

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)