// ce.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	object obj;

        if((time() - (int)me->query_temp("last_ce_time") < 4) && !wizardp(me)){
                write("�𼱣�ˢ�Լ��˵���Ҳ�����Եġ�\n");
                return 1;
        }

	if(!me->query("couple/have_couple")) return help(me);

	obj = find_player(me->query("couple/couple_id"));

	if(!obj || (!wizardp(me) && !me->visible(obj)))
		return notify_fail("��İ������ڲ���....\n");

	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("��İ������ڹ������������Ļ�....\n");

	if( !arg )
	{
//        if((string)me->query("gender") == "Ů��") 
	message_vision(MAG "\n$N��ô˼��"+me->query("couple/couple_gender")
		+me->query("couple/couple_name")+"�����������˺η���...\n"NOR, me);
//        else
//        message_vision(MAG "$N��ô˼������"+me->query("couple/couple_name")+"��...\n"NOR, me);

 tell_object(obj,sprintf(MAG"\n���"+obj->query("couple/couple_gender")+"��˼����... ...\n" NOR));
	}
	else
	switch (arg)
	{
		case "kiss":
			if( objectp(present(me->query("couple/couple_id"), environment(me))) )
				message_vision(MAG "\n$Nӵ����$n�����һ��...\n"NOR, me, obj);
			else
			{
				write(MAG "\n�����ӵ�����" + me->query("couple/couple_gender") + "�����һ��...\n" NOR);
				tell_object(obj, sprintf( MAG "\n���%s����ӵ���㣬���������һ��... ...\n" NOR,
					obj->query("couple/couple_gender")));
			}
			break;	
		case "bye":
			if( objectp(present(me->query("couple/couple_id"), environment(me))) )
				message_vision(MAG "\n$N����������$n�����ʵ�: ��Ҫ�ټ��ˣ���ʱ���ܳ���۲�����ѽ...\n"NOR, me, obj);
			else
			{
				if (me->query("gender")=="Ů��")
				{
				write(MAG "\n������ٶ࿴���"+me->query("couple/couple_gender")+"һ�ۣ�����֪������������һֱ�������...\n" NOR);
				tell_object(obj, sprintf( MAG "\n���%s�����ٶ࿴��һ�ۣ�ɽңˮ��������һֱ�ǹ���ģ���Ҫ�Լ����ذ�... ...\n" NOR,
					obj->query("couple/couple_gender")));
				}
				else
				{
				write(MAG "\n������ٶ࿴���"+me->query("couple/couple_gender")+"һ�ۣ�����֪������������һֱ�������...\n" NOR);
				tell_object(obj, sprintf( MAG "\n���%s�����ٶ࿴��һ�ۣ�ɽңˮ��������һֱ�ǹ���ģ���Ҫ�Լ����ذ�... ...\n" NOR,
					obj->query("couple/couple_gender")));
				}
			}
			break;
		default:
			write(MAG "�����ĸ������" + me->query("couple/couple_gender") + "��" + arg + "\n" NOR);
			tell_object(obj, sprintf( MAG "���%s���ĸ����㣺%s\n" NOR,
				obj->query("couple/couple_gender"), arg));
		        
		        if( !userp(me) || !me->query("channel_snooping") ) return 1;

                        message("channel:snp", HIB"��������"NOR+MAG+
                        me->query("name")+"("+me->query("id")+")"+"���ܵظ���"+obj->query("name")+"("+obj->query("id")+")��"+arg+"\n"NOR, users());

	}
        me->set_temp("last_ce_time",time());
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��ce [kiss|bye][<ѶϢ>]

����������ָ�����İ���˵���Ļ���

HELP
	);
	return 1;
}
