//Room: /d/dali/hongsheng2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ʥ����");
	set("long",@LONG
�����Ǻ�ʥ�����ڲ�������ǽ���϶����з��裬�����÷���
̧ͷ���������Կ�������������«����ɡ�ǡ����ּ��������еȡ�
ɡ�ǳɰ˽��Σ����Ϲ��з��졣
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "down"   : __DIR__"hongsheng1",
	    "up"     : __DIR__"hongsheng3",
	]));
	set("no_clean_up", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	if (dir == "up" )
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		me->add("qi", -20);
		if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
		tell_object(me,"������һ��¥����Щ���ˡ�\n");
	}
	return 1;
}
