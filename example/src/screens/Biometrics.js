import React from 'react';
import {ScrollView, View, Text, Button, StyleSheet, Alert, TextInput} from 'react-native';
import {availabilityStatus, SignIn, verificationResult} from 'react-native-windows-hello';

function BiometricsExample({navigation}) {
  const [customPromptMessage, setCustomPromptMessage] = React.useState(null);
  return (
    <ScrollView>
      <View style={styles.navigationButtonsPanel}>
        <Button
          title="Home"
          onPress={() => navigation.navigate('Home')}
        />
        <Button
          title="Passport"
          onPress={() => navigation.navigate('PassportExample')}
        />
      </View>

      <View style={styles.exampleContent}>
        <Text>Biometrics Example</Text>
        <Button
          title={"Check biometric device availability"}
          onPress={() => {
            SignIn.getDeviceStatus()
              .then(result => {
                if (result === availabilityStatus.Available) {
                  Alert.alert("Biometric device AVAILABLE", result.message);
                } else {
                  Alert.alert(`Biometric device status: ${result.value}`, result.message);
                }
              })
              .catch(error => {
                Alert.alert(error.message);
              });
        }}/>

        <View style={styles.customPromptMessageButtonForm}>
          <TextInput
            style={styles.customMessageInput}
            value={customPromptMessage}
            editable={true}
            placeholder='Enter your customize prompt message...'
            onChangeText={setCustomPromptMessage}
          />
          <Button
            title={"Check user consent verification with custom message"}
            onPress={() => {
              SignIn.requestConsentVerification(customPromptMessage)
                .then(result => {
                  if (result === verificationResult.Verified) {
                    Alert.alert("User verified SUCCESSFULLY", result.message);
                  } else {
                    Alert.alert(`User verification failed: ${result.value}`, result.message);
                  }
                })
                .catch(error => {
                  Alert.alert(error);
                });
            }}
          />
        </View>

        <Button
          title={"Check user consent verification with default message"}
          onPress={() => {
            SignIn.requestConsentVerification()
              .then(result => {
                if (result === verificationResult.Verified) {
                  Alert.alert("User verified SUCCESSFULLY", result.message);
                } else {
                  Alert.alert(`User verification failed: ${result.value}`, result.message);
                }
              })
              .catch(error => {
                Alert.alert(error);
              });
          }}
        />

      </View>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  navigationButtonsPanel: {
    flex: 1,
    justifyContent: 'space-around',
    flexDirection: 'row',
  },
  exampleContent: {
    flex: 1,
    flexDirection: 'column',
    justifyContent: 'space-around',
    alignItems: 'center',
    height: 400,
  },
  customPromptMessageButtonForm: {
    flex: 1,
    flexDirection: 'row',
    maxHeight: 40,
  },
  customMessageInput: {
    width: "30%",
  }
});

export default BiometricsExample;
