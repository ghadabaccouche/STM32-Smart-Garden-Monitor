# STM32 Smart Garden Monitoring System

A robust, low-power embedded system built around an STM32 microcontroller for monitoring plant health and environmental conditions. This project demonstrates firmware development best practices, sensor integration, power management, and communication protocols relevant to embedded systems in critical applications.

![System Block Diagram](Images/system_block_diagram.png)
*Example: You can create this in draw.io or similar tool*

## 📋 Table of Contents
- [Project Overview](#project-overview)
- [Key Features](#key-features)
- [Hardware Requirements](#hardware-requirements)
- [Software Architecture](#software-architecture)
- [Repository Structure](#repository-structure)
- [Setup & Installation](#setup--installation)
- [Usage](#usage)
- [Testing](#testing)
- [Data Flow & Communication](#data-flow--communication)
- [Future Enhancements](#future-enhancements)

## 🎯 Project Overview

This project implements an automated plant monitoring system that collects sensor data (soil moisture, ambient temperature, light intensity) and transmits it via Bluetooth Low Energy (BLE) to a mobile application. The system is designed with low-power operation as a primary concern, utilizing the STM32's sleep modes to extend battery life.

**Key Demonstrations:**
- STM32 HAL Driver Usage & Configuration
- Low-Power Management Strategies
- Multi-Sensor Integration (I2C, SPI, ADC)
- BLE Communication Protocol
- Robust Firmware Architecture
- Unit Testing with Ceedling

## ✨ Key Features

- **Real-time Sensor Monitoring:** Tracks soil moisture, temperature, and light levels.
- **Low-Power Operation:** Implements STOP mode 2 (LP-Modes), reducing power consumption by ~42% compared to active polling.
- **BLE Connectivity:** Advertises sensor data via custom GATT service for mobile app integration.
- **Configurable Parameters:** User-defined thresholds for alerts and sampling rates.
- **Robust Error Handling:** Watchdog timer implementation and sensor communication fault recovery.

## 🔧 Hardware Requirements

| Component | Model | Interface |
|-----------|-------|-----------|
| MCU | STM32L476RG (Nucleo-L476RG) | - |
| Soil Moisture Sensor | Capacitive V1.2 | Analog (ADC) |
| Temperature & Humidity | SHTC3 | I2C |
| Ambient Light Sensor | VEML7700 | I2C |
| BLE Module | STM32 Integrated BLE | UART/USART |

*See `Hardware/` directory for schematics and connection details.*

## 🏗️ Software Architecture
