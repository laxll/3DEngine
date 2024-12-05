#pragma once

#include "window.h"
#include "camera.h"

class Editor
{

public:
	Editor(const std::string& app_name);

	static Editor& Instance() { return *sInstance; }

	void init();
	void loop();
	void end();

private:
	static Editor* sInstance;

	std::unique_ptr<WindowManager> mWindow = std::make_unique<WindowManager>();

};