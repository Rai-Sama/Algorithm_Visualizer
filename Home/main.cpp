// Program for main menu
#include <windows.h>

#define ID_BUTTON1 1
#define ID_BUTTON2 2

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {

		/* Upon destruction, tell the main thread to stop */
		case WM_CREATE:{
			CreateWindowW(L"Static", L"Computer Graphics Project \n\nBy Anshuman Rai(3118041)\n   Rohit Yadav(3118064)\n   Amey Talekar(3118062)",  WS_CHILD | WS_VISIBLE,230, 50, 500, 500, hwnd, NULL, NULL, NULL);
			 CreateWindow(TEXT("BUTTON"), TEXT("Sorting"), WS_CHILD | WS_VISIBLE, 275, 250, 80, 20, hwnd, (HMENU) ID_BUTTON1, NULL, NULL );
			CreateWindow(TEXT("BUTTON"), TEXT("Path Finder"), WS_CHILD | WS_VISIBLE, 275, 290, 80, 20, hwnd, (HMENU) ID_BUTTON2, NULL, NULL );
			break;
		}

		case WM_COMMAND:{
			if(LOWORD(wParam) == ID_BUTTON1){
				system("D:\\Laptop\\Documents\\SortingVisuals\\bin\\Debug\\SortingVisuals.exe");

			}
			if(LOWORD(wParam) == ID_BUTTON2){
				system("D:\\Laptop\\Documents\\Path-Finder\\bin\\Debug\\PathFinder.exe");

			}
			break;
		}
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}

		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);

	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Algorithm Visualizer",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);


	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
