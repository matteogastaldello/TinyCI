# TinyCI
## Table of contents
- [TinyCI](#tinyci)
  * [Table of contents](#table-of-contents)
  * [Project Idea](#project-idea)
  * [Brief Infrastructure](#brief-infrastructure)
  * [Project Layout](#project-layout)
  * [Main Strenghts](#main-strenghts)
  * [Setting up the infrastructure](#setting-up-the-infrastructure)
- [Links to Other Resources](#links-to-other-resources)
  * [Authors](#authors)
  * [Acknowledgments](#acknowledgments)


## Project Idea

TinyCI is a communication and configuration system designed for IoT devices with plug and play configuration of edge devices.

## Brief Infrastructure

The core of the infrastructure is composed of 2 parts:

- [TinyCI-HUB](https://github.com/matteogastaldello/TinyCI-HUB): middleware hub for IoT that bridges the gap between IoT devices and web platforms (see the repo for details).
- [TinyCI-Dashboard](https://github.com/NatFederico/TinyCI-Dashboard): interface for the user to interact with your Hubs and devices, and a way for our device manufacturer to set configuration files to add capabilities and/or sensors to their devices, giving a better experience to the end user (see the repo for details).
Schema of TinyCI

![Schema of TinyCI](https://github.com/matteogastaldello/TinyCI/assets/95225168/e96f4e1c-6d79-4bef-8e72-c1aec2eb1096)

## Project Layout

Our project allows the device manufacturer of IoT devices to support the communication with TinyCI components, leaving the end user with a "plug and play experience".

- The manufacter just need to specify IoT device capabilities as described in [TinyCI-Dashboard](https://github.com/NatFederico/TinyCI-Dashboard) and support the communication from the Edge Device to the TiniCI-HUB as described in [TinyCI-PCService](https://github.com/matteogastaldello/TinyCI-PCService/).

- On the other hand, the end user just needs to put the third-party edge device into pairing mode (as described by the manufacturer), plug the TinyCI-HUB into power, and set it to discovery mode (from TinyCI-Dashboard) and let the TinyCI-HUB do the hard work. After that, the user can interact from the TinyCI-Dashboard with the newly registered device (e.g., getting sensors, setting modes...).

## Main Strenghts
- Neither the purpose, nor the device matter as long as few communication rules are respected to become part of this IoT communication system. 
- We also want to underline how setting it up and running the whole system is almost plug and play and requires little to no technical knowledge from the user.

## Setting up the infrastructure
To run the project you both need to configure [TinyCI-HUB](https://github.com/matteogastaldello/TinyCI-HUB) and [TinyCI-Dashboard](https://github.com/NatFederico/TinyCI-Dashboard) and an edge device like [MSP432-EdgeDevice](https://github.com/matteogastaldello/msp432-endpoint) or [TinyCI-PCService](https://github.com/matteogastaldello/TinyCI-PCService/).
Please refer to [TinyCI-HUB](https://github.com/matteogastaldello/TinyCI-HUB) and to [TinyCI-Dashboard](https://github.com/NatFederico/TinyCI-Dashboard) for the configuration.

# Links to Other Resources

Repos:
- Main Components
  -  [TinyCI-HUB](https://github.com/matteogastaldello/TinyCI-HUB)
  -  [TinyCI-Dashboard](https://github.com/NatFederico/TinyCI-Dashboard)
- Edge Devices
  - [MSP432-EdgeDevice](https://github.com/matteogastaldello/msp432-endpoint)
  - [TinyCI-PCService](https://github.com/matteogastaldello/TinyCI-PCService/)
 
Presentation: [link to powerpoint](https://docs.google.com/presentation/d/1VxE23nRNRouq7jqaF9O26tV4Py5EXvLFKnfno5ubUJo/edit?usp=sharing)

Video Overview: [link to video](https://youtu.be/wujiSl2Amtc)



## Authors

Matteo Gastaldello

Federico Natali

Matteo Sabella

## Acknowledgments

<a href="https://www.unitn.it/">
  <img src="https://github.com/matteogastaldello/TinyCI/assets/95225168/6a5678f0-87e0-4cea-97ef-6f7c31bf0f95" width="300px">
</a>


