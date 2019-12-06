// sword.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void init();


void create()
{
        set_name(HIW"ÓñÁú½£" NOR, ({ "yulong sword","jian","dragon","sword" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "±ú");
            set("dynamic_quest", "/d/npc/xiaofeng");
               set("value", 300000);
                set("material", "steel");
set("wield_msg", CYN"½£¾öÒ»Æğ,´ÓÌìÉÏ·ÉÀ´Ò»ÌõÓñÁú,ÂäÈë$NµÄÊÖÖĞ,»¯³ÉÒ»°Ñ$n,"+NOR+CYN"·ÅÉä³öè­è²¹âÃ¢,ÌìµØÎªÖ®±äÉ«¡£\n" NOR);
               set("unwield_msg", CYN"½£¾öÒ»±Ï,$NÊÖÖĞµÄ$n"+NOR+CYN"ÓÖ±ä»ØÒ»ÌõÓñÁú,Ì¤ÔÆ¶øÈ¥,ÌìÄ»½¥½¥»À³ö¹âÃ¢¡£
¡£\n");
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
        message_vision(HIR "ÕæÎä½£Í»È»»¯×öÒ»Ö»"+NOR+HIW"ÓñÁú"+NOR+HIR"£ Åç³ö¾çÁÒµÄ»ğÑæ£ ÁÇ¿¾×Å$nµÄÈ«Éí¡£\n" NOR,me,victim);
for(equip=0; equip<sizeof(inv); equip++) 
{ 
   if( inv[equip]->query("equipped") && !inv[equip]->query("weapon_prop") && inv[equip]->query("armor_type") == "cloth")
   {
message_vision(HIR"$nÎÅµ½Ò»¹É½¹Î¶£¬·¢ÏÖÉíÉÏµÄ"+NOR+inv[equip]->query("name")+HIR"ÒÑ±»ÉÕµÃ²ĞÆÆ²»¿°£¬µôÔÚÁËµØÉÏ£¡\n"NOR,me,victim);
     inv[equip]->unequip();
     inv[equip]->reset_action();
     inv[equip]->move(environment(victim));
     inv[equip]->set("name", HIR"±»ÆÆËéµÄÎïÊÂ"NOR);
     inv[equip]->set("value", 0);
     inv[equip]->set("armor_prop", 0);
     inv[equip]->set("long", "Ò»¶ÑÆÆËéÎïÊÂ£¬ºÃÏóÊÇ²¼Æ¬ÌúÆ¬Ê²Ã´µÄ¡£\n");
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

        if (!id(arg))   return notify_fail("ÄãÒª×°±¸Ê²Ã´£¿\n");


        if( !objectp(ob = present(arg, me)) )
                return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");

        if( ob->query("equipped") )
                return notify_fail("ÄãÒÑ¾­×°±¸ÖøÁË¡£\n");


        if( ob->wield() ) {
              if( !stringp(str = ob->query("wield_msg")) )
                        str = "$N×°±¸$n×÷ÎäÆ÷¡£\n";
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

        if( !arg ) return notify_fail("ÄãÒªÍÑµôÊ²Ã´£¿\n");

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");

        if( (string)ob->query("equipped")!="wielded" )
                return notify_fail("Äã²¢Ã»ÓĞ×°±¸ÕâÑù¶«Î÷×÷ÎªÎäÆ÷¡£\n");

        if( ob->unequip() ) {
                if( !stringp(str = ob->query("unwield_msg")) )
                        str = "$N·ÅÏÂÊÖÖĞµÄ$n¡£\n";
                message_vision(str, me, ob);
        if ((int)ob->query_temp("wield") == 1 )
                        me->add_temp("apply/damage", -400);
                        me->set_temp("wield", 0);

                return 1;
        } else
                return 0;
}

