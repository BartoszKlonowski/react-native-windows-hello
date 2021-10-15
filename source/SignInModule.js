import { NativeModules } from "react-native";

export class SignInModule {
  getConsentMessage(promptMessageText) {
    return NativeModules.SignIn.requestScanPromise(promptMessageText);
  }

  getDeviceStatusMessage() {
    return NativeModules.SignIn.checkAvailabilityPromise();
  }
}

export default SignInModule;
