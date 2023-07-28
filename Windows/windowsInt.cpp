#include "pch.h"
#include <utility>
#include "windowsInt.h"
#include <Windows.h>
#include <PhysicalMonitorEnumerationAPI.h>
#include <mmsystem.h>
#include <Shellapi.h>
#include <powrprof.h>

// Function to show the taskbar
void ShowTaskbar()
{
    HWND taskbarWnd = FindWindow(L"Shell_TrayWnd", nullptr);
    ShowWindow(taskbarWnd, SW_SHOW);
}

// Function to toggle the taskbar visibility
void ToggleTaskbar()
{
    HWND taskbarWnd = FindWindow(L"Shell_TrayWnd", nullptr);
    if (IsWindowVisible(taskbarWnd))
        ShowWindow(taskbarWnd, SW_HIDE);
    else
        ShowWindow(taskbarWnd, SW_SHOW);
}

// Function to minimize all windows
void MinimizeAllWindows()
{
    HWND shellWnd = GetShellWindow();
    SendMessage(shellWnd, WM_COMMAND, 419, 0); // SC_MINIMIZEALL
}

// Function to restore all windows (unminimize)
void RestoreAllWindows()
{
    HWND shellWnd = GetShellWindow();
    SendMessage(shellWnd, WM_COMMAND, 416, 0); // SC_RESTOREALL
}

// Function to set the volume level (0-100)
void SetVolumeLevel(int volume)
{
    // Volume ranges from 0 to 100
    int adjustedVolume = max(0, min(volume, 100));
    waveOutSetVolume(NULL, MAKELONG((WORD)adjustedVolume, (WORD)adjustedVolume));
}

// Function to mute the system volume
void MuteVolume()
{
    waveOutSetVolume(NULL, 0);
}

// Function to unmute the system volume
void UnmuteVolume()
{
    waveOutSetVolume(NULL, 0xFFFFFFFF);
}

// Function to open the default web browser with a specified URL
void OpenWebBrowser(const char* url)
{
    ShellExecuteA(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
}

// Function to shutdown or restart the system (requires admin privileges)
void ShutdownSystem()
{
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;

    // Get a token for this process
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
        return;

    // Get the LUID for the shutdown privilege
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);

    tkp.PrivilegeCount = 1;  // one privilege to set
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    // Get the shutdown privilege for this process
    AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof(tkp), NULL, NULL);

    // Shut down the system and force all applications to close
    ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0);
}

// Function to log off the current user (requires admin privileges)
void LogoffUser()
{
    ExitWindowsEx(EWX_LOGOFF, 0);
}

// Function to lock the workstation (requires admin privileges)
void LockWorkstation()
{
    LockWorkStation();
}

// Function to change the desktop wallpaper
void SetWallpaper(const char* imagePath)
{
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (PVOID)imagePath, SPIF_SENDCHANGE);
}


void HideTaskbar() {
    HWND hwndTaskbar = FindWindowA("Shell_TrayWnd\0", NULL);
    ShowWindow(hwndTaskbar, SW_HIDE);

    // Enumerate through all top-level windows and maximize them
    HWND hwndTop = GetTopWindow(NULL);
    while (hwndTop) {
        if (IsWindowVisible(hwndTop)) {
            // Get the screen dimensions
            int screenWidth = GetSystemMetrics(SM_CXSCREEN);
            int screenHeight = GetSystemMetrics(SM_CYSCREEN);

            // Get the window rect
            RECT rect;
            GetWindowRect(hwndTop, &rect);

            // Calculate the window size to cover the entire screen including the taskbar space
            int width = screenWidth - rect.left;
            int height = screenHeight - rect.top;

            // Resize and move the window to cover the entire screen
            SetWindowPos(hwndTop, HWND_TOP, 0, 0, width, height, SWP_SHOWWINDOW);
        }
        hwndTop = GetNextWindow(hwndTop, GW_HWNDNEXT);
    }
}

void AddToStartup(const char* appName, const char* appPath)
{
    HKEY hKey;
    if (RegCreateKeyExA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, NULL, 0, KEY_SET_VALUE, NULL, &hKey, NULL) == ERROR_SUCCESS)
    {
        RegSetValueExA(hKey, appName, 0, REG_SZ, (const BYTE*)appPath, strlen(appPath) + 1);
        RegCloseKey(hKey);
    }
}

// Function to remove the application from startup
void RemoveFromStartup(const char* appName)
{
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS)
    {
        RegDeleteValueA(hKey, appName);
        RegCloseKey(hKey);
    }
}

