//Room: /d/dali/hongsheng1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
��ʥ��������ϵ��ʯ�����ɣ���ǧѰ����Ϊש����ͬ��������
�������ţ��������ʵǶ��ϡ�
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "out"    : __DIR__"hongsheng",
	    "up"     : __DIR__"hongsheng2",
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
