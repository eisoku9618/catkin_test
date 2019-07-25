[![Build Status](https://travis-ci.org/eisoku9618/catkin_test.svg?branch=master)](https://travis-ci.org/eisoku9618/catkin_test)

# 別のcatkin packageのヘッダやライブラリを使うときの最小限CMakeLists.txtの書き方

```bash
.
├── child
│   ├── CMakeLists.txt
│   ├── package.xml
│   └── src
│       └── main.cpp
├── parent
│   ├── CMakeLists.txt
│   ├── include
│   │   └── parent
│   │       └── hoge.h
│   ├── package.xml
│   └── src
│       └── hoge.cpp
```

まず，元となるパッケージ（ここではparent package）は

```cmake
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES hoge_library
  )

add_library(hoge_library
  src/hoge.cpp
  )
```

のように``catkin_package``を書くことでヘッダとライブラリを外部から使える準備が整う．
こうすることで，``devel/.private/parent/lib/pkgconfig/parent.pc``に以下のように``Cflags``と``Libs``が追加される

```txt
prefix=/tmp/hoge_ws/devel/.private/parent

Name: parent
Description: Description of parent
Version: 0.0.0
Cflags: -I/tmp/hoge_ws/src/parent/include
Libs: -L/tmp/hoge_ws/devel/.private/parent/lib -lhoge_library
Requires: 
```

これは，downstreamのパッケージ（ここではchild package）で
```cmake
find_package(catkin REQUIRED parent)
```
としたときに，
```cmake
${catkin_INCLUDE_DIRS}
${catkin_LIBRARIES}
```
に値がセットされるようになる．
