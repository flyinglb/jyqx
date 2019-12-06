// Room: /huanghe/shidong.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void init();
int do_insert(string);
void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����ɳĮ����Ȼ�γɵ�һ��ʯ�������й��߻谵����ȴʮ�ָ��
�������߼��ѵ��ݣ��ƺ��ǹ���˯��֮�ã��������������з·�������
ˮ��������һ�Ƿ���������ͷ��(skulls)��
LONG );
	set("exits", ([
		"out" : __DIR__"shamo1",
	]));
	set("item_desc", ([
		"skulls" : "һ���������������ͷ����һ�������壬���಻�٣�ǡ��
�ſŰ׹�����ͷ��\n",
	]));
	set("objects", ([
		__DIR__"npc/mei" :1,
		__DIR__"npc/chen" :1,
	]));
//	set("no_clean_up", 0);
	setup();
//      replace_program(ROOM);
}

void init()
{
        add_action("do_insert","insert");
}

int do_insert(string arg)
{
        object ob;
        int c_skill;
        int exp;

        if (arg != "skulls") return 0;
        ob = this_player();
        exp = ob->query("combat_exp");
        c_skill=(int)ob->query_skill("claw", 1);

        if (ob->query("qi")<120)
                return notify_fail("��̫���ˣ��޷��ٰ���ָ�������ͷ�ˡ�\n");
        if (c_skill< 200)
                return notify_fail("��צ����Ϊ���������޷�����ָ�������ȥ��\n");
        if (exp*10 <= (c_skill*c_skill*c_skill)) {
                ob->receive_damage("qi", 50);
                return notify_fail("��ľ��鲻������ָ�������Ҳûʲô�á�\n");
        }

        message_vision("$N��������צ״�����Ͻ���ָ���ز�����á�\n",ob);
        ob->improve_skill("claw", random(100*ob->query_int()));
        ob->receive_damage("qi", 100);
        return 1;
}


