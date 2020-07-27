###### 项目说明

提取SeetaFace6中的活体检测模块，并封装为python可调用的so文件

###### 原项目地址[https://github.com/seetafaceengine/SeetaFace6](https://github.com/seetafaceengine/SeetaFace6)

###### 依赖环境

> g++ (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609
> 
> Python 3.5.2
> 
> OpenCV-3.4

###### 编译步骤

> 1. 创建build文件夹
> 
> 2. 执行python绑定生成器脚本文件，得到build中的生成文件。
>    
>    ```
>    sh mkbind.sh
>    ```
> 
> 3. 生成.so文件
>    
>    ```
>    make
>    ```

###### 测试结果

```
python test.py
```
