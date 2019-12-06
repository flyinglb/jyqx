
inherit NPC;

void create()
{
        set_name(HIW"易水寒"NOR, ({"Sno"}));
	set("nickname",HIR"【"+HIW+"七星楼"+HIR+"】"+BLK+"黑暗右使 "+HIY+"霸刀无敌"NOR);
	set("gender", "男性");
	set("age", 25);
	set("per", 28);
	set("long", 
                  "风萧萧兮易水寒，壮士一去兮不复还！\n"
                  "……\n");
                             
	setup();
        
	carry_object("/d/city2/obj/jinduan")->wear();
}
