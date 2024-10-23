#include "pch.h"
#include "main.h"
#include "RenderApp.h"

int main()
{
	RenderApp* app = RenderApp::Init();

	app->Run();

	app->Release();

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}
