//
// Created by kim yang on 2020/8/8.
// Copyright (c) Kim Yang All rights reserved.
//

//链式存储——单结点多字符
#include <stdio.h>

/**定义模块**/
typedef struct StringNode{
    char ch[4];//每个结点存多个个字符,存储密度提高，每个字符1B，每个指针4B
    struct StringNode *next;
}StringNode,*String;

/**定义模块**/

/**实现模块**/
//坐等填坑

/**实现模块**/

/**测试模块**/


/**测试模块**/