## Synopsis

Very simple utility application to extract the Garry's Mod addon format also known as `GMAD`
that tend to have the file extension `.GMA`.

The main objective of this application is to provide a light, fast, cross platform cli tool
to extract these files.

Usage: `gmaextract in.gma [outdir]`

## Prerequisites

Depends on `Bootil` which is included as a git submodule and `premake5` to build project files.

## Building From Source

First run: `git submodule update --init --recursive` to grab Bootil.

* **Windows**: Generate your project files using `premake5 vs2015` and build using `project/gmaextract.sln`
* **Linux**: Run `premake5 gmake && make`

## License

[The MIT License (MIT) - Copyright (c) 2014-2017 Matt Stevens](LICENSE)
