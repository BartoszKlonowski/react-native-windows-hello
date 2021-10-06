#pragma once

#include <string>
#include <memory>
#include "WinRTHelper/WinRTHelper.hpp"

namespace winrt::ReactNativeWindowsHello::SignIn
{
    class SignInNativeProvider
    {
    public:
        SignInNativeProvider();

        std::string SignInDeviceStatus();
        std::string SignInScanStatus();

        std::string CheckUserVerification();

        fire_and_forget CheckUserVerificationAsync();

        fire_and_forget CheckSignInAvailabilityAsync();

        std::string CheckSignInAvailability();

    private:
        std::string signInDeviceStatus;
        std::string signInScanStatus;

        std::unique_ptr<WinRtHelper> helper;
    };
}
