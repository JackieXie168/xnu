mkdir -p "${XNU_INSTALL_BASE}"
mkdir -p "${DERIVED_FILE_DIR}/xnu.obj"

make install "DSTROOT=${XNU_INSTALL_BASE}" "OBJROOT=${DERIVED_FILE_DIR}/xnu.obj" "CTFCONVERT=${BUILT_PRODUCTS_DIR}/ctfconvert~xnudep" "CTFMERGE=${BUILT_PRODUCTS_DIR}/ctfmerge~xnudep" &> $XNU_BUILD_LOG_FILE
exit $?
