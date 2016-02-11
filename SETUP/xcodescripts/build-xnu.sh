set -e

mkdir -p "${XNU_INSTALL_BASE}"
mkdir -p "${DERIVED_FILE_DIR}/xnu.obj"

make install "DSTROOT=${XNU_INSTALL_BASE}" "OBJROOT=${DERIVED_FILE_DIR}/xnu.obj" "CTFCONVERT=${BUILT_PRODUCTS_DIR}/ctfconvert" "CTFMERGE=${BUILT_PRODUCTS_DIR}/ctfmerge" "BUILD_LTO=0" &> $XNU_BUILD_LOG_FILE

if [ -f "${XNU_INSTALL_BASE}/System/Library/Kernels/kernel.development" ]; then
    cp -f "${XNU_INSTALL_BASE}/System/Library/Kernels/kernel.development" "${XNU_INSTALL_BASE}/mach_kernel"
elif [ -f "${XNU_INSTALL_BASE}/System/Library/Kernels/kernel" ]; then
    cp -f "${XNU_INSTALL_BASE}/System/Library/Kernels/kernel" "${XNU_INSTALL_BASE}/mach_kernel"
fi
