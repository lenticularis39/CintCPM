#!/bin/sh
rm -f .test.img
cp cpm86_11_pc_xt.img .test.img
cp blank_ibm_pc_ss_160k.img .test2.img
../cpmtools/cpmcp -f ibmpc-514ss .test2.img ../hello/hello.cmd 0:hello.cmd
qemu-system-i386 -no-fd-bootchk \
	-blockdev driver=file,node-name=f0,filename=.test.img \
	-device floppy,drive=f0 \
	-blockdev driver=file,node-name=f1,filename=.test2.img \
	-device floppy,drive=f1
