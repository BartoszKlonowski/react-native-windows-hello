#include "pch.h"
#include "FingerprintNativeProvider.hpp"

namespace winrt::ReactNativeWindowsHello::Fingerprint
{
    FingerprintNativeProvider::FingerprintNativeProvider()
    {
        helper = std::make_unique<WinRtHelper>();
    }

    std::string FingerprintNativeProvider::FingerprintDeviceStatus()
    {
        CheckFingerprintAvailability();
        return fingerprintDeviceStatus;
    }

    fire_and_forget FingerprintNativeProvider::CheckFingerprintAvailabilityAsync()
    {
        try
        {
            auto ucvAvailability = co_await winrt::Windows::Security::Credentials::UI::UserConsentVerifier::CheckAvailabilityAsync();
            this->fingerprintDeviceStatus = helper->UserConsentVerifierAvailabilityToMessage( ucvAvailability );
        }
        catch(const std::exception& e)
        {
            fingerprintDeviceStatus = e.what();
        }
    }

    std::string FingerprintNativeProvider::CheckFingerprintAvailability()
    {
        try
        {
            auto ucvAvailability = winrt::Windows::Security::Credentials::UI::UserConsentVerifier::CheckAvailabilityAsync().get();
            this->fingerprintDeviceStatus = helper->UserConsentVerifierAvailabilityToMessage( ucvAvailability );
        }
        catch( const std::exception& e )
        {
            fingerprintDeviceStatus = e.what();
        }

        return fingerprintDeviceStatus;
    }
}
