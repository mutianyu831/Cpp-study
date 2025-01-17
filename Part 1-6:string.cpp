//6.1
题目描述
大家都知道一些办公软件有自动将字母转换为大写的功能。输入一个长度不超过100且不包括空格的字符串。要求将该字符串中的所有小写字母变成大写字母并输出。
输入格式
输入一行，一个字符串。
输出格式
输出一个字符串，即将原字符串中的所有小写字母转化为大写字母。
输入输出样例
输入 #1
Luogu4!
输出 #1
LUOGU4!

#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    char s[110];
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        if('a'<=s[i]&&s[i]<='z'){
            s[i]-='a'-'A';
        }
    }
    cout<<s<<endl;
    return 0;
}
也可以使用下面的写法：
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	char s;
	while (1) {
		s = getchar();
		if (s == EOF) {
			break;
		}
		if ('a' <= s && s <= 'z')
			s += 'A' - 'a';
		putchar(s);
	}
	return 0;
}

//6.2
题目背景
某蒟蒻迷上了 “小书童”，有一天登陆时忘记密码了（他没绑定邮箱 or 手机），于是便把问题抛给了神犇你。
题目描述
蒟蒻虽然忘记密码，但他还记得密码是由一个字符串组成。密码是由原文字符串（由不超过 50 个小写字母组成）中每个字母向后移动 n 位形成的。z 的下一个字母是 a，如此循环。他现在找到了移动前的原文字符串及 n，请你求出密码。
输入格式
第一行：n。
第二行：未移动前的一串字母。
输出格式
一行，是此蒟蒻的密码。
输入输出样例
输入 #1
1
qwe
输出 #1
rxf
说明/提示
字符串长度 ≤50，1≤n≤26。

  
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n;
    cin>>n;
    char s[55];
    cin>>s;
    for(int i=0;s[i];i++){
        putchar((s[i]-'a'+n)%26+'a');
    }
    return 0;
}

//6.3
题目描述
笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！
这种方法的具体描述如下：假设 maxn 是单词中出现次数最多的字母的出现次数，minn 是单词中出现次数最少的字母的出现次数，如果 maxn−minn 是一个质数，那么笨小猴就认为这是个 Lucky Word，这样的单词很可能就是正确的答案。
输入格式
一个单词，其中只可能出现小写字母，并且长度小于 100。
输出格式
共两行，第一行是一个字符串，假设输入的的单词是 Lucky Word，那么输出 Lucky Word，否则输出 No Answer；
第二行是一个整数，如果输入单词是 Lucky Word，输出 maxn−minn 的值，否则输出 0。
输入输出样例
输入 #1
error
输出 #1
Lucky Word
2
输入 #2
olympic
输出 #2
No Answer
0
说明/提示
【输入输出样例 1 解释】
单词 error 中出现最多的字母 r 出现了 3 次，出现次数最少的字母出现了 1 次，3−1=2，2 是质数。
【输入输出样例 2 解释】
单词 `olympic` 中出现最多的字母 i 出现了 1 次，出现次数最少的字母出现了 1 次，1-1=0，0 不是质数。
//采用函数及bool，与书上不一样
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void zuida(char s[105]) {
    int ans[26] = {0}; // 初始化数组
    int mmax, mmin;
    for (int i = 0; i < strlen(s); i++) {
        ans[s[i] - 'a']++;
    }
    mmax = 0; mmin = 10000;
    for (int i = 0; i < 26; i++) {
        if (ans[i] > mmax)  mmax = ans[i];
        if (ans[i] != 0 && ans[i] < mmin)  mmin = ans[i];
    }

    int delta = mmax - mmin;

    if (is_prime(delta)) {
        printf("Lucky Word\n%d\n", delta);
    } else {
        printf("No Answer\n0\n");
    }
}

int main() {
    char s[105];
    cin >> s;
    zuida(s);

    return 0;
}

//6.4
题目描述
王老师正在教简单算术运算。细心的王老师收集了 i 道学生经常做错的口算题，并且想整理编写成一份练习。 编排这些题目是一件繁琐的事情，为此他想用计算机程序来提高工作效率。王老师希望尽量减少输入的工作量，比如 5+8 的算式最好只要输入 5 和 8，输出的结果要尽量详细以方便后期排版的使用，比如对于上述输入进行处理后输出 5+8=13 以及该算式的总长度 6。王老师把这个光荣的任务交给你，请你帮他编程实现以上功能。
输入格式
第一行一个整数 i。
接着的 i 行为需要输入的算式，每行可能有三个数据或两个数据。
若该行为三个数据则第一个数据表示运算类型，a 表示加法运算，b 表示减法运算，c 表示乘法运算，接着的两个数据表示参加运算的运算数。
若该行为两个数据，则表示本题的运算类型与上一题的运算类型相同，而这两个数据为运算数。
输出格式
输出 2×i 行。对于每个输入的算式，输出完整的运算式及结果，第二行输出该运算式的总长度。
输入输出样例
输入 #1
4
a 64 46
275 125
c 11 99
b 46 64
输出 #1
64+46=110
9
275+125=400
11
11*99=1089
10
46-64=-18
9
说明/提示
【数据规模与约定】
对于 50% 的数据，输入的算式都有三个数据，第一个算式一定有三个数据。
对于所有数据，0<i≤50，运算数为非负整数且小于 10000。
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n,a,b,c;
    char last,s[20],ans[20];
    scanf("%d\n",&n);
    while(n--){
        fgets(s,sizeof(s),stdin);
        if(s[0]=='a'||s[0]=='b'||s[0]=='c')
            last=s[0],s[0]=' ';
        sscanf(s,"%d %d",&a,&b);
        switch(last){
            case'a':c=a+b;sprintf(ans,"%d+%d=%d",a,b,c);  break;        
            case'b':c=a-b;sprintf(ans,"%d-%d=%d",a,b,c);  break;
            case'c':c=a*b;sprintf(ans,"%d*%d=%d",a,b,c);  break;
        }
        printf("%s\n%d\n",ans,strlen(ans));
    }
}
解释：--------------------------------------------------------------------------------------------------------------------
这段代码实现了一个简单的算术运算问题处理程序，通过不同的字母标识符来确定执行哪种运算，并输出运算结果和表达式的长度。我们逐步分析代码：
while (n--)：循环 n 次，每次处理一个测试用例。
fgets(s, sizeof(s), stdin);：读取一行输入到字符串 s 中。fgets 会读取整行输入，并包含换行符，直到读满 19 个字符或遇到换行符。
if (s[0] == 'a' || s[0] == 'b' || s[0] == 'c')：判断字符串 s 的第一个字符是 'a'、'b' 还是 'c'，这表示输入的是哪种运算（加、减、乘）。
last = s[0], s[0] = ' ';：将 s[0]（运算符）赋值给 last，然后把 s[0] 替换为空格，这样后续的 sscanf 可以正确地解析两个整数。
sscanf(s, "%d %d", &a, &b);：从字符串 s 中解析出两个整数 a 和 b。
switch (last)：根据 last 的值（即 'a'、'b' 或 'c'）来决定执行哪个运算。
case 'a'：如果 last 是 'a'（表示加法），执行加法 c = a + b，然后用 sprintf 格式化字符串 ans，表示加法公式和结果。
case 'b'：如果 last 是 'b'（表示减法），执行减法 c = a - b，同样格式化输出。
case 'c'：如果 last 是 'c'（表示乘法），执行乘法 c = a * b，并格式化输出。
printf("%s\n%d\n", ans, strlen(ans));：输出格式化后的字符串 ans，即运算表达式及其结果。接着，输出字符串 ans 的长度 strlen(ans)，即表达式的字符数。
总结：
这个程序的功能是根据输入的运算符和两个操作数，计算并输出相应的数学表达式和结果的长度。运算符通过 'a'、'b'、'c' 来区分，分别代表加法、减法和乘法。

知识：--------------------------------------------------------------------------------------------------------------------
使用fgets()函数读取一行字符串，空格也存下；gets()函数存在可能溢出风险所以不使用。
fgets(s,sizeof(s),stdin);指定了字符数组的最大读入数量，因此安全
sscanf()函数，从已经存储下来的字符串中读入信息。
sprintf()将信息输出到字符串中。

标准模板库（STL）：包含各类容器、算法和一些其他功能 
6.5使用string数据类型来处理字符串问题
//6.5
题目描述
凯凯刚写了一篇美妙的作文，请问这篇作文的标题中有多少个字符？ 注意：标题中可能包含大、小写英文字母、数字字符、空格和换行符。统计标题字符数时，空格和换行符不计算在内。
输入格式
输入文件只有一行，一个字符串 s。
输出格式
输出文件只有一行，包含一个整数，即作文标题的字符数（不含空格和换行符）。
输入输出样例
输入 #1
234 
输出 #1
3
输入 #2
Ca 45 
输出 #2
4
说明/提示
样例 1 说明
标题中共有 3 个字符，这 3 个字符都是数字字符。
样例 2 说明
标题中共有 5 个字符，包括 1 个大写英文字母， 1 个小写英文字母和 2 个数字字符， 还有 1 个空格。由于空格不计入结果中，故标题的有效字符数为 4 个。
数据规模与约定
规定 ∣s∣ 表示字符串 s 的长度（即字符串中的字符和空格数）。
对于 40% 的数据，1≤∣s∣≤5，保证输入为数字字符及行末换行符。
对于 80% 的数据，1≤∣s∣≤5，输入只可能包含大、小写英文字母、数字字符及行末换行符。
对于 100% 的数据，1≤∣s∣≤5，输入可能包含大、小写英文字母、数字字符、空格和行末换行符。

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    int ans=0;
    while(cin>>s)
        ans+=s.length();
    cout<<ans<<endl;
    return 0;
}
讲解：--------------------------------------------------------------------------------------------------------------------------------------------+
使用新的数据类型，string                                                                                                                           |
一个string类型的变量可以用来存储一个字符串，并且将这个字符当作一个整体进行处理————可以对string进行赋值、拼接、裁剪，而字符数组毕竟是个数组，做这些比较麻烦。  |
输入时使用cin语句，读入字符串                                                                                                                       |
注意：当发现读入文件读完后（遇到  EOF，标准输入可以按Ctrl+Z），cin>>s会返回0，中断while语句，结束读入。s可以看作加强版的字符数组。
可使用s.length()直接查询字符串s长度，也可以和字符数组一样使用s[0]来查询字符串最开头的字符是什么
最强大的地方：string类型的字符串可以直接赋值、拼接操作，eg：s=s+s将两个字符串s拼接在一起，结果赋值回s。

字符串string使用头文件string，包括以下常见用法：
1、string s：定义一个名字为s的字符串变量
2、s+=str或s.append(str)：在字符串s后面拼接字符串str
3、s<str：比较字符串s的字典序是否在字符串str的字典序之前
4、s.size()或s.length()：得到字符串s的长度
5、s.substr(pos,len)：截取字符串s，从第pos个位置开始len个字符，并返回这个字符串                                                                        
6、s.insert(pos,str)：在字符串s的第pos个字符之前，插入字符串str，并返回这个字符串                                                                      |
7、s.find(str,[pos])：在字符串s中从第pos个字符开始寻找str,并返回位置，如果找不到返回-1.pos可以省略，默认值是0                                            |
                      注意：使用find 函数查找子串但找不到时，会返回一个常数string::npos，但由于                                                        |
--------------------------------------------------------------------------------------------------------------------------------------------------+
//6.6
题目描述
你需要开发一款文字处理软件。最开始时输入一个字符串作为初始文档。可以认为文档开头是第 0 个字符。需要支持以下操作：
1 str：后接插入，在文档后面插入字符串 str，并输出文档的字符串；
2 a b：截取文档部分，只保留文档中从第 a 个字符起 b 个字符，并输出文档的字符串；
3 a str：插入片段，在文档中第a 个字符前面插入字符串 str，并输出文档的字符串；
4 str：查找子串，查找字符串 str 在文档中最先的位置并输出；如果找不到输出 −1。
为了简化问题，规定初始的文档和每次操作中的 str 都不含有空格或换行。最多会有 q 次操作。
输入格式
第一行输入一个正整数 q，表示操作次数。
第二行输入一个字符串 str，表示最开始的字符串。
第三行开始，往下 q 行，每行表示一个操作，操作如题目描述所示。
输出格式
一共输出 q 行。
对于每个操作 1,2,3，根据操作的要求输出一个字符串。
对于操作 4，根据操作的要求输出一个整数。
输入输出样例
输入 #1
4
ILove
1 Luogu
2 5 5
3 3 guGugu
4 gu
输出 #1
ILoveLuogu
Luogu
LuoguGugugu
3
说明/提示
数据1≤q≤100，开始的字符串长度 ≤100。

#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,opt,l,r;
    string s,a;
    cin>>n;
    cin>>s;
    while(n--){
        cin>>opt;
        if(opt==1){
            cin>>a;
            s.append(a);
            cout<<s<<endl;
        }else if(opt==2){
            cin>>l>>r;
            s=s.substr(l,r);
            cout<<s<<endl;
        }else if(opt==3){
            cin>>l>>a;
            s.insert(l,a);
            cout<<s<<endl;
        }else{
            cin>>a;
            cout<<(int)s.find(a)<<endl;
        }
    }
    return 0;
}
// 使用上面讲解时的代码

//6.7
题目描述
一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，有的还能统计出特定单词在文章中出现的次数。
现在，请你编程实现这一功能，具体要求是：给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。注意：匹配单词时，不区分大小写，但要求完全匹配，即给定单词必须与文章中的某一独立单词在不区分大小写的情况下完全相同（参见样例 1），如果给定单词仅是文章中某一单词的一部分则不算匹配（参见样例 2）。
输入格式
共 2 行。
第 1 行为一个字符串，其中只含字母，表示给定单词；
第 2 行为一个字符串，其中只可能包含字母和空格，表示给定的文章。
输出格式
一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，分别是单词在文章中出现的次数和第一次出现的位置（即在文章中第一次出现时，单词首字母在文章中的位置，位置从 0 开始）；如果单词在文章中没有出现，则直接输出一个整数 −1。
注意：空格占一个字母位
输入输出样例
输入 #1
To
to be or not to be is a question
输出 #1
2 0
输入 #2
to
Did the Ottoman Empire lose its power at that time
输出 #2
-1
说明/提示
数据范围
1≤ 第一行单词长度 ≤10。
1≤ 文章长度 ≤10^6。

#include<iostream>
#include<string>
using namespace std;
int main(){
    string word,s;
    getline(cin,word);
    getline(cin,s);
    for(int i=0;i<word.length();i++){
        if('A'<=word[i]&&word[i]<='Z'){
            word[i]+='a'-'A';
        }
    }
    for(int i=0;i<s.length();i++){
        if('A'<=s[i]&&s[i]<='Z'){
            s[i]+='a'-'A';
        }
    }
    
    word=' '+word+' ';
    s=' '+s+' ';

    if(s.find(word)==-1){
        cout<<-1<<endl;
    }else{
        int firstpos=s.find(word);
        int nextpos=s.find(word),cnt=0;
        while(nextpos!=-1){
            cnt++;
            nextpos=s.find(word,nextpos+1);
        }
        cout<<cnt<<" "<<firstpos<<endl;
    }
    return 0;
}
getline()函数：将完整一行的输入数据读入到字符串中，无论这一行是否有空格；使用方法：getline(cin,字符串名称),cin指输入流

文件操作与重定向
//6.8 问题同6.5，需要将输入输出方式“重定向”到文件输入输出中
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() {
  freopen("title.in","r",stdin);
  freopen("title.out","w",stdout);
    string s;
    int ans = 0;
    while (cin >> s)
        ans += s.length();
    cout << ans << endl;
    return 0;
}

