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
        return fingerprintDeviceStatus;
    }

    std::string FingerprintNativeProvider::FingerprintScanStatus()
    {
        return fingerprintScanStatus;
    }

    std::string FingerprintNativeProvider::CheckUserVerification()
    {
        winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult consentResult = winrt::Windows::Security::Credentials::UI::UserConsentVerifier::RequestVerificationAsync( L"Please confirm your identity by fingerprint scan..." ).get();

        switch(consentResult)
        {
            case winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult::Verified:
                fingerprintScanStatus = "UserVerified";
                break;

            case winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult::DeviceNotPresent:
                fingerprintScanStatus = "Device not present";
                break;

            case winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult::Canceled:
                fingerprintScanStatus = "Verification was canceled";
                break;

            default:
                fingerprintScanStatus = "Unrecognized status";
                break;
        }

        return fingerprintScanStatus;
    }

    fire_and_forget FingerprintNativeProvider::CheckFingerprintAvailabilityAsync()
    {
        try
        {
            auto ucvAvailability = co_await winrt::Windows::Security::Credentials::UI::UserConsentVerifier::CheckAvailabilityAsync();
            this->fingerprintDeviceStatus = helper->UserConsentVerifierAvailabilityToMessage( ucvAvailability );
        }
        catch( const std::exception& e )
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
