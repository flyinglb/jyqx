// /u/beyond/mr/npc/obj/paper.c
// this is made by beyond
// update beyond
inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIW"ֽ��"NOR, ({ "paper" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "��");
               set("long", "����һ��ֽ������ʲô�װ׵ģ�ʲô��û�С�\n");
               set("value", 0);
               set("no_get",1);
               set("no_drop",1);
               set("material", "paper");
       }
       setup();
}

