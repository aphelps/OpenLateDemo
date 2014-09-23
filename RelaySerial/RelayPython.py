#!/usr/bin/python
#
# This depends on the pyserial module: http://pyserial.sourceforge.net/
#
# This script will connect to a serial port and send alternating "on" and "off"

import argparse
import serial
import portscan
import time

def parse_args():
    parser = argparse.ArgumentParser(description='Simple utility to send commands over the serial port')
    parser.add_argument('-d', '--device')

    return parser.parse_args()

if __name__ == "__main__":
    options = parse_args()

    if (options.device == None):
        # If no device specified choose one from the avaliable list
        options.device = portscan.choose_port()

    # Connect to the serial port
    device = serial.Serial(options.device, 9600, timeout=10)

    # Wait for ready indicator
    print("Waiting for 'READY' on port %s" % options.device)
    while True:
        data = device.readline().strip()
        print("Received '%s'" % data)
        if (data == "READY"):
            break

    # Alternate sending "on" and "off"
    command = "on"
    while True:
        print("Sending '%s' to port '%s'" % (command, options.device))
        device.write(command + "\n")

        if (command == "on"):
            command = "off"
        else:
            command = "on"

        time.sleep(1)
