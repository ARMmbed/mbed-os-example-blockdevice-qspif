/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// QSPI SFDP Flash - Block Device example
#include "mbed.h"
#include "QSPIFBlockDevice.h"

QSPIFBlockDevice block_device(QSPI_FLASH1_IO0, QSPI_FLASH1_IO1, QSPI_FLASH1_IO2, QSPI_FLASH1_IO3,
                              QSPI_FLASH1_SCK, QSPI_FLASH1_CSN, QSPIF_POLARITY_MODE_0, MBED_CONF_QSPIF_QSPI_FREQ);

int main()
{
    printf("QSPI SFDP Flash Block Device example\n");

    // Initialize the SPI flash device and print the memory layout
    block_device.init();
    bd_size_t sector_size_at_address_0 = block_device.get_erase_size(0);

    printf("QSPIF BD size: %llu\n",         block_device.size());
    printf("QSPIF BD read size: %llu\n",    block_device.get_read_size());
    printf("QSPIF BD program size: %llu\n", block_device.get_program_size());

    printf("QSPIF BD erase size (at address 0): %llu\n", sector_size_at_address_0);

    // Write "Hello World!" to the first block
    char *buffer = (char *) malloc(sector_size_at_address_0);
    sprintf(buffer, "Hello World!\n");
    block_device.erase(0, sector_size_at_address_0);
    block_device.program(buffer, 0, sector_size_at_address_0);

    // Read back what was stored
    block_device.read(buffer, 0, sector_size_at_address_0);
    printf("%s", buffer);

    // Deinitialize the device
    block_device.deinit();
}
