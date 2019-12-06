            // say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if((time() - (int)me->query_temp("last_say_time") < 4) && !wizardp(me)){
                write("�𼱣��л�����˵!\n");
                return 1;
        }

        if (!arg) {
                        write("���������ﲻ֪����˵Щʲô��\n");
                        message("sound",WHT + me->name() + "�������ﲻ֪����˵Щʲô��\n" NOR,
                        environment(me), me);
                        return 1;
        }
        
        if( (int)me->query("qi") < (int)me->query("max_qi") / 5 ) {
                arg = replace_string(arg, " ", " ... ") + " ...";
        }

        write( HIG "��"+ NOR + YEL +"˵����"+ WHT + arg + "\n" NOR);
        message("sound", HIG + me->name() + NOR + YEL +"˵����"+ WHT +  arg + "\n" NOR,
                environment(me), me);
        if( !userp(me) || !(int)me->query("channel_snooping") ) return 1;

message("channel:snp", HIB"��������"NOR+WHT+me->query("name")+"("+me->query("id")+")˵����"+arg+"\n"NOR, users());

        // The mudlib interface of say
        all_inventory(environment(me))->relay_say(me, arg);
        me->set_temp("last_say_time",time());
        return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: say <ѶϢ>
 
˵�������и�����ͬһ��������˶���������˵�Ļ���
 
ע: ��ָ����� ' ȡ��.
 
HELP
        );
        return 1;
}
