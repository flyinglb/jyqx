#include <ansi.h>

inherit ITEM;

void create()
{
       set_name("����", ({"haigu"}) );
       set_weight(10000);
       set_max_encumbrance(6000000);
       if( clonep() )
               set_default_object(__FILE__);
       else{
       set("unit", "��");
       set("long", "����һ��Ů�ӵĺ��ǡ������ز�����һ�Ѹ��ӡ�\n");
       set("value", 0);
       set("material","wood");
       set("no_get",1);
       set("init",0);
       }
       setup();
}

void init()
{
       object ob;
       object me=this_object();
       if( query("init") == 0 ) {
               ob=new("/d/tiezhang/obj/goldaxe");
               ob->move(me);
               add("init",1);
       }
}

