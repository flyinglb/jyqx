#include <ansi.h>

inherit ITEM;
#include <ansi.h>
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
        object book;
        object me = this_player();
        if (!id(arg))
                return 0;
        if (this_player()->query_temp("wumu_shanshui") ) {
                if (!present("wumu yishu",me)){
                message_vision(
HIY"$N�����Ų�����ǣ�����������һ���飬$N��æ���𴧵����С�\n"NOR
RED"�Ǻ���ͻȻӭͷ��$N�˽�������ˤ�ڵ��ϣ�����ɢ��������$Nһ����\n"NOR,this_player());
                book = new(__DIR__"wumu-yishu");
                book->move(me);
                destruct(this_object());
                return 1;
                }
                message_vision(
HIM"���Ǽ������鶼�õ��˻��������û�°�����Ų��Ųȥ�ĸ�ʲô������\n"NOR, this_player());
                return 1;
                }
                else {
                message_vision(
HIR"$N�����Ų�����ǣ�ͻȻ�Ӻ��ǵ�����ð��һ�ɶ��������$N�ı����С�\n"NOR, this_player());
		me->set_temp("last_damage_from", "�ж�");
                me->die();
                return 1;
        }
}

