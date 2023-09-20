# Código da página no firmware

## Otimizações

```
Connected to CLARO NET 2G
IP address: 192.168.0.123
HTTP server started
Tamanho da página: 12437 B
```

```
Compiling .pio/build/nodemcu-32s/src/main.cpp.o
Linking .pio/build/nodemcu-32s/firmware.elf
Retrieving maximum program size .pio/build/nodemcu-32s/firmware.elf
Checking size .pio/build/nodemcu-32s/firmware.elf
Advanced Memory Usage is available via "PlatformIO Home > Project Inspect"
RAM:   [=         ]  13.6% (used 44588 bytes from 327680 bytes)
Flash: [======    ]  59.6% (used 780965 bytes from 1310720 bytes)
Building .pio/build/nodemcu-32s/firmware.bin
```

Ainda serão feitas otimizações

## Página isolada

A página é obtida de um arquivo .html e gerado um .h para o programa, isso é gitignorado no projeto. Desta forma a equipe de desenvolvimento do front pode fazer tranquilamente sem se preocupar com otimizações pensando no target e também sem sem preocupar com a integração do hardware além de se beneficiar de recursos da IDE como RAD.

## Minificação da página

Falar sobre como o processo de compactação da página foi feito.

pip install htmlmin
pip install csscompressor
pip install jsmin

após minificação:

```
Connecting to
CLARO NET 2G
Connected to CLARO NET 2G
IP address: 192.168.0.123
HTTP server started
Tamanho da página: 7836 B
```

> Comentar sobre compressões, renomear variáveis e classes.

```
Compiling .pio/build/nodemcu-32s/src/main.cpp.o
Linking .pio/build/nodemcu-32s/firmware.elf
Retrieving maximum program size .pio/build/nodemcu-32s/firmware.elf
Checking size .pio/build/nodemcu-32s/firmware.elf
Advanced Memory Usage is available via "PlatformIO Home > Project Inspect"
RAM:   [=         ]  13.6% (used 44588 bytes from 327680 bytes)
Flash: [======    ]  59.2% (used 775445 bytes from 1310720 bytes)
Building .pio/build/nodemcu-32s/firmware.bin
```
