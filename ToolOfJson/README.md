注意事项：
1、Jsoncpp源码仓库地址：https://github.com/open-source-parsers/jsoncpp
2、拉取源码master分支使用CMake编译：
->选择编译项目文件夹->选择生成目录（已存在的目录）->Configure->选择编译器->选择编译配置->Generate
3、CMake编译时提示缺少Python，安装即可

4、编译完成后会在生成目录生成.sln解决方案文件，打开解决方案并编译

5、一开始我认为只需要编译release版本来使用就可以了，后发现在Debug模式下使用release版本json内容无法解析总是报错

6、后编译jsoncpp的Debug版本，编译时一直报错，后将解决方案中的一些不需要的test项目去掉才得以编译成功

7、编译时还会有一个exe一直占用jsoncpp.dll导致无法编译成功（请注意）

8、后编译完成后在项目中使用还是会出现_ASSERTE(__acrt_first_block == header)断言失败

9、查找资料发现，需要在编译jsoncpp_lib项目时改其配置：
->C/C++->代码生成->运行库->多线程调试DLL(/MDd)

10、当前项目亦要应用如上配置

11、至此Release/Debug都正常