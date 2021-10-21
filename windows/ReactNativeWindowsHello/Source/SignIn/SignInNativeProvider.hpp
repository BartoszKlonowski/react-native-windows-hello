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

        Windows::Security::Credentials::UI::UserConsentVerificationResult CheckUserVerification( const winrt::hstring& promptMessage );
        Windows::Security::Credentials::UI::UserConsentVerifierAvailability CheckSignInAvailability();

        fire_and_forget CheckUserVerificationAsync();
        fire_and_forget CheckSignInAvailabilityAsync();

    private:
        std::string signInDeviceStatus;
        std::string signInScanStatus;

        std::unique_ptr<WinRtHelper> helper;
    };
}
