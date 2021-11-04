export const userConsentVerificationResult = Object.freeze({
  Verified: Object.freeze({
    value: 0,
    message: "User consent verified.",
  }),
  DeviceNotPresent: Object.freeze({
    value: 1,
    message: "There is no biometric verifier device available.",
  }),
  NotConfiguredForUser: Object.freeze({
    value: 2,
    message: "A biometric verifier device is not configured for this user.",
  }),
  DisabledByPolicy: Object.freeze({
    value: 3,
    message: "Group policy has disabled the biometric verifier device.",
  }),
  DeviceBusy: Object.freeze({
    value: 4,
    message:
      "The biometric verifier device is performing an operation and is unavailable.",
  }),
  RetriesExhausted: Object.freeze({
    value: 5,
    message:
      "After 10 attempts, the original verification request and all subsequent attempts at the same verification were not verified.",
  }),
  Canceled: Object.freeze({
    value: 6,
    message: "The verification operation was canceled.",
  }),
});

export const userConsentVerifierAvailability = Object.freeze({
  Available: Object.freeze({
    value: 0,
    message: "A biometric verifier device is available.",
  }),
  DeviceNotPresent: Object.freeze({
    value: 1,
    message: "There is no biometric verifier device available.",
  }),
  NotConfiguredForUser: Object.freeze({
    value: 2,
    message: "A biometric verifier device is not configured for this user.",
  }),
  DisabledByPolicy: Object.freeze({
    value: 3,
    message: "Group policy has disabled the biometric verifier device.",
  }),
  DeviceBusy: Object.freeze({
    value: 4,
    message:
      "The biometric verifier device is performing an operation and is unavailable.",
  }),
});

export function getEnumByNativeValue(statusObject, nativeValue) {
  for (const [key, value] of Object.entries(statusObject)) {
    if (value.value === nativeValue) {
      return statusObject[key];
    }
  }
}
