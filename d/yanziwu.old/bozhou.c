//ROOM: /d/yanziwu/bozhou.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "������");
        set("long",@LONG
һƬ«έ�����״����ֳ�һ�����룬��С��ֻ�����ſ����⻨��Ҷ
��������ˮ����ͨ�˴�ɴ˿ɳ˴��뿪�����롣������ϵ��һβС��
(zhou)��
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
            "east"  : __DIR__"pindi",
        ]));
        set("item_desc", ([
            "zhou" : "����������ͺ�����ϵ��С�ۡ�����һ��������Ů�����ϵĿ���ֻҪ��
��(enter)�Ϳ��Գ����ˡ�\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
       add_action("do_enter", "enter");
}
int do_enter(string arg)
{
       object ob ;
       if( !arg || arg !="zhou" ) 
       {
             tell_object(this_player() , "��ҪͶˮ��\n" ) ;
             return 1 ;
       }
       ob = this_player();
message_vision("����һ����������Ľ�����Ů����$N���ۣ������㣬�����밶��
�����뽥������Ұ��Զȥ��\n", ob);
       ob ->move(__DIR__"taihu") ;
       tell_object(ob, HIG "���ں���Ʈ�������ܿ������Ľ���������\n" NOR ) ;
       call_out("home", 10 , ob );
       return 1 ;
}
void home( object ob )
{
       tell_object(ob , "С��������������ؿ����ˡ�������С��������Ů���ֵ���\n" ) ;
       ob->move (__DIR__"hupan") ;
}
