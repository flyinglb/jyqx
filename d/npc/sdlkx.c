/*[1;36mLast modified by Ò»µãºì(sdlkx) on Sun Apr 15 16:56:52 2001[2;37;0m*/
//jyqxII ÃûÈËÌÃ
// by sdlkx 4/15/2001
#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIW"Ò»µãºì"NOR,({"Sdlkx"}));
set("per",30);
set("nickname",BLINK+HIG"Íü"HIR"ÊÂ"HIW"´ó"HIY"Íõ"NOR);
set("gender", "ÄĞĞÔ");
set("age", 20);
set("long",
     "ËûÊÇÕâÀïµÄÍüÊÂ´óÍõ£¬ÀÏÊÇÍüÊÂ£¬Ò»¸öĞÇÆÚ²»ÉÏÏßµÄÅóÓÑ\n"+
     "×¼±»Íüµô£¬±ğÈË½èÁËËûµÄÇ®ËûÒ²Íü£¬Ëû½è±ğÈËµÄÇ®ËûÒ²Íü¡£\n"+
     "ËùÒÔÈË³Æ----"BLINK+HIG"Íü"HIR"ÊÂ"HIW"´ó"HIY"Íõ"NOR"¡£\n"
);
setup();
carry_object("/d/city2/obj/jinduan")->wear();
}
