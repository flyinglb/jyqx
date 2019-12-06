//dangao.c
inherit F_FOOD;
inherit ITEM;
void create()
{
   set_name(HIW"一克拉钻石"NOR, ({ "Diamond" }) )
   set_weight(200);
   if ( clonep() )
       set_default_object(__FILE__);
   else {
	 set("long", "一碗香喷喷的方便面。\n");
	 set("unit","碗");
	 set("value",200);
	 set("food_remaining",4);
         set("food_supply",300);
	}
	setup();
}
