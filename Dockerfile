FROM ubuntu:14.04

RUN apt-get update
RUN apt-get install -y gcc-avr avr-libc dfu-programmer build-essential
