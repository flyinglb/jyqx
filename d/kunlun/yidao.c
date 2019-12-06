//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ĵ���");
	set("long", @LONG
������ʥ�����־�����������¾�ʣ��һ�Ž����ˣ�������������������
�������̾Ϳɿ�һ�ߡ�����(qipan)�ϻ����Ų�֪�ǲ��Ǻ�����Լ����Լ���
��һ��û������塣
LONG );
	set("exits", ([
		"east"  : __DIR__"sanshengju",
	]));
	set("item_desc", ([
		"qipan" : "����һ����û����������������(xiaqi)��\n",
	]));
	setup();
}
void init()
{
	add_action("do_xiaqi","xiaqi");
}
int do_xiaqi(object me)
{
	int skl;
	me = this_player();
	skl = (int)me->query_skill("chess",1);
	if (me->query("jing")<70)
		return notify_fail("��̫���ˣ��޷����о������塣\n");
	if (skl < 40)
		return notify_fail("������ջ��������޷����������ľ��硣\n");
	if (skl > 150)
		return notify_fail("���Ѿ��޷�����������ѧ��ʲô�ˡ�\n");
	if(time() - (int)me->query_temp("last_chess_time") < (3 - random(2)))
		return notify_fail("����һ����û�ºã��������һ���ˣ�\n");
	message_vision("$Nڤ˼���룬��������һ���壬��Χ�������˸���̵���ᡣ\n", me);
	me->set_temp("last_chess_time",time());
	me->improve_skill("chess", random(50 * me->query_int()));
	me->receive_damage("jing", 50);
	return 1;
}
