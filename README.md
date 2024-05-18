# For ubuntu 22.04
1. Install opencv
   -- clone repository from https://github.com/opencv/opencv
```shell
git clone https://github.com/opencv/opencv.git
cd opencv
mkdir build
cd build
sudo apt install cmake
cmake ../
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
    ```
3. build QMake files
  -  ```shell
      qmake
      ```
4. build Makefile
  - ```shell
       mingw32-make
      ```
