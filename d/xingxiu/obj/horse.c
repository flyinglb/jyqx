// item: /d/xingxiu/npc/obj/horse.c
// Jay 3/17/96

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_ride", "ride");
}

void create()
{
        set_name("������", ({"horse", "yili ma", "ma"}));
        set_weight(35000);
        set_max_encumbrance(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ƥ");
                set("long", "һƥ���ֵ�������������(ride)��Ҳ�����Զ�����\n");
                set("value", 1000);
        }
}

int do_ride(string arg)
{
	object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (this_player()->query_temp("marks/��") ) {
                       write("���Ѿ����������ˡ�\n");
                        return 1;
        }
        else {
               message("vision",this_player()->name() + "��������\n",
                        environment(me), ({me}) );
               write("��սս���������������ã�����û��������\n");
                this_player()->set_temp("marks/��", 1);
        return 1;
        }
}
