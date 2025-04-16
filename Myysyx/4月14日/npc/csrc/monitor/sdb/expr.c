#include <isa.h>
#include <memory/paddr.h>
#include <regex.h>

/* 定义枚举类型，表示不同的token */
enum {
  TK_NOTYPE = 256,    //空白符（不需要存储的token）
  TK_EQ,              //等于运算符“==”
  TK_NUM,             //数字
  TK_PLUS,            //加号 "+"
  TK_MINUS,           //减号 "-"
  TK_STAR,            //乘号 "*"
  TK_SLASH,           //除号 "/"
  TK_LPAREN,          //左括号 "("
  TK_RPAREN,          //右括号 ")"
  TK_NEQ,             //不等于"!="
  TK_AND,             //逻辑与"&&"
  TK_LESS_EQ,         //小于等与“<=”
  DEREF,              //解引用
  TK_BITWISE_AND,     //按位与 "&"
  TK_BITWISE_OR,      //按位或 "|"
  TK_BITWISE_XOR,     //按位异或 "^"
  TK_BITWISE_NOT,     //按位取反 "~"
  TK_REG,             //输入寄存器名字，打印寄存器的值
  /* TODO: Add more token types 添加更多的token 类型 */

};

/* 定义正则表达式规则 */
static struct rule {
  const char *regex;  //正则表达式字符串
  int token_type;     //该正则表达式对应的token 类型
} rules[] = {

  /* TODO: Add more rules.添加更多规则
   * Pay attention to the precedence level of different rules.注意不同规则的优先级
   */

  {" +", TK_NOTYPE},            //spaces 匹配空格（一个或多个空格），不存储该token
  {"==", TK_EQ},                //equal 匹配等于运算符“==”
  {"!=", TK_NEQ},               //不等于“!=”
  {"&&", TK_AND},               //逻辑与“&&”
  {"0x[0-9a-fA-F]+", TK_NUM},   //匹配十六进制整数
  {"[0-9]+", TK_NUM},           //匹配十进制整数
  {"\\$[a-zA-Z0-9]+", TK_REG},  //寄存器名称
  {"\\(", TK_LPAREN},           //左括号 "("
  {"\\)", TK_RPAREN},           //右括号 ")"
  {"\\*", TK_STAR},             //乘号 "*"(解引用)
  {"/", TK_SLASH},              //除号 "/"
  {"\\+", TK_PLUS},             //plus 匹配加号 “+”,这原来是直接{"\\+", '+'}
  {"-", TK_MINUS},              //减号 "-"
  {"<=", TK_LESS_EQ},           //小于等于
  {"&", TK_BITWISE_AND},        //按位与 "&"
  {"\\^", TK_BITWISE_XOR},      //按位异或 "^"
  {"\\|", TK_BITWISE_OR},       //按位或 "|"
  {"~", TK_BITWISE_NOT},        //按位取反 "~"
};

/* 计算规则数据的长度 */
#define NR_REGEX ARRLEN(rules)

/* 用于存储编译后的正则表达式 */
static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.由于规则会被多次使用
 * Therefore we compile them only once before any usage.因此我们只在初始化时编译一次正则表达式
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);  //编译正则表达式
    if (ret != 0) {                                       //如果编译失败，打印错误信息并终止程序
      regerror(ret, &re[i], error_msg, 128);
    #if CONFIG_CN
      printf("正则表达式编译失败: %s\n%s\n", error_msg, rules[i].regex);
    #else
      printf("regex compilation failed: %s\n%s\n", error_msg, rules[i].regex);
    #endif
    }
  }
}

/* 定义token结构体*/
typedef struct token {
  int type;     //token类型
  char str[32]; //存储token的字符串值（如果需要的话）
} Token;

/* 用于存储解析出来的token*/
static Token tokens[1024] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;//记录解析出的token数量

/* 词法分析函数，将输入的表达式e解析成token */
static bool make_token(char *e) {
    int position = 0;   //当前处理的位置
    int i;
    regmatch_t pmatch;  //存储regexec()函数的匹配结果

    nr_token = 0;       //解析出的token数量清零

    while (e[position] != '\0') { //遍历整个输入的字符串
    /* Try all rules one by one. 依次尝试所有的规则 */
    for (i = 0; i < NR_REGEX; i ++) {

      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        //regexec() 返回 0 表示匹配成功，且匹配必须从当前位置开始
        char *substr_start = e + position;  //记录匹配子串的起始位置
        int substr_len = pmatch.rm_eo;      //记录匹配子串的长度

      #if CONFIG_CN
        Log("匹配规则[%d] = \"%s\"，位置 %d,长度 %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);
      #else
        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);
      #endif

        position += substr_len; //移动解析位置

        /* TODO: Now a new token is recognized with rules[i]. Add codes现在已经识别出 rules[i] 规则对应的 token，
         * to record the token in the array `tokens'. For certain types需要将其存入 tokens 数组。
         * of tokens, some extra actions should be performed.对于某些特殊类型的 token 可能还需要额外处理。
         */

        switch (rules[i].token_type) {
          case TK_NOTYPE:
            //空格不需要记录，直接跳过
            break;
          case TK_NUM:
            //检查前缀
            if (substr_len > 2 && substr_start[0] == '0' && substr_start[1] == 'x') {
              unsigned int val;
              sscanf(substr_start, "0x%x", &val); //接收到的字符串类型转为unsigned int的十六进制
              snprintf(tokens[nr_token].str, sizeof(tokens[nr_token].str), "%d", val);//再将十六进制数转为十进制数
              tokens[nr_token].type = TK_NUM;
              nr_token++;
            } else {
              strncpy(tokens[nr_token].str, substr_start, substr_len);
              tokens[nr_token].str[substr_len] = '\0';//确保字符串结尾
              tokens[nr_token].type = TK_NUM;
              nr_token++;
            }
            break;

          case TK_REG:
            //处理寄存器名称
            if (substr_len <= 16) {
              strncpy(tokens[nr_token].str, substr_start, substr_len);
              tokens[nr_token].str[substr_len] = '\0';
              const char* reg_name = tokens[nr_token].str;
              
              bool success = false;
              uint32_t reg_val = isa_reg_str2val(reg_name, &success);

              if (success) {
                //如果找到了寄存器
                snprintf(tokens[nr_token].str, sizeof(tokens[nr_token].str), "%d", reg_val);
                tokens[nr_token].type = TK_NUM;
                nr_token++;
              } else {
                //没找到，表示无效
              #if CONFIG_CN
                printf("错误: 未知寄存器 %s\n", tokens[nr_token].str);
              #else
                printf("Error: Unknown register %s\n", tokens[nr_token].str);
              #endif
              }
            }
            break;

          case TK_STAR:
            if (nr_token == 0 || 
                tokens[nr_token - 1].type == TK_LPAREN || 
                tokens[nr_token - 1].type == TK_PLUS || 
                tokens[nr_token - 1].type == TK_MINUS || 
                tokens[nr_token - 1].type == TK_STAR || 
                tokens[nr_token - 1].type == TK_SLASH || 
                tokens[nr_token - 1].type == TK_EQ ||
                tokens[nr_token - 1].type == TK_NEQ || 
                tokens[nr_token - 1].type == TK_LESS_EQ || 
                tokens[nr_token - 1].type == TK_AND) {
              assert(nr_token < sizeof(tokens) / sizeof(tokens[0]));//确保数组不越界
              tokens[nr_token].type = DEREF;
              tokens[nr_token].str[0] = '*';
              tokens[nr_token].str[1] = '\0';  // 确保以 '\0' 结尾
              nr_token++;
            break;
          } else {
            assert(nr_token < sizeof(tokens) / sizeof(tokens[0]));//确保数组不越界
            tokens[nr_token].type = TK_STAR;
            tokens[nr_token].str[0] = '*';
            tokens[nr_token].str[1] = '\0';  // 确保以 '\0' 结尾
          }
            nr_token++;
            break;
          case TK_LPAREN:
          case TK_RPAREN:
          case TK_SLASH:
          case TK_PLUS:
          case TK_MINUS:
          case TK_EQ:
          case TK_NEQ:
          case TK_LESS_EQ:
          case TK_BITWISE_AND:
          case TK_BITWISE_OR:
          case TK_BITWISE_XOR:
          case TK_BITWISE_NOT:
            assert(nr_token < sizeof(tokens) / sizeof(tokens[0]));//确保数组不越界
            tokens[nr_token].type = rules[i].token_type;        //对于运算符和括号，直接记录其类型
            nr_token++;
            break;
          default:
          #if CONFIG_CN
            printf("遇到未知token类型: %d\n", rules[i].token_type);
          #else
            printf("Unknown token type: %d\n", rules[i].token_type);//未知类型
          #endif
        }
        break;
      }
    }

    if (i == NR_REGEX) {        //没有任何规则匹配
    #if CONFIG_CN
      printf("在位置 %d 没有匹配项\n%s\n%*.s^\n", position, e, position, "");
    #else
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
    #endif
      return false;             //词法分析失败
    }
  }

  return true;                  //词法分析成功
}

/* 运算符优先级函数*/
static int priority(int op) {
  switch (op)
  {
    case TK_BITWISE_NOT: return 7; //按位非
    case DEREF:
    case TK_STAR:
    case TK_SLASH:       return 6; //解引用，乘除
    case TK_PLUS:
    case TK_MINUS:       return 5; //加减
    case TK_LESS_EQ:     return 4; //小于等于
    case TK_EQ:
    case TK_NEQ:         return 3; //==，!=
    case TK_AND:         return 2; //逻辑与&&
    case TK_BITWISE_AND: return 1; //按位与
    case TK_BITWISE_XOR: return 1; //按位异或
    case TK_BITWISE_OR:  return 1; //按位或
    default: return 0;
  }
}

/* 辅助计算函数*/
static int compute(int a, int b, int op) {
  switch (op) {
    case TK_PLUS:        return a + b;  //加法
    case TK_MINUS:       return a - b;  //减法
    case TK_STAR:        return a * b;  //乘法
    case TK_SLASH:                      //除法
      if (b == 0) {                     //检查除数是否为0
      #if CONFIG_CN
        printf("Error:被除数不能为零!");
      #else
        printf("Error: Division by zero!\n");
      #endif
        exit(1);                        //除数为0退出程序
      }
      return a / b;
    case TK_EQ:          return a == b; //等于
    case TK_NEQ:         return a != b; //不等于
    case TK_LESS_EQ:     return a <= b; //小于等于
    case TK_AND:         return a && b; //逻辑与
    case DEREF: {
        if (a == 0) {  // 防止解引用空指针
        #if CONFIG_CN
            printf("Error: 空指针解引用！\n");
        #else
            printf("Error: Null pointer dereference!\n");
        #endif
        
            return 0;
        }
        uint32_t value = paddr_read(a, sizeof(word_t));
                         return value;  //解引用
    }
    case TK_BITWISE_AND:  return a & b; //按位与
    case TK_BITWISE_OR:   return a | b; //按位或
    case TK_BITWISE_XOR:  return a ^ b; //按位异或
    case TK_BITWISE_NOT:     return ~a; //按位取反

    default:
    #if CONFIG_CN
      printf("Error: 遇到未知运算符 %d\n", op);
    #else
      printf("Error: Unknown oprator %d\n", op);
    #endif
      exit(1);
  }
}

/* 计算表达式的值 */
uint32_t expr(char *e, bool *success) {
  if (e == NULL) {
    *success = false;
    return 0;
  }

  if (!make_token(e)) {         //先进行词法分析
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression.在这里插入代码来计算表达式的值 */
  //使用栈来进行运算
  int op_stack[1024];              //运算符栈
  int num_stack[1024];             //操作数栈
  int op_top = -1, num_top = -1;   //栈顶指针

  for (int i = 0; i < nr_token; i++){
    Token t = tokens[i];           //获取当前token
    // printf("当前token %s\n", t.str); //打印当前token

    //如果当前是数字
    if (t.type == TK_NUM) {         
      sscanf(t.str, "%d", &num_stack[++num_top]);//将数字字符串转换为整数并压入操作数栈
      // printf("将数字 %d 推入栈 num_stack\n", num_stack[num_top]);
    }

    //处理左括号
    else if (t.type == TK_LPAREN) { 
      op_stack[++op_top] = t.type;  //直接将左括号压入运算符栈
      // printf("将左括号'('推入栈op_stack\n");
    }

    //遇到右括号
    else if (t.type == TK_RPAREN) { 
      // printf("遇到了右括号')'\n");
      //弹出并计算，直到左括号
      while (op_top >= 0 && op_stack[op_top] != TK_LPAREN) {
        int op = op_stack[op_top--];
        // printf("从栈op_stack中弹出运算符 %d\n", op);

        //检查是否是一元运算符
        if (op == DEREF || op == TK_BITWISE_NOT) {
          if (num_top < 0) { *success = false; return 0; }
          int a = num_stack[num_top--];
          num_stack[++num_top] = compute(a, 0, op);
          // printf("计算一元运算符，被计算数是 %d, 计算结果为 %d, 并推入num_stack\n", a, num_stack[num_top]);
        }

        //否则，进行二元运算符操作
        else {
          if (num_top < 1) { *success = false; return 0; }
          int b = num_stack[num_top--];
          int a = num_stack[num_top--];
          num_stack[++num_top] = compute(a, b, op); //计算结果压入操作数栈
          // printf("计算二元运算符，计算数分别是 %d 和 %d , 计算结果为 %d, 并推入num_stack\n", a, b, num_stack[num_top]);
        }
      }
      op_top--;    //弹出左括号
      // printf("从栈op_stack弹出左括号'('\n");
    }

    //处理运算符
    else {                          
      while (op_top >= 0 && priority(op_stack[op_top]) >= priority(t.type)) {
        int op = op_stack[op_top--];
        // printf("由于优先级原因，从 op_stack 弹出运算符 %d\n", op);

        //一元运算符处理
        if (op == DEREF || op == TK_BITWISE_NOT) {
          if (num_top < 0) { *success = false; return 0; }
          int a = num_stack[num_top--];
          num_stack[++num_top] = compute(a, 0, op);
          // printf("计算一元运算符，被计算数是 %d, 计算结果为 %d, 并推入num_stack\n", a, num_stack[num_top]);
        }

        //二元运算符处理
        else {
          if (num_top < 1) { *success = false; return 0; }
          int b = num_stack[num_top--];
          int a = num_stack[num_top--];
          num_stack[++num_top] = compute(a, b, op);
          // printf("计算二元运算符，计算数分别是 %d 和 %d , 计算结果为 %d, 并推入num_stack\n", a, b, num_stack[num_top]);
        }         
    }
    op_stack[++op_top] = t.type;    //当前运算符入栈
    // printf("将运算符 %d 推入栈 op_stack\n", t.type);
  }
  }

  //当前token中的运算符没有了，处理栈内剩余的运算符
  while (op_top >= 0) {
    int op = op_stack[op_top--];
    // printf("从 op_stack 中弹出运算符 %d 以进行最终计算\n", op);
    //一元运算符处理
    if (op == DEREF || op == TK_BITWISE_NOT) {
      if (num_top < 0) { *success = false; return 0; }
      int a = num_stack[num_top--];
      num_stack[++num_top] = compute(a, 0, op);
      // printf("计算一元运算符，被计算数是 %d, 计算结果为 %d\n, 并推入num_stack", a, num_stack[num_top]);
    } 

    //二元运算符处理
    else {
      if (num_top < 1) { *success = false; return 0; }
      int b = num_stack[num_top--];
      int a = num_stack[num_top--];
      num_stack[++num_top] = compute(a, b, op);
      // printf("计算二元运算符，计算数分别是 %d 和 %d , 计算结果为 %d, 并推入num_stack\n", a, b, num_stack[num_top]);
    }
    
  }

  //栈中只有一个最终结果
  if (num_top != 0) { *success = false; return 0; }
  *success = true;
  // printf("最终计算结果为 %d\n", num_stack[num_top]);
  return num_stack[num_top];  //返回计算结果
}
