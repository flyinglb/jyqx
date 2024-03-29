// sword.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void init();


void create()
{
        set_name(HIW"玉龙剑" NOR, ({ "yulong sword","jian","dragon","sword" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
            set("dynamic_quest", "/d/npc/xiaofeng");
               set("value", 300000);
                set("material", "steel");
set("wield_msg", CYN"剑决一起,从天上飞来一条玉龙,落入$N的手中,化成一把$n,"+NOR+CYN"放射出璀璨光芒,天地为之变色。\n" NOR);
               set("unwield_msg", CYN"剑决一毕,$N手中的$n"+NOR+CYN"又变回一条玉龙,踏云而去,天幕渐渐焕出光芒。
。\n");
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
        message_vision(HIR "真武剑突然化做一只"+NOR+HIW"玉龙"+NOR+HIR"� 喷出剧烈的火焰� 燎烤着$n的全身。\n" NOR,me,victim);
for(equip=0; equip<sizeof(inv); equip++) 
{ 
   if( inv[equip]->query("equipped") && !inv[equip]->query("weapon_prop") && inv[equip]->query("armor_type") == "cloth")
   {
message_vision(HIR"$n闻到一股焦味，发现身上的"+NOR+inv[equip]->query("name")+HIR"已被烧得残破不堪，掉在了地上！\n"NOR,me,victim);
     inv[equip]->unequip();
     inv[equip]->reset_action();
     inv[equip]->move(environment(victim));
     inv[equip]->set("name", HIR"被破碎的物事"NOR);
     inv[equip]->set("value", 0);
     inv[equip]->set("armor_prop", 0);
     inv[equip]->set("long", "一堆破碎物事，好象是布片铁片什么的。\n");
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

        if (!id(arg))   return notify_fail("你要装备什么？\n");


        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");

        if( ob->query("equipped") )
                return notify_fail("你已经装备著了。\n");


        if( ob->wield() ) {
              if( !stringp(str = ob->query("wield_msg")) )
                        str = "$N装备$n作武器。\n";
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

        if( !arg ) return notify_fail("你要脱掉什么？\n");

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");

        if( (string)ob->query("equipped")!="wielded" )
                return notify_fail("你并没有装备这样东西作为武器。\n");

        if( ob->unequip() ) {
                if( !stringp(str = ob->query("unwield_msg")) )
                        str = "$N放下手中的$n。\n";
                message_vision(str, me, ob);
        if ((int)ob->query_temp("wield") == 1 )
                        me->add_temp("apply/damage", -400);
                        me->set_temp("wield", 0);

                return 1;
        } else
                return 0;
}

