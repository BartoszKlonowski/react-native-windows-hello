import * as React from 'react';
import {
  StyleSheet,
  ScrollView,
  View,
  Text,
  Button,
  Linking,
} from 'react-native';

function FaceRecognitionExample({navigation}) {
  return (
    <ScrollView>
      <View style={styles.navigationButtonsPanel}>
        <Button title="Home" onPress={() => navigation.navigate('Home')} />
        <Button
          title="Biometrics"
          onPress={() => navigation.navigate('BiometricsExample')}
        />
      </View>
      <View style={styles.exampleContent}>
        <Text>Microsoft Passport Example</Text>
        <Text>This feature will be available in further releases - see:</Text>
        <Text
          style={styles.linkText}
          onPress={() =>
            Linking.openURL(
              'https://github.com/callstack/react-native-windows-hello/issues/5',
            )
          }>
          {' '}
          Issue #5 - Support Microsoft Passport functionality
        </Text>
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
    height: 200,
  },
  linkText: {
    color: 'blue',
  },
});

export default FaceRecognitionExample;
