// jiasi.c

#include <ansi.h>
//inherit F_CLEAN_UP;
void remove_jiasi(object me, int wimpy);

int main(object me, string arg)
{
	int wimpy;
//	if(me->query("class") != "bandit")
//		return notify_fail("�������ɵ��˲�����װ����\n");
        seteuid(getuid());
        if( !me->is_fighting() )
                return notify_fail("�㲻��ս���У�����Ҫ��װ����\n");
	wimpy = (int)me->query("env/wimpy");
	message_vision("$N�ҽ�һ����һͷ�Ե��ڵ��¡�\n$N���ˡ�\n",me);
	me->set_temp("disable_inputs",1);
	me->set_temp("block_msg/all",1);
	me->disable_player(HIG "<������>" NOR);
        me->remove_all_killer();
	me->remove_all_enemy();
	me->delete("env/wimpy");
//        me->start_call_out( (: call_other, __FILE__, "remove_jiasi", me, wimpy :), random(30)+10);
        call_out("remove_jiasi", random(30)+10, me, wimpy);
	return 1;
}

void remove_jiasi(object me, int wimpy)
{
        object env;
	me->delete_temp("disable_inputs");
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        env = environment(me);
        me->move(VOID_OB,1);
        me->move(env,1);
	me->enable_player();
	me->delete_temp("block_msg/all");
	me->set("env/wimpy",wimpy);
   	message_vision("$N�ڵ������ĵط��˸���С��������������ۡ�\n",me);
//        me->move(environment(me),1);

}

int help(object me)
{
        write(@HELP
ָ���ʽ : jiasi
������ս����װ�������������Ļ��ᡣ
�������ɵ��˲�����װ����

HELP
        );
        return 1;
}
 
