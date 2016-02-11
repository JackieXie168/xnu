set -e

function CopyHeader {
    install -d `dirname "${XNU_INSTALL_BASE}/usr/include/$1"`
    cp -f "${SRCROOT}/EXTERNAL_HEADERS/$1" "${XNU_INSTALL_BASE}/usr/include/$1"
}

function CopyPrivateHeader {
    install -d `dirname "${XNU_INSTALL_BASE}/System/Library/Frameworks/System.framework/PrivateHeaders/$1"`
    cp -f "${SRCROOT}/EXTERNAL_HEADERS/$1" "${XNU_INSTALL_BASE}/System/Library/Frameworks/System.framework/PrivateHeaders/$1"
}

CopyHeader AssertMacros.h
CopyHeader Availability.h
CopyHeader AvailabilityInternal.h
CopyHeader AvailabilityMacros.h
CopyHeader stdarg.h
CopyHeader stdbool.h
CopyHeader stddef.h
CopyHeader architecture/byte_order.h
CopyHeader architecture/i386/asm_help.h
CopyHeader architecture/i386/cpu.h
CopyHeader architecture/i386/desc.h
CopyHeader architecture/i386/io.h
CopyHeader architecture/i386/pio.h
CopyHeader architecture/i386/reg_help.h
CopyHeader architecture/i386/sel.h
CopyHeader architecture/i386/table.h
CopyHeader architecture/i386/tss.h

CopyPrivateHeader corecrypto/cc.h
CopyPrivateHeader corecrypto/cc_config.h
CopyPrivateHeader corecrypto/cc_priv.h
CopyPrivateHeader corecrypto/ccaes.h
CopyPrivateHeader corecrypto/ccder.h
CopyPrivateHeader corecrypto/ccdes.h
CopyPrivateHeader corecrypto/ccdigest.h
CopyPrivateHeader corecrypto/cchmac.h
CopyPrivateHeader corecrypto/ccmd5.h
CopyPrivateHeader corecrypto/ccmode.h
CopyPrivateHeader corecrypto/ccmode_factory.h
CopyPrivateHeader corecrypto/ccmode_impl.h
CopyPrivateHeader corecrypto/ccn.h
CopyPrivateHeader corecrypto/ccpad.h
CopyPrivateHeader corecrypto/ccpbkdf2.h
CopyPrivateHeader corecrypto/ccrc4.h
CopyPrivateHeader corecrypto/ccrng.h
CopyPrivateHeader corecrypto/ccrng_system.h
CopyPrivateHeader corecrypto/ccsha1.h
CopyPrivateHeader corecrypto/ccsha2.h

# These headers must also be present in Kernel.framework, so I symlink them there.
pushd "${XNU_INSTALL_BASE}/System/Library/Frameworks/Kernel.framework/Versions/A/Headers"
ln -sfh "../../../../../../../usr/include/Availability.h" Availability.h
ln -sfh "../../../../../../../usr/include/AvailabilityInternal.h" AvailabilityInternal.h
ln -sfh "../../../../../../../usr/include/AvailabilityMacros.h" AvailabilityMacros.h
ln -sfh "../../../../../../../usr/include/AssertMacros.h" AssertMacros.h
popd
