// shouwu.c ������
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(WHT"������"NOR, ({"shouwu"}));
        set_weight(800);
        set("unit", "֧");
        set("long", "����һ֧�ѳ����εĺ����ڣ�����������ҩ��\n");
        setup();
}

int do_eat(string arg)
{
        object me=this_player();

        if (!(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(arg=="shouwu")
        {
                if ((int)me->query("max_jingli")<=200) {
                        write("�������һ֧�����ڣ�ֻ���þ�����֮����\n");
                        me->add("max_jingli",2);
                        me->add("jingli",2);
                }
                else {
                        write("�������һ֧�����ڣ����Ǻ���ûʲô�á�\n");
                }
                destruct(this_object());
                me->unconcious();
        }
        return 1;
}
