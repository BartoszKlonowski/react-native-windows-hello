#pragma once

#include <string>

namespace winrt::ReactNativeWindowsHello::Fingerprint
{
    class WinRtHelper
    {
    public:
        std::string UserConsentVerifierAvailabilityToMessage( const winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability& availability );
        std::string UserConsentVerificationResultToMessage( const winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult& verificationResult );
    };
}
