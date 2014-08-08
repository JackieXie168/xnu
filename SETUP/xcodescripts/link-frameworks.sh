set -e

cd "${XNU_INSTALL_BASE}/System/Library/Frameworks/System.framework/Versions"
ln -sfh B Current

cd "${XNU_INSTALL_BASE}/System/Library/Frameworks/System.framework"
ln -sfh Versions/Current/PrivateHeaders PrivateHeaders
ln -sfh Versions/Current/System System
