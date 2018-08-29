#pragma once
#include "LoggerCore.hpp"

namespace LittleEngine
{
    class LITTLEENGINE_API Logger final : public LoggerCore
    {
    public:
        Logger(LoggerCore *core, const wchar_t *name, bool copyName = true);
        ~Logger();

        const wchar_t *name() const;

        virtual Logger *branch(const wchar_t *name) override;

        void log(const wchar_t *message);

    private:
        LoggerCore *m_core;
        const wchar_t *m_name;
    };
}
