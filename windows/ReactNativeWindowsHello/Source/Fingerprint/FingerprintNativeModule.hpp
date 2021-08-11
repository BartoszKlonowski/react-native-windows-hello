#pragma once

#include "NativeModules.h"
#include "FingerprintNativeProvider.hpp"

namespace winrt::ReactNativeWindowsHello::Fingerprint
{
    REACT_MODULE( FingerprintNativeModule, L"FingerprintNativeModule" );
    struct FingerprintNativeModule
    {
        REACT_INIT( Initialize );
        void Initialize( const Microsoft::ReactNative::ReactContext& reactContext ) noexcept
        {
            this->reactContext = reactContext;
        }

        REACT_METHOD( CheckAvailability, L"checkAvailability" );
        void CheckAvailability( React::ReactPromise<React::JSValue>&& result ) noexcept
        {
            provider.CheckFingerprintAvailability();
            result.Resolve( React::JSValue( provider.FingerprintDeviceStatus() ) );
        }

        REACT_METHOD( RequestScan, L"requestScan" );
        void RequestScan( React::ReactPromise<React::JSValue>&& result ) noexcept
        {
            provider.CheckUserVerification();
            result.Resolve( React::JSValue( provider.FingerprintScanStatus() ) );
        }

    private:
        Microsoft::ReactNative::ReactContext reactContext{ nullptr };

        FingerprintNativeProvider provider;
    };
}
