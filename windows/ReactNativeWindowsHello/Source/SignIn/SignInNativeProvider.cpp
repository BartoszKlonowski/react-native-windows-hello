#include "pch.h"
#include "SignInNativeProvider.hpp"

namespace winrt::ReactNativeWindowsHello::SignIn
{
    SignInNativeProvider::SignInNativeProvider()
    {
        helper = std::make_unique<WinRtHelper>();
    }

    std::string SignInNativeProvider::SignInDeviceStatus()
    {
        return signInDeviceStatus;
    }

    std::string SignInNativeProvider::SignInScanStatus()
    {
        return signInScanStatus;
    }

    Windows::Security::Credentials::UI::UserConsentVerificationResult SignInNativeProvider::CheckUserVerification()
    {
        const winrt::hstring scanPromptMessage = L"Please confirm your identity by SignIn scan...";
        auto&& consentResult = winrt::Windows::Security::Credentials::UI::UserConsentVerifier::RequestVerificationAsync( scanPromptMessage ).get();
        signInScanStatus = helper->UserConsentVerificationResultToMessage( consentResult );
        return consentResult;
    }

    fire_and_forget SignInNativeProvider::CheckUserVerificationAsync()
    {
        const winrt::hstring scanPromptMessage = L"Please confirm your identity by SignIn scan...";
        auto&& consentResult = co_await winrt::Windows::Security::Credentials::UI::UserConsentVerifier::RequestVerificationAsync( scanPromptMessage );
        signInScanStatus = helper->UserConsentVerificationResultToMessage( consentResult );
    }

    fire_and_forget SignInNativeProvider::CheckSignInAvailabilityAsync()
    {
        try
        {
            auto ucvAvailability = co_await winrt::Windows::Security::Credentials::UI::UserConsentVerifier::CheckAvailabilityAsync();
            this->signInDeviceStatus = helper->UserConsentVerifierAvailabilityToMessage( ucvAvailability );
        }
        catch( const std::exception& e )
        {
            signInDeviceStatus = e.what();
        }
    }

    Windows::Security::Credentials::UI::UserConsentVerifierAvailability SignInNativeProvider::CheckSignInAvailability()
    {
        auto ucvAvailability = Windows::Security::Credentials::UI::UserConsentVerifierAvailability::NotConfiguredForUser;

        try
        {
            ucvAvailability = winrt::Windows::Security::Credentials::UI::UserConsentVerifier::CheckAvailabilityAsync().get();
            this->signInDeviceStatus = helper->UserConsentVerifierAvailabilityToMessage( ucvAvailability );
        }
        catch( const std::exception& e )
        {
            signInDeviceStatus = e.what();
        }

        return ucvAvailability;
    }
}
