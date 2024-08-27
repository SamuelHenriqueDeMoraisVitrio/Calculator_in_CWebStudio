wget http://dl-cdn.alpinelinux.org/alpine/v3.12/releases/x86_64/alpine-minirootfs-3.12.0-x86_64.tar.gz
mkdir alpine
tar zxf alpine-minirootfs-*.tar.gz -C ./alpine
mount /dev/ ./alpine/dev/ --bind
mount -o remount,ro,bind ./alpine/dev
cp -L /etc/resolv.conf ./alpine/etc/
mkdir -p /alpine/root
chroot ./alpine apk add gcc
umount ./alpine/dev
rm -f /etc/resolve.conf
echo "alpine installed with gcc"
