mount /dev/ ./alpine/dev/ --bind
mount -o remount,ro,bind ./alpine/dev
cp -L /etc/resolv.conf ./alpine/etc/
cp -r src alpine/src
cp -r static alpine/static
chroot ./alpine gcc src/main.c -o hellokitty.out
chroot ./hellokitty.out
umount ./alpine/dev
