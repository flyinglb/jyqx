//dangao.c
inherit F_FOOD;
inherit ITEM;
void create()
{
   set_name(HIW"һ������ʯ"NOR, ({ "Diamond" }) )
   set_weight(200);
   if ( clonep() )
       set_default_object(__FILE__);
   else {
	 set("long", "һ��������ķ����档\n");
	 set("unit","��");
	 set("value",200);
	 set("food_remaining",4);
         set("food_supply",300);
	}
	setup();
}
