make -j8
make modules
make modules_install
export KERNELVERSION=$(make kernelversion)
cp arch/x86/boot/bzImage /boot/vmlinuz-$KERNELVERSION

cp System.map /boot/System.map-$KERNELVERSION
new-kernel-pkg --mkinitrd --install $KERNELVERSION
echo "Made kernel for $KERNELVERSION"
gcc test_syscall.c -o test_syscall
