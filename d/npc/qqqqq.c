
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"球球"NOR,({"Qqqqq"}));
//      set("nickname", HIW NOR);
	set("gender", "男性");
        set("age", 30);
	set("long", 
                "他是新金庸群侠传II的早期玩家之一，也是最忠实的玩家，\n"
                "虽然经验增长不快，但经过不懈的努力，终于也跻身于三流\n"
                "高手之列。为人诚恳正直，不拘小节，乐于帮助别人。\n");

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
