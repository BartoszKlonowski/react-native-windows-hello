import * as React from 'react';
import {ScrollView, View, Text, Button, StyleSheet} from 'react-native';

function BiometricsExample({navigation}) {
  return (
    <ScrollView>
      <View style={styles.navigationButtonsPanel}>
        <Button title="Home" onPress={() => navigation.navigate('Home')} />
        <Button
          title="Passport"
          onPress={() => navigation.navigate('PassportExample')}
        />
      </View>
      <View style={styles.exampleContent}>
        <Text>Biometrics Example</Text>
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

export default BiometricsExample;
