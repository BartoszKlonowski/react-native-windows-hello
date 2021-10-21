import { NativeModules } from "react-native";

export class SignInModule {
  async getConsentMessage(promptMessage) {
    if (typeof promptMessage === "string") {
      return await NativeModules.SignIn.requestScanPromise(promptMessage);
    } else {
      throw "ERROR: promptMessage should be a valid string";
    }
  }

  getDeviceStatusMessage() {
    return NativeModules.SignIn.checkAvailabilityPromise();
  }
}

export default SignInModule;
