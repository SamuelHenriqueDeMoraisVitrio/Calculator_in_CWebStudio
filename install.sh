
CWEBSTUDIO_VERSION ="v2.000"

if [[ $EUID -ne 0 ]]; then
   echo "these script must be executed as root"
   exit 1
fi

# in case of re-run these script
rm -rf alpine
rm -rf src/dependencies
mkdir src/dependencies


wget https://github.com/OUIsolutions/CWebStudio/releases/download/$CWEBSTUDIO_VERSION/CWebStudio.h  src/dependencies/CWebStudio.h

wget http://dl-cdn.alpinelinux.org/alpine/v3.12/releases/x86_64/alpine-minirootfs-3.12.0-x86_64.tar.gz
mkdir alpine
tar zxf alpine-minirootfs-*.tar.gz -C ./alpine
mount /dev/ ./alpine/dev/ --bind
mount -o remount,ro,bind ./alpine/dev
cp -L /etc/resolv.conf ./alpine/etc/
mkdir -p /alpine/root
chroot ./alpine apk add gcc
chroot ./alpine apk add musl-dev
umount ./alpine/dev
rm -f /etc/resolve.conf
echo "alpine installed with gcc"
