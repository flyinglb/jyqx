/*[1;36mLast modified by 一点红(sdlkx) on Sun Apr 15 16:56:52 2001[2;37;0m*/
//jyqxII 名人堂
// by sdlkx 4/15/2001
#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIW"一点红"NOR,({"Sdlkx"}));
set("per",30);
set("nickname",BLINK+HIG"忘"HIR"事"HIW"大"HIY"王"NOR);
set("gender", "男性");
set("age", 20);
set("long",
     "他是这里的忘事大王，老是忘事，一个星期不上线的朋友\n"+
     "准被忘掉，别人借了他的钱他也忘，他借别人的钱他也忘。\n"+
     "所以人称----"BLINK+HIG"忘"HIR"事"HIW"大"HIY"王"NOR"。\n"
);
setup();
carry_object("/d/city2/obj/jinduan")->wear();
}
