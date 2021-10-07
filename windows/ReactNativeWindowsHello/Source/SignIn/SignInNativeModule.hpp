#pragma once

#include "NativeModules.h"
#include "SignInNativeProvider.hpp"

namespace winrt::ReactNativeWindowsHello::SignIn
{
    REACT_MODULE( SignInNativeModule, L"SignIn" );
    struct SignInNativeModule
    {
        REACT_INIT( Initialize );
        void Initialize( const Microsoft::ReactNative::ReactContext& reactContext ) noexcept
        {
            this->reactContext = reactContext;
        }

        REACT_METHOD( CheckAvailability, L"checkAvailability" );
        void CheckAvailability( React::ReactPromise<React::JSValue>&& result ) noexcept
        {
            provider.CheckSignInAvailability();
            result.Resolve( React::JSValue( provider.SignInDeviceStatus() ) );
        }

        REACT_METHOD( RequestScan, L"requestScan" );
        void RequestScan( React::ReactPromise<React::JSValue>&& result ) noexcept
        {
            provider.CheckUserVerification();
            result.Resolve( React::JSValue( provider.SignInScanStatus() ) );
        }

        REACT_METHOD( CheckAvailabilityAsync, L"checkAvailabilityAsync" );
        void CheckAvailabilityAsync( React::ReactPromise<React::JSValue>&& result ) noexcept
        {
            provider.CheckSignInAvailabilityAsync();
            result.Resolve( React::JSValue( provider.SignInDeviceStatus() ) );
        }

        REACT_METHOD( RequestScanAsync, L"requestScanAsync" );
        void RequestScanAsync( React::ReactPromise<React::JSValue>&& result ) noexcept
        {
            provider.CheckUserVerificationAsync();
            result.Resolve( React::JSValue( provider.SignInScanStatus() ) );
        }

    private:
        Microsoft::ReactNative::ReactContext reactContext{ nullptr };

        SignInNativeProvider provider;
    };
}
