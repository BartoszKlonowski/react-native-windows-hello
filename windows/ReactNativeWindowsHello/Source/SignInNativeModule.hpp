#pragma once

#include "NativeModules.h"
#include "SignIn/SignInNativeProvider.hpp"

namespace winrt::ReactNativeWindowsHello
{
    REACT_MODULE( SignInNativeModule, L"SignIn" );
    struct SignInNativeModule
    {
        REACT_INIT( Initialize );
        void Initialize( const Microsoft::ReactNative::ReactContext& reactContext ) noexcept
        {
            this->reactContext = reactContext;
        }

        REACT_METHOD( GetLastAvailabilityCheckResult, L"getLastAvailabilityCheckResult" );
        void GetLastAvailabilityCheckResult( std::function<void( winrt::hstring )> lastAvailabilityCheckCallback ) noexcept
        {
            lastAvailabilityCheckCallback( winrt::to_hstring( provider.SignInDeviceStatus() ) );
        }

        REACT_METHOD( GetLastScanResult, L"getLastScanResult" );
        void GetLastScanResult( std::function<void( winrt::hstring )> lastBiometricScanResultCallback ) noexcept
        {
            lastBiometricScanResultCallback( winrt::to_hstring( provider.SignInScanStatus() ) );
        }

        REACT_METHOD( CheckAvailabilityPromise, L"checkAvailabilityPromise" );
        void CheckAvailabilityPromise( React::ReactPromise<React::JSValue>&& result ) noexcept
        {
            if( provider.CheckSignInAvailability() == Windows::Security::Credentials::UI::UserConsentVerifierAvailability::Available )
            {
                result.Resolve( React::JSValue( provider.SignInDeviceStatus() ) );
            }
            else
            {
                result.Reject( provider.SignInDeviceStatus().c_str() );
            }
        }

        REACT_METHOD( RequestScanPromise, L"requestScanPromise" );
        void RequestScanPromise( const winrt::hstring& promptMessage, React::ReactPromise<React::JSValue>&& result ) noexcept
        {
            if( provider.CheckUserVerification( promptMessage ) == Windows::Security::Credentials::UI::UserConsentVerificationResult::Verified )
            {
                result.Resolve( React::JSValue( provider.SignInScanStatus() ) );
            }
            else
            {
                result.Reject( provider.SignInScanStatus().c_str() );
            }
        }

        REACT_METHOD( CheckAvailabilityCallback, L"checkAvailabilityCallback" );
        void CheckAvailabilityCallback( std::function<void( winrt::hstring )> biometricDeviceAvailabilityCallback ) noexcept
        {
            provider.CheckSignInAvailability();
            biometricDeviceAvailabilityCallback( winrt::to_hstring( provider.SignInDeviceStatus() ) );
        }

        REACT_METHOD( RequestScanCallback, L"requestScanCallback" );
        void RequestScanCallback( const winrt::hstring& promptMessage, std::function<void( winrt::hstring )> biometricScanCallback ) noexcept
        {
            provider.CheckUserVerification( promptMessage );
            biometricScanCallback( winrt::to_hstring( provider.SignInScanStatus() ) );
        }

        REACT_METHOD( CheckAvailabilityAsync, L"checkAvailabilityAsync" );
        void CheckAvailabilityAsync( std::function<void(void)> biometricDeviceAvailabilityCallback ) noexcept
        {
            provider.CheckSignInAvailabilityAsync();
            biometricDeviceAvailabilityCallback();
        }

        REACT_METHOD( RequestScanAsync, L"requestScanAsync" );
        void RequestScanAsync( std::function<void(void)> biometricScanCallback ) noexcept
        {
            provider.CheckUserVerificationAsync();
            biometricScanCallback();
        }

        REACT_EVENT( OnConsentVerifiedMessage, L"onConsentVerifiedMessage" );
        std::function<void( winrt::hstring )> OnConsentVerifiedMessage;

        REACT_EVENT( OnDeviceStatusCheckedMessage, L"onDeviceAvailabilityCheckedMessage" );
        std::function<void( winrt::hstring )> OnDeviceStatusCheckedMessage;

    private:
        Microsoft::ReactNative::ReactContext reactContext{ nullptr };

        SignIn::SignInNativeProvider provider;
    };
}
