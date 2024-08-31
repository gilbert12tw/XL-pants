# NTHU TEAM Made in Abyss Codebook
----
[![Build Status](https://travis-ci.org/Jinkela-Xiao-Zuan-Feng-Mountaineer/Codebook.svg?branch=master)](https://travis-ci.org/Jinkela-Xiao-Zuan-Feng-Mountaineer/Codebook)

## 1. How to Build
**Step 1:** Download the source code. For example,
~~~
$ git clone https://github.com/gilbert12tw/XL-pants.git
~~~

**Step 2:** Go to the project root and build by
~~~
$ python build.py
~~~

### 1.1. Dependencies

* python (version >= 3.0)
* xelatex (latest version)

#### 1.1.1 Install xelatex

##### For Linux
```bash
apt install texlive-xetex
```

If still cannot build:
```bash
apt install texlive-full
```

##### For Windows
Install MiKTeX https://miktex.org/download


## 2. TODO list

1. 修改 codes 內容
2. 把不要的 code 從 list.tex 中註解掉，然後直接用 `xelatex --shell-escape Codebook.tex` 編譯
