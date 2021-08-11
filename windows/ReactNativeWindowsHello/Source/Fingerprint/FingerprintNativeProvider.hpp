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
        std::string FingerprintScanStatus();

        std::string CheckUserVerification();

        fire_and_forget CheckFingerprintAvailabilityAsync();

        std::string CheckFingerprintAvailability();

    private:
        std::string fingerprintDeviceStatus;
        std::string fingerprintScanStatus;

        std::unique_ptr<WinRtHelper> helper;
    };
}
