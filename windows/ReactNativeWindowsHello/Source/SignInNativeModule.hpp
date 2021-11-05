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
            try
            {
                const auto availabilityResult = (int)provider.CheckSignInAvailability();
                result.Resolve( React::JSValue( availabilityResult ) );
            }
            catch(const std::exception& e)
            {
                result.Reject( e.what() );
            }
        }

        REACT_METHOD( RequestScanPromise, L"requestScanPromise" );
        void RequestScanPromise( const winrt::hstring& promptMessage, React::ReactPromise<React::JSValue>&& result ) noexcept
        {
            try
            {
                const auto consentVerificationResult = (int)provider.CheckUserVerification( promptMessage );
                result.Resolve( React::JSValue( consentVerificationResult ) );
            }
            catch( const std::exception& e )
            {
                result.Reject( e.what() );
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
        void CheckAvailabilityAsync( std::function<void( void )> biometricDeviceAvailabilityCallback ) noexcept
        {
            provider.CheckSignInAvailabilityAsync();
            biometricDeviceAvailabilityCallback();
        }

        REACT_METHOD( RequestScanAsync, L"requestScanAsync" );
        void RequestScanAsync( std::function<void( void )> biometricScanCallback ) noexcept
        {
            provider.CheckUserVerificationAsync();
            biometricScanCallback();
        }

    private:
        Microsoft::ReactNative::ReactContext reactContext{ nullptr };

        SignIn::SignInNativeProvider provider;
    };
}
