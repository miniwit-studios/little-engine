#pragma once

#include "little-engine/stdafx.hpp"

#ifdef WINDOWSPA_EXPORTS
#define WINDOWSPA_API __declspec(dllexport)
#else
#define WINDOWSPA_API __declspec(dllimport)
#endif
