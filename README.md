To do so, make root own spuer and set the setuid bit to allow anyone to execute
it as root.

```
chown root:wheel spuer
chmod 4755 spuer
```

Building
--------

```
make
```