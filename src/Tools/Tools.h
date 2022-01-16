#ifndef TOOLS_H__
#define TOOLS_H

#include <Include.h>

using Handle = std::unique_ptr<void, decltype(&CloseHandle)>;

class Tools
{
public:
    uint32_t GetProccessByName(const std::wstring_view name);
    bool EnablePrivelege(const std::wstring_view name);
    BOOL IsRunAsAdmin();

    std::wstring GetUsername();

    [[nodiscard]] SC_HANDLE StopService(const std::wstring_view name) const;
    [[nodiscard]] BOOL StartTrustedInstallerService() const;
    [[nodiscard]] BOOL DeleteDefenderServices() const;

    [[nodiscard]] int DisableElamDrivers(void) const;

    void ImpersonateUserByProcessId(const uint32_t pid) const;
};

extern Tools* g_tools;
#endif
