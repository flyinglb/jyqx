// kill.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
//        string *killer, callname;
        string callname;

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼ս����\n");

	if( !arg )
		return notify_fail("����ɱ˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(obj==me)
		return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

	if((int)obj->query("age") <= 15 && userp(obj))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");

        if (me->query_enemy_cnt()>=5) 
           return notify_fail("����ô���˶�ɱ������ѽ������\n");

	callname = RANK_D->query_rude(obj);

	if (random(3) > 1)
	message_vision("\n$N����$n�ȵ�����" 
		+ callname + "�����ղ������������һ��\n\n", me, obj);
	else
	message_vision("\n$N����$n�ȵ�����" 
		+ callname + "��������վ�����ļ��գ���\n\n", me, obj);

      me->set("killing",1);
         me->kill_ob(obj);
	// Add by jungu             
	if ( userp(obj))
//Modify by Byp@MX
/*
        write_file("/log/static/ATTEMP_KILL",sprintf("%s   ��ͼɱ��   %s on %s\n",
        me->name(1),obj->name(1),ctime(time()) ));
*/
        write_file("/log/static/ATTEMP_KILL",sprintf("%s(%s)��ͼɱ��%s(%s) on %s\n",
        me->name(1),me->query("id"),obj->name(1),obj->query("id"),ctime(time()) ));
//end
	// Look for PKS 
	if( !userp(obj) )
		obj->kill_ob(me);
	else {
		obj->fight_ob(me);
		tell_object(obj, HIR "�����Ҫ��" + me->name() 
			+ "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
	}

	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ�����������ͼɱ���Է���kill �� fight ����
��ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��

�������ָ��: hit, fight

�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 
