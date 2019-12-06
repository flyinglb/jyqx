// item: /d/xingxiu/npc/obj/donkey.c
// Jay 3/26/96

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_ride", "ride");
}

void create()
{
        set_name("Сë¿", ({"mao lv"}));
        set_weight(15000);
        set_max_encumbrance(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ƥ");
                set("long", "һƥ��ɫ��Сë¿�������Ҳ�����Զ�����\n");
                set("value", 400);
        }
}

int do_ride(string arg)
{
	object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (this_player()->query_temp("marks/��") ) {
                       write("���Ѿ����������ˡ���������¿?!\n");
                        return 1;
        }
        else {
               message("vision",this_player()->name() + "������¿��ë¿һ�����ӣ�"
                       "�ְ�"+this_player()->name() + "����¿����\n",
                        environment(me), ({me}) );
               write("������ë¿�������������\n");
        return 1;
        }
}
