inherit ROOM;

void create()
{
	set("short", "���߽�ʯ");
	set("long", @LONG
����һƬ�տ��ĺ�̲��ȴ�����������͵Ľ�ʯ(jiaoshi)������䣬���ǻ�
�ڽ�ʯǰ�ĺ�̲�ϣ�����������û�п�����(tiao)������Ƭ��ʯ��
LONG
	);
	set("outdoors","taohua");
	set("exits", ([
		"west" : __DIR__"haitan",
	]));
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_tiao", "tiao");
}

int do_tiao(string arg)
{
//	object weapon;
	object me=this_player();
	int dodgeskill=(int)me->query_skill("dodge", 1);
	int exp=(int)me->query("combat_exp");
 
	if( !arg || arg != "jiaoshi")
		return notify_fail("�����������\n");
	if( me->query("qi") < (int)(me->query("max_qi")/5))
		return notify_fail("������ȥ��������ģ�\n");
	else
	{
	message_vision("$N���������ڽ�ʯ���ݺ����ζ�����\n", me);
	if (exp*10 <= (dodgeskill*dodgeskill*dodgeskill))
		{
			me->receive_damage("qi", 30);
			return notify_fail("��ľ��鲻��������ԾҲ�������ʲô�ˡ�\n");
		}
		if (dodgeskill<(int)me->query_skill("literate",1))
		{
			me->improve_skill("dodge", random((int)(me->query("int")
				+me->query_skill("dodge")*2)));
			tell_object(me, "����������һЩ�Ṧ��������š�\n");
		}
		else
		{
			tell_object(me, "����˰��쾢������ʲôҲû��ѧ����\n");
		}
	}
	me->receive_damage("qi", 50);
	return 1;
}

