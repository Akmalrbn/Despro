# Smart Gloves for Non-Verbal Patient Communication

![Smart Gloves](https://github.com/Akmalrbn/Smart-Gloves-for-Non-verbal-Patient/blob/main/image.png) 

## Table of Contents
- [Introduction](#introduction)
- [Project Overview](#project-overview)
- [Components Used](#components-used)
- [How It Works](#how-it-works)
- [Setup Instructions](#setup-instructions)
- [Usage](#usage)
- [Future Improvements](#future-improvements)

## Introduction
In the world of healthcare, effective communication is vital, especially for non-verbal patients who struggle to express their needs. Our **Smart Gloves for Non-Verbal Patient Communication** project aims to bridge this communication gap by utilizing innovative technology to translate hand gestures into audible speech, enhancing the interaction between patients and caregivers.

## Project Overview
The Smart Gloves leverage the capabilities of Arduino Nano and Flex sensor to recognize specific hand gestures made by the user. Each gesture corresponds to a pre-defined phrase or sound, which is then played through a speaker. This technology can significantly improve the quality of life for patients who are unable to speak due to conditions like stroke, ALS, or severe disabilities.

## Components Used
- **Arduino Nano**: The brain of the project, responsible for processing input from the sensors and controlling the output.
- **Flex Sensors (x3)**: These sensors detect the bending of the fingers, allowing the gloves to recognize different gestures.
- **DFPlayer Mini**: A compact MP3 player module that plays audio files stored on a microSD card.
- **LCD Display**: Provides visual feedback to the user and caregivers about the current gesture being recognized.
- **Speaker**: Outputs the spoken phrases corresponding to the gestures detected by the gloves.

## How It Works
1. **Gesture Recognition**: The flex sensors measure the degree of bending in each finger. This data is sent to the Arduino Nano for processing.
2. **Mapping Gestures to Phrases**: Each unique combination of finger positions is mapped to specific phrases or sounds stored on the microSD card.
3. **Audio Playback**: When a gesture is recognized, the Arduino triggers the DFPlayer Mini to play the corresponding audio through the speaker.
4. **User  Feedback**: The LCD displays the recognized gesture or phrase, allowing both the user and caregivers to understand the communication effectively.

## Setup Instructions
1. **Hardware Setup**:
   - Connect the flex sensors to the Arduino Nano.
   - Wire the DFPlayer Mini to the Arduino, ensuring the speaker is connected properly.
   - Connect the LCD display to the Arduino for visual feedback.
   
2. **Software Setup**:
   - Install the necessary libraries for the DFPlayer Mini and LCD.
   - Upload the code to the Arduino Nano, ensuring that the audio files are correctly named and stored on the microSD card.

3. **Calibration**:
   - Test the flex sensors and adjust the threshold values in the code to ensure accurate gesture recognition.

## Usage
1. **Wearing the Gloves**: Put on the smart gloves and ensure that the flex sensors are positioned correctly on the fingers.
2. **Turning on the Power Supply**: Turn on the circuit with the switch button on the battery located next to the circuit box.
3. **Making Gestures**: Use simple hand gestures to communicate. For example, a fist may represent "I need help," while an open hand could signify "I want water."
4. **Listening**: The speaker and LCD will announce the corresponding phrase.

## Future Improvements
- **Expanded Vocabulary**: Adding more phrases and sounds for a broader range of communication.
- **Mobile App Integration**: Developing a companion app to allow caregivers to customize phrases and monitor usage.
- **Machine Learning**: Implementing machine learning algorithms to improve gesture recognition accuracy over time.

---

Thank you for your interest in the Smart Gloves for Non-Verbal Patient Communication project! We hope this innovation helps make a difference in the lives of those who need it most. If you have any questions or feedback, please reach out!
