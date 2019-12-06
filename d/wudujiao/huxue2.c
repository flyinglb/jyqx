// by mayue


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��Ѩ�");
	set("long", @LONG
�������Ҷ��������ֻ�����¼����µ�С�������ڶ�����Ϸ����
�ڽ�������һ�Ѱ׹ǣ�����ϸһ������Ȼ��һ��������Źǡ�
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"langwo",
//		"south" : __DIR__"huxue2",
//		"out" : __DIR__"milin7",
		"north" : __DIR__"huxue1",
	]));
        set("objects", ([
                __DIR__"npc/laohu2": 3,
	]));

	setup();
}
void init()
{
	add_action("do_search","search");
	add_action("do_train","rain");

}

int do_search(string arg)
{
	object me=this_player();
	object ob; 
	if( (!arg) ||!((arg == "bone") || (arg == "�Ź�")))
		return notify_fail("��Ҫ����ʲô��\n");

	if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="staff" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword" ) ) 
		return notify_fail("û�й�����ô�ɻ\n");

	     message_vision(HIR "\n$N���Ღ���ǶѰ׹ǡ�\n\n" NOR, me);
	
//    if( "/d/wudujiao/obj/tongpai"->in_mud() )  {
//  message("vission", HIR "ֻ������һ����������ܳ���һֻ������\n"NOR, me);
//  	   return 1;
//    }
 
if(query("not_tongpai")) {
  	   message("vission", HIR "ֻ������һ����������ܳ���һֻ������\n"NOR, me);
  	   return 1;
    }


	ob=new(__DIR__"obj/tongpai.c");
	ob->move(environment(me));
	 message_vision(HIR "ֻ�������..��һ���������������һ��ͭ�ơ�\n\n\n"NOR, me);
	set("not_tongpai", 1);
        call_out("regenerate", 86400);
	return 1;
}
int regenerate()
{
set("not_tongpai", 0);
return 1;
} 

