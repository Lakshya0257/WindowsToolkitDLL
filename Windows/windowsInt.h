#pragma once

#ifdef WINDOWSINT_EXPORTS
#define WINDOWSINT_API __declspec(dllexport)
#else
#define WINDOWSINT_API __declspec(dllimport)
#endif


extern "C" WINDOWSINT_API void ShowTaskbar();
extern "C" WINDOWSINT_API void HideTaskbar();
extern "C" WINDOWSINT_API void ToggleTaskbar();
extern "C" WINDOWSINT_API void MinimizeAllWindows();
extern "C" WINDOWSINT_API void RestoreAllWindows();
extern "C" WINDOWSINT_API void SetVolumeLevel(int value);
extern "C" WINDOWSINT_API void MuteVolume();
extern "C" WINDOWSINT_API void UnmuteVolume();
extern "C" WINDOWSINT_API void OpenWebBrowser(const char* url);
extern "C" WINDOWSINT_API void ShutdownSystem();
extern "C" WINDOWSINT_API void SetWallpaper(const char* imagePath);
extern "C" WINDOWSINT_API void LockWorkstation();
extern "C" WINDOWSINT_API void LogoffUser();
extern "C" WINDOWSINT_API void AddToStartup(const char* appName, const char* appPath);
extern "C" WINDOWSINT_API void RemoveFromStartup(const char* appName);
