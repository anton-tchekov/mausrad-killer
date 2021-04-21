// MouseKillerCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <Windows.h>
#include <iostream>

using namespace std;

HHOOK mouseHook;

LRESULT __stdcall MouseHookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		switch (wParam)
		{
		case WM_MOUSEWHEEL:
			return 1;
		}
	}
	return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}

void SetHook()
{
	if (!(mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookCallback, NULL, 0)))
	{
		cout << "Failed to install mouse hook!" << endl;
	}
}

void ReleaseHook()
{
	UnhookWindowsHookEx(mouseHook);
}

int main()
{
	SetHook();
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
