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

Application Layer (app_)
├── app_garden_monitor.c - Main application state machine
├── app_ble_controller.c - BLE communication management
└── app_power_manager.c - Power mode management

Hardware Abstraction Layer (hal_)
├── hal_sensors.c - Unified sensor interface
├── hal_rtc.c - Real-time clock operations
└── hal_ble.c - BLE hardware abstraction

Drivers (drv_)
├── drv_shtc3.c - Temperature/humidity driver
├── drv_veml7700.c - Light sensor driver
└── drv_soil_moisture.c - Soil moisture ADC driver

Utilities (util_)
├── util_fifo.c - Circular buffer implementation
├── util_logger.c - Structured logging
└── util_crc.c - CRC checksum calculations

## 📁 Repository Structure

STM32-Smart-Garden-Monitor/
│
├── Documentation/
│ ├── Software_Design_Document.md
│ ├── Testing_Strategy.md
│ └── Power_Consumption_Analysis.md
│
├── Firmware/
│ ├── Core/
│ │ ├── Inc/ - Header files
│ │ ├── Src/ - Source files
│ │ └── Startup/ - Startup scripts
│ │
│ ├── Drivers/
│ │ ├── STM32L4xx_HAL_Driver/
│ │ └── BSP/ - Board Support Package
│ │
│ ├── Middleware/
│ │ └── BLE/ - BLE stack & profiles
│ │
│ └── Projects/
│ └── NUCLEO-L476RG/
│ ├── EWARM/ - IAR project files
│ ├── MDK-ARM/ - Keil project files
│ └── STM32CubeIDE/ - STM32CubeIDE project
│
├── Hardware/
│ ├── Schematics/ - PCB schematics (KiCad)
│ ├── Datasheets/ - Component datasheets
│ └── Bill_of_Materials.csv - BOM
│
├── Testing/
│ ├── UnitTests/ - Ceedling test framework
│ ├── IntegrationTests/ - System integration tests
│ └── Test_Results/ - Test reports & coverage
│
├── Tools/
│ ├── Scripts/ - Python data analysis scripts
│ └── Config/ - Configuration utilities
│
├── Images/ - System diagrams & photos
├── .github/workflows/ - CI/CD for automated testing
├── LICENSE
└── README.md

