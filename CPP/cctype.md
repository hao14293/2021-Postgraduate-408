```md
1.isalnum() 
检查字符c是十进制数还是大写还是小写字母。如果是，则返回true；如果不是，则返回false。

2.isalpha() 
检查字符c是否是字母。如果是，则返回true；如果不是，则返回false。

3.isblank() 
检查字符c是否为空白字符。空白字符是用于分隔文本行内的单词的空格字符。如果是，则返回true；如果不是，则返回false。

4.iscntrl() 
检查c是否是控制字符。控制字符是不占用显示器上打印位置的字符（这与可打印字符相反，用isprint检查）。对于标准ASCII字符集（由“C”语言环境使用），控制字符是ASCII码0x00（NUL）和0x1f（US）之间加上0x7f（DEL）的字符。

5.isdigit() 
检查字符是否为十进制数字,检查c是否是十进制数字字符。小数位是以下任何一个：0 1 2 3 4 5 6 7 8 9

6.isgraph() 
检查字符是否可以图形表示，检查c是否是具有图形表示的字符。带有图形表示的字符是除了空格字符（”）以外都可以打印的字符（由isprint确定）。

7.islower() 
检查字符是否为小写字母，检查c是否是小写字母。

请注意，所考虑的字母可能取决于所使用的语言环境; 在默认的“C”语言环境中，小写字母是以下任何一种：a b c d e f g h i j k l m n o p q r s t u v w x y z。

其他语言环境可能会将字符的不同选择视为小写字符，但永远不会对iscntrl，isdigit，ispunct或isspace返回true。

8.isprint() 
检查字符是否可打印，检查c是否是可打印的字符。可打印字符是在显示器上占据打印位置的字符（这与控制字符相反，使用iscntrl进行检查）。

对于标准ASCII字符集（由“C”语言环境使用），打印字符全部使用大于0x1f（US）的ASCII码，但0x7f（DEL）除外。 
isgraph对于与isprint相同的情况返回true，除了空格字符（”），它在使用isprint检查时返回true，但在使用isgraph检查时返回false。

9.ispunct() 
检查字符是否是标点符号，检查c是否是标点符号。标准的“C”语言环境认为标点字符是非字母数字（如isalnum）中的所有图形字符（如isgraph）。

其他语言环境可能会将不同的字符选择为标点符号，但无论如何它们都是isgraph而不是isalnum。

10.isspace() 
检查字符是否为空白，检查c是否是空格字符。
11.isupper() 
检查字符是否为大写字母，检查参数c是否为大写字母。

请注意，所考虑的信件可能取决于所使用的语言环境; 在默认的“C”语言环境中，大写字母是以下任何一种：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z.

其他语言环境可能会将不同的字符选择视为大写字符，但永远不会对iscntrl，isdigit，ispunct或isspace返回true的字符。

12.isxdigit() 
检查字符是否是十六进制数字，检查c是否是十六进制数字字符。 
十六进制数字是以下任何一种：0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F
1.tolower() 
将字母转换为小写。

2.toupper() 
将字母转换成大写。
```
