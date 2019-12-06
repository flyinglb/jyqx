            // say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if((time() - (int)me->query_temp("last_say_time") < 4) && !wizardp(me)){
                write("别急，有话慢慢说!\n");
                return 1;
        }

        if (!arg) {
                        write("你自言自语不知道在说些什么。\n");
                        message("sound",WHT + me->name() + "自言自语不知道在说些什么。\n" NOR,
                        environment(me), me);
                        return 1;
        }
        
        if( (int)me->query("qi") < (int)me->query("max_qi") / 5 ) {
                arg = replace_string(arg, " ", " ... ") + " ...";
        }

        write( HIG "你"+ NOR + YEL +"说道："+ WHT + arg + "\n" NOR);
        message("sound", HIG + me->name() + NOR + YEL +"说道："+ WHT +  arg + "\n" NOR,
                environment(me), me);
        if( !userp(me) || !(int)me->query("channel_snooping") ) return 1;

message("channel:snp", HIB"【窃听】"NOR+WHT+me->query("name")+"("+me->query("id")+")说道："+arg+"\n"NOR, users());

        // The mudlib interface of say
        all_inventory(environment(me))->relay_say(me, arg);
        me->set_temp("last_say_time",time());
        return 1;
}

int help (object me)
{
        write(@HELP
指令格式: say <讯息>
 
说话，所有跟你在同一个房间的人都会听到你说的话。
 
注: 本指令可用 ' 取代.
 
HELP
        );
        return 1;
}
