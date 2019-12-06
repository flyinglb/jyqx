// sword.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void init();


void create()
{
        set_name(HIW"������" NOR, ({ "yulong sword","jian","dragon","sword" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("dynamic_quest", "/d/npc/xiaofeng");
               set("value", 300000);
                set("material", "steel");
set("wield_msg", CYN"����һ��,�����Ϸ���һ������,����$N������,����һ��$n,"+NOR+CYN"������貹�â,���Ϊ֮��ɫ��\n" NOR);
               set("unwield_msg", CYN"����һ��,$N���е�$n"+NOR+CYN"�ֱ��һ������,̤�ƶ�ȥ,��Ļ����������â��
��\n");
        }
        init_sword(150);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
      int equip;
      object* inv;
      inv = all_inventory(victim);

        victim->receive_wound("qi",5,me);
        message_vision(HIR "���佣ͻȻ����һֻ"+NOR+HIW"����"+NOR+HIR"� ������ҵĻ��� �ǿ���$n��ȫ��\n" NOR,me,victim);
for(equip=0; equip<sizeof(inv); equip++) 
{ 
   if( inv[equip]->query("equipped") && !inv[equip]->query("weapon_prop") && inv[equip]->query("armor_type") == "cloth")
   {
message_vision(HIR"$n�ŵ�һ�ɽ�ζ���������ϵ�"+NOR+inv[equip]->query("name")+HIR"�ѱ��յò��Ʋ����������˵��ϣ�\n"NOR,me,victim);
     inv[equip]->unequip();
     inv[equip]->reset_action();
     inv[equip]->move(environment(victim));
     inv[equip]->set("name", HIR"�����������"NOR);
     inv[equip]->set("value", 0);
     inv[equip]->set("armor_prop", 0);
     inv[equip]->set("long", "һ���������£������ǲ�Ƭ��Ƭʲô�ġ�\n");
    }
}

}
void init()
{
        add_action("do_wield", "wield");
        add_action("do_unwield", "unwield");
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
              if((int)(me->query("shen") > 100000 && me->query("xin") > 400 ))
                        me->add_temp("apply/damage",400);
                        me->set_temp("wield",1);

              return 1;
        }
        else
                return 0;
}

int do_unwield(string arg)
{
        object me=this_player();
        object ob;
        string str;

        if( !arg ) return notify_fail("��Ҫ�ѵ�ʲô��\n");

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("������û������������\n");

        if( (string)ob->query("equipped")!="wielded" )
                return notify_fail("�㲢û��װ������������Ϊ������\n");

        if( ob->unequip() ) {
                if( !stringp(str = ob->query("unwield_msg")) )
                        str = "$N�������е�$n��\n";
                message_vision(str, me, ob);
        if ((int)ob->query_temp("wield") == 1 )
                        me->add_temp("apply/damage", -400);
                        me->set_temp("wield", 0);

                return 1;
        } else
                return 0;
}

