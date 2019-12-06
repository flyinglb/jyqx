// set.c
// modified by Eatdami@MX (10/05/2000)
 
#define MAX_ENV_VARS    20

#include <ansi.h>

inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
        int i;
        string term, *terms, *wiz_only,*valid_env;
        mixed data;
        string data0;
        mapping env;
 
        wiz_only = ({"invisibility", "immortal"});
        valid_env= ({"wimpy","brief","no_fight_msg","no_tell","no_teach",
                        "no_accept","public"});
 
        if( me != this_player(1) ) return 0;
 
        env = me->query("env");
 
        if( !arg || arg=="" ) {
                write("你目前设定的环境变数有：\n");
                if( !mapp(env) || !sizeof(env) )
                        write("\t没有设定任何环境变数。\n");
                else {
                        terms = keys(env);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-20s  %O\n", terms[i], env[terms[i]]);
                }
                return 1;
        }
 

        if( sscanf(arg, "%s %s", term, data)!=2 ) {
                term = arg;
                data = "YES";
        }
        
        if( term && term!="" ) {
                if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
                        return notify_fail("你设的环境变数太多了，请先用 unset 删掉几个吧。\n");
           data0 = data;        /* save string* data */
           sscanf(data, "%d", data);
//added by long,为了避免某些未知的bug
             if ( wiz_level(me)==0  && member_array(term,valid_env ) == -1) {
		log_file("set_error",sprintf("%s(%s) try set %s on %s.\n",me->query("name"),me->query("id"),term,ctime(time()))); 
                return notify_fail("请先用先用help settings看看你所能设定的环境变数。\n");
	}
           if((wiz_level(me) == 0) && (member_array(term, wiz_only) != -1))
              return notify_fail("只有巫师能用这个设定。\n");

           me->set("env/" + term, data);
         
          printf("设定环境变数：%s = %O%s\n", term, data,NOR);
           return 1;
        }
        return help();
}
 
int help()
{
        write(@TEXT
指令格式：set <变数名> [<变数值>]
 
这个指令让你设定一些环境变数，不加参数时会显示你目前设定的环境变数，不指定
变数值，则内定值为 "YES"。变数值若为字符串，可参照 nick 变化颜色.
for example : set msg_min, msg_mout, msg_home , etc.
 
取消变数设定请用 unset 指令。
 
至於有哪些环境变数可以设定，请见 help settings。
TEXT
        );
        return 1;
}
