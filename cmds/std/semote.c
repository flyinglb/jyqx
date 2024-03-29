// semote.c
// modified by ytan Dec 18 1996
// modified by edd Dec 6 1998
#include "/doc/help.h"
 
inherit F_CLEAN_UP;

int all_emote(object me); 
int chkemote(object me,string arg);
int femote(object me,string arg);
int help(object me);
int show(object me,string str,string arg,int count); 
int flag = 1;

int main(object me, string arg)
{
    if( !arg ) return all_emote(me);
    return chkemote(me,arg);
}

int all_emote(object me) 
{
    string *e;
    int i;
    string str1,str;
 
    str="";
    e = sort_array(EMOTE_D->query_all_emote(), 1);
 
    for(i=0; i<sizeof(e); i++) {
        str1=sprintf("%-15s%s", e[i], (i%5==4)?"\n": "");
        str+=str1;
    }
    me->start_more(str);
    write("\n");
    return 1;
}

int chkemote(object me,string arg)
{
    mapping emote;
    string str,*e,str1;
    int i,count;
    count = 0;        
    emote = EMOTE_D->query_emote(arg);
    e = sort_array(EMOTE_D->query_all_emote(), 1);
    str="";

    if ( !arg ) {
        for(i=0; i<sizeof(e); i++) {
            str1=sprintf("%s%s\n%s\n","emote名称：",e[i],EMOTE_D->query_emote(e[i])["others_target"] );
            str+=str1;
        }
    } else {
        for(i=0; i<sizeof(e); i++) {
            if ( arg==e[i] ) {
                str=sprintf("%s%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
                "emote名称：",e[i],
                emote["myself"], emote["others"], emote["myself_self"],
                emote["others_self"], emote["myself_target"], emote["target"],
                emote["others_target"] );
                count ++;
                break;
            }
            if (arg==e[i][0..sizeof(arg)-1]) {
                str1=sprintf("%s%s\n%s%s\n","emote名称：",e[i],"内容：",EMOTE_D->query_emote(e[i])["others_target"] );
                str+=str1;
                count ++;
            }
        }
    } 
        if (str=="") return femote(me,arg);
        else {
            flag = 1;
            return show(me,str,arg,count);
        }
}

int femote(object me,string arg)
{
    mapping emote;
    string *e, *loop;
    string str="", msg;
    int i,count,k;
    count = 0;

    loop = ({ "others_target", "others_self", "others" });

    e = sort_array( EMOTE_D->query_all_emote(), 1);

    for(i=0; i<sizeof(e); i++) {
        emote = EMOTE_D->query_emote(e[i]);
            for( int j=0; j<sizeof(loop); j++ ) {
                msg = emote[ loop[j] ];
                    if( msg && strsrch(msg, arg) != -1 ) {
                        str += sprintf("emote 名: %s\n动作: %s\n", e[i], msg);
                        k ++;
                    }
            }
        if( k ) count ++;
        k = 0;
    }

    if(  str == "" )
        return notify_fail(MUD_NAME" 中无符合查询条件的 emote.\n");
    else {
        flag = 0;
        return show(me,str,arg,count);
    }
}

int show(object me,string str,string arg,int count)

{
    str =
    "\n查询结果"
    "\n---------------------------------------------------------------\n"
    + str;
    str = replace_string(str, "$n", "(对方)");
    str = replace_string(str, "$N", me->name(1));
    str = replace_string(str, "$P", "你");
    str = replace_string(str, "$p", "(他/她)");
    str = replace_string(str, "$S", RANK_D->query_self(me));
    str = replace_string(str, "$s", RANK_D->query_self_rude(me));
    str = replace_string(str, "$R", "(对方的尊称)");
    str = replace_string(str, "$r", "(对方的辱称)");
    str = replace_string(str, "$C", "(自己的呢称)");
    str = replace_string(str, "$c", "(对方的呢称)");

    str += "---------------------------------------------------------------\n";
    flag?
    str += sprintf("在%s中，以“%s”开头的 emote 共有 %d 个。\n",
                                    MUD_NAME, arg, count ):
    str += sprintf("在%s中，包含“%s”的 emote 共有 %d 个。\n",
                                    MUD_NAME, arg, count );
    me->start_more(str);
    return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : semote [(任意的中英文)]
这个指令不加参数的时候可以列出目前所能使用的emote。
加上参数后，可以搜索以参数为开头的emote，或者包含有
参数的emote。
HELP
    );
    return 1;
}
