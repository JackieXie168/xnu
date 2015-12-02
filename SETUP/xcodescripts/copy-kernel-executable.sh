if [ -e "${DSTROOT}/System/Library/Kernels/kernel" ]; then
    cp -f "${DSTROOT}/System/Library/Kernels/kernel" "${DSTROOT}/mach_kernel"
elif [ -e "${DSTROOT}/System/Library/Kernels/kernel.development" ]; then
    cp -f "${DSTROOT}/System/Library/Kernels/kernel.development" "${DSTROOT}/mach_kernel"
elif [ ! -e "${DSTROOT}/mach_kerne;" ]; then
    echo "Kernel file not found" 1>&2
    exit 1
fi

chmod 755 "${DSTROOT}/mach_kernel"
