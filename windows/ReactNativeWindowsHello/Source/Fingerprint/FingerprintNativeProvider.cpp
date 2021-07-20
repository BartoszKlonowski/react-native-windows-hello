#include "pch.h"
#include "FingerprintNativeProvider.hpp"

namespace winrt::ReactNativeWindowsHello::Fingerprint
{
    const std::string FingerprintNativeProvider::CheckFingerprintAvailability()
    {
        auto returnMessage = std::string();

        try
        {
            auto ucvAvailability = winrt::Windows::Security::Credentials::UI::UserConsentVerifier::CheckAvailabilityAsync();
            switch( ucvAvailability.GetResults() )
            {
                case Windows::Security::Credentials::UI::UserConsentVerifierAvailability::Available:
                    returnMessage = "Fingerprint verification is available.";
                    break;
                case Windows::Security::Credentials::UI::UserConsentVerifierAvailability::DeviceBusy:
                    returnMessage = "Biometric device is busy.";
                    break;
                case Windows::Security::Credentials::UI::UserConsentVerifierAvailability::DeviceNotPresent:
                    returnMessage = "No biometric device found.";
                    break;
                case Windows::Security::Credentials::UI::UserConsentVerifierAvailability::DisabledByPolicy:
                    returnMessage = "Biometric verification is disabled by policy.";
                    break;
                case Windows::Security::Credentials::UI::UserConsentVerifierAvailability::NotConfiguredForUser:
                    returnMessage = "The user has no fingerprints registered. Please add a fingerprint to the fingerprint database and try again.";
                    break;
                default:
                    returnMessage = "Fingerprints verification is currently unavailable.";
                    break;
            }
        }
        catch(const std::exception& e)
        {
            returnMessage = e.what();
        }

        return returnMessage;
    }
}
