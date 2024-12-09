#include "pch.h"

#include "Editor.h"
#include "window/window.h"
#include "ui/viewport.h"

Editor::Editor(const std::string& app_name)
{
    mWindow->Init(1024, 720, app_name);
}


void Editor::loop()
{   
    while (mWindow->isRunning()) {
       
        // Clear the view
        mWindow->pre_render();

        // Render Scene
        mWindow->render();

        // Render end, swap buffers
        mWindow->post_render();
    };
};

void Editor::shutdown() {
    mWindow->end();
};