import * as React from 'react';
import {
  ScrollView,
  View,
  Text,
  Button,
  StyleSheet,
  NativeModules,
  Alert,
} from 'react-native';

function FingerprintExample({navigation}) {
  return (
    <ScrollView>
      <View style={styles.navigationButtonsPanel}>
        <Button title="Home" onPress={() => navigation.navigate('Home')} />
        <Button
          title="Face Recognition"
          onPress={() => navigation.navigate('FaceRecognitionExample')}
        />
      </View>
      <View style={styles.exampleContent}>
        <Text>Fingerprint Example</Text>
        <Button
          title={'Check availability'}
          onPress={() => {
            NativeModules.FingerprintNativeModule.checkAvailability()
              .then(result => {
                Alert.alert(`SUCCESS!`, `${result}`);
                return result;
              })
              .catch(error => {
                Alert.alert(`ERROR!`, `${error.message}`);
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
  },
});

export default FingerprintExample;
