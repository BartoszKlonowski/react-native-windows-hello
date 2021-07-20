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

        REACT_METHOD( CheckAvailability );
        void CheckAvailability( React::ReactPromise<React::JSValue>&& result ) noexcept
        {
            result.Resolve( provider.CheckFingerprintAvailability() );
        }

    private:
        Microsoft::ReactNative::ReactContext reactContext{ nullptr };

        FingerprintNativeProvider provider;
    };
}
