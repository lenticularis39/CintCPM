#!/bin/sh
rm -f .test.img
cp cpm86_11_pc_xt.img .test.img
../cpmtools/cpmcp -f ibmpc-514ds .test.img ../hello/hello.cmd 0:hello.cmd
qemu-system-i386 -blockdev driver=file,node-name=f0,filename=.test.img \
	-device floppy,drive=f0 -no-fd-bootchk
