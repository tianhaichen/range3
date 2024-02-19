[![CircleCI](https://circleci.com/gh/Range-Software/range3.svg?style=svg)](https://circleci.com/gh/Range-Software/range3)

# Range Software
Finite Element Analysis

![Range Software](http://www.range-software.com/files/common/Range3-CFD.png)

## Prepare build environment
Following command will download and install all required packages, therefore it must be executed under priviledged (root) user.
```
$ sudo ./scripts/prereqs_ubuntu.sh
```
## Build & Install
### Linux
```
$ ./scripts/build.sh --clean && ./scripts/create_package.sh
```
### MacOS
```
$ ./scripts/build.sh --clean && ./scripts/create_mac_app.sh
```
Above command will produce `./build-Release/packages/range-3.2.8.dmg` which can be installed with following command:
```
$ open './build-Release/packages/range-3.2.8.dmg'
```

### Windows

Qt版本为Qt6。打开项目.../range3/range/range.pro。

在range文件夹下新建文件夹ffmpeg,将下载好的ffmpeg-6.1.1-full_build-shared.7z解压，重命名为ffmpeg-4.3.2-win64。


## Running the software
```
$ $HOME/bin/range-3.2.8/bin/Range
```

## Download
To download already built binaries please visit http://range-software.com

## Powered by

* Qt - https://www.qt.io/
* TetGen - http://tetgen.org
