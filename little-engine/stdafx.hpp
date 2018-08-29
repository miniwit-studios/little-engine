#pragma once

#ifdef LITTLEENGINE_EXPORTS
#define LITTLEENGINE_API __declspec(dllexport)
#else
#define LITTLEENGINE_API __declspec(dllimport)
#endif

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

template <typename T>
void SafeDelete(T *&ptr)
{
    if (ptr != nullptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}
