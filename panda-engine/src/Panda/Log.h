#pragma once

#include "spdlog/spdlog.h"
#include <memory>
#include "Core.h"

namespace Panda {

	class PANDA_API Log {
		public:
			inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
			inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }

			static void init();

		private:
			static std::shared_ptr<spdlog::logger> s_coreLogger;
			static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}

//core log macros
#define PANDA_CORE_TRACE(...) ::Panda::Log::getCoreLogger()->trace(__VA_ARGS__);
#define PANDA_CORE_INFO(...) ::Panda::Log::getCoreLogger()->info(__VA_ARGS__);
#define PANDA_CORE_WARN(...) ::Panda::Log::getCoreLogger()->warn(__VA_ARGS__);
#define PANDA_CORE_ERROR(...) ::Panda::Log::getCoreLogger()->error(__VA_ARGS__);
#define PANDA_CORE_FATAL(...) ::Panda::Log::getCoreLogger()->fatal(__VA_ARGS__);


//client log macros
#define PANDA_TRACE(...) ::Panda::Log::getClientLogger()->trace(__VA_ARGS__);
#define PANDA_INFO(...) ::Panda::Log::getColientogger()->info(__VA_ARGS__);
#define PANDA_WARN(...) ::Panda::Log::getColientogger()->warn(__VA_ARGS__);
#define PANDA_ERROR(...) ::Panda::Log::getClientLogger()->error(__VA_ARGS__);
#define PANDA_FATAL(...) ::Panda::Log::getClientLogger()->fatal(__VA_ARGS__);

//TODO check if in destribution mode, if so the above macros should be defined as nothing so that no logging occurs for end user.