// chkemote.c
// modified by wind

#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
mapping emote;
        string *e;
    string result,msg;
    int i;
    if( !arg )
        {
                printf("此命令用于关键字查询semote  例如 chkemote 鞠躬\n");
        }
    else
        {
                e = sort_array(EMOTE_D->query_all_emote(), 1);
        result = "  序号    名称            内容\n" +
                                 "-------------------------------------\n";
            for(i=0; i<sizeof(e); i++)
                {
                        emote = EMOTE_D->query_emote(e[i]);
            msg="";
            msg=msg+emote["others_target"];
            if(strsrch(msg, arg) >=0)
            {
                                result = result + sprintf("[%4d] %-13s: %s", i,e[i],msg);
                continue;
                        }
            msg="";
            msg=msg+emote["others_self"];
            if(strsrch(msg, arg) >=0)
            {
                                result = result + sprintf("[%4d] %-13s: %s", i,e[i],msg);
                continue;
            }
            msg="";
            msg=msg+emote["others"];
            if(strsrch(msg, arg) >=0)
            {
                                result = result + sprintf("[%4d] %-13s: %s", i,e[i],msg);
                continue;
            }
                }
        if(result=="") result +="没有与您输入的关键字相匹配的emote.";
                result += "\n-------------------------------------\n";
            me->start_more(result);
            return 1;
        }
    return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : chkemote <关键字>

 列出目前所有含指定关键字的emote.


HELP
    );
    return 1;
}
