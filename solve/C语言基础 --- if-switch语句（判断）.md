## C语言基础 --- if-switch语句（判断)

指定一个或多个要评估或测试的条件，以及条件为真时要执行的语句（必需的）和条件为假时要执行的语句（可选的）

### 判断语句

C语言提供了以下类型的判断语句
| 语句                        | **描述**                                                     |
| :-------------------------- | :----------------------------------------------------------- |
| **if**                      | 一个 **if 语句** 由一个布尔表达式后跟一个或多个语句组成。    |
| **if...else**               | 一个 **if 语句** 后可跟一个可选的 **else 语句**，else 语句在布尔表达式为假时执行。 |
| 嵌套 **if** 语句            | 可以在一个 **if** 或 **else if** 语句内使用另一个 **if** 或 **else if** 语句。 |
| **switch** 语句             | 一个 **switch** 语句允许测试一个变量等于多个值时的情况。     |
| 嵌套 **switch** 语句        | 可以在一个 **switch** 语句内使用另一个 **switch** 语句。     |
| **if...else if...else**语句 | 可以设置多个判断条件，也就是 **if..else** 语句的连用         |

#### if 语句

```c++
//语法
if (/*布尔表达式，也就是所需要判断的条件*/) {
     /* 如果布尔表达式为真将执行的语句 */
}

//例如下面这个例子

#include <stdio.h>

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    
    //下面就是进行判断a和b的大小，若是符合两个int变量均小于0，则执行if括号里面的代码
    if (a < 0 && b < 0) {
        printf("最后结果必为负数\n");
    }
    
    printf("%d\n",a + b);
    return 0;
}
```

#### if...else语句

```c++
//语法
if (/*布尔表达式*/) {
    /* 如果布尔表达式为真将执行的语句 */
} else {
    /* 如果布尔表达式为假将执行的语句 */
}

//if...else语句就是if语句中的if判断为假时，扩展出一个else的执行代码

#include <stdio.h>

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    
    //下面就是进行判断a和b的大小，若是符合两个int变量均小于0，则执行if括号里面的代码，若是不满足if中的条件，则执行else中的代码
    if (a < 0 && b < 0) {
        printf("最后结果必为负数\n");
    } else {
        printf("最后结果不一定为负数\n");
    }
    
    printf("%d\n",a + b);
    return 0;
}
```

#### if...else if...else 语句

```c++
//语法
if (/*布尔表达式1*/) {
   /* 当布尔表达式 1 为真时执行 */
} else if (/*布尔表达式2*/) {
   /* 当布尔表达式 2 为真时执行 */
} else if (/*布尔表达式3*/) {
   /* 当布尔表达式 3 为真时执行 */
} else {
   /* 当上面条件都不为真时执行 */
}

//在我们有多个需要判断的情况中，我们就可以使用上述语句

#include <stdio.h>

int main() {
    int a;
    scanf("%d",&a);
    
    if (a < 0) {
        printf("%d是负整数\n"，a);
    } else if (a == 0) {
        printf("%d是零\n"，a);
    } else {
        printf("%d是正整数\n"，a);
    }
    
    //上述要求判断a是整数的哪一类，则需要判断三种情况
}
```

#### 嵌套if...else语句

```c++
//语法
if (/*布尔表达式1*/) {
    /* 当布尔表达式 1 为真时执行 */
   if (/*布尔表达式1*/) {
      /* 当布尔表达式 2 为真时执行 */
   }
}

#include <stdio.h>

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    
    //下面就是进行判断a和b的大小，若是符合两个int变量均小于0，则执行if括号里面的代码
    if (a < 0) {
        //先判断a的大小
        if (b < 0) {
            //再判断b的大小
        	printf("最后结果必为负数\n");
        }
    }
    
    printf("%d\n",a + b);
    return 0;
}
```

#### switch 语句

````c++
意思是先计算表达式的值，再逐个和 case 后的常量表达式比较，若不等则继续往下比较，若一直不等，则执行 default 后的语句；若等于某一个常量表达式，则从这个表达式后的语句开始执行，并执行后面所有 case 后的语句。

与 if 语句的不同：if 语句中若判断为真则只执行这个判断后的语句，执行完就跳出 if 语句，不会执行其他 if 语句；而 switch 语句不会在执行判断为真后的语句之后跳出循环，而是继续执行后面所有 case 语句。在每一 case 语句之后增加 break 语句，使每一次执行之后均可跳出 switch 语句，从而避免输出不应有的结果。
//语法 switch需要跟case连用
//一个 switch 语句允许测试一个变量等于多个值时的情况。每个值称为一个 case，且被测试的变量会对每个 switch case 进行检查。
switch (/*一个常量表达式，必须是一个整型或枚举类型*/) {
    // 可以有任意数量的 case 语句；每个 case 后跟一个要比较的值和一个冒号
    case constant-expression  :
       statement(s);
       break; /* 可选的 */
    case constant-expression  :
       statement(s);
       break; /* 可选的 */
    //constant-expression 必须与 switch 中的变量具有相同的数据类型，且必须是一个常量或字面量
    //当被测试的变量等于 case 中的常量时，case 后跟的语句将被执行，直到遇到 break 语句为止。
    //不是每一个 case 都需要包含 break。如果 case 语句不包含 break，控制流将会 继续 后续的 case，直到遇到 break 为止。
  
    /* 您可以有任意数量的 case 语句 */
    default : /* 可选的 */
       statement(s);
    //一个 switch 语句可以有一个可选的 default case，出现在 switch 的结尾。default case 可用于在上面所有 case 都不为真时执行一个任务。default case 中的 break 语句不是必需的。
}

#include <stdio.h>
 
int main ()
{
   /* 局部变量定义 */
   char grade = 'B';
 
   switch (grade) {
   case 'A' :
      printf("很棒！\n" );
      break;
   case 'B' :
      printf("很不错！\n");
      break;
   case 'C' :
      printf("做得好\n" );
      break;
   case 'D' :
      printf("您通过了\n" );
      break;
   case 'F' :
      printf("最好再试一下\n" );
      break;
   default :
      printf("无效的成绩\n" );
   }
   printf("您的成绩是 %c\n", grade );
 
   return 0;
}
````

#### 嵌套switch语句

```c++
//语法：跟switch的一致
switch(ch1) {
   case 'A': 
      printf("这个 A 是外部 switch 的一部分" );
      switch(ch2) {
         case 'A':
            printf("这个 A 是内部 switch 的一部分" );
            break;
         case 'B': /* 内部 B case 代码 */
      }
      break;
   case 'B': /* 外部 B case 代码 */
}

#include <stdio.h>
 
int main ()
{
   /* 局部变量定义 */
   int a = 100;
   int b = 200;
 
   switch(a) {
      case 100: 
         printf("这是外部 switch 的一部分\n");
         switch(b) {
            case 200:
               printf("这是内部 switch 的一部分\n");
         }
   }
   printf("a 的准确值是 %d\n", a );
   printf("b 的准确值是 %d\n", b );
 
   return 0;
}
```

#### 三元运算符

可以使用三元运算符**?:** ，来代替**if..else**语句来判断条件

```c++
//语法：
/*条件判断*/ ? /*条件为真时所需要执行的*/ : /*条件为假时所需要执行的*/;

//例子
#include<stdio.h>
 
int main()
{
    int num;
 
    printf("输入一个数字 : ");
    scanf("%d",&num);
 
    (num%2==0)?printf("偶数"):printf("奇数");
}

//or

#include <stdio.h>

int main() {
    int a;
    scanf("%d",&a);
    
    printf("%s\n",(a >= 0 ? "非负数" : "负数"));
}
```



