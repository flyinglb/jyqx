//haigu-1.c
//zqb
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_move", "move");
}

void create()
{
       set_name("����", ({"haigu","skeleton"}) );
       set_weight(10000);
       set_max_encumbrance(6000000);
       if( clonep() )
               set_default_object(__FILE__);
       else{
       set("unit", "��");
       set("long", "�⸱�������������Ѿ��ܾ��ˡ�\n");
       set("value", 0);
       set("material","wood");
       set("no_get",1);
       set("init",0);
       }
       setup();
}

int do_move(string arg)
{
//        object book;
        object me = this_player();
        if (!id(arg))
                return 0;
       
                
                {
                message_vision(
HIR"$N�����Ų�����ǣ�ͻȻ�Ӻ��ǵ�������һö���룬����$N�����ڡ�\n"NOR, this_player());
                me->unconcious();
                me->move("/u/zqb/tiezhang/shanlu-6");
                return 1;
        }
}



