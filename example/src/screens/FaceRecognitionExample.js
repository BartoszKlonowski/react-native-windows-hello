import * as React from 'react';
import {StyleSheet, ScrollView, View, Text, Button} from 'react-native';

function FaceRecognitionExample({navigation}) {
  return (
    <ScrollView>
      <View style={styles.navigationButtonsPanel}>
        <Button title="Home" onPress={() => navigation.navigate('Home')} />
        <Button
          title="Fingerprint"
          onPress={() => navigation.navigate('FingerprintExample')}
        />
      </View>
      <View style={styles.exampleContent}>
        <Text>Face Recognition Example</Text>
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

export default FaceRecognitionExample;
