#include <windows.h>
#include <tchar.h>

#define UNICODE

static const PTCHAR className = TEXT("My Class Name");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(_In_ HINSTANCE hInstance,
				   _In_opt_ HINSTANCE hPrevInstance,
				   _In_ LPSTR lpCmdLine,
				   _In_ int nShowCmd)
{
	HWND		hwnd;
	WNDCLASS	wndclass;
	MSG			msg;

	wndclass.cbClsExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.cbWndExtra	= 0;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.lpszClassName = className;
	wndclass.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 3);
	wndclass.lpszMenuName = NULL;
	wndclass.lpfnWndProc = WndProc;
	wndclass.style = NULL;

	if (!RegisterClass(&wndclass))
	{
		return 0;
	}

	hwnd = CreateWindow(className, TEXT("My Window"),
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, CW_USEDEFAULT,
						CW_USEDEFAULT, CW_USEDEFAULT,
						NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}