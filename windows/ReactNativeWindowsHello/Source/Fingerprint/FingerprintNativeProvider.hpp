#pragma once

#include <string>
#include <memory>
#include "WinRTHelper/WinRTHelper.hpp"

namespace winrt::ReactNativeWindowsHello::Fingerprint
{
    class FingerprintNativeProvider
    {
    public:
        FingerprintNativeProvider();

        std::string FingerprintDeviceStatus();

    private:
        fire_and_forget CheckFingerprintAvailabilityAsync();
        std::string CheckFingerprintAvailability();

        std::string fingerprintDeviceStatus;

        std::unique_ptr<WinRtHelper> helper;
    };
}
