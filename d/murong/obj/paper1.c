// /u/beyond/mr/npc/obj/paper1.c
// this is made by beyond
// update beyond
inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIW"��Ϯ��"NOR, ({ "biao" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "��");
               set("long", "����һ��Ľ�����ҵ���Ϯ������д������Ľ�����ҵļ��ס�\n");
               set("value", 0);
               set("no_drop",0);
               set("material", "paper");
       }
       setup();
}

