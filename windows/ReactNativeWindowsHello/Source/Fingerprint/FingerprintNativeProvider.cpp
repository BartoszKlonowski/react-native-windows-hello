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
        const winrt::hstring scanPromptMessage = L"Please confirm your identity by fingerprint scan...";
        auto&& consentResult = winrt::Windows::Security::Credentials::UI::UserConsentVerifier::RequestVerificationAsync( scanPromptMessage ).get();
        fingerprintScanStatus = helper->UserConsentVerificationResultToMessage( consentResult );

        return fingerprintScanStatus;
    }

    fire_and_forget FingerprintNativeProvider::CheckUserVerificationAsync()
    {
        const winrt::hstring scanPromptMessage = L"Please confirm your identity by fingerprint scan...";
        auto&& consentResult = co_await winrt::Windows::Security::Credentials::UI::UserConsentVerifier::RequestVerificationAsync( scanPromptMessage );
        fingerprintScanStatus = helper->UserConsentVerificationResultToMessage( consentResult );
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
