/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */

import React from 'react';
import type {Node} from 'react';
import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  useColorScheme,
  View,
  Button,
  Linking,
} from 'react-native';

import {Colors} from 'react-native/Libraries/NewAppScreen';

import {NavigationContainer} from '@react-navigation/native';
import {createStackNavigator} from '@react-navigation/stack';

import FaceRecognitionExample from './screens/FaceRecognitionExample';
import FingerprintExample from './screens/FingerprintExample';

const Stack = createStackNavigator();

const HomeScreen: () => Node = ({navigation}) => {
  const isDarkMode = useColorScheme() === 'dark';

  const backgroundStyle = {
    backgroundColor: isDarkMode ? Colors.darker : Colors.lighter,
  };

  return (
    <SafeAreaView style={backgroundStyle}>
      <StatusBar barStyle={isDarkMode ? 'light-content' : 'dark-content'} />
      <ScrollView
        contentInsetAdjustmentBehavior="automatic"
        style={backgroundStyle}>
        <View style={styles.navigationButtonsPanel}>
          <Button
            title="Fingerprint"
            onPress={() => navigation.navigate('FingerprintExample')}
          />
          <Button
            title="Face Recognition"
            onPress={() => navigation.navigate('FaceRecognitionExample')}
          />
        </View>
        <View style={styles.informationPanel}>
          <Text>This application is an example of</Text>
          <Text
            style={styles.helloLinkText}
            onPress={() =>
              Linking.openURL(
                'https://support.microsoft.com/en-us/windows/sign-in-to-your-microsoft-account-with-windows-hello-or-a-security-key-800a8c01-6b61-49f5-0660-c2159bea4d84',
              )
            }>
            {' '}
            Windows Hello
          </Text>
          <Text> features in a React Native Windows app</Text>
        </View>
      </ScrollView>
    </SafeAreaView>
  );
};

const App: () => Node = () => {
  return (
    <NavigationContainer>
      <Stack.Navigator>
        <Stack.Screen name="Home" component={HomeScreen} />
        <Stack.Screen
          name="FaceRecognitionExample"
          component={FaceRecognitionExample}
        />
        <Stack.Screen
          name="FingerprintExample"
          component={FingerprintExample}
        />
      </Stack.Navigator>
    </NavigationContainer>
  );
};

const styles = StyleSheet.create({
  navigationButtonsPanel: {
    flex: 1,
    justifyContent: 'space-around',
    flexDirection: 'row',
  },
  helloLinkText: {
    color: 'blue',
  },
  informationPanel: {
    margin: 20,
    flexDirection: 'row',
  },
});

export default App;
