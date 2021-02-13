# Getting started

* [Harbour programming language](https://en.wikipedia.org/wiki/Harbour_(programming_language))
* [Homepage](https://harbour.github.io)
* Select your Harbour:
   - [hb30](https://sourceforge.net/projects/harbour-project/files/)
   - [hb32](https://github.com/harbour/core)
   - [hb34](https://github.com/vszakats/harbour-core)

# Installing on Windows

### Install raylib

Download [raylib](https://github.com/raysan5/raylib/releases/download/3.0.0/raylib-3.0.0-Win64-mingw.zip) binary archive from this page and unpack in the directory:

```
c:\raylib\bin *.dll
c:\raylib\include *.h
c:\raylib\lib *.a
```

### install hb-raylib

Environment Variables

```
set HB_WITH_RAYLIB=c:\raylib\include
set PATH=c:\raylib\bin;%path%
```

Clone an existing repository only fetching the 10 most recent commits on the default branch (useful to save time):

```
git clone --depth 10 https://github.com/MarcosLeonardoMendezGerencir/hb-raylib
cd hb-raylib
hb-raylib>hbmk2 hbraylib.hbp
```

```
hb-raylib\examples\harbour\tutorial>hbmk2 tutorial_01.prg
```

---

[Edit me](https://github.com/rjopek/hb-raylib/edit/main/docs/tutorial/README.md)
