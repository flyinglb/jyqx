
inherit NPC;

void create()
{
        set_name(HIW"萧白"NOR, ({"Netbai"}));
	set("nickname",HIR"【"+HIW+"七星楼"+HIR+"】"+HIG+"副楼主 "+HIY+"天煞孤星"NOR);
	set("gender", "男性");
	set("age", 30);
	set("per", 30);
	set("long", 
                  "他就是在本MUD中最差的新手了，不知道到底是怎么混到这里来的\n"
                  "脾气好，不过心眼挺坏。再见到他的时候要千万小心点！\n");
                             
	setup();
        
	carry_object("/d/city2/obj/jinduan")->wear();
}
