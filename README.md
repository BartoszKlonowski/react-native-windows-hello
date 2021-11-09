<p align="center">
  <img src=".github/Resources/Logo-README.png"/>
</p>
<p align="center">
    React Native Windows library providing developers with all Windows Hello features.
</p>
<p align="center">
    <a href="https://www.npmjs.com/package/react-native-windows-hello">
        <img src="https://img.shields.io/npm/v/react-native-windows-hello.svg" alt="Latest version released on npmjs" />
    </a>
    <a href="https://app.circleci.com/pipelines/github/callstack-internal/react-native-windows-hello?branch=main">
        <img src="https://circleci.com/gh/callstack/react-native-windows-hello/tree/main.svg?style=shield" alt="Build on CircleCI" />
    </a>
    <a href="https://github.com/callstack-internal/react-native-windows-hello/blob/main/LICENSE.md">
        <img src="https://img.shields.io/npm/l/react-native-windows-hello.svg" alt="License" />
    </a>
</p>


<p align="center">
    The following library allows you to use all features of <a href="https://support.microsoft.com/en-us/windows/sign-in-to-your-microsoft-account-with-windows-hello-or-a-security-key-800a8c01-6b61-49f5-0660-c2159bea4d84#WindowsVersion=Windows_10">Windows Hello</a> functionality. This includes the signing-in options and passport.
    This library is a set of native methods providing easy API to fetch the device availability, sign in using your biometrics.
    <img src=".github/Resources/RNW-Hello-FullExample.gif"/>
</p>

---

## Installation & Usage

To install this module `cd` to your project directory and enter the following command:

```console
yarn add -D react-native-windows-hello
```
or
```console
npm install react-native-windows-hello --save
```

After having it installed you can import all the Windows Hello features like so:

```javascript
import { SignIn, verificationResult, availabilityStatus } from 'react-native-windows-hello';
```

The [API](#API) contains two methods: `requestConsentVerification` and `getDeviceStatus` each returning a promise with result object containing both `value` and `message` with pre-defined text (in english) describing the returned result.
<br/>So the example of usage would be:

```javascript
SignIn.requestConsentVerification("This customized message will be displayed in biometric prompt")
  .then(result => {
    Alert.alert(
      `${result === verificationResult.Verified ? "SUCCESS" : "ERROR"}`,
      result.message
    );
  })
  .catch(error => {
    Alert.alert("ERROR:", `${error}`);
  });
```

Check out the [example project](example) for more examples.

---

## API

The following library provides you with the native modules exposing the following methods:

| **Method** & Description | Arguments | Returns |
| - | :-: |:-:|
| **SignIn.getDeviceStatus** | | |
| Gets the status of biometric device on a user's machine and returns a promise with the result.<br/>The returned promise is resolved with a status, and is rejected in case of any internal issues/errors. | - | `Promise`<br/>with<br/>[`availabilityStatus`](#availabilityStatus) |
| **SignIn.requestConsentVerification** | | |
| Displays the biometric scan prompt as a popup and returns a promise after user's actions.<br/>The returned promise is resolved no matter if the verification was successful or not, and is rejected in case of any internal failure/error or when incorrect `promptMessage` has been passed as an argument.| `promptMessage : String`<br/>Additional text which will be placed in the login prompt popup.<br/> | `Promise`<br/>with<br/>[`verificationResult`](#verificationResult) |

---

### Status result object

Each method returns one of the enumerated objects representing the result of called action (`getDeviceStatus`, `requestConsentVerification`).
Each of these objects contain two properties:
* `value` - contains numerical value matching the official values. This can be used by developers for internal implementation keeping the last result for simplicity.
* `message` - official text (in english) saying exactly what the result is. This can be used to directly display the status without conversions.

There are two groups of result objects:

#### [`availabilityStatus`](https://docs.microsoft.com/en-us/uwp/api/windows.security.credentials.ui.userconsentverifieravailability?view=winrt-22000)
| Result | `value` | `message` |
|-|-|-|
| Available | 0 | "A biometric verifier device is available." |
| DeviceNotPresent | 1 | "There is no biometric verifier device available." |
| NotConfiguredForUser | 2 | "A biometric verifier device is not configured for this user." |
| DisabledByPolicy | 3 | "Group policy has disabled the biometric verifier device." |
| DeviceBusy | 4 | "The biometric verifier device is performing an operation and is unavailable." |

and

#### [`verificationResult`](https://docs.microsoft.com/en-us/uwp/api/windows.security.credentials.ui.userconsentverificationresult?view=winrt-22000)
| Result | `value` | `message` |
|-|-|-|
| Verified | 0 | "User consent verified" |
| DeviceNotPresent | 1 | "There is no biometric verifier device available." |
| NotConfiguredForUser | 2 | "A biometric verifier device is not configured for this user." |
| DisabledByPolicy | 3 | "Group policy has disabled the biometric verifier device." |
| DeviceBusy | 4 | "The biometric verifier device is performing an operation and is unavailable." |
| RetriesExhausted | 5 | "After 10 attempts, the original verification request and all subsequent attempts at the same verification were not verified." |
| Canceled | 6 | "The verification operation was canceled." |

---

## Contributing

If you would like to contribute to the *react-native-windows-hello* project, you are more than welcome!
You can do this by:
* Create an [Issue](https://github.com/callstack/react-native-windows-hello/issues/new) and let the author handle it
<br/>Each issue created in the [Issues section](https://github.com/callstack/react-native-windows-hello/issues) gives a chance of improving the project and make it even more useful.
* Create the [Pull Request](https://github.com/callstack/react-native-windows-hello/compare) with the desired changes
<br/>When creating the pull request please remember to describe changes you made and how to test them. A short demo of any kind is very appreciated.

### Setting up the project

To start developing you need to fork this project, and clone your fork.
<br/>After that you can:
* `yarn install`
* Implement changes (mostly in *windows/ReactNativeWindowsHello/Source* directory)
* After implementation you can check the build by running:
<br/>`msbuild -p:Configuration=Debug -p:Platform=x64 .\windows\ReactNativeWindowsHello.sln`
<br/>Or launch the build through the Visual Studio.

---

## Made with ❤️ at Callstack

`react-native-windows-hello` is an open source project and will always remain free to use. If you think it's cool, please star it 🌟. [Callstack](https://callstack.com/) is a group of React and React Native geeks, contact us at [hello@callstack.com](mailto:hello@callstack.com) if you need any help with these or just want to say hi!

Like the project? ⚛️ [Join the team](https://callstack.com/careers) who does amazing stuff for clients and drives React Native Open Source! 🔥
