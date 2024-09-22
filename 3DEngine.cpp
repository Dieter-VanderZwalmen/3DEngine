#include <iostream>
#include <windows.h> // This must be included for Win32 API functions and types

/// <summary>
/// global_ variable of a pointer to a single character.
/// </summary>
/// Use wide-character string (wchar_t) for Unicode
const wchar_t* g_ClassName = L"MyWindowClass"; 


/// <summary>
///
/// </summary>
/// <param name="hwnd">handle to a window</param>
/// <param name="uMsg">message being sent to the window. Messages include events like key presses, mouse movements, resizing, closing the window, etc.</param>
/// <param name="wParam">additional information for some messages, like mouse position or button states</param>
/// <param name="lParam">additional information for some messages, like mouse position or button states</param>
/// <returns>"Long Result,"is an integer value that tells Windows what action the program took when handling a specific message..</returns>
/// <remarks>
/// Windows can "call back" this function to handle events.
/// <remarks>
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}



/// <summary>
/// Entry point for Windows applications. This is where the program starts execution.
/// </summary>
/// <param name="hInstance">Handle to the instance of the application. Each running program is assigned an instance handle.</param>
/// <param name="hPrevInstance">Used in older versions of Windows. It's no longer used, so we can ignore it.</param>
/// <param name="lpCmdLine">Pointer to the command-line arguments passed to the program.</param>
/// <param name="nCmdShow">Tells how the window should be shown (e.g., maximized, minimized, hidden).</param>
/// <returns>Returns an integer value that Windows uses to determine how the program exited.</returns>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Step 1: Define the Window Class
    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc; // Callback function to handle events
    wc.hInstance = hInstance;
    wc.lpszClassName = g_ClassName;

    // Step 2: Register the Window Class
    RegisterClass(&wc);

    // Step 3: Create the Window
    HWND hwnd = CreateWindowEx(
        0,                              // Optional Window Styles
        g_ClassName,                    // Window Class Name
        L"My First Win32 Window",         // Window Title
        WS_OVERLAPPEDWINDOW,            // Window Style
        CW_USEDEFAULT, CW_USEDEFAULT,   // Position (x, y)
        800, 600,                       // Size (width, height)
        NULL,                           // Parent Window    
        NULL,                           // Menu
        hInstance,                      // Instance Handle
        NULL                            // Additional Application Data
    );

    if (hwnd == NULL) {
        return 0;
    }

    // Step 4: Show the Window
    ShowWindow(hwnd, nCmdShow);

    // Step 5: Message Loop (runs until window is closed)
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0)) {
        // TranslateMessage translates keystroke messages into character messages.
        TranslateMessage(&msg);
        // DispatchMessage sends the message to the appropriate window procedure (in our case, WindowProc).
        DispatchMessage(&msg);
    }

    return 0;
}