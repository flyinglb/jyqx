// pubu.c 
// shilling 97.2

inherit ROOM;

#include <ansi.h>
void create()
{
	set("short", "�ٲ�");
	set("long", @LONG
��������ˮ�����������¡¡�����糱ˮ����һ�㣬̧ͷһ����ֻ��һ
�����ٲ����������ӵ������Ӹ�����ֱк������������������Ԩ������������
��������ͷ��������
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"east" : "/d/huashan/sheshen",
	]));
	set("outdoors", "xiaoyao" );
	set("no_clean_up", 0);
	setup();
}
 
void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object ob;
	int new_gin;
	ob = this_player();
	new_gin = random( ob->query("max_gin")*3 );
	if ( new_gin > ob->query("gin") ) new_gin = ob->query("gin") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
		return notify_fail("����Ҫ������ɱ����ô�벻������\n");
	tell_object(ob, HIR"�㲻��˼��������һԾ�����������¡�������\n"NOR);
	message("vision", NOR"ֻ��" + ob->query("name") + "�����ң���������������֮�С�������\n"NOR, environment(ob), ob);
	if((random((int)ob->query("kar")) < 5 ) && ((int)ob->query_skill("dodge")<30) )
	{
		ob->die();
		return 1;
	}
	ob->add("gin", 0 - new_gin);
	ob->move(__DIR__"yanfeng");
	return 1;
}

