// Room: /city/jiao.c
// Date: Feb.14 1998 by Java
inherit ITEM;
#include <ansi.h>
void setup()
{}
void init()
{
        add_action("do_enter", "enter");
}
void create()
{
        set_name(CYN"���عٽ�"NOR, ({"jiao",}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����ش�ٽΣ�������֪���ͳɶ��ᶽ��ͬ���������ģ��������صĿ�Ρ�\n");
                set("unit", "��");
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_drop", 1);
                set("no_put", 1);
        }
        setup();
}
int do_enter(string arg)
{
	object room, me = this_player();
        if( !arg || arg!="jiao" ) return 0;
        message_vision("$Nһ�����ƿ��������������ȥ��\n\n", me ) ;
        if( !(room = find_object(__DIR__"jiaonei")) )
            room = load_object(__DIR__"jiaonei");
        if( room = find_object(__DIR__"jiaonei") ) 
	me->move(room);
	message("vision", me->name() + "�ӽ������˽�����\n\n",
		environment(me), ({me}) );
        call_out("reach", 20, me);
	return 1;
}	

void reach(object me)
{
        tell_object(me, "ͻȻ�����Ӷ���һ��ͣ��������Ȼ������˵: ���ˣ���Ρ�\n");
        me->move("/d/city3/eastroad1");
}
