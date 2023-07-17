# TinyCI
- [TinyCI](#tinyci)
  * [Project Idea](#project-idea)
  * [Brief Infrastructure](#brief-infrastructure)
  * [Project Layout](#project-layout)


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

- The manufacter just need to specify IoT device capabilities as described in [TinyCI-Dashboard](https://github.com/NatFederico/TinyCI-Dashboard) and support the communication from the Edge Device to the TiniCI-HUB as described in [Tiny-CI-PCService - NOLINK]().

- On the other hand, the end user just needs to put the third-party edge device into pairing mode (as described by the manufacturer), plug the TinyCI-HUB into power, and set it to discovery mode (from TinyCI-Dashboard) and let the TinyCI-HUB do the hard work. After that, the user can interact from the TinyCI-Dashboard with the newly registered device (e.g., getting sensors, setting modes...).

