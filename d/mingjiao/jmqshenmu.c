//JMQJIGUAN.C

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��ľ����ľ");
	set("long", @LONG

����ǰֻ��һ�ô��������а��ɣ�ʮ��Ҳ������ס�������о��ڶ�
����֦Ҷ��ï�����ܻ��ƣ���Ȼ�޷�һ��ȫò��������һ���⻬��
�ȣ��ǳ�����Ħ�����ɡ�
LONG );
	set("exits", ([
		"east" : __DIR__"jmqshulin6",
        ])); 
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_climb", "climb");
}
int do_climb()
{
        object me=this_player();
        mapping mypar = (mapping) me->query("party");
        me->receive_damage("qi",15);
        me->receive_wound("qi",15);
        if(!mypar || mypar["party_name"] != HIG "����" NOR) 
             return notify_fail("��Ŭ��������ȥ, ��������ʵ��̫�⻬..\n"); 
        
	message_vision(HIC"$N�������¾�˳����������ȥ...\n"NOR, me);
	me->move(__DIR__"jmqdating");
	tell_object(me, HIC"�������˾�ľ�������\n"NOR);
	message("vision", HIC"ֻ��"+me->query("name")+"˳������������������ǽ��ֱ������\n"NOR, environment(me), me);
}
