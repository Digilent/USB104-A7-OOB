# USB104 A7 Out-of-Box Demo

## Description

This repository contains the Out-of-Box demo for the Digilent USB104 A7. This demo is programmed into the board's SPI Flash at time of manufacturing.

Upon the demo starting up, the message "Welcome to the USB104 A7 Out-Of-Box Demo" is printed over UART to a connected serial terminal. The board's LEDs are cycled through, with one illuminated at a time. Pressing a button results in the direction of the LED cycling being set to the direction associated with that button, and the message "Button Press Detected!" is printed.

The UART controller used within the demo requires that the connected serial terminal use a baud rate of 9600, with one start bit and no parity.

## Requirements

* Digilent USB104 A7
* Vivado and Vitis 2020.1 Installations: To set up Vivado, see the [Installing Vivado and Digilent Board Files Tutorial](https://reference.digilentinc.com/learn/programmable-logic/tutorials/2020.1/installation).
* Serial Terminal application (such as Tera Term or PuTTY)
* MicroUSB Cable

## Demo Setup (v2020.1-1)


**Note**: *Other releases may require other steps be taken to use them. Make sure to check the version of this README found in the commit associated with that release's tag for instructions*.

### From a Release

1. Download the most recent release ZIP archives from the repo's [releases page](https://github.com/Digilent/USB104-A7-OOB/releases). These files are called "USB104-A7-OOB-hw-2020.1-1.zip" and "USB104-A7-OOB-sw-2020.1-1.zip". The -hw- archive contains an exported XPR project file and associated sources for use with Vivado. The -sw- archive contains exported project files for use with Vitis. Both of these files contain the build products of the associated tool.

2. Extract the downloaded -hw- archive. (Do not extract the -sw- archive)

3. Open Vivado 2020.1.

4. Open the XPR project file, found at <archive extracted location>/hw/hw.xpr, included in the extracted hardware release in Vivado 2020.1.

5. No additional steps are required within Vivado. The project can be viewed, modified, and rebuilt, and a new platform can be exported, as desired.

6. Open Vitis 2020.1. Choose an empty folder as the *Workspace* to launch into.

7. With Vitis opened, click the **Import Project** button, under **PROJECT** in the welcome screen.

8. Choose *Vitis project exported zip file* as the Import type, then click **Next**.

9. **Browse** for the downloaded -sw- archive, and **Open** it.

10. Make sure that all boxes are checked in order to import each of the projects present in the archive will be imported, then click **Finish**.

11. Connect the USB104 A7 to your computer via the MicroUSB programming cable.

12. Open a serial terminal application (such as TeraTerm or PuTTY) and connect it to the USB104 A7's serial port, using a baud rate of 9600.

13. In the *Assistant* pane at the bottom left of the Vitis window, right click on the project marked [System], and select **Run -> Launch Hardware**. When the demo is finished launching, messages will be able to be seen through the serial terminal, and the buttons can be used as described in this document's Description section, above.

###From Flash

Assuming that the SPI Flash has not been overwritten, the demo can be booted by setting the programming mode switches to the SPI position (FIXME), then by powering on the board, or by pressing the PROG button, if it already on.

## Next Steps

*This section is primarily used to link to useful resources*

This demo can be used as a basis for other projects by modifying the hardware platform in the Vivado project's block design or by modifying the Vitis application project.

Check out the USB104 A7's [Resource Center](https://reference.digilentinc.com/reference/programmable-logic/usb104-a7/start) to find more documentation, demos, and tutorials.

For technical support or questions, please post on the [Digilent Forum](https://forum.digilentinc.com/).

## Additional Notes

For more information on how this project is version controlled, refer to the [digilent-vivado-scripts](https://github.com/digilent/digilent-vivado-scripts) and [digilent-vitis-scripts](https://github.com/Digilent/digilent-vitis-scripts) repositories.