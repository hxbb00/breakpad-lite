# breakpad-lite

# build

cmake .
make

# dmp分析

dmp文件分析需要用到两个可执行程序，第一个是dump_syms，第二个是minidump_stackwalk

1，dump_syms 用来生成可执行程序的符号表，如
./dump_syms main > main.sym
./dump_syms libsecmodel.so > libsecmodel.so.sym

2，根据 main.sym 得到 version number
执行 head main.sym -n 1
得到 MODULE Linux x86_64 0B3BFC770A76BCA18E2ECC7A19DF61DF0 main
创建文件夹 syms/main/0B3BFC770A76BCA18E2ECC7A19DF61DF0

3，将main.sym 复制到 syms/main/0B3BFC770A76BCA18E2ECC7A19DF61DF0 下

4，假设程序崩溃后生成的dmp文件为 7f0a5ae5-4ea2-150e-55e9b70e-05c9ae40.dmp

5，生成可读的栈信息
minidump_stackwalk 7f0a5ae5-4ea2-150e-55e9b70e-05c9ae40.dmp ./syms > main.result
则栈信息存储在了 main.result 文件中
