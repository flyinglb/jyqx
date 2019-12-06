// haitan.c
#include <ansi.h>

inherit ROOM;

void home( object ob ) ;

void create()
{
    set("short", "��̲");
    set("long", @LONG
����������͵��ˡ�������һ���޼ʵĴ󺣣���������һƬ��
�֡����ϵĿ����ƺ��ǳ����ʣ���ʪ�ĺ����д���һ�ɻ��㣬����
�ô��һƬɳ̲������ʯ����ͣ����ʮ���Ҵ�С�Ĵ�ֻ(boat)��
LONG );

    set("item_desc", ([
        "boat" : "�������͵�������ϵ�Ĵ󴬡����ϵĿ��˻����ֻҪ\n"
                  "�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
    ]));
    set("exits",([
        "south" :__DIR__"lin1",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "xiakedao");
    setup();
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ;
    if( !arg || arg !="boat" )
       {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("�������𷫣������򱱷����С�\n", ob);
    ob ->move("/d/xiakedao/dahai") ;
    tell_object(ob, BLU "���ں��Ϻ�����������ҹ.......\n" NOR ) ;
    call_out("home", 10 , ob );
    return 1 ;
}
void home( object ob )
{
    tell_object(ob , "�����ڵִ����Ϻ����ߡ������´�����\n" ) ;
    ob->move (__DIR__"haigang") ;
}
