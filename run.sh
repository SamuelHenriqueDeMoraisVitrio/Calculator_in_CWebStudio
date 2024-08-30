


# Definir variáveis
URL="http://cdimage.ubuntu.com/ubuntu-base/releases/20.04/release/ubuntu-base-20.04.3-base-amd64.tar.gz"
DIRETORIO="container"
PROJECTS="projects"
TAR_FILE="ubuntu-base.tar.gz"
COMANDO="cd $PROJECTS && gcc src/main.c  && ./a.out"

#resouvendo problemas de montagem anterior
umount "$DIRETORIO/proc"
umount "$DIRETORIO/sys"
umount "$DIRETORIO/dev/pts"
umount "$DIRETORIO/dev"
umount "$DIRETORIO"


# Verificar se o script está sendo executado como root
if [[ $EUID -ne 0 ]]; then
   echo "Este script deve ser executado como root"
   exit 1
fi

#da acesso a internet (nescessário se seu app vai usar internet emquanto roda)
sudo cp -L /etc/resolv.conf ./$DIRETORIO/etc/
sudo mkdir ./$DIRETORIO/$PROJECTS
sudo cp -r ./src ./static ./$DIRETORIO/$PROJECTS


# Montar os sistemas de arquivos necessários para o chroot
echo "Montando sistemas de arquivos necessários..."
mount --bind /proc "$DIRETORIO/proc"
mount --bind /sys "$DIRETORIO/sys"
mount --bind /dev "$DIRETORIO/dev"
mount --bind /dev/pts "$DIRETORIO/dev/pts"

xhost +local:

#starta o app
chroot $DIRETORIO /bin/bash -c  "$COMANDO"


# Após sair do chroot, desmontar os sistemas de arquivos
echo "Desmontando sistemas de arquivos..."
umount "$DIRETORIO/proc"
umount "$DIRETORIO/sys"
umount "$DIRETORIO/dev/pts"
umount "$DIRETORIO/dev"
umount "$DIRETORIO"

#Remove o arquivo de interent do container
sudo rm  $DIRETORIO/etc/resolv.conf

echo "Processo concluído."
