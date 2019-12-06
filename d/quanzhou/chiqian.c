// Room: /d/quanzhou/chiqian.c
// Date: May 7, 96   Jay
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��Ƕ��");
	set("long", @LONG
�˵�Ϊ̨�帮פ����̨�忪��δ�ã�����ү��������
���˳ǣ�Χ����ë�������֮�ã����½����ȱ��
    ���⺣�ۣ�����(zhou)�����������
LONG );
	set("exits", ([
                "eastup" : __DIR__"riyuetang",
                "north"  : __DIR__"jilong",
                "south"  : __DIR__"dagou",
	]));
	set("item_desc", ([
                "zhou" : "һ�����ۣ���������Ľ�ͨ������\n",
	]));
	set("objects", ([
		__DIR__"npc/hongmao": 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
//	replace_program(ROOM);
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ;
//    string dir;
    if( !arg || arg !="zhou" ) 
       {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    message_vision("ˮ��һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("ˮ�����𷫣��������������С�\n", ob);
    ob ->move(__DIR__"dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("tpenghu", 10 , ob );
    return 1 ;
}
void tpenghu(object ob )
{
    tell_object(ob , "�������ڵִ��˺�Ͽ��һ���󵺡������´�����\n" ) ;
    ob->move (__DIR__"penghu") ;
}
