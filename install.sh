# Definir variáveis
URL="http://cdimage.ubuntu.com/ubuntu-base/releases/20.04/release/ubuntu-base-20.04.3-base-amd64.tar.gz"
DIRETORIO="container"
TAR_FILE="ubuntu-base.tar.gz"
CWEBSTUDIO_VERSION="v2.000"

# Verificar se o script está sendo executado como root
if [[ $EUID -ne 0 ]]; then
   echo "Este script deve ser executado como root"
   exit 1
fi

echo ""
echo "delet dependencies"
rm -rf src/dependencies
mkdir src/dependencies
echo ""
echo "Install dependencies"
curl -L https://github.com/OUIsolutions/CWebStudio/releases/download/$CWEBSTUDIO_VERSION/CWebStudio.h -o src/dependencies/CWebStudio.h
echo ""
echo ""
echo ""
#resouvendo problemas de montagem anterior
umount "$DIRETORIO/proc"
umount "$DIRETORIO/sys"
umount "$DIRETORIO/dev/pts"
umount "$DIRETORIO/dev"
umount "$DIRETORIO"


#!/bin/bash
echo "deletando container antigo"
sudo rm -rf $DIRETORIO

echo "Baixando o sistema de arquivos mínimo do Ubuntu..."
wget -O "$TAR_FILE" "$URL"

# Verificar se o download foi bem-sucedido
if [ $? -ne 0 ]; then
    echo "Falha ao baixar o arquivo"
    exit 1
fi

# Criar o diretório onde o sistema de arquivos será montado
echo "Criando diretório $DIRETORIO..."
mkdir -p "$DIRETORIO"

# Descompactar o sistema de arquivos
echo "Descompactando o sistema de arquivos..."
tar -xzf "$TAR_FILE" -C "$DIRETORIO"

#da acesso a internet
 cp -L /etc/resolv.conf ./$DIRETORIO/etc/


# Montar os sistemas de arquivos necessários para o chroot
echo "Montando sistemas de arquivos necessários..."
mount --bind /proc "$DIRETORIO/proc"
mount --bind /sys "$DIRETORIO/sys"
mount --bind /dev "$DIRETORIO/dev"
mount --bind /dev/pts "$DIRETORIO/dev/pts"


echo "Instalando o projeto"
chroot $DIRETORIO /bin/bash -c 'apt update'
chroot $DIRETORIO /bin/bash -c 'DEBIAN_FRONTEND=noninteractive apt install -y gcc build-essential'



# Após sair do chroot, desmontar os sistemas de arquivos
echo "Desmontando sistemas de arquivos..."
umount "$DIRETORIO/proc"
umount "$DIRETORIO/sys"
umount "$DIRETORIO/dev/pts"
umount "$DIRETORIO/dev"
umount "$DIRETORIO"

sudo rm  $DIRETORIO/etc/resolv.conf

echo "Processo concluído."
