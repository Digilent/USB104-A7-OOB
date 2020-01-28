# USB104 A7 Out-of-Box Demo

## Description

This repository contains the Out-of-Box demo for the Digilent USB104 A7. This demo is programmed into the board's SPI Flash at time of manufacturing.

Upon the demo starting up, the message "Welcome to the USB104 A7 Out-Of-Box Demo" is printed over UART to a connected serial terminal. The board's LEDs are cycled through, with one illuminated at a time. Pressing a button results in the direction of the LED cycling being set to the direction associated with that button, and the message "Button Press Detected!" is printed.

The UART controller used within the demo requires that the connected serial terminal use a baud rate of 9600, with one start bit and no parity.

## Requirements

* Digilent USB104 A7
* Xilinx SDK 2019.1 and a Vivado 2019.1 installation, see the [Installing Vivado, Xilinx SDK, and Digilent Board Files](https://reference.digilentinc.com/vivado/installing-vivado/start) guide on the Digilent Wiki for instructions
* Serial Terminal application (such as Tera Term or PuTTY)
* MicroUSB Cable

## Demo Setup


*This section is a step by step guide from downloading the release to programming the board and running the demo. There are two flows, one describes how to run the demo from downloaded sources, while the other describes booting the demo from SPI Flash.*

### From a Release

1. Download the most recent release ZIP archive ("USB104-A7-OOB-2019.1-*.zip") from the repo's [releases page](https://github.com/Digilent/USB104-A7-OOB/releases).

2. Extract the downloaded ZIP.

3. Open the XPR project file, found at \<archive extracted location\>/vivado_proj/USB104-A7-OOB.xpr, included in the extracted release archive in Vivado 2019.1.

4. Launch Xilinx SDK directly (not through the Vivado file menu). When prompted for a workspace, select "\<archive extracted location\>/sdk_workspace".

5. Once the workspace opens, click the **Import** button. In the resulting dialog, first select *Existing Projects into Workspace*, then click **Next**. Navigate to and select the same sdk_workspace folder.

6. Build the project. **Note**: *Errors are sometimes seen at this step. These are typically resolved by right-clicking on the BSP project and selecting Regenerate BSP Sources.*

*Here is where hardware setup should be described, for example:*

7. Open a serial terminal application (such as [TeraTerm](https://ttssh2.osdn.jp/index.html.en) and connect it to the USB104 A7's serial port, using a baud rate of 9600.

8. In the toolbar at the top of the SDK window, select *Xilinx -> Program FPGA*. Leave all fields as their defaults and click "Program".

9. In the Project Explorer pane, right click on the "\<APP NAME\>" application project and select "Run As -> Launch on Hardware (System Debugger)".

10. The application will now be running on the USB104-A7. It can be interacted with as described in the first section of this README.

11. Lastly, the hardware platform must be linked to a hardware handoff, so that changes to the Vivado design can be brought into the SDK workspace. In Vivado, in the toolbar at the top of the window, select *File -> Export -> Export Hardware*. Any Exported Location will do, but make sure to remember the selection, and make sure that the **Include bitstream** box is checked. Click **OK**.

12. In SDK, right click on the \*_hw_platform_\* project, and select *Change Hardware Platform Specification*. Click **Yes** in response to the warning. In the resulting dialog, navigate to and select the .hdf hardware handoff file exported in the previous step, then click **OK**. Now, whenever a modified design is exported from Vivado, on top of the .hdf file, it can be applied to the hardware platform.

###From Flash

Assuming that the SPI Flash has not been overwritten, the demo can be booted by setting the programming mode switches to the SPI position (FIXME), then by powering on the board, or by pressing the PROG button, if it already on.

## Next Steps

*This section is primarily used to link to useful resources*

This demo can be used as a basis for other projects by modifying the hardware platform in the Vivado project's block design or by modifying the SDK application project.

Check out the USB104 A7's [Resource Center](https://reference.digilentinc.com/reference/programmable-logic/usb104-a7/start) to find more documentation, demos, and tutorials.

For technical support or questions, please post on the [Digilent Forum](forum.digilentinc.com).

## Additional Notes

For more information on how this project is version controlled, refer to the [digilent-vivado-scripts repo](https://github.com/digilent/digilent-vivado-scripts).