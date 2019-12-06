//
// xue-dao.c
//

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

int do_wield(string arg);

void create()
{
	set_name( HIR "Ѫ��" NOR , ({ "xblade" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIR "����һ�Ѳ�������ı�����������ŵ�����ѪӰ��\n" NOR );
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(250);
	setup();
}

/*
void init()
{
        add_action("do_wield", "wield");
}


int do_wield(string arg)
{
        object me=this_player();

        object ob;
        string str;

        if (!id(arg))   return notify_fail("��Ҫװ��ʲô��\n");


	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");


	if( ob->wield() ) {
              if( !stringp(str = ob->query("wield_msg")) )
			str = "$Nװ��$n��������\n";
              message_vision(str, me, ob);
              if ( me->query_skill("xue-dao")
              && me->query_skill_mapped("blade") == "xue-dao" )
			me->add_temp("apply/damage",200);

              return 1;
	}

        else
                return 0;
}
*/
