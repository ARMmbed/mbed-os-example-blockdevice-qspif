# Deprecation note

**This repository has been deprecated and is no longer maintained.**


## Getting Started With The mbed-os Example for the QSPI Flash Block Device

This is the mbed-os example for the QSPIFBlockDevice driver.
See the [qspif-blockdevice](https://github.com/ARMmbed/qspif-blockdevice) repository for more information.

This guide outlines the steps to get a QSPI NOR SFDP flash device working on an mbed OS platform.

Please install [mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).

## Hardware Requirements

This example can be used on an mbed-os platform with a QSPI NOR flash device connected to the QSPI pins.

This document uses DISCO_L476VG board as an example. Simply change the relevant target option (e.g. -m DISCO_L476VG) to the target matching your own.

## Create the Example Application

From the command-line, import the example:

```
mbed import mbed-os-example-blockdevice-qspif
```

You should see:

	[mbed] Importing program "mbed-os-example-blockdevice-qspif" from "https://github.com/ARMmbed/mbed-os-example-blockdevice-qspif" at latest revision in the current branch
	[mbed] Adding library "mbed-os" from "https://github.com/ARMmbed/mbed-os" at rev #revision

Move into the newly created directory:

```
cd mbed-os-example-blockdevice-qspif
```

If the mbed-os library was not automatically added (see trace above), do the following to import mbed-os:

```
mbed new .
```


## Build the Example

Invoke `mbed compile`, and specify the name of your platform and your favorite toolchain (`GCC_ARM`, `ARM`, `IAR`). For example, for the GCC_ARM toolchain:

```
mbed compile -m DISCO_L476VG -t GCC_ARM
```

Your PC may take a few minutes to compile your code. At the end, you see the following result:

	[snip]
	+--------------------------+-------+-------+-------+
	| Module                   | .text | .data |  .bss |
	+--------------------------+-------+-------+-------+
	| Fill                     |   149 |     4 |    21 |
	| misc                     |   208 |    12 |    28 |
	| drivers                  |  1234 |     4 |   144 |
	| features                 |    14 |     4 |     0 |
	| hal                      |  1707 |     4 |    68 |
	| platform                 |  2654 |   256 |   133 |
	| rtos                     |  9495 |   168 |  6073 |
	| QSPIFBlockDevice.o       |  3117 |     0 |    40 |
	| targets                  | 13124 |     8 |   848 |
	| Subtotals                | 54840 |  2256 | 10320 |
	+--------------------------+-------+-------+-------+
	Total Static RAM memory (data + bss): 10704 bytes
	Total Flash memory (text + data): 63246 bytes

	Image: ./BUILD/DISCO_L476VG/GCC_ARM/mbed-os-example-blockdevice-qspif.bin


## <a name="run-the-example-binary-on-the-DISCO_L476VG"></a> Run the Example Binary on the DISCO_L476VG

Copy the binary from `<root_dir>/mbed-os-example-blockdevice-qspif/BUILD/DISCO_L476VG/GCC_ARM/mbed-os-example-blockdevice-qspif.bin` to the DISCO_L476VG:

1. Connect your mbed device to the computer over USB.
1. Copy the binary file to the mbed device.
1. Press the reset button to start the program.
1. Open the UART of the board in your favorite UART viewing program. For example, `screen /dev/ttyACM0`.

After connecting a serial console and resetting the target, the following trace should be seen:

	QSPI SFDP Flash Block Device example
	QSPIF BD size: 16777216
	QSPIF BD read size: 1
	QSPIF BD program size: 1
	QSPIF BD erase size (at address 0): 4096
	Hello World!

# Troubleshooting

1. Make sure `mbed-cli` is working correctly and its version is newer than `1.0.0`.

 ```
 mbed --version
 ```

 If not, update it:

 ```
 pip install mbed-cli --upgrade
 ```
