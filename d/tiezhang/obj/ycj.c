//ycj.c
//zqb
#include <ansi.h>
#include <weapon.h>
inherit SWORD;


void setup()
{}

void init()
{
        add_action("do_jian", "jian");
}

void create()
{
       set_name("�㳦��", ({"yuchang jian","jian"}) );
       set_weight(10000);
       
       if( clonep() )
               set_default_object(__FILE__);
       else{
       set("unit", "��");
       set("long", "����Ǵ�˵�е��㳦����û�뵽����������֣�\n"
                   "���Ź�â������\n");
       set("value",1000000);
       set("material", "steel");
       set("no_get",1);
       }
       init_sword(1000);
       setup();
}

int do_jian(string arg)
{
       
        object me = this_player();
        if (!id(arg))
                return 0;
       
                
                {
                message_vision(
HIR"$N����ؼ����㳦����ͻȻ�ӽ������һö���룬����Ĵ���$N�����ڡ�\n"NOR, this_player());
                me->unconcious();
         me->move("/d/tiezhang/shanlu-6");
                return 1;
        }
}



