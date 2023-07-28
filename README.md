# WindowsToolkitDLL - Windows Interaction DLL

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://travis-ci.com/your_username/WindowsUtils.svg?branch=main)](https://travis-ci.com/Lakshya0257/WindowsToolkitDLL)

WindowsUtils is a powerful and versatile DLL file that provides seamless Windows interactions for desktop application development. It offers essential functions like taskbar control, volume adjustment, system notifications, and more.

## Features
- `ShowTaskbar()` - Show the taskbar on the desktop.
- `HideTaskbar()` - Hide the taskbar from the desktop.
- `ToggleTaskbar()` - Toggle the taskbar visibility.
- `MinimizeAllWindows()` - Minimize all open windows.
- `RestoreAllWindows()` - Restore all minimized windows.
- `SetVolumeLevel(int value)` - Set the system volume level (0-100).
- `MuteVolume()` - Mute the system volume.
- `UnmuteVolume()` - Unmute the system volume.
- `OpenWebBrowser(const char* url)` - Open the default web browser with a specified URL.
- `ShutdownSystem()` - Shutdown the system (requires admin privileges).
- `SetWallpaper(const char* imagePath)` - Change the desktop wallpaper programmatically.
- `LockWorkstation()` - Lock the workstation (requires admin privileges).
- `LogoffUser()` - Log off the current user (requires admin privileges).
- `AddToStartup(const char* appName, const char* appPath)` - Add the application to Windows startup.
- `RemoveFromStartup(const char* appName)` - Remove the application from Windows startup.

## Prerequisites
- Windows operating system (32-bit or 64-bit).

## Usage
1. Download the latest WindowsUtils DLL from the [Releases](https://github.com/your_username/WindowsUtils/releases) section.
2. Include the `windowsUtils.h` header file in your C/C++ project.
3. Link the WindowsUtils DLL to your project.

## Examples
```c
// Sample code to hide the taskbar
#include "windowsUtils.h"

int main() {
    HideTaskbar();
    return 0;
}

