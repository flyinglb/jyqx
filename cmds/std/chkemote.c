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
                printf("���������ڹؼ��ֲ�ѯsemote  ���� chkemote �Ϲ�\n");
        }
    else
        {
                e = sort_array(EMOTE_D->query_all_emote(), 1);
        result = "  ���    ����            ����\n" +
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
        if(result=="") result +="û����������Ĺؼ�����ƥ���emote.";
                result += "\n-------------------------------------\n";
            me->start_more(result);
            return 1;
        }
    return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : chkemote <�ؼ���>

 �г�Ŀǰ���к�ָ���ؼ��ֵ�emote.


HELP
    );
    return 1;
}
