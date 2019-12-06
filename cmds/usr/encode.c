#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string code="国标(GB)";
        int suc=0;
        if(arg && arg != ""){
                arg = lower_case(arg);
                switch(arg)
                {
                case "gb": me->set_encoding(0);suc=1;code="国标(GB)";break;
                case "big5": me->set_encoding(1);suc=1;code="大五码(BIG5)";break;
                default: break;
                }
        }
        if(!suc && me->query_encoding() == 1) code = "大五码(BIG5)";
        printf("你现在使用的内码为：%s。\n",code);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : code [GB|BIG5]

这个指令可以使你在本泥潭中随时切换中文的内码格式，使之支持GB(国标码)
和BIG5(大五码)。
HELP
    );
    return 1;
}
