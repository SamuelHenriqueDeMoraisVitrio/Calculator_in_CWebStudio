
# Verificar se o script está sendo executado como root
if [[ $EUID -ne 0 ]]; then
   echo "these script must be executed as root"
   exit 1
fi

mount /dev/ ./alpine/dev/ --bind
mount -o remount,ro,bind ./alpine/dev
cp -L /etc/resolv.conf ./alpine/etc/
cp -r src alpine/src
cp -r static alpine/static
chroot ./alpine gcc src/main.c -o hellokitty.out
chroot ./alpine  ./hellokitty.out
umount ./alpine/dev
echo "container unmounted"
