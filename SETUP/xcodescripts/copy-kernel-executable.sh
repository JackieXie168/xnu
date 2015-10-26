if [ -e "${DSTROOT}/System/Library/Kernels/kernel" ]; then
    cp -f "${DSTROOT}/System/Library/Kernels/kernel" "${DSTROOT}/mach_kernel"
elif [ -e "${DSTROOT}/System/Library/Kernels/kernel.development" ]; then
    cp -f "${DSTROOT}/System/Library/Kernels/kernel.development" "${DSTROOT}/mach_kernel"
else
    echo "Kernel file not found" 1>&2
    exit 1
fi
