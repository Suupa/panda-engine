#pragma once
#ifdef PANDA_PLATFORM_WINDOWS
extern Panda::Application* Panda::CreateApplication();

int main(int argc, char** argv) {
	auto app = Panda::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Panda only supports Windows.
#endif