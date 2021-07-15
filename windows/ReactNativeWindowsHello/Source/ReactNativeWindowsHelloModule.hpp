#pragma once

#include "JSValue.h"
#include "NativeModules.h"

namespace winrt::ReactNativeWindowsHello
{
    REACT_MODULE( ReactNativeWindowsHelloModule, L"ReactNativeWindowsHelloModule" );
    struct ReactNativeWindowsHelloModule
    {
        REACT_INIT( Initialize );
        void Initialize( const Microsoft::ReactNative::ReactContext& reactContext ) noexcept
        {
            this->reactContext = reactContext;
        }

    private:
        Microsoft::ReactNative::ReactContext reactContext{ nullptr };
    };
}
