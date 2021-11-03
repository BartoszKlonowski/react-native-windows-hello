import * as Status from "../source/Statuses";

test("User consent device availability statuses match their enumerated values", () => {
  expect(Status.userConsentVerifierAvailability.Available.value).toBe(0);
  expect(Status.userConsentVerifierAvailability.DeviceBusy.value).toBe(4);
  expect(Status.userConsentVerifierAvailability.DeviceNotPresent.value).toBe(1);
  expect(Status.userConsentVerifierAvailability.DisabledByPolicy.value).toBe(3);
  expect(
    Status.userConsentVerifierAvailability.NotConfiguredForUser.value
  ).toBe(2);
});

test("User consent verification statuses match their enumerated values", () => {
  expect(Status.userConsentVerificationResult.Verified.value).toBe(0);
  expect(Status.userConsentVerificationResult.DeviceNotPresent.value).toBe(1);
  expect(Status.userConsentVerificationResult.NotConfiguredForUser.value).toBe(
    2
  );
  expect(Status.userConsentVerificationResult.DisabledByPolicy.value).toBe(3);
  expect(Status.userConsentVerificationResult.DeviceBusy.value).toBe(4);
  expect(Status.userConsentVerificationResult.RetriesExhausted.value).toBe(5);
  expect(Status.userConsentVerificationResult.Canceled.value).toBe(6);
});

test("getEnumByNativeValue correctly returns enum objects for verifier availability", () => {
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerifierAvailability, 0) ===
      Status.userConsentVerifierAvailability.Available
  ).toBe(true);
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerifierAvailability, 1) ===
      Status.userConsentVerifierAvailability.DeviceNotPresent
  ).toBe(true);
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerifierAvailability, 2) ===
      Status.userConsentVerifierAvailability.NotConfiguredForUser
  ).toBe(true);
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerifierAvailability, 3) ===
      Status.userConsentVerifierAvailability.DisabledByPolicy
  ).toBe(true);
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerifierAvailability, 4) ===
      Status.userConsentVerifierAvailability.DeviceBusy
  ).toBe(true);
});

test("getEnumByNativeValue correctly returns enum objects for verification status", () => {
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerificationResult, 0) ===
      Status.userConsentVerificationResult.Verified
  ).toBe(true);
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerificationResult, 1) ===
      Status.userConsentVerificationResult.DeviceNotPresent
  ).toBe(true);
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerificationResult, 2) ===
      Status.userConsentVerificationResult.NotConfiguredForUser
  ).toBe(true);
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerificationResult, 3) ===
      Status.userConsentVerificationResult.DisabledByPolicy
  ).toBe(true);
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerificationResult, 4) ===
      Status.userConsentVerificationResult.DeviceBusy
  ).toBe(true);
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerificationResult, 5) ===
      Status.userConsentVerificationResult.RetriesExhausted
  ).toBe(true);
  expect(
    Status.getEnumByNativeValue(Status.userConsentVerificationResult, 6) ===
      Status.userConsentVerificationResult.Canceled
  ).toBe(true);
});
