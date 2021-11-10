import { NativeModules } from "react-native";
import {
  getEnumByNativeValue,
  userConsentVerificationResult,
  userConsentVerifierAvailability,
} from "./Statuses";

export class SignInModule {
  static requestConsentVerification(promptMessage = "") {
    return new Promise((resolve, reject) => {
      if (typeof promptMessage === "string") {
        NativeModules.SignIn.requestScanPromise(promptMessage)
          .then((result) => {
            const resultObject = getEnumByNativeValue(
              userConsentVerificationResult,
              result
            );
            resolve(resultObject);
            return resultObject;
          })
          .catch((error) => {
            reject(error);
          });
      } else {
        reject("ERROR: promptMessage should be a valid string");
      }
    });
  }

  static getDeviceStatus() {
    return new Promise((resolve, reject) => {
      NativeModules.SignIn.checkAvailabilityPromise()
        .then((result) => {
          const resultObject = getEnumByNativeValue(
            userConsentVerifierAvailability,
            result
          );
          resolve(resultObject);
          return resultObject;
        })
        .catch((error) => {
          reject(error);
        });
    });
  }
}

export default SignInModule;
