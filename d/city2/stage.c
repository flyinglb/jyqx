#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "Ϸ̨");
	set("long", @LONG
������Ϸ̨����Ȼ��ЩС�����Ǻܸɾ���һ��Ϸ�����ڱ��ݡ�
��һ̤��Ϸ̨���鲻�Խ��ؾͳ��������
LONG );
	set("exits", ([
		"down" : __DIR__"xiyuan",
	        "southdown":__DIR__"houtai",
	]));
	set("objects", ([
		"/d/city2/npc/xizi": 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
if(dir=="down")
{
message_vision(
"\n$Nһ�����գ�һҾ��������ƽ�ɣ���̨��Ծ����˫��أ��\n"+
"��ȭ�����������̬������������Ȳɡ�\n",this_player());
i=this_player()->query("meili");
if(i<20) 
{
i=i+10;
this_player()->set("meili",i);
message_vision(HIC "\n$N������ֵ����ˡ�\n" NOR,this_player());
}
}
this_player()->delete_temp("hastryup");
return ::valid_leave(me, dir);
}
