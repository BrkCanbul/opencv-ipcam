# For ubuntu 22.04
1. Install opencv
- clone repository from https://github.com/opencv/opencv
```shell
git clone https://github.com/opencv/opencv.git
cd opencv
```
-build the repository with Gstreamer library
```shell
mkdir build
cd build
sudo apt install cmake
cmake  cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_GSTREAMER=ON ..
make -j4
sudo make install
```
2. Install QT5 for ubuntu
  - qt tools
  - ```shell
      sudo apt install -y qtcreator qtbase5-dev qt5-qmake cmake
    ```
3. build QMake files
  -  ```shell
      qmake
      ```
4. build Makefile
  - ```shell
       make
      ```
# For windows
1. Install opencv 4.9   from [here](https://opencv.org/releases/)
2. Install Qt from [here](https://www.qt.io/download)
3. clone this repository
   - ```shell
        git clone github.com/brkCanbul/opencv-ipcam
        cd ./opencv-ipcam
        ```
4. Configure config.pri and opencv-ipcam.pro files according to your opencv path
5. build QMake files
  -  ```shell
      qmake
      ```
6. build Makefile
  - ```shell
       mingw32-make
      ```