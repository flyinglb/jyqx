
#include <ansi.h>

inherit NPC;

void create()
{
set_name("�˺Შ",({"rose"}));
	set("nickname", HIG "��" NOR+HIY "��" NOR +HIG "��" NOR);
	set("gender", "Ů��");
	set("age", 20);
	set("long", 
"��������޴�ħŮ�˺Შ");  
  

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
