#include "pch.h"
#include "WinRTHelper.hpp"

namespace winrt::ReactNativeWindowsHello::Fingerprint
{
    std::string WinRtHelper::UserConsentVerifierAvailabilityToMessage( const Windows::Security::Credentials::UI::UserConsentVerifierAvailability& availability )
    {
        switch( availability )
        {
            case Windows::Security::Credentials::UI::UserConsentVerifierAvailability::Available:
                return "Fingerprint verification is available.";
                break;
            case Windows::Security::Credentials::UI::UserConsentVerifierAvailability::DeviceBusy:
                return "Biometric device is busy.";
                break;
            case Windows::Security::Credentials::UI::UserConsentVerifierAvailability::DeviceNotPresent:
                return "No biometric device found.";
                break;
            case Windows::Security::Credentials::UI::UserConsentVerifierAvailability::DisabledByPolicy:
                return "Biometric verification is disabled by policy.";
                break;
            case Windows::Security::Credentials::UI::UserConsentVerifierAvailability::NotConfiguredForUser:
                return "The user has no fingerprints registered. Please add a fingerprint to the fingerprint database and try again.";
                break;
            default:
                return "Fingerprints verification is currently unavailable.";
                break;
        }
    }
}
