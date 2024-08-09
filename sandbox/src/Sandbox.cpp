#include "Panda.h"

class Sandbox : public Panda::Application {

	public:
		Sandbox() {
	
		}
		~Sandbox() {

		}
};

Panda::Application* Panda::CreateApplication() {
	return new Sandbox();
}