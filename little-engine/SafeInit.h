#pragma once
#include "stdafx.h"

namespace LittleEngine
{
    template <typename T>
    class SafeInit final
    {
    public:
        SafeInit(T &t, bool throwOnFailure = true)
        {
            m_t = &t;
            m_isInitialized = (m_t->init() != 0);
            if (!m_isInitialized && throwOnFailure) throw std::exception("Failed to initialize object.");
        }
        ~SafeInit()
        {
            if (m_isInitialized) m_t->shutdown();
            m_t = nullptr;
        }

        bool isInitialized()
        {
            return m_isInitialized;
        }

    private:
        T *m_t;
        bool m_isInitialized = false;
    };
}
