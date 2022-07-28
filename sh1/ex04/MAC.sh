#!/bin/sh
ifconfig | grep -w 'ether' | cut -b 8-24
