#pragma once

#ifdef PANDA_PLATFORM_WINDOWS
	#ifdef PANDA_BUILD_DLL
		#define PANDA_API _declspec(dllexport)
	#else
		#define PANDA_API _declspec(dllimport)
	#endif
#else
	#error Panda only supports Windows.
#endif