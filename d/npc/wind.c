#include <ansi.h>

inherit NPC;

void create()

{
        set_name(HIW"����"NOR, ({"Wind"}));
	set("nickname",HIC"�����ſ�ɽ��ʦ"NOR);
	set("gender", "����");
	set("age", 20);
	set("per", 28);
	set("long", 
		"�����ǵ���ķ磬һ��ƽ�����Ժ󣬹������ˣ�����ɽ�ȡ�\n"+
                "������������ƣ������ǡ��������Գ������֡�\n");
	

	setup();
	
	carry_object("/d/city2/obj/jinduan")->wear();
}
