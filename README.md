
# STM32F103C8-Drivers

[![Status](https://camo.githubusercontent.com/52dc5b531aa6cee975068174b406b2b0b08f86be6e455386c8683db38d3601ec/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f7374617475732d6163746976652d737563636573732e737667)](https://github.com/mhmoudramadan/STM32F756ZG_Bootloader/blob/master)[![GitHub Issues](https://camo.githubusercontent.com/9a6266d1986b6043009223290255410e8d577c9fcea8d6049508825f9c08dd3d/68747470733a2f2f696d672e736869656c64732e696f2f6769746875622f6973737565732f6b796c656c6f626f2f5468652d446f63756d656e746174696f6e2d436f6d70656e6469756d2e737667)](https://github.com/kylelobo/The-Documentation-Compendium/issues)[![GitHub Pull Requests](https://camo.githubusercontent.com/44af8fbca480e9a96fa7f45c477860985aa7ff82ed96d7a0fa533a7d3cd01fda/68747470733a2f2f696d672e736869656c64732e696f2f6769746875622f6973737565732d70722f6b796c656c6f626f2f5468652d446f63756d656e746174696f6e2d436f6d70656e6469756d2e737667)](https://github.com/kylelobo/The-Documentation-Compendium/pulls)[![License](https://camo.githubusercontent.com/2bb6ac78e5a9f4f688a6a066cc71b62012101802fcdb478e6e4c6b6ec75dc694/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f6c6963656e73652d4d49542d626c75652e737667)](https://github.com/mhmoudramadan/STM32F756ZG_Bootloader/blob/master/LICENSE.md)

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Repository Structure](#repository-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Configuration](#configuration)
- [Contributing](#contributing)
- [License](#license)

## Overview

This project contains drivers for the STM32F103C8 microcontroller, which is based on the ARM Cortex-M3 core. The drivers provide low-level hardware control and abstractions for developing embedded applications.

## Features

- **Hardware Abstraction Layer (HAL)**: Simplifies hardware interactions.
- **Microcontroller Abstraction Layer (MCAL)**: Provides low-level driver functions.
- **Modular Design**: Easy integration with various STM32F103C8 applications.

## Repository Structure

- **HAL/**: Hardware Abstraction Layer for interfacing with hardware components.
- **MCAL/**: Microcontroller Abstraction Layer for low-level hardware control.
- **main.c**: Main application file.

## Getting Started

### Prerequisites

- STM32F103C8 development board.
- STM32CubeIDE or compatible development environment.
- Basic knowledge of embedded systems and microcontroller programming.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/mhmoudramadan/STM32F103C8-Drivers.git
   ```


2. Open the project in STM32CubeIDE.
3. Build and flash the project to your STM32F103C8 board.

## Configuration

Modify configuration parameters in the respective driver files to adjust settings as needed.

## Contributing

Contributions to the bootloader project are welcome! Feel free to submit bug reports, feature requests, or pull requests to improve the bootloader's functionality.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
