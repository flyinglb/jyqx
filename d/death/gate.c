// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "���Ź�" NOR);
	set("long", 
		"�������������������ڡ����Źء���������ǰ������һ���ߴ��\n"
                "��ɫ��¥������������޿�������ж�ǰ������Ϊһ�����Źؾ��޷���\n"
		"�������ˡ�\n");
	set("exits", ([
                  "north" : "/d/death/gateway",
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle":1
	]) );
//	set("no_clean_up", 0);
	set("no_fight", "1");
	set("no_sleep_room", "1");
	set("no_steal", "1");

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if( dir=="north" && !wizardp(me) )
		return notify_fail("�ǿ���ͨ���·ѽ�������в�����û���߹�ȥ��\n");
	return ::valid_leave(me, dir);
}

int init()
{
        object *invs = all_inventory(this_object());
        int i,i1;
        for(i=0,i1=sizeof(invs);i<i1;i++) {
//                if( invs[i]->is_character() ) continue;
                if( userp(invs[i]) ) continue;
                if( invs[i]->query("id") == "white gargoyle" ) continue;
                invs[i]->move(VOID_OB);
                destruct(invs[i]);
        }
}

