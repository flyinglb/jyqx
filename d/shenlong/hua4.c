inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIC "�����" NOR, ({"hua"}));
        set("unit", "��");
	set("long", "����һ��ǧ���ѵ�һ���������,��˵�ܽ�ٶ���\n");
        setup();
}

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
if(arg=="hua") 
{
tell_object(this_player(), HIG "��ֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR );
this_player()->set_temp("nopoison", 1);
this_player()->set("eff_jing",this_player()->query("max_jing"));
this_player()->set("jing",this_player()->query("max_jing"));
this_player()->set("eff_qi",this_player()->query("max_qi"));
this_player()->set("qi",this_player()->query("max_qi"));
destruct(this_object());
}
return 1;
}
