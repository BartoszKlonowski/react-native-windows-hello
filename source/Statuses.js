export const userConsentVerificationResult = Object.freeze({
  Verified: Object.freeze({
    value: 0,
    message: "User consent verified.",
  }),
  DeviceNotPresent: Object.freeze({
    value: 1,
    message: "No biometric device found.",
  }),
  NotConfiguredForUser: Object.freeze({
    value: 2,
    message:
      "No biometric data registered - please add a biometric configuration and try again.",
  }),
  DisabledByPolicy: Object.freeze({
    value: 3,
    message: "Biometric verification is disabled by policy.",
  }),
  DeviceBusy: Object.freeze({
    value: 4,
    message: "Biometric device is busy.",
  }),
  RetriesExhausted: Object.freeze({
    value: 5,
    message:
      "There has been too many failed attempts - Biometric authentication canceled.",
  }),
  Canceled: Object.freeze({
    value: 6,
    message: "Biometric authentication canceled.",
  }),
});

export const userConsentVerifierAvailability = Object.freeze({
  Available: Object.freeze({
    value: 0,
    message: "Biometric device available.",
  }),
  DeviceNotPresent: Object.freeze({
    value: 1,
    message: "No biometric device found.",
  }),
  NotConfiguredForUser: Object.freeze({
    value: 2,
    message:
      "No biometric device configured - please add a biometric configuration and try again.",
  }),
  DisabledByPolicy: Object.freeze({
    value: 3,
    message: "Biometric device is disabled by policy.",
  }),
  DeviceBusy: Object.freeze({
    value: 4,
    message: "Biometric device is busy.",
  }),
});

export function getEnumByNativeValue(statusObject, nativeValue) {
  for (const [key, value] of Object.entries(statusObject)) {
    if (value.value === nativeValue) {
      return statusObject[key];
    }
  }
}
