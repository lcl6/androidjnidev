###添加

####笔记整理 
          CMakeLists 
                1.add_library 该指令的主要作用就是将指定的源文件生成链接文件，然后添加到工程中去。该指令常用的语法如下：    
                            add_library(<name> [STATIC | SHARED | MODULE]
                                        [EXCLUDE_FROM_ALL]
                                        [source1] [source2] [...])
                            其中<name>表示库文件的名字，该库文件会根据命令里列出的源文件来创建。而STATIC、SHARED和MODULE的作用是指定生成的库文件的类型。STATIC库是目标文件的归档文件，在链接其它目标的时候使用。SHARED库会被动态链接（动态链接库），在运行时会被加载。MODULE库是一种不会被链接到其它目标中的插件，但是可能会在运行时使用dlopen-系列的函数。默认状态下，库文件将会在于源文件目录树的构建目录树的位置被创建，该命令也会在这里被调用            
                2.link_directories 该指令的作用主要是指定要链接的库文件的路径，该指令有时候不一定需要。因为find_package和find_library指令可以得到库文件的绝对路径。不过你自己写的动态库文件放在自己新建的目录下时，可以用该指令指定该目录的路径以便工程能够找到。
                
                3.target_link_libraries  该指令的作用为将目标文件与库文件进行链接。该指令的语法如下：
                        target_link_libraries(<target> [item1] [item2] [...]
                                      [[debug|optimized|general] <item>] ...)
                        上述指令中的<target>是指通过add_executable()和add_library()指令生成已经创建的目标文件。而[item]表示库文件没有后缀的名字。默认情况下，库依赖项是传递的。当这个目标链接到另一个目标时，链接到这个目标的库也会出现在另一个目标的连接线上。这个传递的接口存储在interface_link_libraries的目标属性中，可以通过设置该属性直接重写传递接口。
              
              
              
              
          语法：
              JNIEnv* env参数     JNIEnv类型实际上代表了Java环境，通过这个JNIEnv* 指针，就可以对Java端的代码进行操作。例如，创建Java类中的对象，调用Java对象的方法，获取Java对象中的属性等等    
                              