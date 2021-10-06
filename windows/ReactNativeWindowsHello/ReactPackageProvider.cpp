#include "pch.h"
#include "ReactPackageProvider.h"
#if __has_include("ReactPackageProvider.g.cpp")
#include "ReactPackageProvider.g.cpp"
#endif

#include "Source/ReactNativeWindowsHelloModule.hpp"
#include "Source/SignIn/SignInNativeModule.hpp"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::ReactNativeWindowsHello::implementation
{
    void ReactPackageProvider::CreatePackage( IReactPackageBuilder const& packageBuilder ) noexcept
    {
        AddAttributedModules( packageBuilder );
    }
}
