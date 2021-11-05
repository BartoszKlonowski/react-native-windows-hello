import SignInModule from "./source/SignInModule";
import {
  userConsentVerificationResult,
  userConsentVerifierAvailability,
} from "./source/Statuses";

const verificationResult = userConsentVerificationResult;
const availabilityStatus = userConsentVerifierAvailability;
export { verificationResult, availabilityStatus };
export const SignIn = SignInModule;
