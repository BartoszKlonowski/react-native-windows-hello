import { NativeModules } from "react-native";

export class SignInModule {
  getConsentMessage() {
    return NativeModules.SignIn.requestScanPromise();
  }

  getDeviceStatusMessage() {
    return NativeModules.SignIn.checkAvailabilityPromise();
  }
}

export default SignInModule;
